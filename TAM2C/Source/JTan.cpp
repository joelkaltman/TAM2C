#include <TAM2C/Include/Jtan.h>

#include <TAM2C/Include/Config.h>

JTan::JTan(p3d::Scene3D* scene, p3d::Scene2D* sceneGDSU) : 
	scene(scene)
{
	transfTraslation = scene->installAffineTransformation();
	transfTraslation->setPose(RELATIVE_DISTANCE_CAMERA_JTAN_X, RELATIVE_DISTANCE_CAMERA_JTAN_Y, RELATIVE_DISTANCE_CAMERA_JTAN_Z,
		RELATIVE_DISTANCE_CAMERA_JTAN_X, RELATIVE_DISTANCE_CAMERA_JTAN_Y + 1.0, RELATIVE_DISTANCE_CAMERA_JTAN_Z,
		0.0, 0.0, 1.0);

	transfRotDirection = scene->installAffineTransformation();

	transfRotHeight = scene->installAffineTransformation();
	transfRotHeight->clampPitch(MIN_ANGLE_RISE_PERISCOPE, MAX_ANGLE_RISE_PERISCOPE);

	camera = scene->installCamera(0.0, 0.0, 0.0,
		-RELATIVE_DISTANCE_CAMERA_JTAN_X + RELATIVE_DISTANCE_CANNON_X, -RELATIVE_DISTANCE_CAMERA_JTAN_Y + RELATIVE_DISTANCE_CANNON_Y + DISTANCIA_CALIBRACION_PUNTERIA, -RELATIVE_DISTANCE_CAMERA_JTAN_Z + RELATIVE_DISTANCE_CANNON_Z,
		0.0, 0.0, 1.0);

	camera->setPerspectiveFovProjection(12.5, 860 / 560, 0.5, 50000.0, true);
	camera->setZoomFactor(2.0);
	
	transfTraslation->addChild(transfRotDirection);
	transfRotDirection->addChild(transfRotHeight);
	transfRotHeight->addChild(camera);

	p3d::TrajectoryManager* trajMng = p3d::P3D::getInstance()->getTrajectoryManager();
	trajDirection = trajMng->createVerticalRotationTrajectory(transfRotDirection, 0.0);
	trajDirection->start();

	trajHeight = trajMng->createLateralRotationTrajectory(transfRotHeight, 0.0);
	trajHeight->start();

	createCameraGDSU();

	gdsu = new GDSU(sceneGDSU);
	window->showScene2D(sceneGDSU, 860 / 2, 560 / 2, 1, 860, 560);

	uiJtan.addSubscriber(this);
}

JTan::~JTan()
{
	p3d::TrajectoryManager* trajMng = p3d::P3D::getInstance()->getTrajectoryManager();
	trajMng->destroyTrajectory(trajDirection);
	trajMng->destroyTrajectory(trajHeight);

	scene->uninstallAffineTransformation(transfTraslation);
	scene->uninstallAffineTransformation(transfRotHeight);
	scene->uninstallCamera(camera);

	uiJtan.close();
}

void JTan::rotate(double drift, double rise)
{
	trajDirection->setFreeRotationVelocity(drift);
	trajHeight->setFreeRotationVelocity(rise);

	gdsu->updateOrientationLabels(drift, rise);
}

void JTan::createCameraGDSU()
{
	Config::initData.fullScreenJtan ? uiJtan.showFullScreen() : uiJtan.show();
	uint32_t winId = uiJtan.getPGSWidget()->winId();

	p3d::P3D* p3d = p3d::P3D::getInstance();
	window = p3d->createWindow(winId);
	window->showCamera(camera);
}

void JTan::notify(ELEM_ID elem, int state)
{
	// General
	if (elem == GDSU_SWITCH_1)
		config.general = (state == POS_2) ? GENERAL_READY : GENERAL_OFF;

	// GDSU
	if (elem == GDSU_BUTTON_LEFT_2 && state == PRESSED)
		(config.ammo == AP1) ? config.ammo = AP2 : config.ammo = AP1;

	if (elem == GDSU_BUTTON_LEFT_3 && state == PRESSED)
		(config.ammo == HP1) ? config.ammo = HP2 : config.ammo = HP1;

	if (elem == GDSU_BUTTON_LEFT_4 && state == PRESSED)
		(config.ammo == HE1) ? config.ammo = HE2 : config.ammo = HE1;

	if (elem == GDSU_BUTTON_RIGHT_1 && state == PRESSED)
		config.vision = DAYCAM;

	if (elem == GDSU_BUTTON_RIGHT_2 && state == PRESSED)
		config.vision = NIGHTCAM;

	if (elem == GDSU_BUTTON_RIGHT_3 && state == PRESSED)
	{
		(config.zoom < VW) ? config.zoom = ZOOM(config.zoom + 1) : config.zoom = ZOOM(0);
		camera->setZoomFactor(std::pow(2.0f, config.zoom));
	}

	if (elem == GDSU_BUTTON_RIGHT_4 && state == PRESSED)
		(config.screen < IR) ? config.screen = SCREEN(config.screen + 1) : config.screen = SCREEN(0);

	gdsu->updateConfig(config);
	uiJtan.updateConfig(config, elem);
}
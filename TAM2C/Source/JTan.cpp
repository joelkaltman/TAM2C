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

	uiJtan.getUiElement(JTAN_P1_SWITCH_1)->setState(POS_1);
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

IElement* JTan::getIElement(ELEM_ID elemId)
{
	return uiJtan.getUiElement(elemId);
}

void JTan::notify(ELEM_ID elem, int state)
{
	if (elem == JTAN_P1_SWITCH_1)
	{
		config.lastChange = 0;
		config.general = (state == POS_2) ? GENERAL_READY : GENERAL_OFF;
	}
	gdsu->updateConfig(config);
	uiJtan.updateConfig(config);
}
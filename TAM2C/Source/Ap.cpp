#include <TAM2C/Include/Ap.h>

#include <TAM2C/Include/Config.h>
#include <TAM2C/Include/LocalResourceManager.h>

Ap::Ap(p3d::Scene3D* scene, p3d::Scene2D* sceneGDSU) :
	scene(scene)
{
	turret = scene->installObject(RELATIVE_DISTANCE_TOWER_X, RELATIVE_DISTANCE_TOWER_Y, RELATIVE_DISTANCE_TOWER_Z,
		RELATIVE_DISTANCE_TOWER_X, RELATIVE_DISTANCE_TOWER_Y + 1.0, RELATIVE_DISTANCE_TOWER_Z,
		0.0, 0.0, 1.0, LocalResourceManager::getInstance().resources["TAM2C_turret"], false);

	cannon = scene->installObject(RELATIVE_DISTANCE_CANNON_X, RELATIVE_DISTANCE_CANNON_Y, RELATIVE_DISTANCE_CANNON_Z,
		RELATIVE_DISTANCE_CANNON_X, RELATIVE_DISTANCE_CANNON_Y + DISTANCIA_CALIBRACION_PUNTERIA, RELATIVE_DISTANCE_CANNON_Z,
		0.0, 0.0, 1.0, LocalResourceManager::getInstance().resources["TAM2C_cannon"], false);

	camera = scene->installCamera(RELATIVE_DISTANCE_CAMERA_APUN_X, RELATIVE_DISTANCE_CAMERA_APUN_Y, RELATIVE_DISTANCE_CAMERA_APUN_Z,
		0.0, DISTANCIA_CALIBRACION_PUNTERIA, 0.0,
		0.0, 0.0, 1.0);

	camera->setPerspectiveFovProjection(12.5, 860/560, 0.5, 50000.0, true);

	cannon->clampPitch(MIN_ANGLE_RISE_PERISCOPE, MAX_ANGLE_RISE_PERISCOPE);

	turret->addChild(cannon);
	cannon->addChild(camera);

	p3d::TrajectoryManager* trajMng = p3d::P3D::getInstance()->getTrajectoryManager();
	trajTower = trajMng->createVerticalRotationTrajectory(turret, 0.0);
	trajTower->start();

	trajCannon = trajMng->createLateralRotationTrajectory(cannon, 0.0);
	trajCannon->start();

	createCameraGDSU(); 
	
	gdsu = new GDSU(sceneGDSU);
	window->showScene2D(gdsu->sceneGDSU, 860 / 2, 560 / 2, 1, 860, 560);

	uiAp.addSubscriber(this);
}

Ap::~Ap()
{
	p3d::TrajectoryManager* trajMng = p3d::P3D::getInstance()->getTrajectoryManager();
	trajMng->destroyTrajectory(trajTower);
	trajMng->destroyTrajectory(trajCannon);

	scene->uninstallObject(turret);
	scene->uninstallObject(cannon);
	scene->uninstallCamera(camera);

	uiAp.close();
}

void Ap::addSubscriberToUI(ISubscriber* sub)
{
	uiAp.addSubscriber(sub);
}

void Ap::rotate(double drift, double rise)
{
	trajTower->setFreeRotationVelocity(drift);
	trajCannon->setFreeRotationVelocity(rise);

	gdsu->updateOrientationLabels(drift, rise);
}

void Ap::createCameraGDSU()
{
	Config::initData.fullScreenAp ? uiAp.showFullScreen() : uiAp.show();
	uint32_t winId = uiAp.getPGSWidget()->winId();

	p3d::P3D* p3d = p3d::P3D::getInstance();
	window = p3d->createWindow(winId);
	window->showCamera(camera);
}

IElement* Ap::getGUIElement(ELEM_ID id)
{
	return uiAp.getUiElement(id);
}

void Ap::notify(ELEM_ID elem, ELEM_TYPE type, int state)
{
	// General
	if (uiAp.getUiElement(GDSU_SWITCH_1)->getState() == POS_2 && uiAp.getUiElement(AP_P1_SWITCH_1)->getState() == POS_2)
	{
		config.general = GENERAL_BIT;
		if(uiAp.getUiElement(AP_P2_SWITCH_4)->getState() == POS_2)
			config.general = GENERAL_READY;
	}
	else
	{
		config.general = GENERAL_OFF;
	}

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

	// Panel 2
	if (elem == AP_P2_SWITCH_1)
		config.gun = (state == POS_2) ? MGUN : GUN;

	if (elem == AP_P2_SWITCH_3)
		config.nav = (state == POS_2) ? STG : MSTG;

	if (elem == AP_P2_SWITCH_2)
		config.nav = (state == POS_2) ? GTS : STG;

	gdsu->updateConfig(config);
	uiAp.updateConfig(config, elem);
}

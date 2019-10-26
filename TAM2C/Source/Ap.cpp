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
	camera->setZoomFactor(2.0);

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

	uiAp.getUiElement(AP_P2_SWITCH_1)->setState(POS_1);
	uiAp.getUiElement(AP_P2_SWITCH_4)->setState(POS_1);
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

IElement* Ap::getIElement(ELEM_ID elemId)
{
	return uiAp.getUiElement(elemId);
}

void Ap::notify(ELEM_ID elem, int state)
{
	if (elem == AP_P2_SWITCH_1)
	{
		config.lastChange = 0;
		config.gun = (state == POS_2) ? MGUN : GUN;
	}

	if (elem == AP_P2_SWITCH_3)
	{
		config.lastChange = 1;
		config.nav = (state == POS_2) ? STG : MSTG;
	}

	if (elem == AP_P2_SWITCH_2)
	{
		config.lastChange = 1;
		config.nav = (state == POS_2) ? GTS : STG;
	}

	if (elem == AP_P2_SWITCH_4)
	{
		config.lastChange = 2;
		config.general = (state == POS_2) ? GENERAL_READY : GENERAL_OFF;
	}

	gdsu->updateConfig(config);
	uiAp.updateConfig(config);
}
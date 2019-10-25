#include <TAM2C/Include/Ap.h>

#include <TAM2C/Include/Config.h>
#include <TAM2C/Include/LocalResourceManager.h>

Ap::Ap(p3d::Scene3D* scene, p3d::Scene2D* sceneGDSU) :
	scene(scene)
{
	turret = scene->installObject(DISTANCIA_RELATIVA_TORRE_X, DISTANCIA_RELATIVA_TORRE_Y, DISTANCIA_RELATIVA_TORRE_Z,
		DISTANCIA_RELATIVA_TORRE_X, DISTANCIA_RELATIVA_TORRE_Y + 1.0, DISTANCIA_RELATIVA_TORRE_Z,
		0.0, 0.0, 1.0, LocalResourceManager::getInstance().resources["TAM2C_turret"], false);

	cannon = scene->installObject(DISTANCIA_RELATIVA_CANION_X, DISTANCIA_RELATIVA_CANION_Y, DISTANCIA_RELATIVA_CANION_Z,
		DISTANCIA_RELATIVA_CANION_X, DISTANCIA_RELATIVA_CANION_Y + DISTANCIA_CALIBRACION_PUNTERIA, DISTANCIA_RELATIVA_CANION_Z,
		0.0, 0.0, 1.0, LocalResourceManager::getInstance().resources["TAM2C_cannon"], false);

	camera = scene->installCamera(DISTANCIA_RELATIVA_CAMARA_APUN_X, DISTANCIA_RELATIVA_CAMARA_APUN_Y, DISTANCIA_RELATIVA_CAMARA_APUN_Z,
		0.0, DISTANCIA_CALIBRACION_PUNTERIA, 0.0,
		0.0, 0.0, 1.0);

	camera->setPerspectiveFovProjection(12.5, 860/560, 0.5, 50000.0, true);
	camera->setZoomFactor(2.0);

	cannon->clampPitch(MIN_ANGULO_CABECEO_PERISCOPIO, MAX_ANGULO_CABECEO_PERISCOPIO);

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

void Ap::rotate(double deriva, double alza)
{
	trajTower->setFreeRotationVelocity(deriva);
	trajCannon->setFreeRotationVelocity(alza);

	gdsu->updateOrientationLabels(deriva, alza);
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
		config.gun = (state == POS_2) ? MGUN : GUN;

	if (elem == AP_P2_SWITCH_3)
		config.nav = (state == POS_2) ? STG : MSTG;

	if (elem == AP_P2_SWITCH_2)
		config.nav = (state == POS_2) ? GTS : STG;

	if (elem == AP_P2_SWITCH_4)
		config.general = (state == POS_2) ? GENERAL_READY : GENERAL_OFF;

	gdsu->updateConfig(config);
	uiAp.updateConfig(config);
}
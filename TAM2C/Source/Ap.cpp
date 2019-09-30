#include <TAM2C/Include/Ap.h>

Ap::Ap(p3d::Resource* rTower, p3d::Resource* rCannon, p3d::Scene3D* scene)
{
	tower = scene->installObject(DISTANCIA_RELATIVA_TORRE_X, DISTANCIA_RELATIVA_TORRE_Y, DISTANCIA_RELATIVA_TORRE_Z,
		DISTANCIA_RELATIVA_TORRE_X, DISTANCIA_RELATIVA_TORRE_Y + 1.0, DISTANCIA_RELATIVA_TORRE_Z,
		0.0, 0.0, 1.0, rTower, false);

	cannon = scene->installObject(DISTANCIA_RELATIVA_CANION_X, DISTANCIA_RELATIVA_CANION_Y, DISTANCIA_RELATIVA_CANION_Z,
		DISTANCIA_RELATIVA_CANION_X, DISTANCIA_RELATIVA_CANION_Y + DISTANCIA_CALIBRACION_PUNTERIA, DISTANCIA_RELATIVA_CANION_Z,
		0.0, 0.0, 1.0, rCannon, false);

	camera = scene->installCamera(DISTANCIA_RELATIVA_CAMARA_APUN_X, DISTANCIA_RELATIVA_CAMARA_APUN_Y, DISTANCIA_RELATIVA_CAMARA_APUN_Z,
		0.0, DISTANCIA_CALIBRACION_PUNTERIA, 0.0,
		0.0, 0.0, 1.0);

	cannon->clampPitch(MIN_ANGULO_CABECEO_PERISCOPIO, MAX_ANGULO_CABECEO_PERISCOPIO);

	tower->addChild(cannon);
	cannon->addChild(camera);


	p3d::TrajectoryManager* trajMng = p3d::P3D::getInstance()->getTrajectoryManager();
	trajTower = trajMng->createVerticalRotationTrajectory(tower, 0.0);
	trajTower->start();

	trajCannon = trajMng->createLateralRotationTrajectory(cannon, 0.0);
	trajCannon->start();
}

void Ap::rotate(double deriva, double alza)
{
	trajTower->setFreeRotationVelocity(deriva);
	trajCannon->setFreeRotationVelocity(alza);
}
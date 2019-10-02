#include <TAM2C/Include/Ap.h>

#include <TAM2C/Include/LocalResourceManager.h>

Ap::Ap(p3d::Scene3D* scene)
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
}

void Ap::rotate(double deriva, double alza)
{
	trajTower->setFreeRotationVelocity(deriva);
	trajCannon->setFreeRotationVelocity(alza);

	spriteRot->setFreeRotationVelocity(-deriva);
}

void Ap::addGDSURotation(p3d::Scene2D* scene2d, p3d::Sprite* sprite)
{
	spriteRot = scene2d->installROIRotationAnimationOnSprite(sprite, 0.0);
	spriteRot->start();
}
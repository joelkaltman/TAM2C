#include <TAM2C/Include/Jtan.h>

JTan::JTan(p3d::Scene3D* scene)
{
	transfTraslation = scene->installAffineTransformation();
	transfTraslation->setPose(DISTANCIA_RELATIVA_CAMARA_JTAN_X, DISTANCIA_RELATIVA_CAMARA_JTAN_Y, DISTANCIA_RELATIVA_CAMARA_JTAN_Z,
		DISTANCIA_RELATIVA_CAMARA_JTAN_X, DISTANCIA_RELATIVA_CAMARA_JTAN_Y + 1.0, DISTANCIA_RELATIVA_CAMARA_JTAN_Z,
		0.0, 0.0, 1.0);

	transfRotDirection = scene->installAffineTransformation();

	transfRotHeight = scene->installAffineTransformation();
	transfRotHeight->clampPitch(MIN_ANGULO_CABECEO_PERISCOPIO, MAX_ANGULO_CABECEO_PERISCOPIO);

	camera = scene->installCamera(0.0, 0.0, 0.0,
		-DISTANCIA_RELATIVA_CAMARA_JTAN_X + DISTANCIA_RELATIVA_CANION_X, -DISTANCIA_RELATIVA_CAMARA_JTAN_Y + DISTANCIA_RELATIVA_CANION_Y + DISTANCIA_CALIBRACION_PUNTERIA, -DISTANCIA_RELATIVA_CAMARA_JTAN_Z + DISTANCIA_RELATIVA_CANION_Z,
		0.0, 0.0, 1.0);

	transfTraslation->addChild(transfRotDirection);
	transfRotDirection->addChild(transfRotHeight);
	transfRotHeight->addChild(camera);


	p3d::TrajectoryManager* trajMng = p3d::P3D::getInstance()->getTrajectoryManager();
	trajDirection = trajMng->createVerticalRotationTrajectory(transfRotDirection, 0.0);
	trajDirection->start();

	trajHeight = trajMng->createLateralRotationTrajectory(transfRotHeight, 0.0);
	trajHeight->start();
}

void JTan::rotate(double deriva, double alza)
{
	trajDirection->setFreeRotationVelocity(deriva);
	trajHeight->setFreeRotationVelocity(alza);
}
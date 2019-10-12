#include <TAM2C/Include/Jtan.h>

#include <TAM2C/Include/Definitions.h>

JTan::JTan(p3d::Scene3D* scene, p3d::Scene2D* sceneGDSU) : 
	scene(scene)
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

void JTan::rotate(double deriva, double alza)
{
	trajDirection->setFreeRotationVelocity(deriva);
	trajHeight->setFreeRotationVelocity(alza);

	gdsu->spriteRot->setFreeRotationVelocity(-deriva);
}

void JTan::createCameraGDSU()
{
	Definitions::initData.fullScreenJtan ? uiJtan.showFullScreen() : uiJtan.show();
	uint32_t winId = uiJtan.getPGSWidget()->winId();

	p3d::P3D* p3d = p3d::P3D::getInstance();
	window = p3d->createWindow(winId);
	window->showCamera(camera);
}

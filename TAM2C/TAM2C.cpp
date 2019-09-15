#include <iostream>

#include <p3d/Include/P3D.h>
#include <resources/Include/Admin.h>
#include <PGSWidget/Include/PGSWidget.h>

#include <QtWidgets/QApplication>
#include <GUI/Include/ApPanels.h>
#include <GUI/Include/JtanPanels.h>

#include <TAM2C/Include/Definitions.h>


#pragma comment(lib, "Ws2_32.lib")

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ApPanels w;
	w.show();

	JtanPanels w2;
	w2.show();

	p3d::P3D::initialize(p3d::P3D::NetworkingMode::ONLY_LOCAL, p3d::P3D::Platform::DIRECTX_11); 
	p3d::P3D* pgs = p3d::P3D::getInstance();
	p3d::SceneDescription* scene_description = pgs->createBasicSceneDescription(Definitions::getMultimediaResourcesPath(), "Terrenos/Topografias/ValleSerrano/ValleSerranoPaso100res100fin_con_heightmap.rpgs", "Skyboxs/Dialight/dialight.rpgs");
	
	p3d::Window* ventana;

	p3d::ResourceManager* resource_manager = pgs->getResourceManager();

	resource_manager->loadResources(scene_description);

	p3d::Resource* resource1 = resource_manager->loadResource(Definitions::getMultimediaResourcesPath("Objetos/Animados/Terrorist/Terrorist.rpgs"));
	resource1->waitTillLoaded();

	p3d::Resource* resource_billboard = resource_manager->loadResource(Definitions::getMultimediaResourcesPath("Videos/Fuego/Fuego01/Fuego_01.rpgs"));
	resource_billboard->waitTillLoaded();

	p3d::Resource* resource_image = resource_manager->loadResource(Definitions::getScreenSpritesPath("GDSU_periscope.rpgs"));
	resource_image->waitTillLoaded();

	p3d::Resource* resource_image2 = resource_manager->loadResource(Definitions::getScreenSpritesPath("LW.rpgs"));
	resource_image2->waitTillLoaded();

	p3d::Context* contexto = pgs->createExecutionContext();

	p3d::Scene3D* escena = contexto->createScene3D();
	p3d::Scene2D* escena2d = contexto->createScene2D();

	escena->installSceneDescription(scene_description);

	double camera_pos_x = 5000.0;
	double camera_pos_y = 5000.0;
	p3d::Camera* camera = escena->installCamera("camaraAP", camera_pos_x, camera_pos_y, 10, 5001, 5001, 10, 0, 0, 1);

	double camera_2_pos_x = 5000.0;
	double camera_2_pos_y = 5010.0;
	p3d::Camera* camera2 = escena->installCamera("camaraJTAN", camera_2_pos_x, camera_2_pos_y, 10, 5005.0, 5006.0, 10, 0, 0, 1);

	p3d::DirectionalLight* directional_light = escena->installDirectionalLight("luz direccional", 0, 1, -1, 255, 255, 255);

	double fuego_pos_x = 5010.0;
	double fuego_pos_y = 5010.0;
	p3d::Billboard* video_fuego = escena->installBillboard("video_fuego", fuego_pos_x, fuego_pos_y, 8, camera_pos_x, camera_pos_x, 8, 0, 0, 1, resource_billboard, false);
	video_fuego->scale(5.0, 5.0, 5.0);

	double animated_obj_pos_x = 5005.0;
	double animated_obj_pos_y = 5006.0;
	p3d::AnimatedObject3D* object_1 = escena->installAnimatedObject("objeto", animated_obj_pos_x, animated_obj_pos_y, 8, animated_obj_pos_x - 1, animated_obj_pos_y - 1, 8, 0, 0, 1, resource1, true, p3d::Object3D::FillMode::SOLID);

	p3d::Sprite* imagen1 =  escena2d->installSprite(860/2, 560/2, 860, 560, resource_image);

	p3d::Sprite* imagen2 = escena2d->installSprite(100/2 + 10, 20/2 + 40, 100, 20, resource_image2);

	p3d::Window* window = pgs->createWindow(w.getPGSWidget()->winId());
	window->showCamera(camera);

	p3d::Window* window2 = pgs->createWindow(w2.getPGSWidget()->winId());
	window2->showCamera(camera2);

	window->showScene2D(escena2d, 860/2, 560/2, 1, 860, 560);

	pgs->initRendering();

	object_1->startAnimation(0, true);
	video_fuego->start();

	return a.exec();
}
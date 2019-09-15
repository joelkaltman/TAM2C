#include <iostream>

#include <QtWidgets/QApplication>
#include <GUI/Include/ApPanels.h>
#include <GUI/Include/JtanPanels.h>

#include <p3d/Include/P3D.h>
#include <resources/Include/Admin.h>

#include <PGSWidget/Include/PGSWidget.h>

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
	p3d::SceneDescription* scene_description = pgs->createBasicSceneDescription("C:/repos/RecursosMultimedia/trunk", "Terrenos/Topografias/ValleSerrano/ValleSerranoPaso100res100fin_con_heightmap.rpgs", "Skyboxs/Dialight/dialight.rpgs");
	
	p3d::Window* ventana;

	p3d::ResourceManager* resource_manager = pgs->getResourceManager();

	resource_manager->loadResources(scene_description);

	p3d::Resource* recurso4 = resource_manager->loadResource("C:/repos/RecursosMultimedia/trunk/Objetos/Animados/Terrorist/Terrorist.rpgs");
	recurso4->waitTillLoaded();

	p3d::Resource* recurso5 = resource_manager->loadResource("C:/repos/RecursosMultimedia/trunk/Objetos/Construcciones/silo/Silo.rpgs");
	recurso5->waitTillLoaded();

	p3d::Resource* recurso_video_fuego = resource_manager->loadResource("C:/repos/RecursosMultimedia/trunk/Videos/Fuego/Fuego01/Fuego_01.rpgs");
	recurso_video_fuego->waitTillLoaded();
	
	p3d::Context* contexto = pgs->createExecutionContext();

	p3d::Scene3D* escena = contexto->createScene3D();

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
	p3d::Billboard* video_fuego = escena->installBillboard("video_fuego", fuego_pos_x, fuego_pos_y, 8, camera_pos_x, camera_pos_x, 8, 0, 0, 1, recurso_video_fuego, false);
	video_fuego->scale(5.0, 5.0, 5.0);

	double animated_obj_pos_x = 5005.0;
	double animated_obj_pos_y = 5006.0;
	p3d::AnimatedObject3D* object_1 = escena->installAnimatedObject("objeto", animated_obj_pos_x, animated_obj_pos_y, 8, animated_obj_pos_x - 1, animated_obj_pos_y - 1, 8, 0, 0, 1, recurso4, true, p3d::Object3D::FillMode::SOLID);

	p3d::Window* window = pgs->createWindow(w.getPGSWidget()->winId());
	window->showCamera(camera);

	p3d::Window* window2 = pgs->createWindow(w2.getPGSWidget()->winId());
	window2->showCamera(camera2);

	pgs->initRendering();

	object_1->startAnimation(0, true);
	video_fuego->start();

	return a.exec();
}
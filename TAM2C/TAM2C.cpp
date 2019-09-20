#include <iostream>

#include <p3d/Include/P3D.h>
#include <resources/Include/Admin.h>
#include <PGSWidget/Include/PGSWidget.h>

#include <QtWidgets/QApplication>
#include <GUI/Include/ApPanels.h>
#include <GUI/Include/JtanPanels.h>

#include <TAM2C/Include/Definitions.h>
#include <TAM2C/Include/Cabin.h>

#include <math/Include/Vector4.h>

// TaskLib
#include <TaskLib/Include/PeriodicTask.h>
#include <TaskLib/Include/TaskManager.h>
#include <TaskLib/Include/StdTaskManager.h>

#include <UtilsLib/Include/Semaphore.h>

// SDL
#include <SDL.h>
#include <SDL_Wrapper/Include/SDLWrapper.h>
#include <SDL_Wrapper/Include/SDLJoystickManager.h>

FILE _iob[] = { *stdin, *stdout, *stderr };
extern "C" FILE * __cdecl __iob_func(void) { return _iob; }

#pragma comment(lib, "Ws2_32.lib")

std::map<std::string, p3d::Resource*> resources;

void loadResources(p3d::ResourceManager* resource_manager)
{
	resources["Terrorist"] = resource_manager->loadResource(Definitions::getMultimediaResourcesPath("Objetos/Animados/Terrorist/Terrorist.rpgs"));

	resources["Fire"] = resource_manager->loadResource(Definitions::getMultimediaResourcesPath("Videos/Fuego/Fuego01/Fuego_01.rpgs"));

	resources["GDSU_periscope"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("GDSU_periscope.rpgs"));
	resources["GDSU_-"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("-.rpgs"));
	resources["GDSU_+"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("+.rpgs"));
	resources["GDSU_2114"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("2114.rpgs"));
	resources["GDSU_5567"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("5567.rpgs"));
	resources["GDSU_AP1_AP2"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("AP1 AP2.rpgs"));
	resources["GDSU_AP1"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("AP1.rpgs"));
	resources["GDSU_ARM"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("ARM.rpgs"));
	resources["GDSU_Btl_Man"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("Btl Man.rpgs"));
	resources["GDSU_DATA"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("DATA.rpgs"));
	resources["GDSU_DayCam"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("DayCam.rpgs"));
	resources["GDSU_empty"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("empty.rpgs"));
	resources["GDSU_FLS_WP"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("FLS WP.rpgs"));
	resources["GDSU_Fst_Last"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("Fst Last.rpgs"));
	resources["GDSU_Gn_Cm_CLR"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("Gn Cm CLR.rpgs"));
	resources["GDSU_Gn_Cm"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("Gn Cm.rpgs"));
	resources["GDSU_GUN"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("GUN.rpgs"));
	resources["GDSU_HE1_HE2"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("HE1 HE2.rpgs"));
	resources["GDSU_HT1_HT2"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("HT1 HT2.rpgs"));
	resources["GDSU_LW"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("LW.rpgs"));
	resources["GDSU_MAN"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("MAN.rpgs"));
	resources["GDSU_MG_SC"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("MG SC.rpgs"));
	resources["GDSU_MSTG"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("MSTG.rpgs"));
	resources["GDSU_N_W_VW"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("N W VW.rpgs"));
	resources["GDSU_NEXT_FLT"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("NEXT FLT.rpgs"));
	resources["GDSU_NextAlt"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("NextAlt.rpgs"));
	resources["GDSU_NightCam"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("NightCam.rpgs"));
	resources["GDSU_RDY"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("RDY.rpgs"));
	resources["GDSU_Zm_Rt_Fc_Ir"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("Zm Rt Fc Ir.rpgs"));

	for (auto& res : resources)
	{
		res.second->waitTillLoaded();
	}
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	p3d::P3D::initialize(p3d::P3D::NetworkingMode::ONLY_LOCAL, p3d::P3D::Platform::DIRECTX_11); 
	p3d::P3D* p3d = p3d::P3D::getInstance();
	p3d::Window* ventana;

	p3d::ResourceManager* resource_manager = p3d->getResourceManager();

	p3d::SceneDescription* scene_description = p3d->createBasicSceneDescription(Definitions::getMultimediaResourcesPath(), "Terrenos/Topografias/ValleSerrano/ValleSerranoPaso100res100fin_con_heightmap.rpgs", "Skyboxs/DiaRosado/DiaRosado.rpgs");
	resource_manager->loadResources(scene_description);

	loadResources(resource_manager);

	p3d::Context* context = p3d->createExecutionContext();

	p3d::Scene3D* scene = context->createScene3D();
	scene->installSceneDescription(scene_description);
	
	p3d::DirectionalLight* directional_light = scene->installDirectionalLight("luz direccional", 0, 1, -1, 255, 255, 255);

	double fuego_pos_x = 5010.0;
	double fuego_pos_y = 5010.0;
	p3d::Billboard* billboard = scene->installBillboard("fire", 5010.0, 5010.0, 8, 5000.0, 5000.0, 8, 0, 0, 1, resources["Fire"], false);
	billboard->scale(5.0, 5.0, 5.0);
	billboard->playLoop();

	double animated_obj_pos_x = 5005.0;
	double animated_obj_pos_y = 5006.0;
	p3d::AnimatedObject3D* object_1 = scene->installAnimatedObject("terrorist", 5005.0, 5006.0, 8, animated_obj_pos_x - 1, animated_obj_pos_y - 1, 8, 0, 0, 1, resources["Terrorist"], true, p3d::Object3D::FillMode::SOLID);

	Cabin* cabin = new Cabin();
	cabin->createCameraAp(scene);
	cabin->createCameraJtan(scene);
	cabin->createGDSUAp(context, resources);
	cabin->createGDSUJtan(context, resources);

	p3d->initRendering();

	object_1->startAnimation(0, true);
	billboard->start();

	return a.exec();
}
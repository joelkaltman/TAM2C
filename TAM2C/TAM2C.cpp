#include <iostream>

#include <p3d/Include/P3D.h>
#include <resources/Include/Admin.h>
#include <PGSWidget/Include/PGSWidget.h>

#include <QtWidgets/QApplication>
#include <GUI/Include/ApPanels.h>
#include <GUI/Include/JtanPanels.h>

#include <TAM2C/Include/Definitions.h>

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

void createGDSUui(p3d::Scene2D* escena2d)
{
	p3d::math::Vector4 screen1(860 / 2, 560 / 2, 860, 560);

	escena2d->installSprite(screen1.getX(), screen1.getY(), screen1.getZ(), screen1.getW(), resources["GDSU_periscope"]);

	p3d::math::Vector4 btn1(100 / 2, 20 / 2, 100, 20);
	p3d::math::Vector4 btn2(80 / 2, 15 / 2, 80, 15);
	p3d::math::Vector4 btn3(60 / 2, 20 / 2, 60, 20);

	escena2d->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 0, btn1.getZ(), btn1.getW(), resources["GDSU_LW"]);
	escena2d->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 1, btn1.getZ(), btn1.getW(), resources["GDSU_AP1_AP2"]);
	escena2d->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 2, btn1.getZ(), btn1.getW(), resources["GDSU_HT1_HT2"]);
	escena2d->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 3, btn1.getZ(), btn1.getW(), resources["GDSU_HE1_HE2"]);
	escena2d->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 4, btn1.getZ(), btn1.getW(), resources["GDSU_MG_SC"]);
	escena2d->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 5, btn1.getZ(), btn1.getW(), resources["GDSU_FLS_WP"]);

	escena2d->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 0, btn1.getZ(), btn1.getW(), resources["GDSU_Gn_Cm_CLR"]);
	escena2d->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ(),		 btn1.getY() + 40 + 90 * 0 + 20, btn2.getZ(), btn2.getW(), resources["GDSU_DayCam"]);
	escena2d->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 1, btn1.getZ(), btn1.getW(), resources["GDSU_Gn_Cm"]);
	escena2d->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ(),		 btn1.getY() + 40 + 90 * 1 + 20, btn2.getZ(), btn2.getW(), resources["GDSU_NightCam"]);
	escena2d->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 2, btn1.getZ(), btn1.getW(), resources["GDSU_N_W_VW"]);
	escena2d->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 3, btn1.getZ(), btn1.getW(), resources["GDSU_Zm_Rt_Fc_Ir"]);
	escena2d->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 4, btn1.getZ(), btn1.getW(), resources["GDSU_+"]);
	escena2d->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 5, btn1.getZ(), btn1.getW(), resources["GDSU_-"]);

	escena2d->installSprite(btn1.getX() + 60 + 80 * 0, btn1.getY() + 10, btn1.getZ(), btn1.getW(), resources["GDSU_2114"]);
	escena2d->installSprite(btn3.getX() + 100 + 80 * 1, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_MAN"]);
	escena2d->installSprite(btn3.getX() + 100 + 80 * 2, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_MSTG"]);
	escena2d->installSprite(btn3.getX() + 100 + 80 * 3, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_RDY"]);
	escena2d->installSprite(btn3.getX() + 100 + 80 * 4, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_ARM"]);
	escena2d->installSprite(btn3.getX() + 100 + 80 * 5, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_empty"]);
	escena2d->installSprite(btn3.getX() + 100 + 80 * 6, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_5567"]);
	escena2d->installSprite(btn3.getX() + 100 + 80 * 7, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_GUN"]);
	escena2d->installSprite(btn3.getX() + 100 + 80 * 8, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_AP1"]);

	escena2d->installSprite(btn1.getX() + 250 + 120 * 0, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_DATA"]);
	escena2d->installSprite(btn1.getX() + 250 + 120 * 1, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_NEXT_FLT"]);
	escena2d->installSprite(btn1.getX() + 250 + 120 * 2, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_Btl_Man"]);
	escena2d->installSprite(btn1.getX() + 250 + 120 * 3, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_Fst_Last"]);
	escena2d->installSprite(btn1.getX() + 250 + 120 * 4, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_NextAlt"]);
}

bool AbrirJoysticks()
{
	std::cout << "Joystick Task is running" << std::endl;
	//Init Joystick

	SDLWrapper* sdl_wrapper = SDLWrapper::getInstance();


	sdl_wrapper->initJoysticksManagers(1);

	SDLJoystickManager* joystickManager = sdl_wrapper->getJoystickManager(0);

	std::cout << "todo bien con el joystick del jtan y del ap" << std::endl;

	return true;
}

void HandleJoysticksEvent(SDL_Event &joystick_event)
{
	//determino que joystick cambió
	if (joystick_event.type == SDL_JOYAXISMOTION)
	{
		std::cout << "AXIS" << std::endl;
	}
	else if ((joystick_event.type == SDL_JOYBUTTONDOWN) || (joystick_event.type == SDL_JOYBUTTONUP) || (joystick_event.type == SDL_JOYHATMOTION))
	{
		std::cout << "BUTTON" << std::endl;
	}
}

static void joystick_listener_function(const double_t& delta_time, void* instance)
{
	SDLWrapper* sdl_wrapper = SDLWrapper::getInstance();
	SDL_Event joystick_event;

	while (sdl_wrapper->pollSDLEvent(&joystick_event))
		// Polls for currently pending events, and returns 1 if there are any pending events, or 0 if there are none available. https://www.libsdl.org/release/SDL-1.2.15/docs/html/sdlpollevent.html
	{
		HandleJoysticksEvent(joystick_event);
		//		printCambiosJoystick(estado_anterior,estado_nuevo,p_param->p_canal);
		//		estado_anterior = estado_nuevo;
	}
}

task::PeriodicTask* joystick_listener;
utils::Semaphore* end_sem_joystick_listener_task;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	AbrirJoysticks();
	
	task::TaskManager::initialize(new task::StdTaskManager());
	task::TaskManager* task_man = task::TaskManager::getInstance();
	end_sem_joystick_listener_task = new utils::Semaphore();
	joystick_listener = task_man->createPeriodicTask(100, joystick_listener_function, nullptr);
	joystick_listener->start();

	return a.exec();
	// ================
	ApPanels uiAP;
	uiAP.show();

	JtanPanels uiJTAN;
	uiJTAN.show();

	p3d::P3D::initialize(p3d::P3D::NetworkingMode::ONLY_LOCAL, p3d::P3D::Platform::DIRECTX_11); 
	p3d::P3D* p3d = p3d::P3D::getInstance();
	p3d::Window* ventana;

	p3d::ResourceManager* resource_manager = p3d->getResourceManager();

	p3d::SceneDescription* scene_description = p3d->createBasicSceneDescription(Definitions::getMultimediaResourcesPath(), "Terrenos/Topografias/ValleSerrano/ValleSerranoPaso100res100fin_con_heightmap.rpgs", "Skyboxs/DiaRosado/DiaRosado.rpgs");
	resource_manager->loadResources(scene_description);

	loadResources(resource_manager);

	p3d::Context* contexto = p3d->createExecutionContext();

	p3d::Scene3D* scene = contexto->createScene3D();
	p3d::Scene2D* scene2dAP = contexto->createScene2D();
	p3d::Scene2D* scene2dJTAN = contexto->createScene2D();

	scene->installSceneDescription(scene_description);

	double camera_pos_x = 5000.0;
	double camera_pos_y = 5000.0;
	p3d::Camera* camera = scene->installCamera("cameraAP", 5000.0, 5000.0, 10, 5001, 5001, 10, 0, 0, 1);

	double camera_2_pos_x = 5000.0;
	double camera_2_pos_y = 5010.0;
	p3d::Camera* camera2 = scene->installCamera("cameraJTAN", 5000.0, 5010.0, 10, 5005.0, 5006.0, 10, 0, 0, 1);

	p3d::DirectionalLight* directional_light = scene->installDirectionalLight("luz direccional", 0, 1, -1, 255, 255, 255);

	double fuego_pos_x = 5010.0;
	double fuego_pos_y = 5010.0;
	p3d::Billboard* billboard = scene->installBillboard("fire", 5010.0, 5010.0, 8, camera_pos_x, camera_pos_x, 8, 0, 0, 1, resources["Fire"], false);
	billboard->scale(5.0, 5.0, 5.0);
	billboard->playLoop();

	double animated_obj_pos_x = 5005.0;
	double animated_obj_pos_y = 5006.0;
	p3d::AnimatedObject3D* object_1 = scene->installAnimatedObject("terrorist", 5005.0, 5006.0, 8, animated_obj_pos_x - 1, animated_obj_pos_y - 1, 8, 0, 0, 1, resources["Terrorist"], true, p3d::Object3D::FillMode::SOLID);

	createGDSUui(scene2dAP);
	createGDSUui(scene2dJTAN);

	p3d::Window* windowAP = p3d->createWindow(uiAP.getPGSWidget()->winId());
	windowAP->showCamera(camera);

	p3d::Window* windowJTAN = p3d->createWindow(uiJTAN.getPGSWidget()->winId());
	windowJTAN->showCamera(camera2);

	windowAP->showScene2D(scene2dAP, 860 / 2, 560 / 2, 1, 860, 560);
	windowJTAN->showScene2D(scene2dJTAN, 850 / 2, 560 / 2, 1, 850, 560);

	p3d->initRendering();

	object_1->startAnimation(0, true);
	billboard->start();

	return a.exec();
}
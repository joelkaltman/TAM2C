#include <TAM2C/Include/Cabin.h>

// TaskLib
#include <TaskLib/Include/TaskManager.h>
#include <TaskLib/Include/StdTaskManager.h>

// SDL
#include <SDL_Wrapper/Include/SDLWrapper.h>
#include <SDL_Wrapper/Include/SDLJoystickManager.h>

// p3d
#include <p3d/Include/P3D.h>
#include <p3d/Include/Scene3d.h>
#include <p3d/Include/Scene2D.h>
#include <p3d/Include/Camera.h>
#include <p3d/Include/Window.h>
#include <p3d/Include/Resource.h>
#include <p3d/Include/Context.h>

#define ZONA_MUERTA 4000.0
#define MAX 32767.0

Cabin::Cabin()
{
	openJoysticks();

	task::TaskManager* task_man = task::TaskManager::getInstance();
	end_sem_joystick_listener_task = new utils::Semaphore();
	joystick_listener = task_man->createPeriodicTask(100, joystickListenerFunction, this);
	joystick_listener->start();
}

bool Cabin::openJoysticks()
{
	SDLWrapper* sdl_wrapper = SDLWrapper::getInstance();

	sdl_wrapper->initJoysticksManagers(1);

	SDLJoystickManager* joystickManager = sdl_wrapper->getJoystickManager(0);

	return true;
}

void Cabin::joystickListenerFunction(const double_t& delta_time, void* instance)
{
	SDLWrapper* sdl_wrapper = SDLWrapper::getInstance();
	SDL_Event joystick_event;

	while (sdl_wrapper->pollSDLEvent(&joystick_event))
	{
		Cabin* c = (Cabin*)instance;
		c->handleJoysticksEvent(joystick_event);
	}
}

double normalizarPosicionEje(Sint16 valor_eje)
{
	double valor_normalizado = 0.0;

	if ((valor_eje > -ZONA_MUERTA) && (valor_eje < ZONA_MUERTA))
	{
		valor_normalizado = 0.0;
	}
	else
	{
		valor_normalizado = (abs(valor_eje) - ZONA_MUERTA) / (MAX - ZONA_MUERTA);
		if (valor_eje < 0)
		{
			valor_normalizado *= -1;
		}
	}

	return valor_normalizado;
}

void Cabin::handleJoysticksEvent(SDL_Event &joystick_event)
{
	if (joystick_event.type == SDL_JOYAXISMOTION)
	{
		float deriva = 0;
		float alza = 0;
		if (((EJE_X > 0) ? EJE_X - 1 : (EJE_X*-1) - 1) == joystick_event.jaxis.axis)
		{
			deriva = normalizarPosicionEje(joystick_event.jaxis.value)*((EJE_X < 0) ? -1 : 1);
		}
		else if (((EJE_Y > 0) ? EJE_Y - 1 : (EJE_Y*-1) - 1) == joystick_event.jaxis.axis)
		{
			alza = normalizarPosicionEje(joystick_event.jaxis.value)*((EJE_Y < 0) ? -1 : 1);
		}

		camera_ap->rotate(deriva, 0, 0, 1);

		double x, y, z, atx, aty, atz, upx, upy, upz;
		camera_ap->getPose(&x, &y, &z, &atx, &aty, &atz, &upx, &upy, &upz);

		p3d::math::Vector3 res = p3d::math::Vector3::cross(p3d::math::Vector3(atx - x, aty - y, 0), p3d::math::Vector3(0, 0, 1));

		camera_ap->rotate(alza, res.getX(), res.getY(), 0);

		//std::cout << "AXIS d="<<d<<" a="<<a<< std::endl;
	}
	else if ((joystick_event.type == SDL_JOYBUTTONDOWN) || (joystick_event.type == SDL_JOYBUTTONUP) || (joystick_event.type == SDL_JOYHATMOTION))
	{
		//std::cout << "BUTTON" << std::endl;
	}
}

p3d::Camera* Cabin::getCameraAp()
{
	return this->camera_ap;
}

p3d::Camera* Cabin::getCameraJtan()
{
	return this->camera_jtan;
}

void Cabin::createCameraAp(p3d::Scene3D* scene)
{
	double camera_pos_x = 5000.0;
	double camera_pos_y = 5000.0;
	camera_ap = scene->installCamera("cameraAP", 5000.0, 5000.0, 10, 5001, 5001, 10, 0, 0, 1);

	uiAp.show();

	p3d::P3D* p3d = p3d::P3D::getInstance();
	win_ap = p3d->createWindow(uiAp.getPGSWidget()->winId());
	win_ap->showCamera(camera_ap);
}

void Cabin::createCameraJtan(p3d::Scene3D* scene)
{
	double camera_2_pos_x = 5000.0;
	double camera_2_pos_y = 5010.0;
	camera_jtan = scene->installCamera("cameraJTAN", 5000.0, 5010.0, 10, 5005.0, 5006.0, 10, 0, 0, 1);

	uiJtan.show();

	p3d::P3D* p3d = p3d::P3D::getInstance();
	win_jtan = p3d->createWindow(uiJtan.getPGSWidget()->winId());
	win_jtan->showCamera(camera_jtan);
}

void Cabin::createGDSUAp(p3d::Context* context, std::map<std::string, p3d::Resource*> resources)
{
	p3d::Scene2D* scene = context->createScene2D();

	p3d::math::Vector4 screen1(860 / 2, 560 / 2, 860, 560);

	scene->installSprite(screen1.getX(), screen1.getY(), screen1.getZ(), screen1.getW(), resources["GDSU_periscope"]);

	p3d::math::Vector4 btn1(100 / 2, 20 / 2, 100, 20);
	p3d::math::Vector4 btn2(80 / 2, 15 / 2, 80, 15);
	p3d::math::Vector4 btn3(60 / 2, 20 / 2, 60, 20);

	scene->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 0, btn1.getZ(), btn1.getW(), resources["GDSU_LW"]);
	scene->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 1, btn1.getZ(), btn1.getW(), resources["GDSU_AP1_AP2"]);
	scene->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 2, btn1.getZ(), btn1.getW(), resources["GDSU_HT1_HT2"]);
	scene->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 3, btn1.getZ(), btn1.getW(), resources["GDSU_HE1_HE2"]);
	scene->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 4, btn1.getZ(), btn1.getW(), resources["GDSU_MG_SC"]);
	scene->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 5, btn1.getZ(), btn1.getW(), resources["GDSU_FLS_WP"]);

	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 0, btn1.getZ(), btn1.getW(), resources["GDSU_Gn_Cm_CLR"]);
	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ(), btn1.getY() + 40 + 90 * 0 + 20, btn2.getZ(), btn2.getW(), resources["GDSU_DayCam"]);
	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 1, btn1.getZ(), btn1.getW(), resources["GDSU_Gn_Cm"]);
	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ(), btn1.getY() + 40 + 90 * 1 + 20, btn2.getZ(), btn2.getW(), resources["GDSU_NightCam"]);
	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 2, btn1.getZ(), btn1.getW(), resources["GDSU_N_W_VW"]);
	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 3, btn1.getZ(), btn1.getW(), resources["GDSU_Zm_Rt_Fc_Ir"]);
	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 4, btn1.getZ(), btn1.getW(), resources["GDSU_+"]);
	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 5, btn1.getZ(), btn1.getW(), resources["GDSU_-"]);

	scene->installSprite(btn1.getX() + 60 + 80 * 0, btn1.getY() + 10, btn1.getZ(), btn1.getW(), resources["GDSU_2114"]);
	scene->installSprite(btn3.getX() + 100 + 80 * 1, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_MAN"]);
	scene->installSprite(btn3.getX() + 100 + 80 * 2, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_MSTG"]);
	scene->installSprite(btn3.getX() + 100 + 80 * 3, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_RDY"]);
	scene->installSprite(btn3.getX() + 100 + 80 * 4, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_ARM"]);
	scene->installSprite(btn3.getX() + 100 + 80 * 5, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_empty"]);
	scene->installSprite(btn3.getX() + 100 + 80 * 6, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_5567"]);
	scene->installSprite(btn3.getX() + 100 + 80 * 7, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_GUN"]);
	scene->installSprite(btn3.getX() + 100 + 80 * 8, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_AP1"]);

	scene->installSprite(btn1.getX() + 250 + 120 * 0, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_DATA"]);
	scene->installSprite(btn1.getX() + 250 + 120 * 1, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_NEXT_FLT"]);
	scene->installSprite(btn1.getX() + 250 + 120 * 2, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_Btl_Man"]);
	scene->installSprite(btn1.getX() + 250 + 120 * 3, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_Fst_Last"]);
	scene->installSprite(btn1.getX() + 250 + 120 * 4, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_NextAlt"]);

	win_ap->showScene2D(scene, 860 / 2, 560 / 2, 1, 860, 560);
}

void Cabin::createGDSUJtan(p3d::Context* context, std::map<std::string, p3d::Resource*> resources)
{
	p3d::Scene2D* scene = context->createScene2D();

	p3d::math::Vector4 screen1(860 / 2, 560 / 2, 860, 560);

	scene->installSprite(screen1.getX(), screen1.getY(), screen1.getZ(), screen1.getW(), resources["GDSU_periscope"]);

	p3d::math::Vector4 btn1(100 / 2, 20 / 2, 100, 20);
	p3d::math::Vector4 btn2(80 / 2, 15 / 2, 80, 15);
	p3d::math::Vector4 btn3(60 / 2, 20 / 2, 60, 20);

	scene->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 0, btn1.getZ(), btn1.getW(), resources["GDSU_LW"]);
	scene->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 1, btn1.getZ(), btn1.getW(), resources["GDSU_AP1_AP2"]);
	scene->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 2, btn1.getZ(), btn1.getW(), resources["GDSU_HT1_HT2"]);
	scene->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 3, btn1.getZ(), btn1.getW(), resources["GDSU_HE1_HE2"]);
	scene->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 4, btn1.getZ(), btn1.getW(), resources["GDSU_MG_SC"]);
	scene->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 5, btn1.getZ(), btn1.getW(), resources["GDSU_FLS_WP"]);

	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 0, btn1.getZ(), btn1.getW(), resources["GDSU_Gn_Cm_CLR"]);
	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ(), btn1.getY() + 40 + 90 * 0 + 20, btn2.getZ(), btn2.getW(), resources["GDSU_DayCam"]);
	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 1, btn1.getZ(), btn1.getW(), resources["GDSU_Gn_Cm"]);
	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ(), btn1.getY() + 40 + 90 * 1 + 20, btn2.getZ(), btn2.getW(), resources["GDSU_NightCam"]);
	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 2, btn1.getZ(), btn1.getW(), resources["GDSU_N_W_VW"]);
	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 3, btn1.getZ(), btn1.getW(), resources["GDSU_Zm_Rt_Fc_Ir"]);
	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 4, btn1.getZ(), btn1.getW(), resources["GDSU_+"]);
	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 5, btn1.getZ(), btn1.getW(), resources["GDSU_-"]);

	scene->installSprite(btn1.getX() + 60 + 80 * 0, btn1.getY() + 10, btn1.getZ(), btn1.getW(), resources["GDSU_2114"]);
	scene->installSprite(btn3.getX() + 100 + 80 * 1, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_MAN"]);
	scene->installSprite(btn3.getX() + 100 + 80 * 2, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_MSTG"]);
	scene->installSprite(btn3.getX() + 100 + 80 * 3, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_RDY"]);
	scene->installSprite(btn3.getX() + 100 + 80 * 4, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_ARM"]);
	scene->installSprite(btn3.getX() + 100 + 80 * 5, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_empty"]);
	scene->installSprite(btn3.getX() + 100 + 80 * 6, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_5567"]);
	scene->installSprite(btn3.getX() + 100 + 80 * 7, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_GUN"]);
	scene->installSprite(btn3.getX() + 100 + 80 * 8, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_AP1"]);

	scene->installSprite(btn1.getX() + 250 + 120 * 0, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_DATA"]);
	scene->installSprite(btn1.getX() + 250 + 120 * 1, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_NEXT_FLT"]);
	scene->installSprite(btn1.getX() + 250 + 120 * 2, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_Btl_Man"]);
	scene->installSprite(btn1.getX() + 250 + 120 * 3, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_Fst_Last"]);
	scene->installSprite(btn1.getX() + 250 + 120 * 4, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_NextAlt"]);

	win_jtan->showScene2D(scene, 860 / 2, 560 / 2, 1, 860, 560);
}
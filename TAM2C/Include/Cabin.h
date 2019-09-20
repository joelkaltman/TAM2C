#pragma once

// UtilsLib
#include <UtilsLib/Include/Semaphore.h>

// TaskLib
#include <TaskLib/Include/PeriodicTask.h>

// SDL
#include <SDL.h>

// GUI
#include <GUI/Include/ApPanels.h>
#include <GUI/Include/JtanPanels.h>

namespace p3d
{
	class Scene3D;
	class Scene2D;
	class Camera;
	class Window;
	class Context;
	class Resource;
}

class Cabin
{
public:
	enum JoystickAxis
	{
		EJE_X = 1,
		EJE_Y = 2,
		EJE_Z = 3,
		ROTACION_Z = 4
	};

	Cabin();

	void createCameraAp(p3d::Scene3D* scene);
	void createCameraJtan(p3d::Scene3D* scene);

	void createGDSUAp(p3d::Context* context, std::map<std::string, p3d::Resource*> resources);
	void createGDSUJtan(p3d::Context* context, std::map<std::string, p3d::Resource*> resources);

	p3d::Camera* getCameraAp();
	p3d::Camera* getCameraJtan();

private:
	bool openJoysticks();
	void handleJoysticksEvent(SDL_Event &joystick_event);
	static void joystickListenerFunction(const double_t& delta_time, void* instance);

	task::PeriodicTask* joystick_listener;
	utils::Semaphore* end_sem_joystick_listener_task;

	p3d::Camera* camera_ap;
	p3d::Camera* camera_jtan;

	ApPanels uiAp;
	JtanPanels uiJtan;

	p3d::Window* win_ap;
	p3d::Window* win_jtan;
};
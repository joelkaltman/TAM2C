#pragma once

// UtilsLib
#include <UtilsLib/Include/Semaphore.h>

// TaskLib
#include <TaskLib/Include/PeriodicTask.h>

// SDL
#include <SDL.h>

class Cabin;

class JoysticksManager
{
public:
	enum JoystickAxis
	{
		EJE_X = 1,
		EJE_Y = 2,
		EJE_Z = 3,
		ROTACION_Z = 4
	};

	JoysticksManager(Cabin* cabin);
	~JoysticksManager();

private:
	bool openJoysticks();
	void handleJoysticksEvent(SDL_Event &joystick_event);
	static void joystickListenerFunction(const double_t& delta_time, void* instance);

	task::PeriodicTask* joystick_listener;

	Cabin* cabin;
};
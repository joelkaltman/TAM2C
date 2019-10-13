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
		AXIS_X = 1,
		AXIS_Y = 2,
		AXIS_Z = 3,
		ROT_Z = 4
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
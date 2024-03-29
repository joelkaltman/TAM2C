#include <TAM2C/Include/JoysticksManager.h>

// TaskLib
#include <TaskLib/Include/TaskManager.h>
#include <TaskLib/Include/StdTaskManager.h>

// SDL
#include <SDL_Wrapper/Include/SDLWrapper.h>
#include <SDL_Wrapper/Include/SDLJoystickManager.h>
#include <SDL_Wrapper/Include/MissingJoysticksException.h>

// TAM2C
#include <TAM2C/Include/Cabin.h>

#define DEAD_ZONE 4000.0
#define MAX 32767.0

JoysticksManager::~JoysticksManager()
{
	joystick_listener->stop();
}

void JoysticksManager::init(Cabin* cabin)
{
	this->cabin = cabin;

	task::TaskManager* task_man = task::TaskManager::getInstance();
	joystick_listener = task_man->createPeriodicTask(100, joystickListenerFunction, this);
	joystick_listener->start();
}

bool JoysticksManager::openJoysticks()
{
	SDLWrapper* sdl_wrapper = SDLWrapper::getInstance();

	try
	{
		sdl_wrapper->initJoysticksManagers(2);
	}
	catch (MissingJoysticksException* e)
	{
		std::cout << "2 joysticks are needed to run the simulation." << std::endl;
		return false;
	}

	SDLJoystickManager* joystickManager = sdl_wrapper->getJoystickManager(0);

	return true;
}

void JoysticksManager::joystickListenerFunction(const double_t& delta_time, void* instance)
{
	SDLWrapper* sdl_wrapper = SDLWrapper::getInstance();
	SDL_Event joystick_event;

	while (sdl_wrapper->pollSDLEvent(&joystick_event))
	{
		JoysticksManager* jmg = (JoysticksManager*)instance;
		jmg->handleJoysticksEvent(joystick_event);
	}
}

double normalizeAxisPos(Sint16 axisVal)
{
	double normalVal = 0.0;

	if ((axisVal > -DEAD_ZONE) && (axisVal < DEAD_ZONE))
	{
		normalVal = 0.0;
	}
	else
	{
		normalVal = (abs(axisVal) - DEAD_ZONE) / (MAX - DEAD_ZONE);
		if (axisVal < 0)
		{
			normalVal *= -1;
		}
	}

	return normalVal;
}

void JoysticksManager::handleJoysticksEvent(SDL_Event &joystick_event)
{
	if (joystick_event.type == SDL_JOYAXISMOTION)
	{
		float drift = 0;
		float rise = 0;
		if (((AXIS_X > 0) ? AXIS_X - 1 : (AXIS_X*-1) - 1) == joystick_event.jaxis.axis)
		{
			drift = normalizeAxisPos(joystick_event.jaxis.value)*((AXIS_X < 0) ? -1 : 1);
		}
		else if (((AXIS_Y > 0) ? AXIS_Y - 1 : (AXIS_Y*-1) - 1) == joystick_event.jaxis.axis)
		{
			rise = normalizeAxisPos(joystick_event.jaxis.value)*((AXIS_Y < 0) ? -1 : 1);
		}

		//std::cout << "AXIS d="<<d<<" a="<<a<< std::endl;
		cabin->axisModified(joystick_event.jaxis.which, drift, rise);
	}
	else if ((joystick_event.type == SDL_JOYBUTTONDOWN) || (joystick_event.type == SDL_JOYBUTTONUP) || (joystick_event.type == SDL_JOYHATMOTION))
	{
		//std::cout << "BUTTON" << std::endl;
	}
}

#include <TAM2C/Include/JoysticksManager.h>

// TaskLib
#include <TaskLib/Include/TaskManager.h>
#include <TaskLib/Include/StdTaskManager.h>

// SDL
#include <SDL_Wrapper/Include/SDLWrapper.h>
#include <SDL_Wrapper/Include/SDLJoystickManager.h>

// TAM2C
#include <TAM2C/Include/Cabin.h>

#define ZONA_MUERTA 4000.0
#define MAX 32767.0

JoysticksManager::JoysticksManager(Cabin* cabin) : cabin(cabin)
{
	openJoysticks();

	task::TaskManager* task_man = task::TaskManager::getInstance();
	joystick_listener = task_man->createPeriodicTask(100, joystickListenerFunction, this);
	joystick_listener->start();
}

JoysticksManager::~JoysticksManager()
{
	joystick_listener->stop();
}

bool JoysticksManager::openJoysticks()
{
	SDLWrapper* sdl_wrapper = SDLWrapper::getInstance();

	sdl_wrapper->initJoysticksManagers(2);

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

void JoysticksManager::handleJoysticksEvent(SDL_Event &joystick_event)
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

		//std::cout << "AXIS d="<<d<<" a="<<a<< std::endl;
		cabin->axisModified(joystick_event.jaxis.which, deriva, alza);
	}
	else if ((joystick_event.type == SDL_JOYBUTTONDOWN) || (joystick_event.type == SDL_JOYBUTTONUP) || (joystick_event.type == SDL_JOYHATMOTION))
	{
		//std::cout << "BUTTON" << std::endl;
	}
}

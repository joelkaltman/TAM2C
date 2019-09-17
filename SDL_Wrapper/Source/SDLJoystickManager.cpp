#include <SDL_Wrapper/Include/SDLJoystickManager.h>

#include <SDL_Wrapper/Include/MissingJoysticksException.h>

//STL
#include <iostream>

SDLJoystickManager::SDLJoystickManager(unsigned int id)
{
	this->joystick = SDL_JoystickOpen(id);
	this->id = id;
	if (!this->joystick)
	{
        MissingJoysticksException* missing_joysticks_exception = new MissingJoysticksException("Ocurrio un error creando un joystick manager");
        missing_joysticks_exception->setJoystickId(id);
	    throw missing_joysticks_exception;
	}
	else
	{
		std::cout<<"El joystick "<<id<<std::endl;
	}

}


SDLJoystickManager::~SDLJoystickManager(void)
{
	SDL_JoystickClose(joystick);
}

int SDLJoystickManager::getAxis(int axis_number)
{
    SDL_JoystickUpdate();
    return SDL_JoystickGetAxis(this->joystick, axis_number);
}

unsigned int SDLJoystickManager::getButton(int button_number)
{
	SDL_JoystickUpdate();
    return SDL_JoystickGetButton(this->joystick, button_number);
}

unsigned int SDLJoystickManager::getHat(int hat)
{
	SDL_JoystickUpdate();
    return SDL_JoystickGetHat(this->joystick, hat);
}

unsigned int SDLJoystickManager::getJoystickIndex()
{
    return this->id;
}

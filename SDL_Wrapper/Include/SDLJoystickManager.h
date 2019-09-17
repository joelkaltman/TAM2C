#pragma once

// SDL
#include <SDL_joystick.h>

class SDLJoystickManager
{
	
	friend class SDLWrapper;

	SDL_Joystick* joystick;
	unsigned int id;
	
	SDLJoystickManager(unsigned int id);
	virtual ~SDLJoystickManager(void);

public:
	int getAxis( int axis_number);
	unsigned int getButton( int button_number);
    unsigned int getHat(int hat);
	unsigned int getJoystickIndex();

};


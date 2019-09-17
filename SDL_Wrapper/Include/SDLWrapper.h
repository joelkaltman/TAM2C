#pragma once

// STL
#include <map>

// SDL
#include <SDL.h>
#include <SDL_Wrapper/Include/SDLAudioChannelManager.h>
#include <SDL_Wrapper/Include/SDLJoystickManager.h>

class SDLWrapper
{
	static SDLWrapper* instance;
	std::map<unsigned int , SDLAudioChannelManager*> audio_channel_managers;
	std::map<unsigned int , SDLJoystickManager*> joystick_managers;

	SDLWrapper(void);
	virtual ~SDLWrapper(void);

public:
	static SDLWrapper* getInstance();
	static void release();

	void initAudioChannlesManagers(unsigned int channels_count);
	void initJoysticksManagers(unsigned int joysticks_count);

	SDLAudioChannelManager* getAudioChannelManager(unsigned int id);
	SDLJoystickManager* getJoystickManager(unsigned int id);

	void releaseJoystickManager(SDLJoystickManager* joystick_manager);
	void releaseAudioChannelManager(SDLAudioChannelManager* audio_channel_manager);

    bool minimumNumberOfJoysticksConnected();
    bool speakersConnected();

	int pollSDLEvent(SDL_Event* sdl_event);
	
};

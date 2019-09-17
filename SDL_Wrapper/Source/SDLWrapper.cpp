#include <SDL_Wrapper/Include/SDLWrapper.h>

#include <SDL_Wrapper/Include/MissingAudioException.h>
#include <SDL_Wrapper/Include/MissingJoysticksException.h>
#include <SDL_Wrapper/Include/SDLInitException.h>

// STL
#include <iostream>

// SDL
#include <SDL.h>

SDLWrapper* SDLWrapper::instance = 0;

SDLWrapper::SDLWrapper(void)
{
    // Event handling is initalised (along with video) with a call to: SDL_Init(SDL_INIT_VIDEO); https://www.libsdl.org/release/SDL-1.2.15/docs/html/event.html
    if (SDL_Init(SDL_INIT_AUDIO|SDL_INIT_JOYSTICK|SDL_INIT_VIDEO) == -1)
    {
        throw new SDLInitException("Falla en SDL_Init");
    }
        
    SDL_JoystickEventState(SDL_ENABLE);
}

SDLWrapper::~SDLWrapper(void)
{
	std::map<unsigned int, SDLAudioChannelManager*>::iterator it_audio = audio_channel_managers.begin();
	while( it_audio != audio_channel_managers.end() )
	{
		delete it_audio->second;
		it_audio++;
	}
	audio_channel_managers.clear();

	std::map<unsigned int, SDLJoystickManager*>::iterator it_stick = joystick_managers.begin();
	while( it_stick != joystick_managers.end() )
	{
		delete it_stick->second;
		it_stick++;
	}
	joystick_managers.clear();
	
    SDL_Quit();
}

SDLWrapper* SDLWrapper::getInstance()
{
	if( instance == 0)
		instance = new SDLWrapper();
	return instance;
}

void SDLWrapper::release()
{
	if(instance != NULL)
	{
		delete instance;
		instance = NULL;
	}
}

void SDLWrapper::initAudioChannlesManagers(unsigned int count)
{
	if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2/*stereo*/, 4096 ) == -1 )
    {
        throw new MissingAudioException("Falla en Mix_OpenAudio");
    }
	Mix_AllocateChannels(count);
	for( unsigned int id = 0; id < count ; id++ )
	{
		SDLAudioChannelManager* audio_man = new SDLAudioChannelManager(id);
		audio_channel_managers.insert(std::pair<unsigned int , SDLAudioChannelManager*>(id, audio_man));
	}

}

void SDLWrapper::initJoysticksManagers(unsigned int count)
{
    int sdl_joystick_count = SDL_NumJoysticks();
	if (sdl_joystick_count != count)
	{
        MissingJoysticksException* missing_joystick_exception = new MissingJoysticksException("No hay la cantidad solicitada de joysticks");
        missing_joystick_exception->setJoystickCount(sdl_joystick_count);
		throw missing_joystick_exception;
	}

	for( unsigned int id = 0; id < count ; id++ )
	{
		SDLJoystickManager* joystick_man = new SDLJoystickManager(id);
		joystick_managers.insert(std::pair<unsigned int , SDLJoystickManager*>(id, joystick_man));
	}
	
}

SDLAudioChannelManager* SDLWrapper::getAudioChannelManager(unsigned int id)
{
	std::map<unsigned int, SDLAudioChannelManager*>::iterator it = audio_channel_managers.find(id);
	if( it != audio_channel_managers.end() )
	{
		return it->second;
	}
    MissingAudioException* missing_audio_exception = new MissingAudioException("Ocurrio un error obteniendo el manager del canal de audio");
    missing_audio_exception->setAudioChannelId(id);
    throw missing_audio_exception;
}

SDLJoystickManager* SDLWrapper::getJoystickManager(unsigned int id)
{
	std::map<unsigned int, SDLJoystickManager*>::iterator it = joystick_managers.find(id);
	if( it != joystick_managers.end() )
	{
		return it->second;
	}
    MissingJoysticksException* missing_joysticks_exception = new MissingJoysticksException("Ocurrio un error obteniendo un joystick manager");
    missing_joysticks_exception->setJoystickId(id);
	throw missing_joysticks_exception;
}

void SDLWrapper::releaseJoystickManager(SDLJoystickManager* joystick_man)
{
	std::map<unsigned int, SDLJoystickManager*>::iterator it = joystick_managers.find(joystick_man->id);
	if( it != joystick_managers.end() )
	{
		delete it->second;
		joystick_managers.erase(it);
	}
	else
	{
        MissingJoysticksException* missing_joysticks_exception = new MissingJoysticksException("Ocurrio un error liberando un joystick manager");
        //missing_joysticks_exception->setJoystickId(joystick_man->id);
		throw missing_joysticks_exception;
	}
}

void SDLWrapper::releaseAudioChannelManager(SDLAudioChannelManager* audio_channel_man)
{
	std::map<unsigned int, SDLAudioChannelManager*>::iterator it = audio_channel_managers.find(audio_channel_man->id);
	if( it != audio_channel_managers.end() )
	{
		delete it->second;
		audio_channel_managers.erase(it);
	}
	else
	{
        MissingAudioException* missing_audio_exception = new MissingAudioException("Ocurrio un error liberando manager del canal de audio");
        //missing_audio_exception->setAudioChannelId(audio_channel_man->id);
        throw missing_audio_exception;
	}
}

int SDLWrapper::pollSDLEvent(SDL_Event* sdl_event)
{
	return SDL_PollEvent(sdl_event);
}

bool SDLWrapper::minimumNumberOfJoysticksConnected()
{
    return (3 <= SDL_NumJoysticks());
}

bool SDLWrapper::speakersConnected()
{
    return true;
}

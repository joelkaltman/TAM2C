#include <SDL_Wrapper/Include/SDLAudioChannelManager.h>

#include <SDL_Wrapper/Include/MissingAudioException.h>

// STL
#include <iostream>
#include <Windows.h>

SDLAudioChannelManager::SDLAudioChannelManager(unsigned int id)
{
	this->id = id;
	this->scratch_mix_chunk = NULL;
}


SDLAudioChannelManager::~SDLAudioChannelManager(void)
{
	if( this->scratch_mix_chunk != NULL)
	{
		Mix_FreeChunk(this->scratch_mix_chunk);
	}
}

void SDLAudioChannelManager::playSound(std::string sound_file_path)
{
    // Si el audio a reproducir es voz de mando (id = 0), me fijo si no habia reproduciendo algo
    // si lo habia, espero que termine antes de empezar con el nuevo, asi no lo interrumpe
    while(this->id == 0 && Mix_Playing(this->id) )
    {
        Sleep(1000);
    }

	if( this->scratch_mix_chunk != NULL)
	{
		Mix_FreeChunk(this->scratch_mix_chunk);
	}

	this->scratch_mix_chunk = Mix_LoadWAV(sound_file_path.c_str());

	if ( this->scratch_mix_chunk == NULL )
	{
        MissingAudioException* missing_audio_exception = new MissingAudioException("EjecutarOrdenTiro - no pudo cargar el archivo de sonido " + sound_file_path);
        throw missing_audio_exception;
		/// \todo decidir qué hacer acá
	}
    
	Mix_PlayChannel( this->id, this->scratch_mix_chunk, 0 );
}

void SDLAudioChannelManager::playSoundLoop(std::string sound_file_path)
{
	if( this->scratch_mix_chunk != NULL)
	{
		Mix_FreeChunk(this->scratch_mix_chunk);
	}

	this->scratch_mix_chunk = Mix_LoadWAV(sound_file_path.c_str());

	if ( this->scratch_mix_chunk == NULL )
	{
        MissingAudioException* missing_audio_exception = new MissingAudioException("EjecutarOrdenTiro - no pudo cargar el archivo de sonido " + sound_file_path);
        throw missing_audio_exception;
		/// \todo decidir qué hacer acá
	}

	Mix_PlayChannel( this->id, this->scratch_mix_chunk, -1 );
}

void SDLAudioChannelManager::stop()
{
	Mix_HaltChannel( this->id );
}


#pragma once

// STL
#include <string>

// SDL
#include <SDL_Mixer.h>

class SDLAudioChannelManager
{
	friend class SDLWrapper;
	unsigned int id;

	Mix_Chunk* scratch_mix_chunk;

	SDLAudioChannelManager(unsigned int id);
	virtual ~SDLAudioChannelManager(void);

public:
	void playSound(std::string sound_file_path);
	void playSoundLoop(std::string sound_file_path);
	void stop();

};


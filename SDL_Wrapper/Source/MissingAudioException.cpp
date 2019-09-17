#include <SDL_Wrapper/Include/MissingAudioException.h>


MissingAudioException::MissingAudioException()
{
}

MissingAudioException::MissingAudioException(const std::string& desc) : Exception(desc)
{
    
}

MissingAudioException::~MissingAudioException()
{
}

void MissingAudioException::setAudioChannelId(int audio_channel_id)
{
    this->audio_channel_id = audio_channel_id;
}

int MissingAudioException::getAudioChannelId()
{
    return this->audio_channel_id;
}
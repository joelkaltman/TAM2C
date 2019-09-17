#pragma once

#include <UtilsLib/Include/Exception.h>

class MissingAudioException : public utils::Exception
{
    public:

        MissingAudioException();

        explicit MissingAudioException(const std::string& desc);

        ~MissingAudioException();

        void setAudioChannelId(int audio_channel_id);

        int getAudioChannelId();

    protected:

        int audio_channel_id;
};


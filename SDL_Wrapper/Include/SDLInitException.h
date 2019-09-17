#pragma once

#include <UtilsLib/Include/Exception.h>

class SDLInitException : public utils::Exception
{
    public:

        SDLInitException();

        explicit SDLInitException(const std::string& desc);

        ~SDLInitException();


};


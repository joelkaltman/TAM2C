#include <SDL_Wrapper/Include/SDLInitException.h>


SDLInitException::SDLInitException()
{
}

SDLInitException::SDLInitException(const std::string& desc) : Exception(desc)
{
}

SDLInitException::~SDLInitException()
{
}

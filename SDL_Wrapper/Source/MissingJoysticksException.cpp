#include <SDL_Wrapper/Include/MissingJoysticksException.h>


MissingJoysticksException::MissingJoysticksException()
{
    this->joystick_count = -1;
    this->joystick_id = -1;
}

MissingJoysticksException::MissingJoysticksException(const std::string& desc) : Exception(desc)
{
    this->joystick_count = -1;
    this->joystick_id = -1;
}

MissingJoysticksException::~MissingJoysticksException()
{
}

void MissingJoysticksException::setJoystickCount(int joystick_count)
{
    this->joystick_count = joystick_count;
}

int MissingJoysticksException::getJoystickCount()
{
    return this->joystick_count;
}

void MissingJoysticksException::setJoystickId(int joystick_id)
{
    this->joystick_id = joystick_id;
}

int MissingJoysticksException::getJoystickId()
{
    return this->joystick_id;
}

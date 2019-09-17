#pragma once

#include <UtilsLib/Include/Exception.h>

class MissingJoysticksException : public utils::Exception
{
    public:

        MissingJoysticksException();

        explicit MissingJoysticksException(const std::string& desc);

        ~MissingJoysticksException();

        void setJoystickCount(int joystick_count);

        int getJoystickCount();

        void setJoystickId(int joystick_id);

        int getJoystickId();

    protected:

        int joystick_count;

        int joystick_id;
};


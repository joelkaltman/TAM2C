#pragma once

// math
#include <math/Include/Vector3.h>

// TAM2C
#include <TAM2C/Include/Definitions.h>
#include <TAM2C/Include/Cabin.h>
#include <TAM2C/Include/JoysticksManager.h>

class Scene
{
public:
	Scene() = default;

	void init();

private:
	friend class Definitions;

	Cabin* cabin;
	JoysticksManager* joystickMng;
};
#pragma once

// TAM2C
#include <TAM2C/Include/IMember.h>

class Cabin
{
public:
	enum ID
	{
		AP,
		JTAN,
		INVALID
	};

	Cabin(p3d::Scene3D* scene, p3d::Context* context);

	void setJoystick(ID id, int joystickId);

	void axisModified(int id, float deriva, float alza);

private:
	std::map<ID, IMember*> members;

	p3d::Object3D* carriage = nullptr;
};
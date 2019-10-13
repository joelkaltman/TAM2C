#pragma once

// TAM2C
#include <TAM2C/Include/IMember.h>

class Cabin
{
public:
	enum MEMBER_ID
	{
		AP,
		JTAN,
		INVALID
	};

	Cabin(p3d::Scene3D* scene, p3d::Context* context);
	~Cabin();

	IMember* getMember(MEMBER_ID id);

	void axisModified(int id, float deriva, float alza);

private:
	std::map<MEMBER_ID, IMember*> members;

	p3d::Object3D* carriage = nullptr;

	p3d::Scene3D* scene = nullptr;
};
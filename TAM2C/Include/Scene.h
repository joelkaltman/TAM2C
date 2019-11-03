#pragma once

// math
#include <math/Include/Vector3.h>

// p3d
#include <p3d/Include/P3D.h>
#include <p3d/Include/Context.h>
#include <p3d/Include/Scene3d.h>
#include <p3d/Include/SceneDescription.h>

// TAM2C
#include <TAM2C/Include/Config.h>
#include <TAM2C/Include/Cabin.h>
#include <TAM2C/Include/JoysticksManager.h>

class Scene
{
public:
	Scene() = default;

	bool init(p3d::P3D::Platform plataform);
	void end();

	Cabin* getMainCabin() const;

private:
	friend class Config;

	Cabin* cabin = nullptr;
	JoysticksManager* joystickMng = nullptr;

	p3d::Context* context = nullptr;
	p3d::Scene3D* scene3d = nullptr;
	p3d::SceneDescription* sceneDesc = nullptr;
};
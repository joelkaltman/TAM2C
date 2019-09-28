#pragma once

// math
#include <math/Include/Vector3.h>

// TAM2C
#include <TAM2C/Include/Definitions.h>
#include <TAM2C/Include/Cabin.h>
#include <TAM2C/Include/JoysticksManager.h>

namespace p3d
{
	class P3D;
	class Resource;
	class ResourceManager;
};

class Scene
{
public:
	Scene() = default;

	void init(p3d::P3D* p3d);

private:
	friend class Definitions;

	void loadResources(p3d::ResourceManager* resource_manager);

	std::map<std::string, p3d::Resource*> resources;
	
	Cabin* cabin;
	JoysticksManager* joystickMng;
};
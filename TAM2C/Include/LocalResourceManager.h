#pragma once

#include <map>

// p3d
#include <p3d/Include/Resource.h>
#include <p3d/Include/ResourceManager.h>

class LocalResourceManager
{
public:
	static LocalResourceManager& getInstance()
	{
		static LocalResourceManager instance;
		return instance;
	}

	LocalResourceManager(LocalResourceManager const&) = delete;
	void operator=(LocalResourceManager const&) = delete;

	void loadResources(p3d::ResourceManager* resource_manager);

	std::map<std::string, p3d::Resource*> resources;
private:
	LocalResourceManager() {}

};

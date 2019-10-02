#pragma once

#include <map>

// p3d
#include <p3d/Include/Resource.h>

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

	std::map<std::string, p3d::Resource*> resources;

private:
	LocalResourceManager() {}
};

#pragma once

#include <string>

class Scene;

struct Definitions
{
	static std::string getGUIPath(std::string path = "")
	{
		if (!path.empty()) path.insert(0, "/");
		return Definitions::GUIPath + path;
	}

	static std::string getScreenSpritesPath(std::string path = "")
	{
		if (!path.empty()) path.insert(0, "/");
		return Definitions::ScreenSpritesPath + path;
	}

	static std::string getMultimediaResourcesPath(std::string path = "")
	{
		if (!path.empty()) path.insert(0, "/");
		return Definitions::MultimediaResourcesPath + path;
	}

	static std::string getScenePath(std::string path = "")
	{
		if (!path.empty()) path.insert(0, "/");
		return Definitions::Scenes + path;
	}

	Definitions(const std::string& pathConfig, Scene* scene);

 private:
	static std::string GUIPath;
	static std::string ScreenSpritesPath;
	static std::string MultimediaResourcesPath;
	static std::string Scenes;
};
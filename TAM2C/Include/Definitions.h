#pragma once

#include <string>

class Definitions
{
 public:
	static struct InitData
	{
		std::string scene = "";
		int idJoyAp = 0;
		int idJoyJTAN = 0;
		bool fullScreenAp = false;
		bool fullScreenJtan = false;
		float cabinX = 0.f;
		float cabinY = 0.f;
	} initData;

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

	Definitions(const std::string& pathConfig);

 private:
	static std::string GUIPath;
	static std::string ScreenSpritesPath;
	static std::string MultimediaResourcesPath;
	static std::string Scenes;
};
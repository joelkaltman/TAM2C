#pragma once

#include <string>

struct Definitions
{
	static const std::string getGUIPath(const std::string& path = "")
	{
		return GUIPath + path;
	}

	static const std::string getScreenSpritesPath(const std::string& path = "")
	{
		return ScreenSpritesPath + path;
	}

	static const std::string getMultimediaResourcesPath(const std::string& path = "")
	{
		return MultimediaResourcesPath + path;
	}

 private:
	static const std::string GUIPath;
	static const std::string ScreenSpritesPath;
	static const std::string MultimediaResourcesPath;
};
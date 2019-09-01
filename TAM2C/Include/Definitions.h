#pragma once

#include <string>

struct Definitions
{
	static const std::string getGUIPath(const std::string& path)
	{
		return GUIPath + path;
	}

 private:
	static const std::string GUIPath;
};
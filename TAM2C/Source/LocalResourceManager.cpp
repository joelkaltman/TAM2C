#include <TAM2C/Include/LocalResourceManager.h>

#include <TAM2C/Include/Config.h>

#include <direct.h>
#include <windows.h>
#include <ShlObj.h>
#include <windows.h>
#include <Lmcons.h>
#include <sstream>
#include <codecvt>
#include <filesystem>

std::vector<std::string> listDirectoryFiles(const std::string& dirPath)
{
	std::vector<std::string> result = std::vector<std::string>();

	// Add wildcard search to path
	std::string extendedPath = dirPath + "/*";
	if (extendedPath.length() >= MAX_PATH)
	{
		std::cout << "Directory '%s' path too long!" << dirPath.c_str() << std::endl;
		return result;
	}

	HANDLE hFile = INVALID_HANDLE_VALUE;
	WIN32_FIND_DATA wfData;
	WCHAR dirpath[MAX_PATH];

	int res = MultiByteToWideChar(CP_UTF8, 0, extendedPath.c_str(), -1, dirpath, MAX_PATH);

	hFile = FindFirstFile(dirpath, &wfData);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		std::cout << "Directory '%s' has  no Files!"<< dirPath.c_str() << std::endl;
		return result;
	}

	do {
		//if ((wfData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
		{
			char fileName[MAX_PATH];
			wcstombs(fileName, wfData.cFileName, MAX_PATH);
			std::string fname;
			fname += fileName;

			if (fname != "." && fname != "..")
			{
				if ((wfData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
				{
					result.push_back(fname);
				}
				else
				{
					result.push_back(fname + "/");
				}
				//printf("[fs::listDirectoryFiles] File %s", fname.c_str());
			}
		}
	} while (FindNextFile(hFile, &wfData));

	return result;
}

void LocalResourceManager::loadResources(p3d::ResourceManager* resource_manager)
{
	auto& resources = LocalResourceManager::getInstance().resources;

	std::vector<std::string> files;
	for (auto& entry : std::filesystem::directory_iterator(Config::getScreenSpritesPath()))
	{
		std::string filePath = entry.path().string();
		const size_t last_slash_idx = filePath.find_last_of("\\/");
		if (std::string::npos != last_slash_idx)
			filePath.erase(0, last_slash_idx + 1);

		const size_t period_idx = filePath.rfind('.');
		if (std::string::npos != period_idx)
		{
			std::string extension = filePath.substr(period_idx);	
			if (extension == ".rpgs")
			{
				filePath.erase(period_idx);
				files.push_back(filePath);
			}
		}
	}

	for (auto& f : files)
	{
		resources[f] = resource_manager->loadResource(Config::getScreenSpritesPath(f + ".rpgs"));
	}

	resources["TAM2C_carriage"] = resource_manager->loadResource(Config::getMultimediaResourcesPath(Config::initData.carriage));
	resources["TAM2C_turret"] = resource_manager->loadResource(Config::getMultimediaResourcesPath(Config::initData.turret));
	resources["TAM2C_cannon"] = resource_manager->loadResource(Config::getMultimediaResourcesPath(Config::initData.cannon));

	for (auto& res : resources)
	{
		res.second->waitTillLoaded();
	}
}

void LocalResourceManager::unloadResources(p3d::ResourceManager* resource_manager)
{
	for (auto& res : resources)
		resource_manager->unloadResource(res.second);

	resources.clear();
}
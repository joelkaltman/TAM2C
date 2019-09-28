#include <Include/Definitions.h>

// stl
#include <fstream>

// rapidjson
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>

// TAM2C
#include <TAM2C/Include/Scene.h>

std::string Definitions::GUIPath = "";
std::string Definitions::ScreenSpritesPath = "";
std::string Definitions::MultimediaResourcesPath = "";
std::string Definitions::Scenes = "";

Definitions::Definitions(const std::string& pathConfig, Scene* scene)
{
	std::ifstream inStream(pathConfig);
	rapidjson::IStreamWrapper isw(inStream);

	rapidjson::Document configJson;
	configJson.ParseStream(isw);

	rapidjson::Value& paths = configJson["paths"];
	Definitions::MultimediaResourcesPath = paths["MultimediaResources"].GetString();
	Definitions::GUIPath = paths["GUI"].GetString();
	Definitions::ScreenSpritesPath = paths["GDSUSprites"].GetString();
	Definitions::Scenes = paths["Scenes"].GetString();

	rapidjson::Value& cabin = configJson["cabin"];
	scene->initData.idJoyAp = cabin["joystickAP"].GetInt();
	scene->initData.idJoyJTAN = cabin["joystickJTAN"].GetInt();

	rapidjson::Value& jscene = configJson["scene"];
	scene->initData.scene = jscene["pgsscene"].GetString();
	scene->initData.cabinX = jscene["cabinPosX"].GetFloat();
	scene->initData.cabinY = jscene["cabinPosY"].GetFloat();
}
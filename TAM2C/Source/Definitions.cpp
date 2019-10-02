#include <Include/Definitions.h>

// stl
#include <fstream>

// rapidjson
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>

std::string Definitions::GUIPath = "";
std::string Definitions::ScreenSpritesPath = "";
std::string Definitions::MultimediaResourcesPath = "";
std::string Definitions::Scenes = "";

Definitions::InitData Definitions::initData = Definitions::InitData();

Definitions::Definitions(const std::string& pathConfig)
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
	initData.carriage = cabin["carriage"].GetString();
	initData.turret = cabin["turret"].GetString();
	initData.cannon = cabin["cannon"].GetString();

	rapidjson::Value& ap = cabin["ap"];
	initData.idJoyAp = ap["joystick"].GetInt();
	initData.fullScreenAp = ap["fullscreen"].GetBool();

	rapidjson::Value& jtan = cabin["jtan"];
	initData.idJoyJTAN = jtan["joystick"].GetInt();
	initData.fullScreenJtan = jtan["fullscreen"].GetBool();

	rapidjson::Value& jscene = configJson["scene"];
	initData.scene = jscene["pgsscene"].GetString();
	initData.cabinPosX = jscene["cabinPosX"].GetFloat();
	initData.cabinPosY = jscene["cabinPosY"].GetFloat();
	initData.cabinAtX = jscene["cabinAtX"].GetFloat();
	initData.cabinAtY = jscene["cabinAtY"].GetFloat();
}
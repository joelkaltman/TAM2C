#include <Include/Config.h>

// stl
#include <fstream>

// rapidjson
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>

std::string Config::GUIPath = "";
std::string Config::ScreenSpritesPath = "";
std::string Config::MultimediaResourcesPath = "";
std::string Config::Scenes = "";

Config::InitData Config::initData = Config::InitData();

Config::Config(const std::string& pathConfig)
{
	std::ifstream inStream(pathConfig);
	rapidjson::IStreamWrapper isw(inStream);

	rapidjson::Document configJson;
	configJson.ParseStream(isw);

	rapidjson::Value& paths = configJson["paths"];
	Config::MultimediaResourcesPath = paths["MultimediaResources"].GetString();
	Config::GUIPath = paths["GUI"].GetString();
	Config::ScreenSpritesPath = paths["GDSUSprites"].GetString();
	Config::Scenes = paths["Scenes"].GetString();

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
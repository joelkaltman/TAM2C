#include <TAM2C/Include/LocalResourceManager.h>

#include <TAM2C/Include/Config.h>

void LocalResourceManager::loadResources(p3d::ResourceManager* resource_manager)
{
	auto& resources = LocalResourceManager::getInstance().resources;

	resources["TAM2C_carriage"] = resource_manager->loadResource(Config::getMultimediaResourcesPath(Config::initData.carriage));
	resources["TAM2C_turret"] = resource_manager->loadResource(Config::getMultimediaResourcesPath(Config::initData.turret));
	resources["TAM2C_cannon"] = resource_manager->loadResource(Config::getMultimediaResourcesPath(Config::initData.cannon));

	resources["GDSU_periscope"] = resource_manager->loadResource(Config::getScreenSpritesPath("GDSU_periscope.rpgs"));
	resources["GDSU_-"] = resource_manager->loadResource(Config::getScreenSpritesPath("-.rpgs"));
	resources["GDSU_+"] = resource_manager->loadResource(Config::getScreenSpritesPath("+.rpgs"));
	resources["GDSU_2114"] = resource_manager->loadResource(Config::getScreenSpritesPath("2114.rpgs"));
	resources["GDSU_5567"] = resource_manager->loadResource(Config::getScreenSpritesPath("5567.rpgs"));
	resources["GDSU_AP1_AP2"] = resource_manager->loadResource(Config::getScreenSpritesPath("AP1 AP2.rpgs"));
	resources["GDSU_AP1"] = resource_manager->loadResource(Config::getScreenSpritesPath("AP1.rpgs"));
	resources["GDSU_ARM"] = resource_manager->loadResource(Config::getScreenSpritesPath("ARM.rpgs"));
	resources["GDSU_Btl_Man"] = resource_manager->loadResource(Config::getScreenSpritesPath("Btl Man.rpgs"));
	resources["GDSU_DATA"] = resource_manager->loadResource(Config::getScreenSpritesPath("DATA.rpgs"));
	resources["GDSU_DayCam"] = resource_manager->loadResource(Config::getScreenSpritesPath("DayCam.rpgs"));
	resources["GDSU_empty"] = resource_manager->loadResource(Config::getScreenSpritesPath("empty.rpgs"));
	resources["GDSU_FLS_WP"] = resource_manager->loadResource(Config::getScreenSpritesPath("FLS WP.rpgs"));
	resources["GDSU_Fst_Last"] = resource_manager->loadResource(Config::getScreenSpritesPath("Fst Last.rpgs"));
	resources["GDSU_Gn_Cm_CLR"] = resource_manager->loadResource(Config::getScreenSpritesPath("Gn Cm CLR.rpgs"));
	resources["GDSU_Gn_Cm"] = resource_manager->loadResource(Config::getScreenSpritesPath("Gn Cm.rpgs"));
	resources["GDSU_GUN"] = resource_manager->loadResource(Config::getScreenSpritesPath("GUN.rpgs"));
	resources["GDSU_MGUN"] = resource_manager->loadResource(Config::getScreenSpritesPath("MGUN.rpgs"));
	resources["GDSU_HE1_HE2"] = resource_manager->loadResource(Config::getScreenSpritesPath("HE1 HE2.rpgs"));
	resources["GDSU_HT1_HT2"] = resource_manager->loadResource(Config::getScreenSpritesPath("HT1 HT2.rpgs"));
	resources["GDSU_LW"] = resource_manager->loadResource(Config::getScreenSpritesPath("LW.rpgs"));
	resources["GDSU_MAN"] = resource_manager->loadResource(Config::getScreenSpritesPath("MAN.rpgs"));
	resources["GDSU_MG_SC"] = resource_manager->loadResource(Config::getScreenSpritesPath("MG SC.rpgs"));
	resources["GDSU_MSTG"] = resource_manager->loadResource(Config::getScreenSpritesPath("MSTG.rpgs"));
	resources["GDSU_STG"] = resource_manager->loadResource(Config::getScreenSpritesPath("STG.rpgs"));
	resources["GDSU_GTS"] = resource_manager->loadResource(Config::getScreenSpritesPath("GTS.rpgs"));
	resources["GDSU_N_W_VW"] = resource_manager->loadResource(Config::getScreenSpritesPath("N W VW.rpgs"));
	resources["GDSU_NEXT_FLT"] = resource_manager->loadResource(Config::getScreenSpritesPath("NEXT FLT.rpgs"));
	resources["GDSU_NextAlt"] = resource_manager->loadResource(Config::getScreenSpritesPath("NextAlt.rpgs"));
	resources["GDSU_NightCam"] = resource_manager->loadResource(Config::getScreenSpritesPath("NightCam.rpgs"));
	resources["GDSU_RDY"] = resource_manager->loadResource(Config::getScreenSpritesPath("RDY.rpgs"));
	resources["GDSU_Zm_Rt_Fc_Ir"] = resource_manager->loadResource(Config::getScreenSpritesPath("Zm Rt Fc Ir.rpgs"));
	resources["Drift"] = resource_manager->loadResource(Config::getScreenSpritesPath("Drift.rpgs"));
	resources["DriftCenter"] = resource_manager->loadResource(Config::getScreenSpritesPath("DriftCenter.rpgs"));
	resources["Rise"] = resource_manager->loadResource(Config::getScreenSpritesPath("Rise.rpgs"));
	resources["RiseIndicator"] = resource_manager->loadResource(Config::getScreenSpritesPath("RiseIndicator.rpgs"));
	resources["Numbers"] = resource_manager->loadResource(Config::getScreenSpritesPath("Numbers.rpgs"));
	resources["SelectedLabel"] = resource_manager->loadResource(Config::getScreenSpritesPath("SelectedLabel.rpgs"));
	resources["DisabledLabel"] = resource_manager->loadResource(Config::getScreenSpritesPath("DisabledLabel.rpgs"));
	resources["Blackout"] = resource_manager->loadResource(Config::getScreenSpritesPath("Blackout.rpgs"));

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
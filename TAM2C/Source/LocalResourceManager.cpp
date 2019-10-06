#include <TAM2C/Include/LocalResourceManager.h>

#include <TAM2C/Include/Definitions.h>

void LocalResourceManager::loadResources(p3d::ResourceManager* resource_manager)
{
	auto& resources = LocalResourceManager::getInstance().resources;

	resources["TAM2C_carriage"] = resource_manager->loadResource(Definitions::getMultimediaResourcesPath(Definitions::initData.carriage));
	resources["TAM2C_turret"] = resource_manager->loadResource(Definitions::getMultimediaResourcesPath(Definitions::initData.turret));
	resources["TAM2C_cannon"] = resource_manager->loadResource(Definitions::getMultimediaResourcesPath(Definitions::initData.cannon));

	resources["GDSU_periscope"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("GDSU_periscope.rpgs"));
	resources["GDSU_-"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("-.rpgs"));
	resources["GDSU_+"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("+.rpgs"));
	resources["GDSU_2114"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("2114.rpgs"));
	resources["GDSU_5567"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("5567.rpgs"));
	resources["GDSU_AP1_AP2"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("AP1 AP2.rpgs"));
	resources["GDSU_AP1"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("AP1.rpgs"));
	resources["GDSU_ARM"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("ARM.rpgs"));
	resources["GDSU_Btl_Man"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("Btl Man.rpgs"));
	resources["GDSU_DATA"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("DATA.rpgs"));
	resources["GDSU_DayCam"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("DayCam.rpgs"));
	resources["GDSU_empty"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("empty.rpgs"));
	resources["GDSU_FLS_WP"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("FLS WP.rpgs"));
	resources["GDSU_Fst_Last"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("Fst Last.rpgs"));
	resources["GDSU_Gn_Cm_CLR"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("Gn Cm CLR.rpgs"));
	resources["GDSU_Gn_Cm"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("Gn Cm.rpgs"));
	resources["GDSU_GUN"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("GUN.rpgs"));
	resources["GDSU_HE1_HE2"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("HE1 HE2.rpgs"));
	resources["GDSU_HT1_HT2"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("HT1 HT2.rpgs"));
	resources["GDSU_LW"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("LW.rpgs"));
	resources["GDSU_MAN"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("MAN.rpgs"));
	resources["GDSU_MG_SC"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("MG SC.rpgs"));
	resources["GDSU_MSTG"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("MSTG.rpgs"));
	resources["GDSU_N_W_VW"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("N W VW.rpgs"));
	resources["GDSU_NEXT_FLT"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("NEXT FLT.rpgs"));
	resources["GDSU_NextAlt"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("NextAlt.rpgs"));
	resources["GDSU_NightCam"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("NightCam.rpgs"));
	resources["GDSU_RDY"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("RDY.rpgs"));
	resources["GDSU_Zm_Rt_Fc_Ir"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("Zm Rt Fc Ir.rpgs"));
	resources["Cabin"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("Cabin.rpgs"));
	resources["CabinAt"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("CabinAt.rpgs"));
	resources["Numbers"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("Numbers.rpgs"));
	resources["SelectedLabel"] = resource_manager->loadResource(Definitions::getScreenSpritesPath("SelectedLabel.rpgs"));

	for (auto& res : resources)
	{
		res.second->waitTillLoaded();
	}
}
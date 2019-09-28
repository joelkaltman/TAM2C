#include <TAM2C/Include/Scene.h>

// p3d
#include <p3d/Include/P3D.h>
#include <p3d/include/ResourceManager.h>
#include <resources/Include/Admin.h>

// PGSWidget
#include <PGSWidget/Include/PGSWidget.h>

void Scene::init(p3d::P3D* p3d)
{
	p3d::ResourceManager* resource_manager = p3d->getResourceManager();

	p3d::SceneDescription* scene_description = p3d->loadSceneDescription(Definitions::getScenePath(initData.scene), Definitions::getMultimediaResourcesPath());

	resource_manager->loadResources(scene_description);

	loadResources(resource_manager);

	p3d::Context* context = p3d->createExecutionContext();

	p3d::Scene3D* scene = context->createScene3D();
	scene->installSceneDescription(scene_description);

	p3d::DirectionalLight* directional_light = scene->installDirectionalLight("luz direccional", 0, 1, -1, 255, 255, 255);

	p3d::Billboard* billboard = scene->installBillboard("fire", 5010.0, 5010.0, 8, 5000.0, 5000.0, 8, 0, 0, 1, resources["Fire"], false);
	billboard->scale(5.0, 5.0, 5.0);
	billboard->playLoop();

	p3d::AnimatedObject3D* object_1 = scene->installAnimatedObject("terrorist", 5005.0, 5006.0, 8, 5005.0 - 1, 5006.0 - 1, 8, 0, 0, 1, resources["Terrorist"], true, p3d::Object3D::FillMode::SOLID);

	cabin = new Cabin(initData.cabinX, initData.cabinY);

	cabin->setJoystick(Cabin::ID::AP, initData.idJoyAp);
	cabin->setJoystick(Cabin::ID::JTAN, initData.idJoyJTAN);

	cabin->createCamera(Cabin::AP, scene);
	cabin->createGDSU(Cabin::AP, context, resources);

	cabin->createCamera(Cabin::JTAN, scene);
	cabin->createGDSU(Cabin::JTAN, context, resources);

	joystickMng = new JoysticksManager(cabin);

	p3d->initRendering();

	object_1->startAnimation(0, true);
	billboard->start();
}

void Scene::loadResources(p3d::ResourceManager* resource_manager)
{
	resources["Terrorist"] = resource_manager->loadResource(Definitions::getMultimediaResourcesPath("Objetos/Animados/Terrorist/Terrorist.rpgs"));

	resources["Fire"] = resource_manager->loadResource(Definitions::getMultimediaResourcesPath("Videos/Fuego/Fuego01/Fuego_01.rpgs"));

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

	for (auto& res : resources)
	{
		res.second->waitTillLoaded();
	}
}
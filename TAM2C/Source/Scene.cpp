#include <TAM2C/Include/Scene.h>

// p3d
#include <p3d/Include/P3D.h>
#include <p3d/include/ResourceManager.h>
#include <resources/Include/Admin.h>

// PGSWidget
#include <PGSWidget/Include/PGSWidget.h>

// TAM2C
#include <TAM2C/Include/LocalResourceManager.h>

void Scene::init()
{
	p3d::P3D* p3d = p3d::P3D::getInstance();
	p3d::ResourceManager* resource_manager = p3d->getResourceManager();

	p3d::SceneDescription* scene_description = p3d->loadSceneDescription(Definitions::getScenePath(Definitions::initData.scene), Definitions::getMultimediaResourcesPath());

	resource_manager->loadResources(scene_description);

	LocalResourceManager::getInstance().loadResources(resource_manager);

	p3d::Context* context = p3d->createExecutionContext();

	p3d::Scene3D* scene = context->createScene3D();
	scene->installSceneDescription(scene_description);

	p3d::DirectionalLight* directional_light = scene->installDirectionalLight(0, 1, -1, 255, 255, 255);

	cabin = new Cabin(scene, context);

	joystickMng = new JoysticksManager(cabin);

	p3d->initRendering();
}
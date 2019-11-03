#include <TAM2C/Include/Scene.h>

// UtilsLib
#include <UtilsLib/Include/Exception.h>

// TaskLib
#include <TaskLib/Include/TaskManager.h>

// p3d
#include <p3d/Include/P3D.h>
#include <p3d/include/ResourceManager.h>
#include <resources/Include/Admin.h>

// PGSWidget
#include <PGSWidget/Include/PGSWidget.h>

// TAM2C
#include <TAM2C/Include/LocalResourceManager.h>

bool Scene::init(p3d::P3D::Platform platform)
{
	joystickMng = new JoysticksManager();
	if (!joystickMng->openJoysticks())
		return false;

	if (!Config::load("../config.json"))
		return false;

	p3d::P3D::initialize(p3d::P3D::NetworkingMode::ONLY_LOCAL, platform);

	p3d::P3D* p3d = p3d::P3D::getInstance();
	p3d::ResourceManager* resource_manager = p3d->getResourceManager();

	sceneDesc = p3d->loadSceneDescription(Config::getScenePath(Config::initData.scene), Config::getMultimediaResourcesPath());

	resource_manager->loadResources(sceneDesc);
	
	LocalResourceManager::getInstance().loadResources(resource_manager);
	
	context = p3d->createExecutionContext();

	scene3d = context->createScene3D();
	scene3d->installSceneDescription(sceneDesc);

	cabin = new Cabin(scene3d, context);

	joystickMng->init(cabin);

	p3d->initRendering();

	return true;
}

void Scene::end()
{
	p3d::P3D* p3d = p3d::P3D::getInstance();
	p3d->stopRendering();

	delete joystickMng;
	delete cabin;

	try
	{
		scene3d->uninstallSceneDescription(sceneDesc);
	}
	catch (utils::Exception* e)
	{
		std::cout << e->getMensaje().str() << std::endl;
	}

	context->destroyAllScene2D();
	context->destroyAllScene3D();

	p3d::ResourceManager* resource_manager = p3d->getResourceManager();
	
	LocalResourceManager::getInstance().unloadResources(resource_manager);
	resource_manager->unloadResources(sceneDesc);

	p3d->exitFromExecutionContext(context);
	p3d::P3D::release();
}

Cabin* Scene::getMainCabin() const
{
	return cabin;
}
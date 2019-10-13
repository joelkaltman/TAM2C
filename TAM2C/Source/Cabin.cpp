#include <TAM2C/Include/Cabin.h>

// TAM2C
#include <TAM2C/Include/Config.h>
#include <TAM2C/Include/Ap.h>
#include <TAM2C/Include/Jtan.h>
#include <TAM2C/Include/LocalResourceManager.h>

// TaskLib
#include <TaskLib/Include/TaskManager.h>

Cabin::Cabin(p3d::Scene3D* scene, p3d::Context* context) :
	scene(scene)
{
	Ap* ap = new Ap(scene, context->createScene2D());
	JTan* jtan = new JTan(scene, context->createScene2D());

	carriage = scene->installObjectVerticalToTerrain(
		Config::initData.cabinPosX, Config::initData.cabinPosY, 10, 
		Config::initData.cabinAtX, Config::initData.cabinAtY, 10, 
		LocalResourceManager::getInstance().resources["TAM2C_carriage"], true);

	carriage->addChild(ap->turret);
	ap->turret->addChild(jtan->transfTraslation);

	members[AP] = ap;
	members[JTAN] = jtan;

	members[AP]->joystick = Config::initData.idJoyAp;
	members[JTAN]->joystick = Config::initData.idJoyJTAN;
}

Cabin::~Cabin()
{
	members.clear();
	scene->uninstallObject(carriage);
}

void Cabin::axisModified(int id, float deriva, float alza)
{
	MEMBER_ID mId = INVALID;

	for (auto& m : members)
	{
		if (m.second->joystick == id)
			mId = m.first;
	}

	if (mId == INVALID)
		return;

	members[mId]->rotate(deriva, alza);
}

IMember* Cabin::getMember(MEMBER_ID id)
{
	if (members.find(id) != members.end())
		return members.at(id);

	return nullptr;
}
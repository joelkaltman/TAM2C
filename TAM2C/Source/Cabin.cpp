#include <TAM2C/Include/Cabin.h>

// TAM2C
#include <TAM2C/Include/Definitions.h>
#include <TAM2C/Include/Ap.h>
#include <TAM2C/Include/Jtan.h>
#include <TAM2C/Include/LocalResourceManager.h>

// TaskLib
#include <TaskLib/Include/TaskManager.h>

Cabin::Cabin(p3d::Scene3D* scene, p3d::Context* context)
{
	Ap* ap = new Ap(scene, context->createScene2D());
	JTan* jtan = new JTan(scene, context->createScene2D());

	carriage = scene->installObjectVerticalToTerrain(
		Definitions::initData.cabinPosX, Definitions::initData.cabinPosY, 10, 
		Definitions::initData.cabinAtX, Definitions::initData.cabinAtY, 10, 
		LocalResourceManager::getInstance().resources["TAM2C_carriage"], true);

	carriage->addChild(ap->turret);
	ap->turret->addChild(jtan->transfTraslation);

	members[AP] = ap;
	members[JTAN] = jtan;

	members[AP]->joystick = Definitions::initData.idJoyAp;
	members[JTAN]->joystick = Definitions::initData.idJoyJTAN;
}

void Cabin::axisModified(int id, float deriva, float alza)
{
	ID mId = INVALID;

	for (auto& m : members)
	{
		if (m.second->joystick == id)
			mId = m.first;
	}

	if (mId == INVALID)
		return;

	members[mId]->rotate(deriva, alza);
}
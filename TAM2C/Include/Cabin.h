#pragma once

// UtilsLib
#include <UtilsLib/Include/Semaphore.h>

// TaskLib
#include <TaskLib/Include/PeriodicTask.h>

// SDL
#include <SDL.h>

// GUI
#include <GUI/Include/ApPanels.h>
#include <GUI/Include/JtanPanels.h>

// TAM2C
#include <TAM2C/Include/IMember.h>

class Cabin
{
public:
	enum ID
	{
		AP,
		JTAN,
		INVALID
	};

	Cabin(float x, float y, p3d::Resource* rCarriage, p3d::Resource* rTower, p3d::Resource* rCannon, p3d::Scene3D* scene);

	void setJoystick(ID id, int joystickId);

	void createCamera(ID id, p3d::Scene3D* scene);
	void createGDSU(ID id, p3d::Context* context, std::map<std::string, p3d::Resource*> resources);

	p3d::Camera* getCamera(ID id) const;

	void axisModified(int id, float deriva, float alza);

private:
	float spawnX = 0;
	float spawnY = 0;

	std::map<ID, IMember*> members;

	ApPanels uiAp;
	JtanPanels uiJtan;

	p3d::Object3D* carriage = nullptr;
};
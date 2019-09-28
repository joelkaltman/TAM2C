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

namespace p3d
{
	class Scene3D;
	class Camera;
	class Window;
	class Context;
	class Resource;
	class Sprite;
}

class Cabin
{
public:
	enum ID
	{
		AP,
		JTAN,
		INVALID
	};

	struct Member
	{
		int joystick;
		p3d::Camera* camera;
		p3d::Window* window;
		std::map<std::string, p3d::Sprite*> sprites;
	};

	Cabin(float x, float y) : spawnX(x), spawnY(y) {};

	void setJoystick(ID id, int joystickId);

	void createCamera(ID id, p3d::Scene3D* scene);
	void createGDSU(ID id, p3d::Context* context, std::map<std::string, p3d::Resource*> resources);

	p3d::Camera* getCamera(ID id) const;

	void axisModified(int id, float deriva, float alza);

private:
	std::map<ID, Member> members;

	ApPanels uiAp;
	JtanPanels uiJtan;

	float spawnX = 0;
	float spawnY = 0;
};
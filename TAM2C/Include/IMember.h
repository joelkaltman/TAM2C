#pragma once

#include <map>

// p3d
#include <p3d/Include/P3D.h>
#include <p3d/Include/Scene3d.h>
#include <p3d/Include/Scene2D.h>
#include <p3d/Include/Camera.h>
#include <p3d/Include/Window.h>
#include <p3d/Include/Resource.h>
#include <p3d/Include/Context.h>
#include <p3d/Include/ResourceManager.h>
#include <p3d/Include/Object3D.h>

// GUI
#include <GUI/Include/IElement.h>

// TAM2C
#include <TAM2C/Include/GDSU.h>
#include <TAM2C/Include/IMemberConfig.h>

#define RELATIVE_DISTANCE_TOWER_X 0.0
#define RELATIVE_DISTANCE_TOWER_Y 0.0
#define RELATIVE_DISTANCE_TOWER_Z 1.75

#define RELATIVE_DISTANCE_CANNON_X 0.0
#define RELATIVE_DISTANCE_CANNON_Y 1.05
#define RELATIVE_DISTANCE_CANNON_Z 0.21

#define RELATIVE_DISTANCE_CAMERA_APUN_X -0.36
#define RELATIVE_DISTANCE_CAMERA_APUN_Y 0.0
#define RELATIVE_DISTANCE_CAMERA_APUN_Z 0.0

#define DISTANCIA_CALIBRACION_PUNTERIA 1500.0

#define MAX_ANGLE_RISE_PERISCOPE 0.314159 // PI/180*18 = 18º
#define MIN_ANGLE_RISE_PERISCOPE -0.12217 // -PI/180*7 = -7º

#define RELATIVE_DISTANCE_CAMERA_JTAN_X -0.816
#define RELATIVE_DISTANCE_CAMERA_JTAN_Y -0.048
#define RELATIVE_DISTANCE_CAMERA_JTAN_Z 0.907

class IMember
{
 public:

	 IMember() = default;
	 ~IMember() = default;
	 
	 virtual void rotate(double drift, double rise) {};

	 virtual void addSubscriberToUI(ISubscriber* sub) {};

	 virtual IElement* getGUIElement(ELEM_ID id) { return nullptr; };

 protected:
	friend class Cabin;

	virtual void createCameraGDSU() {};

	GDSU* gdsu = nullptr;

	int joystick;
	p3d::Camera* camera = nullptr;
	p3d::Window* window = nullptr;

	IMemberConfig config;

};
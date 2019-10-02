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

#define DISTANCIA_RELATIVA_TORRE_X 0.0
#define DISTANCIA_RELATIVA_TORRE_Y 0.0
#define DISTANCIA_RELATIVA_TORRE_Z 1.75

#define DISTANCIA_RELATIVA_CANION_X 0.0
#define DISTANCIA_RELATIVA_CANION_Y 1.05
#define DISTANCIA_RELATIVA_CANION_Z 0.21

#define DISTANCIA_RELATIVA_CAMARA_APUN_X -0.36
#define DISTANCIA_RELATIVA_CAMARA_APUN_Y 0.0
#define DISTANCIA_RELATIVA_CAMARA_APUN_Z 0.0

#define DISTANCIA_CALIBRACION_PUNTERIA 1500.0

#define MAX_ANGULO_CABECEO_PERISCOPIO 0.314159 // PI/180*18 = 18º
#define MIN_ANGULO_CABECEO_PERISCOPIO -0.12217 // -PI/180*7 = -7º

#define DISTANCIA_RELATIVA_CAMARA_JTAN_X -0.816
#define DISTANCIA_RELATIVA_CAMARA_JTAN_Y -0.048
#define DISTANCIA_RELATIVA_CAMARA_JTAN_Z 0.907

namespace p3d
{
	class Object3D;
	class Scene3D;
	class Camera;
	class Window;
	class Sprite;
}

class IMember
{
 public:
	 IMember() = default;

	 virtual void rotate(double deriva, double alza) {};

	 virtual void addGDSURotation(p3d::Scene2D* scene2d, p3d::Sprite* sprite) {};

	 

 protected:
	friend class Cabin;

	int joystick;
	p3d::Camera* camera;
	p3d::Window* window;
	std::map<std::string, p3d::Sprite*> sprites;
};
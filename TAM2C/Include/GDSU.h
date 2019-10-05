#pragma once

#include <map>

// p3d
#include <p3d/Include/Scene2D.h>
#include <p3d/Include/Sprite.h>

class GDSU
{
 public:
	GDSU(p3d::Scene2D* sceneGDSU);

	void addGDSURotation(p3d::Sprite* sprite);

	 p3d::Scene2D* sceneGDSU;
	 p3d::ROIRotationAnimation* spriteRot;
	 std::map<std::string, p3d::Sprite*> sprites;
};
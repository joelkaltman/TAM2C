#pragma once

#include <map>

// p3d
#include <p3d/Include/Scene2D.h>
#include <p3d/Include/Sprite.h>
#include <math/Include/Vector4.h>

class GDSU;

struct NumLabel
{
	NumLabel(int posX, int posY, int offX, std::string labelName, GDSU* gdsu);

	void showNum(unsigned int num);

	p3d::Sprite* numbers[4];
};

struct OptionLabel
{
	OptionLabel(std::vector<p3d::math::Vector4> prop, std::string labelName, GDSU* gdsu);

	void select(unsigned int index);

	std::vector<p3d::Sprite*> selectionSprites;
};

class GDSU
{
 public:
	 GDSU(p3d::Scene2D* sceneGDSU);
	 
	 void addGDSURotation(p3d::Sprite* sprite);
	 
	 p3d::Scene2D* sceneGDSU;
	 p3d::ROIRotationAnimation* spriteRot;
	 std::map<std::string, p3d::Sprite*> sprites;

	 std::map<std::string, NumLabel*> numLabels;
	 std::map<std::string, OptionLabel*> optionLabels;
};
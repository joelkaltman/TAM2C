#pragma once

#include <map>

// p3d
#include <p3d/Include/Scene2D.h>
#include <p3d/Include/Sprite.h>
#include <math/Include/Vector4.h>

class GDSU;

struct Label
{
	Label(int x, int y, int w, int h, std::string labelName, GDSU* gdsu, std::string resource = "");

	void setEnabled(bool enable);

	void addOption(float offX, int w, int h, GDSU* gdsu);
	void selectOption(unsigned int index);

	void addNumbers(float offX, GDSU* gdsu);
	void showNum(unsigned int num);

	int x;
	int y;
	int w;
	int h;

	p3d::Sprite* background = nullptr;
	p3d::Sprite* disableSprite = nullptr;
	std::vector<p3d::Sprite*> selectionSprites;
	std::vector<p3d::Sprite*> numberSprites;

	bool enabled = true;
};

class GDSU
{
 public:
	 GDSU(p3d::Scene2D* sceneGDSU);
	 
	 void addGDSURotation(p3d::Sprite* sprite);
	 
	 p3d::Scene2D* sceneGDSU;
	 p3d::ROIRotationAnimation* spriteRot;

	 std::map<std::string, Label*> labels;
};
#pragma once

#include <map>
#include <vector>

// p3d
#include <p3d/Include/Scene2D.h>
#include <p3d/Include/Sprite.h>
#include <math/Include/Vector4.h>

class GDSU;

class Label
{
 public:
	Label(int x, int y, int w, int h, std::string res, p3d::Scene2D* sceneGDSU);
	Label(int x, int y, int w, int h, std::vector<std::string> res, p3d::Scene2D* sceneGDSU);
	~Label() = default;

	p3d::Sprite* getBackground(const std::string& res = "") const;
	void changeBackground(const std::string& res);

	void setVisible(bool visible);
	void setEnabled(bool enable);

	std::vector<p3d::Sprite*> getAllSprites() const;

	void addOption(float offX, int w, int h, p3d::Scene2D* sceneGDSU);
	void selectOption(unsigned int index);

	void addNumbers(float offX, p3d::Scene2D* sceneGDSU);
	void showNum(unsigned int num);

	int x;
	int y;
	int w;
	int h;

 private:
	friend class GDSU;

	std::map<std::string, p3d::Sprite*> background;
	p3d::Sprite* disableSprite = nullptr;
	std::vector<p3d::Sprite*> selectionSprites;
	std::vector<p3d::Sprite*> numberSprites;

	std::string currentBackground = "";
	bool enabled = true;
};

class GDSU
{
 public:
	 GDSU(p3d::Scene2D* sceneGDSU);
	 ~GDSU();
	 
	 void loadMainView();

	 Label* getLabel(const std::string& labelName) const;

 private:
	 friend class Label;
	 friend class Ap;
	 friend class JTan;

	 void addGDSURotation(p3d::Sprite* sprite);
	 
	 void clearLabels(std::map<std::string, Label*>& labels);

	 p3d::Scene2D* sceneGDSU = nullptr;
	 p3d::ROIRotationAnimation* spriteRot = nullptr;

	 std::map<std::string, Label*> commonLabels;
	 std::map<std::string, Label*> viewLabels;
};
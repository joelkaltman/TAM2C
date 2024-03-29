#pragma once

#include <map>
#include <vector>

// TaskLib
#include <TaskLib/Include/PeriodicTask.h>

// p3d
#include <p3d/Include/Scene2D.h>
#include <p3d/Include/Sprite.h>
#include <math/Include/Vector4.h>

// TAM2C
#include <TAM2C/Include/IMemberConfig.h>
#include <TAM2C/Include/IMemberSubscriber.h>

class GDSU;

class Label
{
 public:
	enum Color
	{
		BLACK,
		WHITE,
		RED
	};

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
	
	void addText(p3d::Scene2D* sceneGDSU, const std::string& text, Color color = BLACK, float offX = 0, float step = 10);

	int x;
	int y;
	int w;
	int h;

 private:
	friend class GDSU;

	std::map<std::string, p3d::Sprite*> background;
	p3d::Sprite* disableSprite = nullptr;
	std::vector<p3d::Sprite*> selectionSprites;
	std::vector<p3d::Sprite*> textSprites;

	std::string currentBackground = "";
	bool enabled = true;
};

class GDSU : public IMemberSubscriber
{
 public:
	 GDSU(p3d::Scene2D* sceneGDSU);
	 ~GDSU();
	 
	 void loadMainView();

	 Label* getLabel(const std::string& labelName) const;

	 void notifyMemberConfigChanged(const IMemberConfig& config) override;

	 void updateOrientationLabels(float drift, float rise);

 private:
	 friend class Label;
	 friend class Ap;
	 friend class JTan;

	 static void riseUpdateFunction(const double_t& delta_time, void* instance);
	 task::PeriodicTask* riseUpdateTask;

	 void addGDSURotation(p3d::Sprite* sprite);
	 
	 void clearLabels(std::map<std::string, Label*>& labels);

	 p3d::Scene2D* sceneGDSU = nullptr;

	 p3d::ROIRotationAnimation* spriteRot = nullptr;

	 float lastRise = 0;
	 int totalRise = 0;

	 std::map<std::string, Label*> commonLabels;
	 std::map<std::string, Label*> viewLabels;
};
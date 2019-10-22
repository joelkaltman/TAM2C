#include <TAM2C/Include/GDSU.h>

#include <math/Include/Vector4.h>

#include <TAM2C/Include/LocalResourceManager.h>

GDSU::GDSU(p3d::Scene2D* sceneGDSU):
	sceneGDSU(sceneGDSU)
{
	auto& resources = LocalResourceManager::getInstance().resources;

	p3d::math::Vector2 screen1(860, 560);

	commonLabels["Periscope"] = new Label(0, 0, screen1.getX(), screen1.getY(), "GDSU_periscope", sceneGDSU);

	p3d::math::Vector2 image1(70, 124);
	p3d::math::Vector2 image2(300, 300);

	commonLabels["Drift"] = new Label(210, 80, image1.getX(), image1.getY(), "Drift", sceneGDSU);
	commonLabels["DriftCenter"] = new Label(95, 0, image2.getX(), image2.getY(), "DriftCenter", sceneGDSU);

	// Rotation
	p3d::Sprite* at = commonLabels["DriftCenter"]->getBackground();
	at->setROIPosition(150, 150);
	addGDSURotation(at);

	p3d::math::Vector2 image3(50, 110);
	p3d::math::Vector2 image4(40, 16);

	commonLabels["Rise"] = new Label(340, 80, image3.getX(), image3.getY(), "Rise", sceneGDSU);
	commonLabels["RiseIndicator"] = new Label(333, 150, image4.getX(), image4.getY(), "RiseIndicator", sceneGDSU);

	updateOrientationLabels(0, 0);

	loadMainView();
}

void GDSU::loadMainView()
{
	clearLabels(viewLabels);

	p3d::math::Vector2 screen1(860, 560);

	p3d::math::Vector2 btn1(100, 20);
	p3d::math::Vector2 btn2(80, 15);
	p3d::math::Vector2 btn3(60, 20);

	viewLabels["Left_1"] = new Label(10, 40 + 90 * 0, btn1.getX(), btn1.getY(), "GDSU_LW", sceneGDSU);
	viewLabels["Left_2"] = new Label(10, 40 + 90 * 1, btn1.getX(), btn1.getY(), "GDSU_AP1_AP2", sceneGDSU);
	viewLabels["Left_3"] = new Label(10, 40 + 90 * 2, btn1.getX(), btn1.getY(), "GDSU_HT1_HT2", sceneGDSU);
	viewLabels["Left_4"] = new Label(10, 40 + 90 * 3, btn1.getX(), btn1.getY(), "GDSU_HE1_HE2", sceneGDSU);
	viewLabels["Left_5"] = new Label(10, 40 + 90 * 4, btn1.getX(), btn1.getY(), "GDSU_MG_SC", sceneGDSU);
	viewLabels["Left_6"] = new Label(10, 40 + 90 * 5, btn1.getX(), btn1.getY(), "GDSU_FLS_WP", sceneGDSU);

	viewLabels["Right_1"] = new Label(screen1.getX() - btn1.getX() - 10, 40 + 90 * 0, btn1.getX(), btn1.getY(), "GDSU_Gn_Cm_CLR", sceneGDSU);
	viewLabels["Right_2"] = new Label(screen1.getX() - btn1.getX(), 40 + 90 * 0 + 30, btn2.getX(), btn2.getY(), "GDSU_DayCam", sceneGDSU);
	viewLabels["Right_3"] = new Label(screen1.getX() - btn1.getX() - 10, 40 + 90 * 1, btn1.getX(), btn1.getY(), "GDSU_Gn_Cm", sceneGDSU);
	viewLabels["Right_4"] = new Label(screen1.getX() - btn1.getX(), 40 + 90 * 1 + 30, btn2.getX(), btn2.getY(), "GDSU_NightCam", sceneGDSU);
	viewLabels["Right_5"] = new Label(screen1.getX() - btn1.getX() - 10, 40 + 90 * 2, btn1.getX(), btn1.getY(), "GDSU_N_W_VW", sceneGDSU);
	viewLabels["Right_6"] = new Label(screen1.getX() - btn1.getX() - 10, 40 + 90 * 3, btn1.getX(), btn1.getY(), "GDSU_Zm_Rt_Fc_Ir", sceneGDSU);
	viewLabels["Right_7"] = new Label(screen1.getX() - btn1.getX() - 10, 40 + 90 * 4, btn1.getX(), btn1.getY(), "GDSU_+", sceneGDSU);
	viewLabels["Right_8"] = new Label(screen1.getX() - btn1.getX() - 10, 40 + 90 * 5, btn1.getX(), btn1.getY(), "GDSU_-", sceneGDSU);

	viewLabels["Dist_Value"] = new Label(60 + 80 * 0, 10, btn1.getX(), btn1.getY(), "GDSU_empty", sceneGDSU);
	viewLabels["Dist_System"] = new Label(100 + 80 * 1, 10, btn3.getX(), btn3.getY(), "GDSU_MAN", sceneGDSU);
	viewLabels["Nav_System"] = new Label(100 + 80 * 2, 10, btn3.getX(), btn3.getY(), { "GDSU_MSTG", "GDSU_STG", "GDSU_GTS" }, sceneGDSU);
	viewLabels["Test_State"] = new Label(100 + 80 * 3, 10, btn3.getX(), btn3.getY(), "GDSU_RDY", sceneGDSU);
	viewLabels["Top_5"] = new Label(100 + 80 * 4, 10, btn3.getX(), btn3.getY(), "GDSU_ARM", sceneGDSU);
	viewLabels["Top_6"] = new Label(100 + 80 * 5, 10, btn3.getX(), btn3.getY(), "GDSU_empty", sceneGDSU);
	viewLabels["Top_7"] = new Label(100 + 80 * 6, 10, btn3.getX(), btn3.getY(), "GDSU_empty", sceneGDSU);
	viewLabels["Gun_Type"] = new Label(100 + 80 * 7, 10, btn3.getX(), btn3.getY(), "GDSU_GUN", sceneGDSU);
	viewLabels["Top_9"] = new Label(100 + 80 * 8, 10, btn3.getX(), btn3.getY(), "GDSU_AP1", sceneGDSU);

	viewLabels["Bottom_1"] = new Label(250 + 120 * 0, screen1.getY() - btn1.getY() - 10, btn1.getX(), btn1.getY(), "GDSU_DATA", sceneGDSU);
	viewLabels["Bottom_2"] = new Label(250 + 120 * 1, screen1.getY() - btn1.getY() - 10, btn1.getX(), btn1.getY(), "GDSU_NEXT_FLT", sceneGDSU);
	viewLabels["Bottom_3"] = new Label(250 + 120 * 2, screen1.getY() - btn1.getY() - 10, btn1.getX(), btn1.getY(), "GDSU_Btl_Man", sceneGDSU);
	viewLabels["Bottom_4"] = new Label(250 + 120 * 3, screen1.getY() - btn1.getY() - 10, btn1.getX(), btn1.getY(), "GDSU_Fst_Last", sceneGDSU);
	viewLabels["Bottom_5"] = new Label(250 + 120 * 4, screen1.getY() - btn1.getY() - 10, btn1.getX(), btn1.getY(), "GDSU_NextAlt", sceneGDSU);

	// Disabled
	viewLabels["Left_5"]->setEnabled(false);
	viewLabels["Right_5"]->setEnabled(false);
	viewLabels["Right_6"]->setEnabled(false);
	viewLabels["Bottom_2"]->setEnabled(false);
	viewLabels["Bottom_4"]->setEnabled(false);
	viewLabels["Bottom_5"]->setEnabled(false);

	// NumLabels
	viewLabels["Dist_Value"]->addNumbers(10, sceneGDSU);
	viewLabels["Dist_Value"]->showNum(5473);

	viewLabels["Top_7"]->addNumbers(10, sceneGDSU);
	viewLabels["Top_7"]->showNum(9876);

	// OptionLabels
	viewLabels["Left_2"]->addOption(0, 50, 20, sceneGDSU);
	viewLabels["Left_2"]->addOption(50, 50, 20, sceneGDSU);
	viewLabels["Left_2"]->selectOption(1);

	viewLabels["Right_1"]->addOption(0, 30, 20, sceneGDSU);
	viewLabels["Right_1"]->addOption(30, 30, 20, sceneGDSU);
	viewLabels["Right_1"]->addOption(60, 40, 20, sceneGDSU);
	viewLabels["Right_1"]->selectOption(1);

	viewLabels["Bottom_3"]->addOption(0, 50, 20, sceneGDSU);
	viewLabels["Bottom_3"]->addOption(50, 50, 20, sceneGDSU);
	viewLabels["Bottom_3"]->selectOption(1);

	viewLabels["Right_6"]->addOption(0, 29, 20, sceneGDSU);
	viewLabels["Right_6"]->addOption(29, 24, 20, sceneGDSU);
	viewLabels["Right_6"]->addOption(29 + 24, 25, 20, sceneGDSU);
	viewLabels["Right_6"]->addOption(29 + 24 + 25, 23, 20, sceneGDSU);
	viewLabels["Right_6"]->selectOption(1);
}

GDSU::~GDSU()
{
	if (spriteRot)
		sceneGDSU->uninstallROIRotationAnimation(spriteRot);

	clearLabels(viewLabels);
	clearLabels(commonLabels);
}

void GDSU::clearLabels(std::map<std::string, Label*>& labels)
{
	for (auto& l : labels)
	{
		std::vector<p3d::Sprite*> sprites = l.second->getAllSprites();

		for (auto& s : sprites)
			sceneGDSU->uninstallSprite(s);
	}
	labels.clear();
}

Label* GDSU::getLabel(const std::string& labelName) const
{
	if (commonLabels.find(labelName) != commonLabels.end())
		return commonLabels.at(labelName);

	if (viewLabels.find(labelName) != viewLabels.end())
		return viewLabels.at(labelName);

	return nullptr;
}

void GDSU::addGDSURotation(p3d::Sprite* sprite)
{
	spriteRot = sceneGDSU->installROIRotationAnimationOnSprite(sprite, 0.0);
	spriteRot->start();
}

void GDSU::updateConfig(IMemberConfig config)
{
	Label* navSystem = getLabel("Nav_System");
	if (navSystem)
	{
		switch (config.nav)
		{
			case MSTG: navSystem->changeBackground("GDSU_MSTG"); break;
			case STG: navSystem->changeBackground("GDSU_STG"); break;
			case GTS: navSystem->changeBackground("GDSU_GTS"); break;
		}
	}
}

void GDSU::updateOrientationLabels(float drift, float rise)
{
	spriteRot->setFreeRotationVelocity(-drift);

	Label* labelRise = commonLabels["Rise"];
	Label* labelRiseIndicator = commonLabels["RiseIndicator"];

	totalRise += rise * 20;
	totalRise = std::clamp(totalRise, -labelRise->h / 2, labelRise->h / 4);
	labelRiseIndicator->getBackground()->setFramePosition(labelRiseIndicator->x, labelRiseIndicator->y + totalRise);
}

Label::Label(int x, int y, int w, int h, std::string res, p3d::Scene2D* sceneGDSU) :
	x(x), y(y), w(w), h(h)
{
	auto& resources = LocalResourceManager::getInstance().resources;
	
	background[""] = sceneGDSU->installSprite(x + w/2, y + h/2, w, h, resources[res]);
	disableSprite = sceneGDSU->installSprite(x + w/2, y + h/2, w, h, resources["DisabledLabel"]);
	disableSprite->hide();
}

Label::Label(int x, int y, int w, int h, std::vector<std::string> res, p3d::Scene2D* sceneGDSU) :
	x(x), y(y), w(w), h(h)
{
	auto& resources = LocalResourceManager::getInstance().resources;
	
	for (auto& r : res)
	{
		background[r] = sceneGDSU->installSprite(x + w / 2, y + h / 2, w, h, resources[r]);
		if (background.size() == 1)
		{
			background[r]->show();
			currentBackground = r;
		}
		else
		{
			background[r]->hide();
		}
	}

	disableSprite = sceneGDSU->installSprite(x + w / 2, y + h / 2, w, h, resources["DisabledLabel"]);
	disableSprite->hide();
}

std::vector<p3d::Sprite*> Label::getAllSprites() const
{
	std::vector<p3d::Sprite*> allSprites;
	for (auto& b : background)
		allSprites.push_back(b.second);

	if (disableSprite)
		allSprites.push_back(disableSprite);

	for (auto& s : numberSprites)
		allSprites.push_back(s);

	for (auto& s : selectionSprites)
		allSprites.push_back(s);

	return allSprites;
}

p3d::Sprite* Label::getBackground(const std::string& res) const
{
	if (background.find(res) != background.end())
		return background.at(res);

	return nullptr;
}

void Label::changeBackground(const std::string& res)
{
	for (auto& b : background)
	{
		if (b.first == res)
		{
			b.second->show();
			currentBackground = res;
		}
		else
		{
			b.second->hide();
		}
	}
}

void Label::setVisible(bool visible)
{
	std::vector<p3d::Sprite*> sprites = getAllSprites();
	for (auto& s : sprites)
		visible ? s->show() : s->hide();
}

void Label::setEnabled(bool enable)
{
	enable ? disableSprite->hide() : disableSprite->show();
	this->enabled = enable;
}

void Label::addOption(float offX, int w, int h, p3d::Scene2D* sceneGDSU)
{
	auto& resources = LocalResourceManager::getInstance().resources;

	p3d::Sprite* s = sceneGDSU->installSprite(x + offX + w/2, y + h/2, w, h, resources["SelectedLabel"]);
	s->hide();
	selectionSprites.push_back(s);
}

void Label::selectOption(unsigned int index)
{
	for (int i = 0; i < selectionSprites.size(); ++i)
		i == index ? selectionSprites[i]->show() : selectionSprites[i]->hide();
}

void Label::addNumbers(float offX, p3d::Scene2D* sceneGDSU)
{
	auto& resources = LocalResourceManager::getInstance().resources;

	int wNum = 14;
	int hNum = 14;

	for (int i = 0; i < 4; ++i)
	{
		p3d::Sprite* num = sceneGDSU->installSprite(wNum / 2 + x + offX * i + 3, hNum / 2 + y + 3, wNum, hNum, resources["Numbers"]);
		num->changeROISize(wNum, hNum);
		num->setROIPosition(7, 0 * (14 + 10) + 7);
		numberSprites.push_back(num);
	}
}

void Label::showNum(unsigned int num)
{
	for (int i = numberSprites.size() - 1; i >= 0; --i)
	{
		int digit = num % 10;
		num /= 10;
		numberSprites[i]->setROIPosition(7, digit * (14 + 10) + 7);
	}
}
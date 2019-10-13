#include <TAM2C/Include/GDSU.h>

#include <math/Include/Vector4.h>

#include <TAM2C/Include/LocalResourceManager.h>

GDSU::GDSU(p3d::Scene2D* sceneGDSU):
	sceneGDSU(sceneGDSU)
{
	auto& resources = LocalResourceManager::getInstance().resources;

	p3d::math::Vector2 screen1(860, 560);

	new Label(0, 0, screen1.getX(), screen1.getY(), "GDSU_periscope", this);

	p3d::math::Vector2 image1(70, 104);
	p3d::math::Vector2 image2(300, 300);

	new Label(210, 80, image1.getX(), image1.getY(), "Cabin", this);
	new Label(95, 0, image2.getX(), image2.getY(), "CabinAt", this);

	p3d::math::Vector2 btn1(100, 20);
	p3d::math::Vector2 btn2(80, 15);
	p3d::math::Vector2 btn3(60, 20);

	new Label(10, 40 + 90 * 0, btn1.getX(), btn1.getY(), "GDSU_LW", this);
	new Label(10, 40 + 90 * 1, btn1.getX(), btn1.getY(), "GDSU_AP1_AP2", this);
	new Label(10, 40 + 90 * 2, btn1.getX(), btn1.getY(), "GDSU_HT1_HT2", this);
	new Label(10, 40 + 90 * 3, btn1.getX(), btn1.getY(), "GDSU_HE1_HE2", this);
	new Label(10, 40 + 90 * 4, btn1.getX(), btn1.getY(), "GDSU_MG_SC", this);
	new Label(10, 40 + 90 * 5, btn1.getX(), btn1.getY(), "GDSU_FLS_WP", this);

	new Label(screen1.getX() - btn1.getX() - 10, 40 + 90 * 0, btn1.getX(), btn1.getY(), "GDSU_Gn_Cm_CLR", this);
	new Label(screen1.getX() - btn1.getX(), 40 + 90 * 0 + 30, btn2.getX(), btn2.getY(), "GDSU_DayCam", this);
	new Label(screen1.getX() - btn1.getX() - 10, 40 + 90 * 1, btn1.getX(), btn1.getY(), "GDSU_Gn_Cm", this);
	new Label(screen1.getX() - btn1.getX(), 40 + 90 * 1 + 30, btn2.getX(), btn2.getY(), "GDSU_NightCam", this);
	new Label(screen1.getX() - btn1.getX() - 10, 40 + 90 * 2, btn1.getX(), btn1.getY(), "GDSU_N_W_VW", this);
	new Label(screen1.getX() - btn1.getX() - 10, 40 + 90 * 3, btn1.getX(), btn1.getY(), "GDSU_Zm_Rt_Fc_Ir", this);
	new Label(screen1.getX() - btn1.getX() - 10, 40 + 90 * 4, btn1.getX(), btn1.getY(), "GDSU_+", this);
	new Label(screen1.getX() - btn1.getX() - 10, 40 + 90 * 5, btn1.getX(), btn1.getY(), "GDSU_-", this);

	new Label(60 + 80 * 0, 10, btn1.getX(), btn1.getY(), "GDSU_2114", this, "GDSU_empty");
	new Label(100 + 80 * 1, 10, btn3.getX(), btn3.getY(), "GDSU_MAN", this);
	new Label(100 + 80 * 2, 10, btn3.getX(), btn3.getY(), "GDSU_MSTG", this);
	new Label(100 + 80 * 3, 10, btn3.getX(), btn3.getY(), "GDSU_RDY", this);
	new Label(100 + 80 * 4, 10, btn3.getX(), btn3.getY(), "GDSU_ARM", this);
	new Label(100 + 80 * 5, 10, btn3.getX(), btn3.getY(), "GDSU_empty", this);
	new Label(100 + 80 * 6, 10, btn3.getX(), btn3.getY(), "GDSU_5567", this, "GDSU_empty");
	new Label(100 + 80 * 7, 10, btn3.getX(), btn3.getY(), "GDSU_GUN", this);
	new Label(100 + 80 * 8, 10, btn3.getX(), btn3.getY(), "GDSU_AP1", this);

	new Label(250 + 120 * 0, screen1.getY() - btn1.getY() - 10, btn1.getX(), btn1.getY(), "GDSU_DATA", this);
	new Label(250 + 120 * 1, screen1.getY() - btn1.getY() - 10, btn1.getX(), btn1.getY(), "GDSU_NEXT_FLT", this);
	new Label(250 + 120 * 2, screen1.getY() - btn1.getY() - 10, btn1.getX(), btn1.getY(), "GDSU_Btl_Man", this);
	new Label(250 + 120 * 3, screen1.getY() - btn1.getY() - 10, btn1.getX(), btn1.getY(), "GDSU_Fst_Last", this);
	new Label(250 + 120 * 4, screen1.getY() - btn1.getY() - 10, btn1.getX(), btn1.getY(), "GDSU_NextAlt", this);

	// Disabled
	labels["GDSU_MG_SC"]->setEnabled(false);
	labels["GDSU_N_W_VW"]->setEnabled(false);
	labels["GDSU_Zm_Rt_Fc_Ir"]->setEnabled(false);
	labels["GDSU_NEXT_FLT"]->setEnabled(false);
	labels["GDSU_Fst_Last"]->setEnabled(false);
	labels["GDSU_NextAlt"]->setEnabled(false);

	// Rotation
	p3d::Sprite* at = labels["CabinAt"]->background;
	at->setROIPosition(150, 150);
	addGDSURotation(at);

	// NumLabels
	labels["GDSU_2114"]->addNumbers(10, this);
	labels["GDSU_2114"]->showNum(5473);

	labels["GDSU_5567"]->addNumbers(10, this);
	labels["GDSU_5567"]->showNum(9876);

	// OptionLabels
	labels["GDSU_AP1_AP2"]->addOption(0, 50, 20, this);
	labels["GDSU_AP1_AP2"]->addOption(50, 50, 20, this);
	labels["GDSU_AP1_AP2"]->selectOption(1);

	labels["GDSU_Gn_Cm_CLR"]->addOption(0, 30, 20, this);
	labels["GDSU_Gn_Cm_CLR"]->addOption(30, 30, 20, this);
	labels["GDSU_Gn_Cm_CLR"]->addOption(60, 40, 20, this);
	labels["GDSU_Gn_Cm_CLR"]->selectOption(1);

	labels["GDSU_Btl_Man"]->addOption(0, 50, 20, this);
	labels["GDSU_Btl_Man"]->addOption(50, 50, 20, this);
	labels["GDSU_Btl_Man"]->selectOption(1);

	labels["GDSU_Zm_Rt_Fc_Ir"]->addOption(0, 29, 20, this);
	labels["GDSU_Zm_Rt_Fc_Ir"]->addOption(29, 24, 20, this);
	labels["GDSU_Zm_Rt_Fc_Ir"]->addOption(29 + 24, 25, 20, this);
	labels["GDSU_Zm_Rt_Fc_Ir"]->addOption(29 + 24 + 25, 23, 20, this);
	labels["GDSU_Zm_Rt_Fc_Ir"]->selectOption(1);
}

GDSU::~GDSU()
{
	if (spriteRot)
		sceneGDSU->uninstallROIRotationAnimation(spriteRot);

	for (auto& l : labels)
	{
		if (l.second->background)
			sceneGDSU->uninstallSprite(l.second->background);

		if (l.second->disableSprite)
			sceneGDSU->uninstallSprite(l.second->disableSprite);

		for(auto& s : l.second->numberSprites)
			sceneGDSU->uninstallSprite(s);

		for (auto& s : l.second->selectionSprites)
			sceneGDSU->uninstallSprite(s);
	}
	labels.clear();
}

void GDSU::addGDSURotation(p3d::Sprite* sprite)
{
	spriteRot = sceneGDSU->installROIRotationAnimationOnSprite(sprite, 0.0);
	spriteRot->start();
}

Label::Label(int x, int y, int w, int h, std::string labelName, GDSU* gdsu, std::string resource) :
	x(x), y(y), w(w), h(h)
{
	auto& resources = LocalResourceManager::getInstance().resources;

	if (resource.empty())
		resource = labelName;

	background = gdsu->sceneGDSU->installSprite(x + w/2, y + h/2, w, h, resources[resource]);
	disableSprite = gdsu->sceneGDSU->installSprite(x + w/2, y + h/2, w, h, resources["DisabledLabel"]);
	disableSprite->hide();

	gdsu->labels[labelName] = this;
}

std::vector<p3d::Sprite*> Label::getAllSprites() const
{
	std::vector<p3d::Sprite*> allSprites;
	if (background)
		allSprites.push_back(background);

	if (disableSprite)
		allSprites.push_back(disableSprite);

	for (auto& s : numberSprites)
		allSprites.push_back(s);

	for (auto& s : selectionSprites)
		allSprites.push_back(s);

	return allSprites;
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

void Label::addOption(float offX, int w, int h, GDSU* gdsu)
{
	auto& resources = LocalResourceManager::getInstance().resources;

	p3d::Sprite* s = gdsu->sceneGDSU->installSprite(x + offX + w/2, y + h/2, w, h, resources["SelectedLabel"]);
	s->hide();
	selectionSprites.push_back(s);
}

void Label::selectOption(unsigned int index)
{
	for (int i = 0; i < selectionSprites.size(); ++i)
		i == index ? selectionSprites[i]->show() : selectionSprites[i]->hide();
}

void Label::addNumbers(float offX, GDSU* gdsu)
{
	auto& resources = LocalResourceManager::getInstance().resources;

	int wNum = 14;
	int hNum = 14;

	for (int i = 0; i < 4; ++i)
	{
		p3d::Sprite* num = gdsu->sceneGDSU->installSprite(wNum / 2 + x + offX * i + 3, hNum / 2 + y + 3, wNum, hNum, resources["Numbers"]);
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
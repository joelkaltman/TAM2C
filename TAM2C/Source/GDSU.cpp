#include <TAM2C/Include/GDSU.h>

#include <math/Include/Vector4.h>

#include <TAM2C/Include/LocalResourceManager.h>

GDSU::GDSU(p3d::Scene2D* sceneGDSU):
	sceneGDSU(sceneGDSU)
{
	auto& resources = LocalResourceManager::getInstance().resources;

	p3d::math::Vector4 screen1(860 / 2, 560 / 2, 860, 560);

	sprites["GDSU_periscope"] = sceneGDSU->installSprite(screen1.getX(), screen1.getY(), screen1.getZ(), screen1.getW(), resources["GDSU_periscope"]);

	p3d::math::Vector4 image1(70 / 2, 104 / 2, 70, 104);
	p3d::math::Vector4 image2(300 / 2, 300 / 2, 300, 300);

	sprites["Cabin"] = sceneGDSU->installSprite(image1.getX() + 210, image1.getY() + 80, image1.getZ(), image1.getW(), resources["Cabin"]);
	p3d::Sprite* at = sceneGDSU->installSprite(image1.getX() + 210, image1.getY() + 80, image2.getZ(), image2.getW(), resources["CabinAt"]);

	at->setROIPosition(150, 150);
	addGDSURotation(at);

	sprites["CabinAt"] = at;

	p3d::math::Vector4 btn1(100 / 2, 20 / 2, 100, 20);
	p3d::math::Vector4 btn2(80 / 2, 15 / 2, 80, 15);
	p3d::math::Vector4 btn3(60 / 2, 20 / 2, 60, 20);

	sprites["GDSU_LW"] = sceneGDSU->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 0, btn1.getZ(), btn1.getW(), resources["GDSU_LW"]);
	sprites["GDSU_AP1_AP2"] = sceneGDSU->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 1, btn1.getZ(), btn1.getW(), resources["GDSU_AP1_AP2"]);
	sprites["GDSU_HT1_HT2"] = sceneGDSU->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 2, btn1.getZ(), btn1.getW(), resources["GDSU_HT1_HT2"]);
	sprites["GDSU_HE1_HE2"] = sceneGDSU->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 3, btn1.getZ(), btn1.getW(), resources["GDSU_HE1_HE2"]);
	sprites["GDSU_MG_SC"] = sceneGDSU->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 4, btn1.getZ(), btn1.getW(), resources["GDSU_MG_SC"]);
	sprites["GDSU_FLS_WP"] = sceneGDSU->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 5, btn1.getZ(), btn1.getW(), resources["GDSU_FLS_WP"]);

	std::vector<p3d::math::Vector4> ap1ap2Sel;
	ap1ap2Sel.push_back(p3d::math::Vector4(btn1.getX() / 2 + 10, btn1.getY() + 40 + 90 * 1, btn1.getZ() / 2, btn1.getW()));
	ap1ap2Sel.push_back(p3d::math::Vector4(btn1.getX() / 2 + 10 + btn1.getX(), btn1.getY() + 40 + 90 * 1, btn1.getZ() / 2, btn1.getW()));
	optionLabels["GDSU_AP1_AP2"] = new OptionLabel(ap1ap2Sel, "GDSU_AP1_AP2", this);
	optionLabels["GDSU_AP1_AP2"]->select(1);

	sprites["GDSU_Gn_Cm_CLR"] = sceneGDSU->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 0, btn1.getZ(), btn1.getW(), resources["GDSU_Gn_Cm_CLR"]);
	sprites["GDSU_DayCam"] = sceneGDSU->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ(), btn1.getY() + 40 + 90 * 0 + 20, btn2.getZ(), btn2.getW(), resources["GDSU_DayCam"]);
	sprites["GDSU_Gn_Cm"] = sceneGDSU->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 1, btn1.getZ(), btn1.getW(), resources["GDSU_Gn_Cm"]);
	sprites["GDSU_NightCam"] = sceneGDSU->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ(), btn1.getY() + 40 + 90 * 1 + 20, btn2.getZ(), btn2.getW(), resources["GDSU_NightCam"]);
	sprites["GDSU_N_W_VW"] = sceneGDSU->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 2, btn1.getZ(), btn1.getW(), resources["GDSU_N_W_VW"]);
	sprites["GDSU_Zm_Rt_Fc_Ir"] = sceneGDSU->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 3, btn1.getZ(), btn1.getW(), resources["GDSU_Zm_Rt_Fc_Ir"]);
	sprites["GDSU_+"] = sceneGDSU->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 4, btn1.getZ(), btn1.getW(), resources["GDSU_+"]);
	sprites["GDSU_-"] = sceneGDSU->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 5, btn1.getZ(), btn1.getW(), resources["GDSU_-"]);

	sprites["GDSU_2114"] = sceneGDSU->installSprite(btn1.getX() + 60 + 80 * 0, btn1.getY() + 10, btn1.getZ(), btn1.getW(), resources["GDSU_empty"]);
	sprites["GDSU_MAN"] = sceneGDSU->installSprite(btn3.getX() + 100 + 80 * 1, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_MAN"]);
	sprites["GDSU_MSTG"] = sceneGDSU->installSprite(btn3.getX() + 100 + 80 * 2, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_MSTG"]);
	sprites["GDSU_RDY"] = sceneGDSU->installSprite(btn3.getX() + 100 + 80 * 3, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_RDY"]);
	sprites["GDSU_ARM"] = sceneGDSU->installSprite(btn3.getX() + 100 + 80 * 4, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_ARM"]);
	sprites["GDSU_empty"] = sceneGDSU->installSprite(btn3.getX() + 100 + 80 * 5, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_empty"]);
	sprites["GDSU_5567"] = sceneGDSU->installSprite(btn3.getX() + 100 + 80 * 6, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_empty"]);
	sprites["GDSU_GUN"] = sceneGDSU->installSprite(btn3.getX() + 100 + 80 * 7, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_GUN"]);
	sprites["GDSU_AP1"] = sceneGDSU->installSprite(btn3.getX() + 100 + 80 * 8, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_AP1"]);

	numLabels["GDSU_2114"] = new NumLabel(60, 10, 10, "GDSU_2114", this);
	numLabels["GDSU_2114"]->showNum(5473);

	numLabels["GDSU_5567"] = new NumLabel(100 + 80 * 6, 10, 10, "GDSU_5567", this);
	numLabels["GDSU_5567"]->showNum(9876);

	sprites["GDSU_DATA"] = sceneGDSU->installSprite(btn1.getX() + 250 + 120 * 0, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_DATA"]);
	sprites["GDSU_NEXT_FLT"] = sceneGDSU->installSprite(btn1.getX() + 250 + 120 * 1, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_NEXT_FLT"]);
	sprites["GDSU_Btl_Man"] = sceneGDSU->installSprite(btn1.getX() + 250 + 120 * 2, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_Btl_Man"]);
	sprites["GDSU_Fst_Last"] = sceneGDSU->installSprite(btn1.getX() + 250 + 120 * 3, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_Fst_Last"]);
	sprites["GDSU_NextAlt"] = sceneGDSU->installSprite(btn1.getX() + 250 + 120 * 4, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_NextAlt"]);
}

void GDSU::addGDSURotation(p3d::Sprite* sprite)
{
	spriteRot = sceneGDSU->installROIRotationAnimationOnSprite(sprite, 0.0);
	spriteRot->start();
}


NumLabel::NumLabel(int posX, int posY, int offX, std::string labelName, GDSU* gdsu)
{
	auto& resources = LocalResourceManager::getInstance().resources;

	p3d::math::Vector4 num(14 / 2, 14 / 2, 14, 14);

	for (int i = 0; i < 4; ++i)
	{
		numbers[i] = gdsu->sceneGDSU->installSprite(num.getX() + posX + offX * i + 3, num.getY() + posY + 3, num.getZ(), num.getW(), resources["Numbers"]);
		numbers[i]->changeROISize(14, 14);
		numbers[i]->setROIPosition(7, 0 * (14 + 10) + 7);
		
		gdsu->sprites[labelName + "_num_" + std::to_string(i)] = numbers[i];
	}
}

void NumLabel::showNum(unsigned int num)
{
	if (num > 9999)
		std::cout << "ERROR trying to show number with more than 4 digits in GDSU label" << std::endl;

	for (int i = 3; i >= 0; --i)
	{
		int digit = num % 10;
		num /= 10;
		numbers[i]->setROIPosition(7, digit * (14 + 10) + 7);
	}
}

OptionLabel::OptionLabel(std::vector<p3d::math::Vector4> prop, std::string labelName, GDSU* gdsu)
{
	auto& resources = LocalResourceManager::getInstance().resources;

	for (int i = 0; i < prop.size(); ++i)
	{
		p3d::Sprite* s = gdsu->sceneGDSU->installSprite(prop[i].getX(), prop[i].getY(), prop[i].getZ(), prop[i].getW(), resources["SelectedLabel"]);
		s->hide();
		selectionSprites.push_back(s);

		gdsu->sprites[labelName + "_opt_" + std::to_string(i)] = s;
	}
}

void OptionLabel::select(unsigned int index)
{
	for (int i = 0; i < selectionSprites.size(); ++i)
		i == index ? selectionSprites[i]->show() : selectionSprites[i]->hide();
}
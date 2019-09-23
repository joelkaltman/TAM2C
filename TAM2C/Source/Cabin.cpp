#include <TAM2C/Include/Cabin.h>

// p3d
#include <p3d/Include/P3D.h>
#include <p3d/Include/Scene3d.h>
#include <p3d/Include/Scene2D.h>
#include <p3d/Include/Camera.h>
#include <p3d/Include/Window.h>
#include <p3d/Include/Resource.h>
#include <p3d/Include/Context.h>

Cabin::Cabin()
{
	members[AP].joystick = 0;
	members[JTAN].joystick = 1;
}

p3d::Camera* Cabin::getCamera(ID id) const
{
	if (members.find(id) != members.end())
		return members.at(id).camera;

	return nullptr;
}

void Cabin::createCamera(ID id, p3d::Scene3D* scene)
{
	members[id].camera = scene->installCamera("cameraAP", 5000.0, 5000.0, 10, 5001, 5001, 10, 0, 0, 1);

	uint32_t winId;
	if (id == AP)
	{
		uiAp.show();
		winId = uiAp.getPGSWidget()->winId();
	}
	else if (id == JTAN)
	{
		uiJtan.show();
		winId = uiJtan.getPGSWidget()->winId();
	}

	p3d::P3D* p3d = p3d::P3D::getInstance();
	members[id].window = p3d->createWindow(winId);
	members[id].window->showCamera(members[id].camera);
}

void Cabin::createGDSU(ID id, p3d::Context* context, std::map<std::string, p3d::Resource*> resources)
{
	p3d::Scene2D* scene = context->createScene2D();

	p3d::math::Vector4 screen1(860 / 2, 560 / 2, 860, 560);

	members[id].sprites["GDSU_periscope"] = scene->installSprite(screen1.getX(), screen1.getY(), screen1.getZ(), screen1.getW(), resources["GDSU_periscope"]);

	p3d::math::Vector4 image1(70 / 2, 104 / 2, 70, 104);
	p3d::math::Vector4 image2(2 / 2, 160 / 2, 2, 160);

	members[id].sprites["Cabin"] = scene->installSprite(image1.getX() + 210, image1.getY() + 80, image1.getZ(), image1.getW(), resources["Cabin"]);
	members[id].sprites["CabinAt"] = scene->installSprite(image2.getX() + image1.getX() + 210, image2.getY() + 110, image2.getZ(), image2.getW(), resources["CabinAt"]);

	p3d::math::Vector4 btn1(100 / 2, 20 / 2, 100, 20);
	p3d::math::Vector4 btn2(80 / 2, 15 / 2, 80, 15);
	p3d::math::Vector4 btn3(60 / 2, 20 / 2, 60, 20);

	members[id].sprites["GDSU_LW"] = scene->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 0, btn1.getZ(), btn1.getW(), resources["GDSU_LW"]);
	members[id].sprites["GDSU_AP1_AP2"] = scene->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 1, btn1.getZ(), btn1.getW(), resources["GDSU_AP1_AP2"]);
	members[id].sprites["GDSU_HT1_HT2"] = scene->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 2, btn1.getZ(), btn1.getW(), resources["GDSU_HT1_HT2"]);
	members[id].sprites["GDSU_HE1_HE2"] = scene->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 3, btn1.getZ(), btn1.getW(), resources["GDSU_HE1_HE2"]);
	members[id].sprites["GDSU_MG_SC"] =	scene->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 4, btn1.getZ(), btn1.getW(), resources["GDSU_MG_SC"]);
	members[id].sprites["GDSU_FLS_WP"] = scene->installSprite(btn1.getX() + 10, btn1.getY() + 40 + 90 * 5, btn1.getZ(), btn1.getW(), resources["GDSU_FLS_WP"]);

	members[id].sprites["GDSU_Gn_Cm_CLR"] =	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 0, btn1.getZ(), btn1.getW(), resources["GDSU_Gn_Cm_CLR"]);
	members[id].sprites["GDSU_DayCam"] = scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ(), btn1.getY() + 40 + 90 * 0 + 20, btn2.getZ(), btn2.getW(), resources["GDSU_DayCam"]);
	members[id].sprites["GDSU_Gn_Cm"] =	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 1, btn1.getZ(), btn1.getW(), resources["GDSU_Gn_Cm"]);
	members[id].sprites["GDSU_NightCam"] = scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ(), btn1.getY() + 40 + 90 * 1 + 20, btn2.getZ(), btn2.getW(), resources["GDSU_NightCam"]);
	members[id].sprites["GDSU_N_W_VW"] = scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 2, btn1.getZ(), btn1.getW(), resources["GDSU_N_W_VW"]);
	members[id].sprites["GDSU_Zm_Rt_Fc_Ir"] = scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 3, btn1.getZ(), btn1.getW(), resources["GDSU_Zm_Rt_Fc_Ir"]);
	members[id].sprites["GDSU_+"] =	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 4, btn1.getZ(), btn1.getW(), resources["GDSU_+"]);
	members[id].sprites["GDSU_-"] =	scene->installSprite(btn1.getX() + screen1.getZ() - btn1.getZ() - 10, btn1.getY() + 40 + 90 * 5, btn1.getZ(), btn1.getW(), resources["GDSU_-"]);

	members[id].sprites["GDSU_2114"] = scene->installSprite(btn1.getX() + 60 + 80 * 0, btn1.getY() + 10, btn1.getZ(), btn1.getW(), resources["GDSU_2114"]);
	members[id].sprites["GDSU_MAN"] = scene->installSprite(btn3.getX() + 100 + 80 * 1, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_MAN"]);
	members[id].sprites["GDSU_MSTG"] = scene->installSprite(btn3.getX() + 100 + 80 * 2, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_MSTG"]);
	members[id].sprites["GDSU_RDY"] = scene->installSprite(btn3.getX() + 100 + 80 * 3, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_RDY"]);
	members[id].sprites["GDSU_ARM"] = scene->installSprite(btn3.getX() + 100 + 80 * 4, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_ARM"]);
	members[id].sprites["GDSU_empty"] = scene->installSprite(btn3.getX() + 100 + 80 * 5, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_empty"]);
	members[id].sprites["GDSU_5567"] = scene->installSprite(btn3.getX() + 100 + 80 * 6, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_5567"]);
	members[id].sprites["GDSU_GUN"] = scene->installSprite(btn3.getX() + 100 + 80 * 7, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_GUN"]);
	members[id].sprites["GDSU_AP1"] = scene->installSprite(btn3.getX() + 100 + 80 * 8, btn3.getY() + 10, btn3.getZ(), btn3.getW(), resources["GDSU_AP1"]);

	members[id].sprites["GDSU_DATA"] = scene->installSprite(btn1.getX() + 250 + 120 * 0, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_DATA"]);
	members[id].sprites["GDSU_NEXT_FLT"] = scene->installSprite(btn1.getX() + 250 + 120 * 1, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_NEXT_FLT"]);
	members[id].sprites["GDSU_Btl_Man"] = scene->installSprite(btn1.getX() + 250 + 120 * 2, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_Btl_Man"]);
	members[id].sprites["GDSU_Fst_Last"] = scene->installSprite(btn1.getX() + 250 + 120 * 3, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_Fst_Last"]);
	members[id].sprites["GDSU_NextAlt"] = scene->installSprite(btn1.getX() + 250 + 120 * 4, btn1.getY() + screen1.getW() - btn1.getW() - 10, btn1.getZ(), btn1.getW(), resources["GDSU_NextAlt"]);

	members[id].window->showScene2D(scene, 860 / 2, 560 / 2, 1, 860, 560);
}

void Cabin::axisModified(int id, float deriva, float alza)
{
	ID mId = INVALID;

	for (auto& m : members)
	{
		if (m.second.joystick == id)
			mId = m.first;
	}

	if (mId == INVALID)
		return;

	// deriva
	members[mId].camera->rotate(deriva, 0, 0, 1);

	// alza
	double x, y, z, atx, aty, atz, upx, upy, upz;
	members[mId].camera->getPose(&x, &y, &z, &atx, &aty, &atz, &upx, &upy, &upz);

	p3d::math::Vector3 res = p3d::math::Vector3::cross(p3d::math::Vector3(atx - x, aty - y, 0), p3d::math::Vector3(0, 0, 1));

	float dz = atz - z;
	if ((alza > 0 && dz < 1) || (alza < 0 && dz > -1))
	{
		members[mId].camera->rotate(alza, res.getX(), res.getY(), 0);
	}

	// sprite
	members[mId].sprites["CabinAt"]->rotateFrame(deriva);

}
#pragma once

enum GENERAL_SYSTEM
{
	GENERAL_OFF,
	GENERAL_BIT,
	GENERAL_READY
};

enum NAV_SYSTEM
{
	MSTG,
	STG,
	GTS
};

enum GUN_SYSTEM
{
	GUN,
	MGUN
};

enum AMMO
{
	AP1,
	AP2,
	HP1,
	HP2,
	HE1,
	HE2
};

enum VISION
{
	DAYCAM,
	NIGHTCAM
};

enum ZOOM
{
	N,
	W,
	VW
};

enum SCREEN
{
	ZM,
	RT,
	FC,
	IR
};

struct IMemberConfig
{
	GENERAL_SYSTEM general =	GENERAL_OFF;
	NAV_SYSTEM nav =			MSTG;
	GUN_SYSTEM gun =			GUN;
	AMMO ammo =					AP1;
	VISION vision =				DAYCAM;
	ZOOM zoom =					N;
	SCREEN screen =				RT;
};
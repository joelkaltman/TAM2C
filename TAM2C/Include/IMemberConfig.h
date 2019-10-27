#pragma once

enum GENERAL_SYSTEM
{
	GENERAL_OFF,
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

struct IMemberConfig
{
	GENERAL_SYSTEM general =	GENERAL_OFF;
	NAV_SYSTEM nav =			MSTG;
	GUN_SYSTEM gun =			MGUN;
	AMMO ammo =					AP1;
};
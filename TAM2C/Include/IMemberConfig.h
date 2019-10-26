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

struct IMemberConfig
{
	unsigned int lastChange =	0;
	GENERAL_SYSTEM general =	GENERAL_OFF;
	NAV_SYSTEM nav =			MSTG;
	GUN_SYSTEM gun =			MGUN;
};
#pragma once

#include <vector>
#include <string>

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


namespace MemberConfig
{
	static std::string generalToString(GENERAL_SYSTEM id)
	{
		std::vector<std::string> strings =
		{
			"OFF",
			"OFF",
			"READY"
		};
		return strings[id];
	}

	static std::string navToString(NAV_SYSTEM id)
	{
		std::vector<std::string> strings =
		{
			"MSTG",
			"STG",
			"GTS"
		};
		return strings[id];
	}

	static std::string gunToString(GUN_SYSTEM id)
	{
		std::vector<std::string> strings =
		{
			"GUN",
			"MGUN"
		};
		return strings[id];
	}

	static std::string ammoToString(AMMO id)
	{
		std::vector<std::string> strings =
		{
			"AP1",
			"AP2",
			"HP1",
			"HP2",
			"HE1",
			"HE2"
		};
		return strings[id];
	}

	static std::string visionToString(VISION id)
	{
		std::vector<std::string> strings =
		{
			"DAYCAM",
			"NIGHTCAM"
		};
		return strings[id];
	}

	static std::string zoomToString(ZOOM id)
	{
		std::vector<std::string> strings =
		{
			"N",
			"W",
			"VW"
		};
		return strings[id];
	}

	static std::string screenToString(SCREEN id)
	{
		std::vector<std::string> strings =
		{
			"ZM",
			"RT",
			"FC",
			"IR"
		};
		return strings[id];
	}
}
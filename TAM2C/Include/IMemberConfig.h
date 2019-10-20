#pragma once

enum NAV_SYSTEM
{
	MSTG,
	STG,
	GTS
};

struct IMemberConfig
{
	NAV_SYSTEM nav = MSTG;
};
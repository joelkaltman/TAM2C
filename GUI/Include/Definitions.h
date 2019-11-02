#pragma once

#include <string>

enum ELEM_TYPE
{
	BUTTON,
	SWITCH,
	LED,
	INVALID
};

enum ELEM_ID
{
	GDSU_SWITCH_1,
	GDSU_BUTTON_LEFT_1,
	GDSU_BUTTON_LEFT_2,
	GDSU_BUTTON_LEFT_3,
	GDSU_BUTTON_LEFT_4,
	GDSU_BUTTON_LEFT_5,
	GDSU_BUTTON_LEFT_6,
	GDSU_BUTTON_RIGHT_1,
	GDSU_BUTTON_RIGHT_2,
	GDSU_BUTTON_RIGHT_3,
	GDSU_BUTTON_RIGHT_4,
	GDSU_BUTTON_RIGHT_5,
	GDSU_BUTTON_RIGHT_6,
	GDSU_BUTTON_BOTTOM_1,
	GDSU_BUTTON_BOTTOM_2,
	GDSU_BUTTON_BOTTOM_3,
	GDSU_BUTTON_BOTTOM_4,
	GDSU_BUTTON_BOTTOM_5,
	GDSU_BUTTON_BOTTOM_6,
	GDSU_BUTTON_BOTTOM_7,
	GDSU_BUTTON_MINUS,
	GDSU_BUTTON_PLUS,
	GDSU_BUTTON_CIRCLE,

	AP_P1_SWITCH_1,
	AP_P1_SWITCH_2,
	AP_P1_SWITCH_3,
	AP_P1_BUTTON_1,
	AP_P1_LED_1,

	AP_P2_SWITCH_1,
	AP_P2_SWITCH_2,
	AP_P2_SWITCH_3,
	AP_P2_SWITCH_4,
	AP_P2_LED_1,
	AP_P2_LED_2,
	AP_P2_LED_3,
	AP_P2_LED_4,
	AP_P2_LED_5,
	AP_P2_LED_6,
	AP_P2_LED_7,
	AP_P2_LED_8,
	AP_P2_LED_9,
	AP_P2_LED_10,
	AP_P2_BUTTON_1,

	JTAN_P1_SWITCH_1,
	JTAN_P1_SWITCH_2,
	JTAN_P1_LED_1,
	JTAN_P1_KNOB,
	JTAN_P1_BUTTON_1,
	JTAN_P1_BUTTON_2,

	INVALID_ID
};

enum BUTTON_STATE
{
	RELEASED,
	PRESSED,
	INVALID_BUTTON
};

enum SWITCH_STATE
{
	POS_1,
	POS_2,
	POS_3,
	INVALID_SWITCH
};

enum LED_STATE
{
	OFF,
	ON,
	INVALID_LED
};

namespace Definitons
{
	static std::string idToString(ELEM_ID id)
	{
		std::vector<std::string> strings =
		{
			"GDSU SWITCH",
			"GDSU BUTTON LEFT 1",
			"GDSU BUTTON LEFT 2",
			"GDSU BUTTON LEFT 3",
			"GDSU BUTTON LEFT 4",
			"GDSU BUTTON LEFT 5",
			"GDSU BUTTON LEFT 6",
			"GDSU BUTTON RIGHT 1",
			"GDSU BUTTON RIGHT 2",
			"GDSU BUTTON RIGHT 3",
			"GDSU BUTTON RIGHT 4",
			"GDSU BUTTON RIGHT 5",
			"GDSU BUTTON RIGHT 6",
			"GDSU BUTTON BOTTOM 1",
			"GDSU BUTTON BOTTOM 2",
			"GDSU BUTTON BOTTOM 3",
			"GDSU BUTTON BOTTOM 4",
			"GDSU BUTTON BOTTOM 5",
			"GDSU BUTTON BOTTOM 6",
			"GDSU BUTTON BOTTOM 7",
			"GDSU BUTTON MINUS",
			"GDSU BUTTON PLUS",
			"GDSU BUTTON CIRCLE",

			"AP PANEL 1 SWITCH 1",
			"AP PANEL 1 SWITCH 2",
			"AP PANEL 1 SWITCH 3",
			"AP PANEL 1 BUTTON 1",
			"AP PANEL 1 LED 1",

			"AP PANEL 2 SWITCH 1",
			"AP PANEL 2 SWITCH 2",
			"AP PANEL 2 SWITCH 3",
			"AP PANEL 2 SWITCH 4",
			"AP PANEL 2 LED 1",
			"AP PANEL 2 LED 2",
			"AP PANEL 2 LED 3",
			"AP PANEL 2 LED 4",
			"AP PANEL 2 LED 5",
			"AP PANEL 2 LED 6",
			"AP PANEL 2 LED 7",
			"AP PANEL 2 LED 8",
			"AP PANEL 2 LED 9",
			"AP PANEL 2 LED 10",
			"AP PANEL 2 BUTTON 1",

			"JTAN PANEL 1 SWITCH 1",
			"JTAN PANEL 1 SWITCH 2",
			"JTAN PANEL 1 LED 1",
			"JTAN PANEL 1 KNOB",
			"JTAN PANEL 1 BUTTON 1",
			"JTAN PANEL 1 BUTTON 2"
		};
		return strings[id];
	}

	static std::string typeToString(ELEM_TYPE type)
	{
		std::vector<std::string> strings =
		{
			"BUTTON",
			"SWITCH",
			"LED",
			"INVALID"
		};
		return strings[type];
	}


	static std::string buttonStateToString(BUTTON_STATE state)
	{
		std::vector<std::string> strings =
		{
			"RELEASED",
			"PRESSED"
		};
		return strings[state];
	}

	static std::string switchStateToString(SWITCH_STATE state)
	{
		std::vector<std::string> strings =
		{
			"POS_1",
			"POS_2",
			"POS_3"
		};
		return strings[state];
	}

	static std::string ledStateToString(LED_STATE state)
	{
		std::vector<std::string> strings =
		{
			"OFF",
			"ON",
		};
		return strings[state];
	}
};
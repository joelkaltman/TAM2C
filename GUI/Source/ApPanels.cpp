#include <GUI/Include/ApPanels.h>

#include <iostream>

#include <GUI/Include/Button.h>

#include <TAM2C/Include/Definitions.h>

ApPanels::ApPanels(QWidget *parent)
	: QWidget(parent)
 {
	ui.setupUi(this);

	gdsu[BUTTON_1] = new Button(ui.GDSU_btn_1, "AP_GDSU_button_vertical_pressed.png");
	gdsu[BUTTON_2] = new Button(ui.GDSU_btn_2, "AP_GDSU_button_vertical_pressed.png");
	gdsu[BUTTON_3] = new Button(ui.GDSU_btn_3, "AP_GDSU_button_vertical_pressed.png");
	gdsu[BUTTON_4] = new Button(ui.GDSU_btn_4, "AP_GDSU_button_vertical_pressed.png");
	gdsu[BUTTON_5] = new Button(ui.GDSU_btn_5, "AP_GDSU_button_vertical_pressed.png");
	gdsu[BUTTON_6] = new Button(ui.GDSU_btn_6, "AP_GDSU_button_vertical_pressed.png");
	gdsu[BUTTON_7] = new Button(ui.GDSU_btn_7, "AP_GDSU_button_vertical_pressed.png");
	gdsu[BUTTON_8] = new Button(ui.GDSU_btn_8, "AP_GDSU_button_vertical_pressed.png");
	gdsu[BUTTON_9] = new Button(ui.GDSU_btn_9, "AP_GDSU_button_vertical_pressed.png");
	gdsu[BUTTON_10] = new Button(ui.GDSU_btn_10, "AP_GDSU_button_vertical_pressed.png");
	gdsu[BUTTON_11] = new Button(ui.GDSU_btn_11, "AP_GDSU_button_vertical_pressed.png");
	gdsu[BUTTON_12] = new Button(ui.GDSU_btn_12, "AP_GDSU_button_vertical_pressed.png");
	gdsu[BUTTON_13] = new Button(ui.GDSU_btn_13, "AP_GDSU_button_vertical_pressed.png");
	gdsu[BUTTON_14] = new Button(ui.GDSU_btn_14, "AP_GDSU_button_horizontal_pressed.png");
	gdsu[BUTTON_15] = new Button(ui.GDSU_btn_15, "AP_GDSU_button_horizontal_pressed.png");
	gdsu[BUTTON_16] = new Button(ui.GDSU_btn_16, "AP_GDSU_button_horizontal_pressed.png");
	gdsu[BUTTON_17] = new Button(ui.GDSU_btn_17, "AP_GDSU_button_horizontal_pressed.png");
	gdsu[BUTTON_18] = new Button(ui.GDSU_btn_18, "AP_GDSU_button_horizontal_pressed.png");
	gdsu[BUTTON_19] = new Button(ui.GDSU_btn_19, "AP_GDSU_button_horizontal_pressed.png");
	gdsu[BUTTON_MINUS] = new Button(ui.GDSU_btn_minus, "AP_GDSU_button_minus_pressed.png");
	gdsu[BUTTON_PLUS] = new Button(ui.GDSU_btn_plus, "AP_GDSU_button_plus_pressed.png");
	gdsu[BUTTON_CIRCLE] = new Button(ui.GDSU_btn_circle, "AP_GDSU_button_circle_pressed.png");

	panel1[P1_SWITCH_1] = new Button(ui.Panel_1_switch_1, "AP_panel1_switch1_2.png");

	loadImages();
}

void ApPanels::loadImages() {
	ui.AP_background->setPixmap(QPixmap(Definitions::getGUIPath("ApPanels.png").c_str()));
}
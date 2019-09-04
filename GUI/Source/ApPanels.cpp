#include <GUI/Include/ApPanels.h>

#include <TAM2C/Include/Definitions.h>

#include <iostream>

ApPanels::ApPanels(QWidget *parent)
	: QWidget(parent)
 {
	ui.setupUi(this);

	loadImages();
}

void ApPanels::loadImages() {
	ui.AP_background->setPixmap(QPixmap(Definitions::getGUIPath("ApPanels.png").c_str()));
}

void ApPanels::on_GDSU_btn_1_pressed() {
	ui.GDSU_btn_1->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_vertical_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_1_released() {
	ui.GDSU_btn_1->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_2_pressed() {
	ui.GDSU_btn_2->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_vertical_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_2_released() {
	ui.GDSU_btn_2->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_3_pressed() {
	ui.GDSU_btn_3->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_vertical_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_3_released() {
	ui.GDSU_btn_3->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_4_pressed() {
	ui.GDSU_btn_4->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_vertical_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_4_released() {
	ui.GDSU_btn_4->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_5_pressed() {
	ui.GDSU_btn_5->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_vertical_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_5_released() {
	ui.GDSU_btn_5->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_6_pressed() {
	ui.GDSU_btn_6->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_vertical_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_6_released() {
	ui.GDSU_btn_6->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_7_pressed() {
	ui.GDSU_btn_7->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_vertical_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_7_released() {
	ui.GDSU_btn_7->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_8_pressed() {
	ui.GDSU_btn_8->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_vertical_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_8_released() {
	ui.GDSU_btn_8->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_9_pressed() {
	ui.GDSU_btn_9->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_vertical_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_9_released() {
	ui.GDSU_btn_9->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_10_pressed() {
	ui.GDSU_btn_10->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_vertical_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_10_released() {
	ui.GDSU_btn_10->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_11_pressed() {
	ui.GDSU_btn_11->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_vertical_pressed.png").c_str()));
}
void ApPanels::on_GDSU_btn_11_released() {
	ui.GDSU_btn_11->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_12_pressed() {
	ui.GDSU_btn_12->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_vertical_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_12_released() {
	ui.GDSU_btn_12->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_13_pressed() {
	ui.GDSU_btn_13->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_horizontal_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_13_released() {
	ui.GDSU_btn_13->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_14_pressed() {
	ui.GDSU_btn_14->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_horizontal_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_14_released() {
	ui.GDSU_btn_14->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_15_pressed() {
	ui.GDSU_btn_15->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_horizontal_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_15_released() {
	ui.GDSU_btn_15->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_16_pressed() {
	ui.GDSU_btn_16->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_horizontal_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_16_released() {
	ui.GDSU_btn_16->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_17_pressed() {
	ui.GDSU_btn_17->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_horizontal_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_17_released() {
	ui.GDSU_btn_17->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_18_pressed() {
	ui.GDSU_btn_18->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_horizontal_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_18_released() {
	ui.GDSU_btn_18->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_19_pressed() {
	ui.GDSU_btn_19->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_horizontal_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_19_released() {
	ui.GDSU_btn_19->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_minus_pressed() {
	ui.GDSU_btn_minus->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_minus_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_minus_released() {
	ui.GDSU_btn_minus->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_plus_pressed() {
	ui.GDSU_btn_plus->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_plus_pressed.png").c_str()));
}
void ApPanels::on_GDSU_btn_plus_released() {
	ui.GDSU_btn_plus->setIcon(QIcon());
}

void ApPanels::on_GDSU_btn_circle_pressed() {
	ui.GDSU_btn_circle->setIcon(QPixmap(Definitions::getGUIPath("AP_GDSU_button_circle_pressed.png").c_str()));
}

void ApPanels::on_GDSU_btn_circle_released() {
	ui.GDSU_btn_circle->setIcon(QIcon());
}
#include <GUI/Include/ApPanels.h>

#include <iostream>

#include <GUI/Include/UIElement.h>
#include <GUI/Include/Button.h>
#include <GUI/Include/Switch.h>
#include <GUI/Include/Led.h>

#include <TAM2C/Include/Config.h>

ApPanels::ApPanels(QWidget *parent)
	: QWidget(parent)
 {
	ui.setupUi(this);

	uiElem[GDSU_BUTTON_1] = new Button(ui.GDSU_btn_1, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_2] = new Button(ui.GDSU_btn_2, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_3] = new Button(ui.GDSU_btn_3, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_4] = new Button(ui.GDSU_btn_4, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_5] = new Button(ui.GDSU_btn_5, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_6] = new Button(ui.GDSU_btn_6, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_7] = new Button(ui.GDSU_btn_7, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_8] = new Button(ui.GDSU_btn_8, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_9] = new Button(ui.GDSU_btn_9, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_10] = new Button(ui.GDSU_btn_10, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_11] = new Button(ui.GDSU_btn_11, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_12] = new Button(ui.GDSU_btn_12, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_13] = new Button(ui.GDSU_btn_13, "AP_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_14] = new Button(ui.GDSU_btn_14, "AP_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_15] = new Button(ui.GDSU_btn_15, "AP_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_16] = new Button(ui.GDSU_btn_16, "AP_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_17] = new Button(ui.GDSU_btn_17, "AP_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_18] = new Button(ui.GDSU_btn_18, "AP_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_19] = new Button(ui.GDSU_btn_19, "AP_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_MINUS] = new Button(ui.GDSU_btn_minus, "AP_GDSU_button_minus_pressed.png");
	uiElem[GDSU_BUTTON_PLUS] = new Button(ui.GDSU_btn_plus, "AP_GDSU_button_plus_pressed.png");
	uiElem[GDSU_BUTTON_CIRCLE] = new Button(ui.GDSU_btn_circle, "AP_GDSU_button_circle_pressed.png");

	uiElem[AP_P1_SWITCH_1] = new Switch(ui.Panel_1_switch_1, "AP_panel1_switch1_1.png", "AP_panel1_switch1_2.png", "AP_panel1_switch1_3.png");
	uiElem[AP_P1_SWITCH_2] = new Switch(ui.Panel_1_switch_2, "AP_panel1_switch2_1.png", "AP_panel1_switch2_2.png");
	uiElem[AP_P1_SWITCH_3] = new Switch(ui.Panel_1_switch_3, "AP_panel1_switch3_1.png", "AP_panel1_switch3_2.png");
	uiElem[AP_P1_BUTTON] = new Button(ui.Panel_1_button, "AP_panel1_red_pressed.png");

	uiElem[AP_P2_SWITCH_1] = new Switch(ui.Panel_2_switch_1, "AP_panel2_switch1_2.png", "AP_panel2_switch1_1.png");
	uiElem[AP_P2_SWITCH_2] = new Switch(ui.Panel_2_switch_2, "AP_panel2_switch2_2.png", "AP_panel2_switch2_1.png");
	uiElem[AP_P2_SWITCH_3] = new Switch(ui.Panel_2_switch_3, "AP_panel2_switch3_2.png", "AP_panel2_switch3_1.png");
	uiElem[AP_P2_SWITCH_4] = new Switch(ui.Panel_2_switch_4, "AP_panel2_switch4_2.png", "AP_panel2_switch4_1.png");
	uiElem[AP_P2_LED_1] = new Led(ui.Panel_2_led_1, "AP_panel2_led1.png");
	uiElem[AP_P2_LED_2] = new Led(ui.Panel_2_led_2, "AP_panel2_led2.png");
	uiElem[AP_P2_LED_3] = new Led(ui.Panel_2_led_3, "AP_panel2_led3.png");
	uiElem[AP_P2_LED_4] = new Led(ui.Panel_2_led_4, "AP_panel2_led4.png");
	uiElem[AP_P2_LED_5] = new Led(ui.Panel_2_led_5, "AP_panel2_led5.png");
	uiElem[AP_P2_LED_6] = new Led(ui.Panel_2_led_6, "AP_panel2_led6.png");
	uiElem[AP_P2_LED_7] = new Led(ui.Panel_2_led_7, "AP_panel2_led7.png");
	uiElem[AP_P2_LED_8] = new Led(ui.Panel_2_led_8, "AP_panel2_led8.png");
	uiElem[AP_P2_LED_9] = new Led(ui.Panel_2_led_9, "AP_panel2_led9.png");
	uiElem[AP_P2_LED_10] = new Led(ui.Panel_2_led_10, "AP_panel2_led10.png");

	this->pgs_qt_widget = new PGSQtWidget::PGSWidget(this);
	this->pgs_qt_widget->setObjectName(QStringLiteral("p3dQtWidget"));
	this->pgs_qt_widget->setGeometry(QRect(142, 290, 860, 560));

	loadImages();


	uiElem[AP_P2_SWITCH_3]->setCallback(POS_2, [this]()
	{
		subscriber->notify(AP_P2_SWITCH_3, POS_2);
		opPWRpressed();
	}, 1000);

	uiElem[AP_P2_SWITCH_2]->setCallback(POS_2, [this]()
	{
		subscriber->notify(AP_P2_SWITCH_2, POS_2);
		opSTABpressed();
	}, 1000);
}

void ApPanels::loadImages() {
	ui.AP_background->setPixmap(QPixmap(Config::getGUIPath("ApPanels.png").c_str()));
}

PGSQtWidget::PGSWidget* ApPanels::getPGSWidget() const
{
	return this->pgs_qt_widget;
}

UIElement* ApPanels::getUiElement(ELEM_ID id) const
{
	if (uiElem.find(id) == uiElem.end())
		return nullptr;

	return uiElem.at(id);
}

void ApPanels::addSubscriber(ISubscriber* sub)
{
	this->subscriber = sub;
}

void ApPanels::opPWRpressed()
{
	uiElem[AP_P2_SWITCH_3]->setUsable(false);

	uiElem[AP_P2_LED_8]->setState(ON);
	uiElem[AP_P2_LED_9]->setState(ON);
}

void ApPanels::opSTABpressed()
{
	if (uiElem[AP_P2_SWITCH_3]->getState() != POS_2)
		return;

	uiElem[AP_P2_SWITCH_2]->setUsable(false);

	uiElem[AP_P2_LED_6]->setState(ON);
	uiElem[AP_P2_LED_7]->setState(ON);
}
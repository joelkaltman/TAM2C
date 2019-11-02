#include <GUI/Include/ApPanels.h>

#include <iostream>

#include <GUI/Include/IElement.h>
#include <GUI/Include/Button.h>
#include <GUI/Include/Switch.h>
#include <GUI/Include/Led.h>

#include <TAM2C/Include/Config.h>
#include <TAM2C/Include/IMemberConfig.h>

ApPanels::ApPanels(QWidget *parent)
	: QWidget(parent)
 {
	ui.setupUi(this);
	
	ui.AP_background->setPixmap(QPixmap(Config::getGUIPath("AP.png").c_str()));

	uiElem[GDSU_SWITCH_1] = new Switch(ui.GDSU_switch_1, "AP_GDSU_switch1_1.png", "AP_GDSU_switch1_2.png");
	uiElem[GDSU_BUTTON_LEFT_1] = new Button(ui.GDSU_btn_left_1, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_LEFT_2] = new Button(ui.GDSU_btn_left_2, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_LEFT_3] = new Button(ui.GDSU_btn_left_3, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_LEFT_4] = new Button(ui.GDSU_btn_left_4, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_LEFT_5] = new Button(ui.GDSU_btn_left_5, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_LEFT_6] = new Button(ui.GDSU_btn_left_6, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_RIGHT_1] = new Button(ui.GDSU_btn_right_1, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_RIGHT_2] = new Button(ui.GDSU_btn_right_2, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_RIGHT_3] = new Button(ui.GDSU_btn_right_3, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_RIGHT_4] = new Button(ui.GDSU_btn_right_4, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_RIGHT_5] = new Button(ui.GDSU_btn_right_5, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_RIGHT_6] = new Button(ui.GDSU_btn_right_6, "AP_GDSU_button_vertical_pressed.png");
	uiElem[GDSU_BUTTON_BOTTOM_1] = new Button(ui.GDSU_btn_bottom_1, "AP_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_BOTTOM_2] = new Button(ui.GDSU_btn_bottom_2, "AP_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_BOTTOM_3] = new Button(ui.GDSU_btn_bottom_3, "AP_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_BOTTOM_4] = new Button(ui.GDSU_btn_bottom_4, "AP_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_BOTTOM_5] = new Button(ui.GDSU_btn_bottom_5, "AP_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_BOTTOM_6] = new Button(ui.GDSU_btn_bottom_6, "AP_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_BOTTOM_7] = new Button(ui.GDSU_btn_bottom_7, "AP_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_MINUS] = new Button(ui.GDSU_btn_minus, "AP_GDSU_button_minus_pressed.png");
	uiElem[GDSU_BUTTON_PLUS] = new Button(ui.GDSU_btn_plus, "AP_GDSU_button_plus_pressed.png");
	uiElem[GDSU_BUTTON_CIRCLE] = new Button(ui.GDSU_btn_circle, "AP_GDSU_button_circle_pressed.png");

	uiElem[AP_P1_SWITCH_1] = new Switch(ui.Panel_1_switch_1, "AP_panel1_switch1_1.png", "AP_panel1_switch1_2.png", "AP_panel1_switch1_3.png");
	uiElem[AP_P1_SWITCH_2] = new Switch(ui.Panel_1_switch_2, "AP_panel1_switch2_1.png", "AP_panel1_switch2_2.png");
	uiElem[AP_P1_SWITCH_3] = new Switch(ui.Panel_1_switch_3, "AP_panel1_switch3_1.png", "AP_panel1_switch3_2.png");
	uiElem[AP_P1_BUTTON_1] = new Button(ui.Panel_1_button_1, "AP_panel1_red_pressed.png");
	uiElem[AP_P1_LED_1] = new Led(ui.Panel_1_led_1, "AP_panel1_led1.png");

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
	uiElem[AP_P2_BUTTON_1] = new Button(ui.Panel_2_button_1, "AP_panel2_button1.png");

	for (auto& e : uiElem)
		e.second->setId(e.first);

	this->pgs_qt_widget = new PGSQtWidget::PGSWidget(this);
	this->pgs_qt_widget->setObjectName(QStringLiteral("p3dQtWidget"));
	this->pgs_qt_widget->setGeometry(QRect(188, 290, 860, 560));
}

PGSQtWidget::PGSWidget* ApPanels::getPGSWidget() const
{
	return this->pgs_qt_widget;
}

IElement* ApPanels::getUiElement(ELEM_ID id) const
{
	if (uiElem.find(id) == uiElem.end())
		return nullptr;

	return uiElem.at(id);
}

void ApPanels::addSubscriber(ISubscriber* sub)
{
	for (auto& e : uiElem)
		e.second->addSubscriber(sub);
}

void ApPanels::updateConfig(IMemberConfig config, ELEM_ID elemLastChange)
{
	// GENERAL
	if (config.general == GENERAL_OFF || config.general == GENERAL_BIT)
	{
		for (auto& e : uiElem)
			if (e.second->getType() == LED)
				e.second->setState(OFF);

		if (config.general == GENERAL_BIT)
			uiElem[AP_P1_LED_1]->setState(ON);

		return;
	}
	else if(elemLastChange == AP_P2_SWITCH_4)
	{
		uiElem[AP_P2_LED_10]->setState(ON);

		for (auto& e : uiElem)
			if (e.first >= AP_P2_LED_1 && e.first <= AP_P2_LED_9)
				e.second->setState(ON);

		IElement::sleepUI(1000);

		for (auto& e : uiElem)
			if (e.first >= AP_P2_LED_1 && e.first <= AP_P2_LED_9)
				e.second->setState(OFF);
	}

	// GUN
	if (config.gun == MGUN)
	{
		uiElem[AP_P2_LED_2]->setState(ON);
		uiElem[AP_P2_LED_3]->setState(OFF);
	}
	else
	{
		uiElem[AP_P2_LED_2]->setState(OFF);
		uiElem[AP_P2_LED_3]->setState(ON);
	}

	// NAVEGATION
	switch (config.nav)
	{
		case MSTG:
			uiElem[AP_P2_SWITCH_2]->setUsable(true);
			uiElem[AP_P2_SWITCH_3]->setUsable(true);
			break;
		case STG:
		{
			uiElem[AP_P2_SWITCH_2]->setUsable(true);
			uiElem[AP_P2_SWITCH_3]->setUsable(true);

			uiElem[AP_P2_LED_8]->setState(ON);
			uiElem[AP_P2_LED_9]->setState(ON);
			break;
		}
		case GTS:
		{
			uiElem[AP_P2_SWITCH_2]->setUsable(false);
			uiElem[AP_P2_SWITCH_3]->setUsable(false);

			if (elemLastChange == AP_P2_SWITCH_2)
			{
				for (int i = 0; i < 6; i++)
				{
					uiElem[AP_P2_LED_6]->setState(i % 2);
					uiElem[AP_P2_LED_7]->setState(i % 2);
					IElement::sleepUI(500);
				}
			}

			uiElem[AP_P2_SWITCH_2]->setUsable(true);

			break;
		}
	}
}
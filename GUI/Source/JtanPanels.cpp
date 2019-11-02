#include <GUI/Include/JtanPanels.h>


#include <GUI/Include/IElement.h>
#include <GUI/Include/Button.h>
#include <GUI/Include/Switch.h>
#include <GUI/Include/Led.h>

#include <TAM2C/Include/Config.h>
#include <TAM2C/Include/IMemberConfig.h>

JtanPanels::JtanPanels(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.JTAN_Background->setPixmap(QPixmap(Config::getGUIPath("JTAN.png").c_str()));

	uiElem[GDSU_SWITCH_1] = new Switch(ui.GDSU_switch_1, "JTAN_GDSU_switch1_1.png", "JTAN_GDSU_switch1_2.png");
	uiElem[GDSU_BUTTON_LEFT_1] = new Button(ui.GDSU_btn_left_1, "JTAN_GDSU_button_vertical1_pressed.png");
	uiElem[GDSU_BUTTON_LEFT_2] = new Button(ui.GDSU_btn_left_2, "JTAN_GDSU_button_vertical1_pressed.png");
	uiElem[GDSU_BUTTON_LEFT_3] = new Button(ui.GDSU_btn_left_3, "JTAN_GDSU_button_vertical1_pressed.png");
	uiElem[GDSU_BUTTON_LEFT_4] = new Button(ui.GDSU_btn_left_4, "JTAN_GDSU_button_vertical1_pressed.png");
	uiElem[GDSU_BUTTON_LEFT_5] = new Button(ui.GDSU_btn_left_5, "JTAN_GDSU_button_vertical1_pressed.png");
	uiElem[GDSU_BUTTON_LEFT_6] = new Button(ui.GDSU_btn_left_6, "JTAN_GDSU_button_vertical1_pressed.png");
	uiElem[GDSU_BUTTON_RIGHT_1] = new Button(ui.GDSU_btn_right_1, "JTAN_GDSU_button_vertical2_pressed.png");
	uiElem[GDSU_BUTTON_RIGHT_2] = new Button(ui.GDSU_btn_right_2, "JTAN_GDSU_button_vertical2_pressed.png");
	uiElem[GDSU_BUTTON_RIGHT_3] = new Button(ui.GDSU_btn_right_3, "JTAN_GDSU_button_vertical2_pressed.png");
	uiElem[GDSU_BUTTON_RIGHT_4] = new Button(ui.GDSU_btn_right_4, "JTAN_GDSU_button_vertical2_pressed.png");
	uiElem[GDSU_BUTTON_RIGHT_5] = new Button(ui.GDSU_btn_right_5, "JTAN_GDSU_button_vertical2_pressed.png");
	uiElem[GDSU_BUTTON_RIGHT_6] = new Button(ui.GDSU_btn_right_6, "JTAN_GDSU_button_vertical2_pressed.png");
	uiElem[GDSU_BUTTON_BOTTOM_1] = new Button(ui.GDSU_btn_bottom_1, "JTAN_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_BOTTOM_2] = new Button(ui.GDSU_btn_bottom_2, "JTAN_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_BOTTOM_3] = new Button(ui.GDSU_btn_bottom_3, "JTAN_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_BOTTOM_4] = new Button(ui.GDSU_btn_bottom_4, "JTAN_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_BOTTOM_5] = new Button(ui.GDSU_btn_bottom_5, "JTAN_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_BOTTOM_6] = new Button(ui.GDSU_btn_bottom_6, "JTAN_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_BOTTOM_7] = new Button(ui.GDSU_btn_bottom_7, "JTAN_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_MINUS] = new Button(ui.GDSU_btn_minus, "JTAN_GDSU_button_minus_pressed.png");
	uiElem[GDSU_BUTTON_PLUS] = new Button(ui.GDSU_btn_plus, "JTAN_GDSU_button_plus_pressed.png");
	uiElem[GDSU_BUTTON_CIRCLE] = new Button(ui.GDSU_btn_circle, "JTAN_GDSU_button_circle_pressed.png");

	uiElem[JTAN_P1_SWITCH_1] = new Switch(ui.Panel_1_switch_1, "JTAN_panel1_switch1_2.png", "JTAN_panel1_switch1_1.png");
	uiElem[JTAN_P1_SWITCH_2] = new Switch(ui.Panel_1_switch_2, "JTAN_panel1_switch2_2.png", "JTAN_panel1_switch2_1.png");
	uiElem[JTAN_P1_KNOB] = new Switch(ui.Panel_1_knob, "JTAN_panel1_knob_1.png", "JTAN_panel1_knob_2.png", "JTAN_panel1_knob_3");
	uiElem[JTAN_P1_LED_1] = new Led(ui.Panel_1_led_1, "JTAN_panel1_led1.png");
	uiElem[JTAN_P1_BUTTON_1] = new Button(ui.Panel_1_button_1, "JTAN_panel1_button1.png");
	uiElem[JTAN_P1_BUTTON_2] = new Button(ui.Panel_1_button_2, "JTAN_panel1_button2.png");

	for (auto& e : uiElem)
		e.second->setId(e.first);

	this->pgs_qt_widget = new PGSQtWidget::PGSWidget(this);
	this->pgs_qt_widget->setObjectName(QStringLiteral("p3dQtWidget"));
	this->pgs_qt_widget->setGeometry(QRect(227, 290, 850, 560));
}

PGSQtWidget::PGSWidget* JtanPanels::getPGSWidget() const
{
	return this->pgs_qt_widget;
}

IElement* JtanPanels::getUiElement(ELEM_ID id) const
{
	if (uiElem.find(id) == uiElem.end())
		return nullptr;

	return uiElem.at(id);
}

void JtanPanels::addSubscriber(ISubscriber* sub)
{
	for (auto& e : uiElem)
		e.second->addSubscriber(sub);
}

void JtanPanels::updateConfig(IMemberConfig config, ELEM_ID elemLastChange)
{
	for (auto& e : uiElem)
		e.second->setInitialState();

	if (config.general)
		uiElem[JTAN_P1_LED_1]->setState(ON);
	else
	{
		uiElem[JTAN_P1_LED_1]->setState(OFF);
		return;
	}
}
#include <GUI/Include/JtanPanels.h>


#include <GUI/Include/UIElement.h>
#include <GUI/Include/Button.h>
#include <GUI/Include/Switch.h>

#include <TAM2C/Include/Definitions.h>

JtanPanels::JtanPanels(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	uiElem[GDSU_BUTTON_1] = new Button(ui.GDSU_btn_1, "JTAN_GDSU_button_vertical1_pressed.png");
	uiElem[GDSU_BUTTON_2] = new Button(ui.GDSU_btn_2, "JTAN_GDSU_button_vertical1_pressed.png");
	uiElem[GDSU_BUTTON_3] = new Button(ui.GDSU_btn_3, "JTAN_GDSU_button_vertical1_pressed.png");
	uiElem[GDSU_BUTTON_4] = new Button(ui.GDSU_btn_4, "JTAN_GDSU_button_vertical1_pressed.png");
	uiElem[GDSU_BUTTON_5] = new Button(ui.GDSU_btn_5, "JTAN_GDSU_button_vertical1_pressed.png");
	uiElem[GDSU_BUTTON_6] = new Button(ui.GDSU_btn_6, "JTAN_GDSU_button_vertical1_pressed.png");
	uiElem[GDSU_BUTTON_7] = new Button(ui.GDSU_btn_7, "JTAN_GDSU_button_vertical2_pressed.png");
	uiElem[GDSU_BUTTON_8] = new Button(ui.GDSU_btn_8, "JTAN_GDSU_button_vertical2_pressed.png");
	uiElem[GDSU_BUTTON_9] = new Button(ui.GDSU_btn_9, "JTAN_GDSU_button_vertical2_pressed.png");
	uiElem[GDSU_BUTTON_10] = new Button(ui.GDSU_btn_10, "JTAN_GDSU_button_vertical2_pressed.png");
	uiElem[GDSU_BUTTON_11] = new Button(ui.GDSU_btn_11, "JTAN_GDSU_button_vertical2_pressed.png");
	uiElem[GDSU_BUTTON_12] = new Button(ui.GDSU_btn_12, "JTAN_GDSU_button_vertical2_pressed.png");
	uiElem[GDSU_BUTTON_13] = new Button(ui.GDSU_btn_13, "JTAN_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_14] = new Button(ui.GDSU_btn_14, "JTAN_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_15] = new Button(ui.GDSU_btn_15, "JTAN_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_16] = new Button(ui.GDSU_btn_16, "JTAN_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_17] = new Button(ui.GDSU_btn_17, "JTAN_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_18] = new Button(ui.GDSU_btn_18, "JTAN_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_19] = new Button(ui.GDSU_btn_19, "JTAN_GDSU_button_horizontal_pressed.png");
	uiElem[GDSU_BUTTON_MINUS] = new Button(ui.GDSU_btn_minus, "JTAN_GDSU_button_minus_pressed.png");
	uiElem[GDSU_BUTTON_PLUS] = new Button(ui.GDSU_btn_plus, "JTAN_GDSU_button_plus_pressed.png");
	uiElem[GDSU_BUTTON_CIRCLE] = new Button(ui.GDSU_btn_circle, "JTAN_GDSU_button_circle_pressed.png");

	uiElem[JTAN_P1_SWITCH_1] = new Switch(ui.Panel_1_switch_1, "JTAN_panel1_switch1_1.png", "JTAN_panel1_switch1_2.png");
	uiElem[JTAN_P1_SWITCH_2] = new Switch(ui.Panel_1_switch_2, "JTAN_panel1_switch2_1.png", "JTAN_panel1_switch2_2.png");
	uiElem[JTAN_P1_KNOB] = new Switch(ui.Panel_1_knob, "JTAN_panel1_knob_1.png", "JTAN_panel1_knob_2.png", "JTAN_panel1_knob_3");

	this->pgs_qt_widget = new PGSQtWidget::PGSWidget(this);
	this->pgs_qt_widget->setObjectName(QStringLiteral("p3dQtWidget"));
	this->pgs_qt_widget->setGeometry(QRect(162, 290, 850, 560));

	loadImages();
}

void JtanPanels::loadImages()
{
	ui.JTAN_Background->setPixmap(QPixmap(Definitions::getGUIPath("JtanPanels.png").c_str()));
}

PGSQtWidget::PGSWidget* JtanPanels::getPGSWidget() const
{
	return this->pgs_qt_widget;
}
#pragma once

#include <QtWidgets/QWidget>
#include <GUI/GeneratedFiles/ui_ApPanels.h>

#include <GUI/Include/Definitions.h>

class Button;

class ApPanels : public QWidget
{
	Q_OBJECT

public:
	ApPanels(QWidget *parent = Q_NULLPTR);

private:
	void loadImages();

	Ui::ApPanelsClass ui;

	std::map<GDSU_ELEM, Button*> gdsu;
	std::map<AP_PANEL_1, Button*> panel1;
	std::map<AP_PANEL_2, Button*> panel2;
};

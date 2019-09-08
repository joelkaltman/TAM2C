#pragma once

#include <QtWidgets/QWidget>
#include <GUI/GeneratedFiles/ui_ApPanels.h>

#include <GUI/Include/Definitions.h>

class UIElement;

class ApPanels : public QWidget
{
	Q_OBJECT

public:
	ApPanels(QWidget *parent = Q_NULLPTR);

private:
	void loadImages();

	Ui::ApPanelsClass ui;

	std::map<ELEM_ID, UIElement*> uiElem;
};

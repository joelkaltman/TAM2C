#pragma once

#include <QtWidgets/QWidget>
#include <GUI/GeneratedFiles/ui_JtanPanels.h>

#include <GUI/Include/Definitions.h>

class UIElement;

class JtanPanels : public QWidget
{
	Q_OBJECT

public:
	JtanPanels(QWidget *parent = Q_NULLPTR);

private:
	void loadImages();

	Ui::JtanPanelsClass ui;

	std::map<ELEM_ID, UIElement*> uiElem;
};

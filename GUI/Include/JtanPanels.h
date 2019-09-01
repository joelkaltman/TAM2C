#pragma once

#include <QtWidgets/QWidget>
#include <GUI/GeneratedFiles/ui_JtanPanels.h>

class JtanPanels : public QWidget
{
	Q_OBJECT

public:
	JtanPanels(QWidget *parent = Q_NULLPTR);

private:
	void loadImages();

	Ui::JtanPanelsClass ui;
};

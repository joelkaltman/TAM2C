#pragma once

#include <QtWidgets/QWidget>
#include <GUI/GeneratedFiles/ui_ApPanels.h>

#include <GUI/Include/Definitions.h>

#include <PGSWidget/Include/PGSWidget.h>

class UIElement;

class ApPanels : public QWidget
{
	Q_OBJECT

public:
	ApPanels(QWidget *parent = Q_NULLPTR);

	PGSQtWidget::PGSWidget* getPGSWidget() const;

private:
	void loadImages();

	Ui::ApPanelsClass ui;

	PGSQtWidget::PGSWidget* pgs_qt_widget;

	std::map<ELEM_ID, UIElement*> uiElem;
};

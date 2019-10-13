#pragma once

#include <QtWidgets/QWidget>
#include <GUI/GeneratedFiles/ui_JtanPanels.h>

#include <GUI/Include/Definitions.h>

#include <PGSWidget/Include/PGSWidget.h>

class UIElement;

class JtanPanels : public QWidget
{
	Q_OBJECT

public:
	JtanPanels(QWidget *parent = Q_NULLPTR);

	PGSQtWidget::PGSWidget* getPGSWidget() const;

	UIElement* getUiElement(ELEM_ID id) const;

private:
	void loadImages();

	Ui::JtanPanelsClass ui;

	PGSQtWidget::PGSWidget* pgs_qt_widget;

	std::map<ELEM_ID, UIElement*> uiElem;
};

#pragma once

#include <QtWidgets/QWidget>
#include <GUI/GeneratedFiles/ui_ApPanels.h>

#include <GUI/Include/Definitions.h>
#include <GUI/Include/ISubscriber.h>

#include <PGSWidget/Include/PGSWidget.h>

class UIElement;

class ApPanels : public QWidget
{
	Q_OBJECT

public:
	ApPanels(QWidget *parent = Q_NULLPTR);

	PGSQtWidget::PGSWidget* getPGSWidget() const;

	UIElement* getUiElement(ELEM_ID id) const;

	void addSubscriber(ISubscriber* sub);

private:
	void loadImages();

	void operation(ELEM_ID elem, int state);
	void opPWRpressed();
	void opSTABpressed();

	Ui::ApPanelsClass ui;

	PGSQtWidget::PGSWidget* pgs_qt_widget;

	std::map<ELEM_ID, UIElement*> uiElem;

	ISubscriber* subscriber;
};

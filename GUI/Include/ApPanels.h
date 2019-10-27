#pragma once

#include <QtWidgets/QWidget>
#include <GUI/GeneratedFiles/ui_ApPanels.h>

#include <GUI/Include/Definitions.h>
#include <GUI/Include/ISubscriber.h>

#include <PGSWidget/Include/PGSWidget.h>

class IElement;
class IMemberConfig;

class ApPanels : public QWidget
{
	Q_OBJECT

public:
	ApPanels(QWidget *parent = Q_NULLPTR);

	PGSQtWidget::PGSWidget* getPGSWidget() const;

	IElement* getUiElement(ELEM_ID id) const;

	void addSubscriber(ISubscriber* sub);

	void updateConfig(IMemberConfig config, ELEM_ID elemLastChange);

private:
	void loadImages();

	Ui::ApPanelsClass ui;

	PGSQtWidget::PGSWidget* pgs_qt_widget;

	std::map<ELEM_ID, IElement*> uiElem;
};

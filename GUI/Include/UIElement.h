#pragma once

#include <QtWidgets/QWidget>
#include <GUI/GeneratedFiles/ui_ApPanels.h>

class UIElement : public QWidget
{
	Q_OBJECT
public:
	enum ButtonState
	{
		RELESED,
		PRESSED
	};

	enum SwitchState
	{
		POS_1,
		POS_2,
		POS_3,
		INVALID
	};

	virtual void setState(int state) = 0;
};
#pragma once

#include <QtWidgets/QWidget>
#include <GUI/GeneratedFiles/ui_ApPanels.h>

#include <GUI/Include/Definitions.h>

class Button : public QWidget
{
	Q_OBJECT
public:
	enum State
	{
		RELESED,
		PRESSED,
		PRESSED_2,
	};

	Button(QPushButton* uiButton, std::string nameImage);

private slots:
	void Pressed();
	void Released();

private:
	State state;
	std::string nameImage;
	QPushButton* uiButton;
};
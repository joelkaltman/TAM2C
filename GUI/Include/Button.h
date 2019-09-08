#pragma once

#include <GUI/Include/UIElement.h>

class Button : public UIElement
{
	Q_OBJECT
public:
	Button(QPushButton* uiButton, const std::string& nameImage);

	void setState(int state) override;

private slots:
	void Pressed();
	void Released();

private:
	ButtonState state;
	std::string nameImage;
	QPushButton* uiButton;
};
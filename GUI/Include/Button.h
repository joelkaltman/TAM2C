#pragma once

#include <GUI/Include/UIElement.h>

class Button : public UIElement
{
	Q_OBJECT
public:
	Button(QPushButton* uiButton, const std::string& nameImage);

	void setState(int newState) override;
	int getState() const override;

private slots:
	void Pressed();
	void Released();

private:
	BUTTON_STATE state;
	std::string nameImage;
	QPushButton* uiButton;
};
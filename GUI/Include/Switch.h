#pragma once

#include <GUI/Include/UIElement.h>

class Switch : public UIElement
{
	Q_OBJECT
public:
	Switch(QPushButton* uiButton, const std::string& nameImage1, const std::string& nameImage2);
	Switch(QPushButton* uiButton, const std::string& nameImage1, const std::string& nameImage2, const std::string& nameImage3);

	void setState(int state) override;

private slots:
	void Pressed();

private:
	int positions;
	SwitchState state;
	std::string nameImages[3];
	QPushButton* uiButton;
};
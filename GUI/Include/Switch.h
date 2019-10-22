#pragma once

#include <GUI/Include/IElement.h>

class Switch : public IElement
{
	Q_OBJECT
public:
	Switch(QPushButton* uiButton, const std::string& nameImage1, const std::string& nameImage2);
	Switch(QPushButton* uiButton, const std::string& nameImage1, const std::string& nameImage2, const std::string& nameImage3);

	void setState(int newState) override;
	int getState() const override;

	void setSubscriber(ISubscriber* subscriber) override;

private slots:
	void Pressed();

private:
	int positions;
	SWITCH_STATE state;
	std::string nameImages[3];
	QPushButton* uiButton;
};
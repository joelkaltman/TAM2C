#pragma once

#include <GUI/Include/IElement.h>

class Led : public IElement
{
	Q_OBJECT
public:
	Led(QLabel* uiLabel, const std::string& nameImage);

	void setState(int newState) override;
	int getState() const override;

private:
	LED_STATE state;
	std::string nameImage;
	QLabel* uiLabel;
};
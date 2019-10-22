#pragma once

#include <GUI/Include/IElement.h>

class Button : public IElement
{
	Q_OBJECT
public:
	Button(QPushButton* uiButton, const std::string& nameImage);

	void setState(int newState) override;
	int getState() const override;

	void setSubscriber(ISubscriber* subscriber) override;

private slots:
	void Pressed();
	void Released();

private:
	BUTTON_STATE state;
	std::string nameImage;
	QPushButton* uiButton;
};
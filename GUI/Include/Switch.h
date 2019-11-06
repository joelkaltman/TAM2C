#pragma once

#include <GUI/Include/IElement.h>

class Switch : public IElement
{
	Q_OBJECT
public:
	Switch(QPushButton* uiButton, const std::string& nameImage1, const std::string& nameImage2);
	Switch(QPushButton* uiButton, const std::vector<std::string>& images);

	ELEM_TYPE getType() const override
	{
		return SWITCH;
	}

	int getPositions() const;

	void setState(int newState) override;
	int getState() const override;

	void addSubscriber(ISubscriber* subscriber) override;

private slots:
	void Pressed();

private:
	SWITCH_STATE state;
	std::vector<std::string> nameImages;
	QPushButton* uiButton;
};
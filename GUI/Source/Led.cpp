#include <GUI/Include/Led.h>

#include <TAM2C/Include/Config.h>

Led::Led(QLabel* uiLabel, const std::string& nameImage) :
	uiLabel(uiLabel), state(OFF), nameImage(nameImage)
{
	initialState = state;
}

void Led::setState(int newState)
{
	if (newState < 0 || newState > 1 || !enabled)
		return;

	state = (LED_STATE)newState;

	if (newState == ON)
		uiLabel->setPixmap(QPixmap(Config::getGUIPath(nameImage).c_str()));
	else
		uiLabel->setPixmap(QPixmap());

	IElement::setState(newState);
}

void Led::setInitialState()
{
	state = (LED_STATE)initialState;

	if (initialState == ON)
		uiLabel->setPixmap(QPixmap(Config::getGUIPath(nameImage).c_str()));
	else
		uiLabel->setPixmap(QPixmap());
}

int Led::getState() const
{
	return state;
}
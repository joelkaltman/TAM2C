#include <GUI/Include/Led.h>

#include <TAM2C/Include/Config.h>

Led::Led(QLabel* uiLabel, const std::string& nameImage) :
	uiLabel(uiLabel), state(OFF), nameImage(nameImage)
{
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

	if (callbacks.find(state) != callbacks.end())
		callbacks.at(state)();
}

int Led::getState() const
{
	return state;
}
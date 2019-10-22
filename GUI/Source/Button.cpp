#include <GUI/Include/Button.h>

#include <TAM2C/Include/Config.h>

Button::Button(QPushButton* uiButton, const std::string& nameImage) :
	uiButton(uiButton), state(RELEASED), nameImage(nameImage)
{
	connect(uiButton, SIGNAL(pressed()), this, SLOT(Pressed()));
	connect(uiButton, SIGNAL(released()), this, SLOT(Released()));
}

void Button::Pressed()
{
	if (!usable)
		return;

	setState(PRESSED);
}

void Button::Released()
{
	if (!usable)
		return;

	setState(RELEASED);
}

void Button::setState(int newState)
{
	if (newState < 0 || newState > 1 || !enabled)
		return;

	state = (BUTTON_STATE)newState;

	if(newState == PRESSED)
		uiButton->setIcon(QPixmap(Config::getGUIPath(nameImage).c_str()));
	else
		uiButton->setIcon(QIcon());

	IElement::setState(newState);
}

int Button::getState() const
{
	return state;
}

void Button::setSubscriber(ISubscriber* subscriber)
{
	this->subscriber = subscriber;
}
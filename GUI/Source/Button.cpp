#include <GUI/Include/Button.h>

#include <TAM2C/Include/Definitions.h>

Button::Button(QPushButton* uiButton, const std::string& nameImage) :
	uiButton(uiButton), state(RELESED), nameImage(nameImage)
{
	connect(uiButton, SIGNAL(pressed()), this, SLOT(Pressed()));
	connect(uiButton, SIGNAL(released()), this, SLOT(Released()));
}

void Button::Pressed()
{
	uiButton->setIcon(QPixmap(Definitions::getGUIPath(nameImage).c_str()));
	state = PRESSED;
}

void Button::Released()
{
	uiButton->setIcon(QIcon());
	state = RELESED;
}

void Button::setState(int state)
{
	if (state < 0 || state > 1)
		return;

	this->state = (ButtonState)state;

	uiButton->setIcon(QPixmap(Definitions::getGUIPath(nameImage).c_str()));
}
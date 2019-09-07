#include <GUI/Include/Button.h>

#include <TAM2C/Include/Definitions.h>

Button::Button(QPushButton* uiButton, std::string nameImage) :
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

#include <GUI/Include/Switch.h>

#include <TAM2C/Include/Definitions.h>

Switch::Switch(QPushButton* uiButton, const std::string& nameImage1, const std::string& nameImage2) :
	uiButton(uiButton), state(POS_1), positions(2)
{
	nameImages[0] = nameImage1;
	nameImages[1] = nameImage2;

	setState(state);

	connect(uiButton, SIGNAL(pressed()), this, SLOT(Pressed()));
}

Switch::Switch(QPushButton* uiButton, const std::string& nameImage1, const std::string& nameImage2, const std::string& nameImage3) :
	uiButton(uiButton), state(POS_1), positions(3)
{
	nameImages[0] = nameImage1;
	nameImages[1] = nameImage2;
	nameImages[2] = nameImage3;

	setState(state);

	connect(uiButton, SIGNAL(pressed()), this, SLOT(Pressed()));
}

void Switch::Pressed()
{
	state = SwitchState(state + 1);
	if (state == INVALID || state > positions - 1)
		state = SwitchState(0);

	uiButton->setIcon(QPixmap(Definitions::getGUIPath(nameImages[state]).c_str()));
}

void Switch::setState(int state)
{
	if (state < 0 || state > positions - 1)
		return;

	this->state = (SwitchState)state;

	uiButton->setIcon(QPixmap(Definitions::getGUIPath(nameImages[state]).c_str()));
}
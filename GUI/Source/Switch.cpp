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
	if (!usable)
		return;

	SWITCH_STATE newState = SWITCH_STATE(state + 1);
	if (newState == INVALID_SWITCH || newState > positions - 1)
		setState(0);
	else
		setState(newState);
}

void Switch::setState(int newState)
{
	if (newState < 0 || newState > positions - 1 || !enabled)
		return;

	state = (SWITCH_STATE)newState;

	uiButton->setIcon(QPixmap(Definitions::getGUIPath(nameImages[newState]).c_str()));

	if (callbacks.find(state) != callbacks.end())
		callbacks.at(state)();
}
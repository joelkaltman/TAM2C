#include <GUI/Include/Switch.h>

#include <TAM2C/Include/Config.h>

Switch::Switch(QPushButton* uiButton, const std::string& nameImage1, const std::string& nameImage2) :
	uiButton(uiButton), state(POS_1)
{
	this->nameImages.push_back(nameImage1);
	this->nameImages.push_back(nameImage2);

	setState(state);

	connect(uiButton, SIGNAL(pressed()), this, SLOT(Pressed()));

	initialState = state;
}

Switch::Switch(QPushButton* uiButton, const std::vector<std::string>& images) :
	uiButton(uiButton), state(POS_1)
{
	this->nameImages = images;

	setState(state);

	connect(uiButton, SIGNAL(pressed()), this, SLOT(Pressed()));

	initialState = state;
}

void Switch::Pressed()
{
	if (!usable)
		return;

	SWITCH_STATE newState = SWITCH_STATE(state + 1);
	if (newState == INVALID_SWITCH || newState >= this->nameImages.size())
		setState(0);
	else
		setState(newState);
}

void Switch::setState(int newState)
{
	if (newState < 0 || newState >= this->nameImages.size() || !enabled)
		return;

	state = (SWITCH_STATE)newState; 

	 (nameImages[newState].empty()) ? uiButton->setIcon(QIcon()) : uiButton->setIcon(QPixmap(Config::getGUIPath(nameImages[newState]).c_str()));

	IElement::setState(newState);
}

int Switch::getState() const
{
	return state;
}

int Switch::getPositions() const
{
	return this->nameImages.size();
}

void Switch::addSubscriber(ISubscriber* subscriber)
{
	this->subscribers.push_back(subscriber);
}
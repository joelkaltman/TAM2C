#include <GUI/Include/IElement.h>

void IElement::setState(int newState)
{
	for (auto& sub : subscribers)
		sub->notify(id, getType(), newState);

	if (callbacks.find(newState) != callbacks.end())
	{
		CBTime cbTime = callbacks.at(newState);

		sleepUI(cbTime.first);

		cbTime.second();
	}
}

void IElement::setInitialState()
{
}

void IElement::setCallback(int cbState, const std::function<void()>& cb, int delayMs)
{
	this->callbacks[cbState] = std::make_pair(delayMs, cb);
}

bool IElement::getEnabled() const
{
	return this->enabled;
}

void IElement::setEnabled(bool enabled)
{
	this->enabled = enabled;
}

bool IElement::getUsable() const
{
	return this->usable;
}

void IElement::setUsable(bool usable)
{
	this->usable = usable;
}

void IElement::setId(ELEM_ID id)
{
	this->id = id;
}

void IElement::addSubscriber(ISubscriber* subscriber)
{
}

void IElement::sleepUI(int ms)
{
	QTime dieTime = QTime::currentTime().addMSecs(ms);
	while (QTime::currentTime() < dieTime)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
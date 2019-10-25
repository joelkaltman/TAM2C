#include <GUI/Include/IElement.h>

void IElement::setState(int newState)
{
	if (subscriber)
		subscriber->notify(id, newState);

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

void IElement::setEnabled(bool enabled)
{
	this->enabled = enabled;
}

void IElement::setUsable(bool usable)
{
	this->usable = usable;
}

void IElement::setId(ELEM_ID id)
{
	this->id = id;
}

void IElement::setSubscriber(ISubscriber* subscriber)
{
}

void IElement::sleepUI(int ms)
{
	QTime dieTime = QTime::currentTime().addMSecs(ms);
	while (QTime::currentTime() < dieTime)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
#include <GUI/Include/IElement.h>

void IElement::setState(int newState)
{
	if (subscriber)
		subscriber->notify(id, newState);

	if (callbacks.find(newState) != callbacks.end())
	{
		CBTime cbTime = callbacks.at(newState);

		QTime dieTime = QTime::currentTime().addMSecs(cbTime.first);
		while (QTime::currentTime() < dieTime)
			QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

		cbTime.second();
	}
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

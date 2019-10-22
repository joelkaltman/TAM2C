#pragma once

#include <QtWidgets/QWidget>
#include <QTime>

#include <GUI/GeneratedFiles/ui_ApPanels.h>

#include <GUI/Include/Definitions.h>
#include <GUI/Include/ISubscriber.h>

class IElement : public QWidget
{
	Q_OBJECT
public:
	typedef std::pair<int, std::function<void()>> CBTime;

	virtual int getState() const = 0;

	virtual void setState(int newState);

	virtual void setSubscriber(ISubscriber* subscriber);

	void setCallback(int cbState, const std::function<void()>& cb, int delayMs = 0);

	void setEnabled(bool enabled);

	void setUsable(bool usable);

	void setId(ELEM_ID id);


protected:
	ELEM_ID id = INVALID_ID;

	bool enabled = true;
	bool usable = true;

	std::map<int, CBTime> callbacks;

	ISubscriber* subscriber = nullptr;
};
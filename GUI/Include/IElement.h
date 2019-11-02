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

	virtual ELEM_TYPE getType() const = 0;

	virtual int getState() const = 0;
	virtual void setState(int newState);
	virtual void setInitialState();

	virtual void setSubscriber(ISubscriber* subscriber);

	void setCallback(int cbState, const std::function<void()>& cb, int delayMs = 0);

	bool getEnabled() const;
	void setEnabled(bool enabled);

	bool getUsable() const;
	void setUsable(bool usable);

	void setId(ELEM_ID id);

	static void sleepUI(int ms);

protected:
	ELEM_ID id = INVALID_ID;

	bool enabled = true;
	bool usable = true;

	int initialState = 0;

	std::map<int, CBTime> callbacks;

	ISubscriber* subscriber = nullptr;
};
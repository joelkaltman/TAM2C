#pragma once

#include <QtWidgets/QWidget>
#include <QTime>

#include <GUI/GeneratedFiles/ui_ApPanels.h>

#include <GUI/Include/Definitions.h>

class UIElement : public QWidget
{
	Q_OBJECT
public:
	typedef std::pair<int, std::function<void()>> CBTime;

	virtual void setState(int newState) = 0;
	virtual int getState() const = 0;

	void setCallback(int cbState, const std::function<void()>& cb, int delayMs = 0)
	{
		this->callbacks[cbState] = std::make_pair(delayMs, cb);
	}

	void setEnabled(bool enabled)
	{
		this->enabled = enabled;
	}

	void setUsable(bool usable)
	{
		this->usable = usable;
	}

protected:
	bool enabled = true;
	bool usable = true;
	std::map<int, CBTime> callbacks;
};
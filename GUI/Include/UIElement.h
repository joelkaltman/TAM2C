#pragma once

#include <QtWidgets/QWidget>
#include <GUI/GeneratedFiles/ui_ApPanels.h>

#include <GUI/Include/Definitions.h>

class UIElement : public QWidget
{
	Q_OBJECT
public:
	virtual void setState(int newState) = 0;
	virtual int getState() const = 0;

	void setCallback(int cbState, const std::function<void()>& cb)
	{
		this->callbacks[cbState] = cb;
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
	std::map<int, std::function<void()>> callbacks;
};
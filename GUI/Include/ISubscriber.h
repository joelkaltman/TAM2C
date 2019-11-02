#pragma once

#include <GUI/Include/Definitions.h>

class ISubscriber
{
	public:
		ISubscriber() = default;

		virtual void notifyUIChanged(ELEM_ID elem, ELEM_TYPE type, int state) = 0;
};
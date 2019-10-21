#pragma once

#include <GUI/Include/Definitions.h>

class ISubscriber
{
	public:
		ISubscriber() = default;

		virtual void notify(ELEM_ID elem, int state) = 0;
};
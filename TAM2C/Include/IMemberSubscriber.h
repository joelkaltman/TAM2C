#pragma once

#include <TAM2C/Include/IMemberConfig.h>

class IMemberSubscriber
{
public:
	IMemberSubscriber() = default;

	virtual void notifyMemberConfigChanged(const IMemberConfig& config) = 0;
};
#pragma once

#include "DMEvent.h"

class DMEventFight : public DMEvent
{
public:
	DMEventFight(map<int, DMPlayer*> player);
	virtual ~DMEventFight(void);
	virtual bool Continue();
};


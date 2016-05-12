#pragma once
#include "dmevent.h"
class DMEventEdle :
	public DMEvent
{
public:
	DMEventEdle(DMPlayer* player): DMEvent(player){};
	virtual ~DMEventEdle(void);
private:
	virtual bool Continue() override;
};


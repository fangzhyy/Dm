#pragma once
#include "dmevent.h"
#include "DMGlobal.h"

using namespace std;

class DMEventIdle :
	public DMEvent
{
public:
	virtual ~DMEventIdle(void);
	static DMEventIdle* create(map<int, DMPlayer*> player);

private:
	DMEventIdle(map<int, DMPlayer*> player);
	virtual bool Continue() override;
	virtual bool init() override;
};


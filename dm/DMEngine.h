#pragma once

#include "DMEvent.h"

class DMEngine
{
public:
	DMEngine(void);
	~DMEngine(void);
	
public:
	void run();
private:
	vector<DMEvent> mEvents;
};


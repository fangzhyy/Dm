#pragma once

#include "DMEvent.h"

class DMEngine
{
public:
	DMEngine(void);
	~DMEngine(void);
	void wait(int s);
	void addEvent(DMEvent* e);
public:
	void run();
private:
	vector<DMEvent*> mEvents;
};


#pragma once

#include "stdafx.h"


class DMEnginBase
{
public:
	DMEnginBase(void);
	~DMEnginBase(void);
public:
	void start();
protected:
	virtual void run() = 0;
};


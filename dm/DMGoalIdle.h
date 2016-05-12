#pragma once
#ifndef __DMGOALIDLE_H__
#define __DMGOALIDLE_H__

#include "DMGlobal.h"
#include "DMGoal.h"

class DMGoalIdle : public DMGoal
{
public:
	DMGoalIdle();
	virtual ~DMGoalIdle();
	CREAET_FUNC(DMGoalIdle);
private:
	virtual bool init() override;
	virtual bool doTask() override;
};

#endif
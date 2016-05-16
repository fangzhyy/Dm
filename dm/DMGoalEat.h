#pragma once
#include "DMGoal.h"
#include "DMGlobal.h"

class DMGoalEat :
	public DMGoal
{
public:
	virtual ~DMGoalEat();
	CREAET_FUNC(DMGoalEat)
private:
	DMGoalEat();
	virtual void onExit(DMPlayer* player) override;
	virtual bool doTask(DMPlayer* player) override;
	PROPERTY(double, EatSpeed)
};


#include "stdafx.h"
#include "DMGoal.h"


DMGoal::DMGoal()
{
}


DMGoal::~DMGoal()
{
}

void DMGoal::addSubGoal(DMGoal* goal) {
	mSubGoals.push_back(goal);

}

//返回值：true，完成 false，需要继续
bool DMGoal::excute(DMPlayer* player)
{
	if(mSubGoals.size()) {
		auto iter = mSubGoals.begin();
		if ((*iter)->excute(player)){
			auto tempPtr = *iter;
			iter = mSubGoals.erase(iter);
			tempPtr->onExit(player);
			delete tempPtr;
		}
		return false;
	}
	else
		return doTask(player);

}

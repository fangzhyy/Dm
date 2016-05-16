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

//����ֵ��true����� false����Ҫ����
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

#include "stdafx.h"
#include "DMGoal.h"


DMGoal::DMGoal()
{
}


DMGoal::~DMGoal()
{
}

void DMGoal::addSubGoal(const DMGoal& goal) {
	mSubGoals.push_back(goal);

}

//����ֵ��true����� false����Ҫ����
bool DMGoal::excute()
{
	for (auto iter = mSubGoals.begin(); iter < mSubGoals.end(); iter++) {
		if (iter->excute()){
			iter = mSubGoals.erase(iter);
		}
		else
			break;
	}
	if (mSubGoals.size() == 0)
		return doTask();

}

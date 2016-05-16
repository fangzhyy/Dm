#pragma once
#include <vector>
#include "DMGlobal.h"

using namespace std;

class DMPlayer;

class DMGoal
{
public:
	DMGoal();
	virtual ~DMGoal();
	void addSubGoal(DMGoal* goal);
public:	
	bool excute(DMPlayer* player);
protected:
	virtual bool doTask(DMPlayer* player) = 0;
	virtual bool init(){
		return true;
	};
	virtual void onExit(DMPlayer* player){}
private:
	vector<DMGoal*> mSubGoals;
};


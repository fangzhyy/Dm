#pragma once
#include <vector>

using namespace std;

class DMGoal
{
public:
	DMGoal();
	virtual ~DMGoal();
	void addSubGoal(const DMGoal& goal);
public:	
	bool excute();
protected:
	virtual bool doTask() = 0;
	virtual bool init() = 0;
private:
	vector<DMGoal> mSubGoals;
};


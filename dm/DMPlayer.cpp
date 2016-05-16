#include "stdafx.h"
#include "DMPlayer.h"
#include "DMMessage.h"
#include "DMGoal.h"
#include "DMGoalIdle.h"
#include "singleton.h"

DMPlayer::DMPlayer(void) : mGoal(nullptr), mHappy(5), mHunger(0), mTired(0)
{

}


DMPlayer::~DMPlayer(void)
{
	delete mGoal;
}

void DMPlayer::HandleMessage(DMMessage* msg) {
	
}

bool DMPlayer::act()
{
	//根据所在的event上下文，自身状态选择适当的行为，和执行行为的方式。
	_ASSERT(mGoal);
	mGoal->excute(this);
	return true;
}

void DMPlayer::setGoal(DMGoal* goal) {
	delete goal;
	mGoal = goal;
}

bool DMPlayer::init() {
	return true;
}

//每次增加1分钟
void DMPlayer::onTimeElapse() {
	//一天增加两点饥饿
	double Increament = 2.0 / (24 * 60);
	mHunger += Increament;
	mTired += Increament;
	//xiaohua
	if (mStuffInStomach > 0){
		double digestSpeed = mStuffInStomach / 240;
		mStuffInStomach -= digestSpeed;
		MinZero(mStuffInStomach);
		mStuffToCarryOut += digestSpeed;
	}
	
}

void DMPlayer::onEat(double food) {
	mStuffInStomach += food;
}
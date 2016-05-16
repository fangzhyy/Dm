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
	//�������ڵ�event�����ģ�����״̬ѡ���ʵ�����Ϊ����ִ����Ϊ�ķ�ʽ��
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

//ÿ������1����
void DMPlayer::onTimeElapse() {
	//һ���������㼢��
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
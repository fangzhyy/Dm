#include "stdafx.h"
#include "DMPlayer.h"
#include "DMMessage.h"
#include "DMGoal.h"

DMPlayer::DMPlayer(void) : mGoal(nullptr)
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
	mGoal->excute();
	return true;
}

void DMPlayer::setGoal(DMGoal* goal) {
	delete goal;
	mGoal = goal;
}
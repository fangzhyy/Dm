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
	//�������ڵ�event�����ģ�����״̬ѡ���ʵ�����Ϊ����ִ����Ϊ�ķ�ʽ��
	_ASSERT(mGoal);
	mGoal->excute();
	return true;
}

void DMPlayer::setGoal(DMGoal* goal) {
	delete goal;
	mGoal = goal;
}
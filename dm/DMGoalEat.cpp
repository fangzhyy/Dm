#include "stdafx.h"
#include "DMGoalEat.h"
#include "DMPlayer.h"

DMGoalEat::DMGoalEat() : mEatSpeed(0.0)
{
}


DMGoalEat::~DMGoalEat()
{
}

void DMGoalEat::onExit(DMPlayer* player) {
	

}

bool DMGoalEat::doTask(DMPlayer* player) {
	double hunger = player->getHunger();
	if (mEatSpeed == 0.0) {
		mEatSpeed = DMPlayer::sStateMaxValue - hunger;
		mEatSpeed /= 30;
	}
	hunger -= mEatSpeed;
	if (hunger < 0.0)
		hunger = 0;
	player->setHunger(hunger);
	return hunger > 0;
}

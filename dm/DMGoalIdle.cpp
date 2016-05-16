#include "stdafx.h"
#include "DMGoalIdle.h"
#include "DMPlayer.h"
#include "DMGoalEat.h"

DMGoalIdle::DMGoalIdle()
{
}


DMGoalIdle::~DMGoalIdle()
{
}

bool DMGoalIdle::init() {

	return true;
}

bool DMGoalIdle::doTask(DMPlayer* player) {
	double hunger = player->getHunger();
	double tired = player->getTired();
	if (hunger > DMPlayer::sNeedEatValue){
		auto g = DMGoalEat::create();
		addSubGoal(g);
	}
	return false;
}
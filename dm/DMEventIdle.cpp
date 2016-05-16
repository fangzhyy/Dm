#include "stdafx.h"
#include "DMEventIdle.h"
#include "DMPlayer.h"
#include "DMGoalIdle.h"

DMEventIdle::DMEventIdle(map<int, DMPlayer*> player) : DMEvent(player)
{
}


DMEventIdle::~DMEventIdle(void)
{
}

DMEventIdle* DMEventIdle::create(map<int, DMPlayer*> player) {
	CREATE(DMEventIdle, player);
}

bool DMEventIdle::init() {
	for (auto iter : mPlayers) {
		auto goal = DMGoalIdle::create();
		iter.second->setGoal(goal);
	}
	return true;
}


bool DMEventIdle::isFinished() {
	return false;
}
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

bool DMEventIdle::Continue() {
	auto iter = mPlayers.begin();
	bool alive = false;
	for (auto iter : mPlayers) {
		alive = iter.second->act();
	}
	return alive;
}

bool DMEventIdle::init() {
	for (auto iter : mPlayers) {
		auto goal = DMGoalIdle::create();
		iter.second->setGoal(goal);
	}

}

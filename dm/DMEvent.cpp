#include "stdafx.h"
#include "DMEvent.h"
#include "DMMessage.h"
#include "DMPlayer.h"

DMEvent::~DMEvent(void)
{
}

bool DMEvent::Update() {
	mDuration++;
	DispatchMessage();
	return Continue();
}

bool DMEvent::Continue() {
	auto iter = mPlayers.begin();
	bool alive = false;
	for (auto iter : mPlayers) {
		iter.second->onTimeElapse();
		alive = iter.second->act();
	}
	return isFinished();
}

void DMEvent::DispatchToAll(DMMessage* msg) {
	map<int , DMPlayer*>::iterator iter = mPlayers.begin();
	while(iter != mPlayers.end()) {
		iter->second->HandleMessage(msg);
	}
}

void DMEvent::DispatchMessage() {
	vector<DMMessage*>::iterator iter = mMsgQueue.begin();
	while(iter != mMsgQueue.end()) {
		int targetId = (*iter)->target();
		if( targetId == KSendToAllId) {
			DispatchToAll(*iter);
		}
		else{
			DMPlayer* player = mPlayers[targetId];
			if(player)
				player->HandleMessage(*iter);
		}
		delete *iter;
	}
	mMsgQueue.clear();
}
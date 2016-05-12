#include "stdafx.h"
#include "DMFsState.h"
#include "DMPlayer.h"

DMFsState::DMFsState(DMPlayer* player) : mOwner(player)
{
}



DMFsState::~DMFsState(void)
{
}

void DMFsState::addChildren(DMFsState* state) {
	mChildren.push_back(state);
}

void DMFsState::removeChildren(DMFsState* state) {
	vector<DMFsState*>::iterator iter = mChildren.begin();
	vector<DMFsState*>::iterator target;
	while(iter != mChildren.end()) {
		if(*iter == state) {
			(*iter)->onExit();
			target = iter;
			delete *iter;
			break;
		}
		iter++;
	}
	mChildren.erase(target);
}

void DMFsState::clearChildren() {
	vector<DMFsState*>::iterator iter = mChildren.begin();
	while(iter != mChildren.end()) {
		(*iter)->onExit();
		delete *iter;
	}
	mChildren.clear();
}
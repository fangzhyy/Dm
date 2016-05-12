#pragma once

#include "stdafx.h"
#include "DMFsm.h"

class DMPlayer;

class DMFsState
{
protected:
	DMFsState(DMPlayer* player);
public:
	virtual ~DMFsState(void);
protected:
	vector<DMFsState*> mChildren;
	void addChildren(DMFsState* state);
	void removeChildren(DMFsState* state);
	void clearChildren();
protected:
	virtual void onEnter() = 0;
	virtual void onExit() = 0;
	virtual void Excute() = 0;
	virtual void onResume() = 0;
protected:
	DMPlayer* mOwner;
friend DMFsm;
};


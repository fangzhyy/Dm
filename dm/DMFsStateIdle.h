#pragma once
#include "dmfsstate.h"
class DMFsStateIdle :
	public DMFsState
{
public:
	DMFsStateIdle(DMPlayer* player);
	virtual ~DMFsStateIdle(void);
private:
	virtual void onEnter();
	virtual void onExit();
	virtual void onResume();
	virtual void Excute();
};


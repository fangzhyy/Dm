#include "stdafx.h"
#include "DMFsm.h"
#include "DMFsState.h"

DMFsm::DMFsm(DMFsState* initState) : mCurrentState(initState)
{
}


DMFsm::~DMFsm(void)
{
}

void DMFsm::setState(DMFsState* state) {
	if(mCurrentState){
		delete mLastState;
		mLastState = mCurrentState;
	}
	mCurrentState = state;
}

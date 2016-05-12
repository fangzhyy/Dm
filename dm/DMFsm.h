#pragma once

class DMFsState;

class DMFsm
{
protected:
	DMFsm(DMFsState* initState);
public:
	~DMFsm(void);
	void setState(DMFsState* state);
private:
	DMFsState* mCurrentState;
	DMFsState* mLastState;
	DMFsState* mGlobalState;
};


#pragma once

#include "DMEventFrame.h"


class DMPlayer;
class DMMessage;

class DMEvent 
{
public:
	DMEvent(map<int, DMPlayer*> player) : mPlayers(player), mDuration(0){};
	virtual ~DMEvent(void);
	virtual bool Update();
	virtual bool Continue();
	virtual bool init() = 0;
	virtual bool isFinished() = 0;
protected:
	vector<DMEventFrame> mFrames;
	map<int ,DMPlayer*> mPlayers;
	vector<DMMessage*> mMsgQueue;
	void SendMessage(DMMessage* msg);
private:
	void DispatchMessage();
	void DispatchToAll(DMMessage* msg);
	const static int KSendToAllId = -1;
	int mDuration;
};


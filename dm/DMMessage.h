#pragma once
class DMMessage
{
public:
	~DMMessage(void);
private:
	DMMessage();
	DMMessage(int senderId, int targetId, void* extra = 0):mSenderId(senderId), mTargetId(targetId), mExtra(extra){};
public:
	static DMMessage* create(int senderId, int targetId, void* extra = 0);
	int target(){ return mTargetId; }
private:
	int mTargetId;
	int mSenderId;
	void* mExtra;
};


#include "stdafx.h"
#include "DMMessage.h"


DMMessage::DMMessage(void)
{
}


DMMessage::~DMMessage(void)
{
}

DMMessage* DMMessage::create(int senderId, int targetId, void* extra)
{
	return new DMMessage(senderId, targetId, extra);
}
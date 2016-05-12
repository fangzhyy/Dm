/*
 * AbstractEngine.h
 *
 *  Created on: 2015年1月20日
 *      Author: kerlw
 */

#ifndef ABSTRACTENGINE_H_
#define ABSTRACTENGINE_H_

#include "Handler.h"

class AbstractEngine : public HandlerImpl {
public:
	AbstractEngine():mHandler(NULL){};
	virtual void handleMessage(const Message& msg) = 0;
	virtual ~AbstractEngine() {}

	void sendMessage(const int32_t& what) {
		if (mHandler)
			mHandler->sendEmptyMessage(what);
	}
	void sendMessageDelay(const int32_t& what, const uint32_t& delay) {
		if (mHandler)
			mHandler->sendEmptyMessageDelayed(what, delay);
	}
	void sendMessage(const int32_t& what, void* obj) {
        if(mHandler) {
            Message* msg = mHandler->obtainMessage(what, 0, 0, obj);
            mHandler->sendMessage(*msg);
        }
	}
	void sendMessage(const int32_t& what, const int32_t& arg1, const int32_t& arg2, void* obj = NULL) {
        if(mHandler) {
            Message* msg = mHandler->obtainMessage(what, arg1, arg2, obj);
            mHandler->sendMessage(*msg);
        }
	}
protected:
	Handler* mHandler;
};


#endif /* ABSTRACTENGINE_H_ */

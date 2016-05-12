#pragma once

#include "stdafx.h"

class DMMessage;
class DMGoal;
class DMPlayer
{
private:
	static const int sStateMaxValue = 10;
public:
	DMPlayer();
	~DMPlayer(void);
	int id(){return mId;}
	void HandleMessage(DMMessage* msg);
	void setGoal(DMGoal* goal);
private:
	vector<DMPlayer*> mMates;
	vector<DMPlayer*> mTargets;
	DMGoal* mGoal;
	void observe();
	int mId;
	//五天不吃饭会会死，值为8时不能动，为9时昏迷。为10就死了。全饱为0，所以一天增加两点。
	int mHunger;
	//五天不睡觉会死，为8时昏迷。那么一天增加2.一天睡六个小时睡眠补满，那么睡三个小时减少一点。
	//hunger和tired的值可以相加，很大程度说明身体状态。如果设置为三天不吃不睡会死，那么两个属性的和为12时会死，和越大越虚弱。
	//两个条件的竞争关系，简单的认为哪个值更大，哪个优先级就更高。
	//任意一个值超过6，会随机对基础属性造成永久损害。
	int mTired;
	int mPoo;
	int mHappy;
	int mStrength;
	int mFatigue;
	int mAgility;
public:
	virtual bool act();
};


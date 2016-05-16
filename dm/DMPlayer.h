#pragma once

#include "stdafx.h"
#include "DMGlobal.h"

class DMMessage;
class DMGoal;
class DMPlayer
{
public:
	static const int sStateMaxValue = 10;
	static const int sNeedEatValue = 1;
public:
	DMPlayer();
	~DMPlayer(void);
	int id(){return mId;}
	void HandleMessage(DMMessage* msg);
	void setGoal(DMGoal* goal);
	void onTimeElapse();
private:
	vector<DMPlayer*> mMates;
	vector<DMPlayer*> mTargets;
	DMGoal* mGoal;
	void observe();
	bool init();
	PROPERTY(int, Id)
		//五天不吃饭会会死，值为8时不能动，为9时昏迷。为10就死了。全饱为0，所以一天增加两点。
		PROPERTY(double, Hunger)
		//五天不睡觉会死，为8时昏迷。那么一天增加2.一天睡六个小时睡眠补满，那么睡三个小时减少一点。
		//hunger和tired的值可以相加，很大程度说明身体状态。如果设置为三天不吃不睡会死，那么两个属性的和为12时会死，和越大越虚弱。
		//两个条件的竞争关系，简单的认为哪个值更大，哪个优先级就更高。
		//任意一个值超过6，会随机对基础属性造成永久损害。
		PROPERTY(double, Tired)
		PROPERTY(int, Poo)
		PROPERTY(int, Happy)
		PROPERTY(int, Strength)
		PROPERTY(int, Fatigue)
		PROPERTY(int, Agility)
		PROPERTY(int, ExistDay)
		PROPERTY(float, ExistHour)
		PROPERTY(double, StuffInStomach)
		PROPERTY(double, StuffToCarryOut)
public:
	virtual bool act();
	void onEat(double food);
	CREAET_FUNC(DMPlayer);
	friend class DMGoalIdle;
	friend class DMGoalEat;
};


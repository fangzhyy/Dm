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
		//���첻�Է��������ֵΪ8ʱ���ܶ���Ϊ9ʱ���ԡ�Ϊ10�����ˡ�ȫ��Ϊ0������һ���������㡣
		PROPERTY(double, Hunger)
		//���첻˯��������Ϊ8ʱ���ԡ���ôһ������2.һ��˯����Сʱ˯�߲�������ô˯����Сʱ����һ�㡣
		//hunger��tired��ֵ������ӣ��ܴ�̶�˵������״̬���������Ϊ���첻�Բ�˯��������ô�������Եĺ�Ϊ12ʱ��������Խ��Խ������
		//���������ľ�����ϵ���򵥵���Ϊ�ĸ�ֵ�����ĸ����ȼ��͸��ߡ�
		//����һ��ֵ����6��������Ի���������������𺦡�
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


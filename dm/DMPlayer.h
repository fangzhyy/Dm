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
	//���첻�Է��������ֵΪ8ʱ���ܶ���Ϊ9ʱ���ԡ�Ϊ10�����ˡ�ȫ��Ϊ0������һ���������㡣
	int mHunger;
	//���첻˯��������Ϊ8ʱ���ԡ���ôһ������2.һ��˯����Сʱ˯�߲�������ô˯����Сʱ����һ�㡣
	//hunger��tired��ֵ������ӣ��ܴ�̶�˵������״̬���������Ϊ���첻�Բ�˯��������ô�������Եĺ�Ϊ12ʱ��������Խ��Խ������
	//���������ľ�����ϵ���򵥵���Ϊ�ĸ�ֵ�����ĸ����ȼ��͸��ߡ�
	//����һ��ֵ����6��������Ի���������������𺦡�
	int mTired;
	int mPoo;
	int mHappy;
	int mStrength;
	int mFatigue;
	int mAgility;
public:
	virtual bool act();
};


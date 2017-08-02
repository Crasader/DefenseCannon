#pragma once
#ifndef __HeartBuff_H__
#define __HeartBuff_H__
#include"cocos2d.h"

class HeartBuff :public cocos2d::CCSprite
{
public:
	HeartBuff();
	virtual ~HeartBuff();
	CREATE_FUNC(HeartBuff);
	bool init();

	/*
	*m_vx��m_vy��setter����buff�ƶ��ٶ�
	*@Param v���ٶ�
	*@Param angle:�ƶ�����Ƕȣ��Դ�����Ϊ��׼
	*/
	void setVelocity(float v, float angle);

	/*
	*�ƶ�
	*/
	void move();

	/*
	*decCd();
	*������ȴ�ӳ�
	*/
	void decCd();

	/*
	*getCd()
	*��ȡcdʱ��
	*/
	const int& getCd();
private:
	float m_vx;
	float m_vy;
	int m_cd;
};

#endif // !__HeartBuff_H__


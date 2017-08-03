#pragma once
#ifndef __BUFF_H__
#define __BUFF_H__
#include"cocos2d.h"

class Buff:public cocos2d::CCSprite
{
public:
	Buff();
	virtual ~Buff();
	CREATE_FUNC(Buff);
	bool init();

	/*
	*m_vx��m_vy��setter����buff�ƶ��ٶ�
	*@Param v���ٶ�
	*@Param angle:�ƶ�����Ƕȣ��Դ�����Ϊ��׼
	*/
	virtual void setVelocity(float v, float angle);

	/*
	*�ƶ�
	*/
	virtual void move();

	/*
	*decCd();
	*������ȴ�ӳ�
	*/
	virtual void decCd();

	/*
	*getCd()
	*��ȡcdʱ��
	*/
	virtual const int& getCd();

	/*
	*doBuffTing() 
	*����BuffЧ��
	*/
	virtual void doBuffThing();
protected:
	float m_vx;
	float m_vy;
	int m_cd;
};

#endif // !__BUFF_H__


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
	*m_vx和m_vy的setter设置buff移动速度
	*@Param v：速度
	*@Param angle:移动方向角度，以垂向上为基准
	*/
	virtual void setVelocity(float v, float angle);

	/*
	*移动
	*/
	virtual void move();

	/*
	*decCd();
	*减少冷却延迟
	*/
	virtual void decCd();

	/*
	*getCd()
	*获取cd时长
	*/
	virtual const int& getCd();

	/*
	*doBuffTing() 
	*处理Buff效果
	*/
	virtual void doBuffThing();
protected:
	float m_vx;
	float m_vy;
	int m_cd;
};

#endif // !__BUFF_H__


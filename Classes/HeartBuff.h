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
	*m_vx和m_vy的setter设置buff移动速度
	*@Param v：速度
	*@Param angle:移动方向角度，以垂向上为基准
	*/
	void setVelocity(float v, float angle);

	/*
	*移动
	*/
	void move();

	/*
	*decCd();
	*减少冷却延迟
	*/
	void decCd();

	/*
	*getCd()
	*获取cd时长
	*/
	const int& getCd();
private:
	float m_vx;
	float m_vy;
	int m_cd;
};

#endif // !__HeartBuff_H__


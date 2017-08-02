#pragma once

#ifndef __BULLET_H__
#define __BULLET_H__
#include"cocos2d.h"

class Bullet :public cocos2d::CCSprite
{
public:
	Bullet();
	virtual ~Bullet();
	CREATE_FUNC(Bullet);
	bool init();

	/*
	*m_vx、m_vy子弹速度的setter和getter方法
	*/
	void setVelocity(float v, float angle);
	float getVx();
	float getVy();

	/*
	*m_isDelete标记该子弹是否应被删除的setter和getter方法
	*/
	void setIsDelete(const bool& b);
	const bool& getIsDelete();

	/*
	*m_attack子弹攻击力的setter和getter方法
    */
	void setAttack(const int& attack);
	const int& getAttack();
private:
	float m_vx;
	float m_vy;
	bool m_isDelete;
	int m_attack;
};

#endif // !__BULLET_H__


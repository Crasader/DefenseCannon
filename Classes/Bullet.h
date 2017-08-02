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
	*m_vx��m_vy�ӵ��ٶȵ�setter��getter����
	*/
	void setVelocity(float v, float angle);
	float getVx();
	float getVy();

	/*
	*m_isDelete��Ǹ��ӵ��Ƿ�Ӧ��ɾ����setter��getter����
	*/
	void setIsDelete(const bool& b);
	const bool& getIsDelete();

	/*
	*m_attack�ӵ���������setter��getter����
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


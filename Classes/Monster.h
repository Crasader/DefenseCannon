#pragma once
#ifndef  __MONSTER_H__
#define __MONSTER_H__
#include"cocos2d.h"

class Monster :public cocos2d::CCSprite
{
public:
	Monster();
	virtual ~Monster();
	CREATE_FUNC(Monster);
	virtual bool init();

	/*
	*setVelocity(const float& v, const float& angle);
	*设置怪物速度
	*@Param v：速度大小
	*@Param angle：移动方向角度
	*/
	virtual void setVelocity(const float& v, const float& angle);

	/*
	*move();
	*移动自身
	*/
	virtual void move();

	/*
	*m_life怪物生命值的setter和getter方法
	*/
	virtual void setLife(const float& life);
	virtual const float& getLife();

	/*
	*m_score怪物死亡得分数的setter和getter方法
	*/
	void setScore(const int& score);
	const int& getScore();

	/*
	*m_glod怪物死亡获得金币数的setter和getter方法
	*/
	void setGlod(const int& glod);
	const int& getGlod();

	virtual Monster* generiteChild();
protected:
	float m_vx;
	float m_vy;
	float m_life;
	int m_score;
	int m_glod;
};

#endif // ! __STAR_H__


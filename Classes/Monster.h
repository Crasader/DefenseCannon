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
	*���ù����ٶ�
	*@Param v���ٶȴ�С
	*@Param angle���ƶ�����Ƕ�
	*/
	virtual void setVelocity(const float& v, const float& angle);

	/*
	*move();
	*�ƶ�����
	*/
	virtual void move();

	/*
	*m_life��������ֵ��setter��getter����
	*/
	virtual void setLife(const float& life);
	virtual const float& getLife();

	/*
	*m_score���������÷�����setter��getter����
	*/
	void setScore(const int& score);
	const int& getScore();

	/*
	*m_glod����������ý������setter��getter����
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


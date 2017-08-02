#pragma once
#ifndef __CANNON_H__
#define __CANNON_H__
#include"cocos2d.h"

class Cannon :public cocos2d::CCSprite
{
public:
	Cannon() {}
	virtual ~Cannon() {}

	CREATE_FUNC(Cannon);

	bool init();

	/*
	*m_drawLine����Ƿ������׼�ߵ�setter��getter����
	*/
	void setDrawLine(bool var);
	const bool& getDrawLine() const;

	/*
	*m_attack���ڹ�������setter��getter����
	*/
	void setAttack(const int& attack);
	const int& getAttack();

	/*
	*m_velocity���ڷ����ӵ����ٶȵ�setter��getter����
	*/
	void setVelocity(const float& v);
	const float& getVelocity();

	/*
	*m_bulletGlodһ���ӵ������ҵ�getter����
	*/
	const int& getBulletGlod();
protected:
	virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags) override;

private:
	bool drawLine;
	cocos2d::DrawNode* m_drawNode;
	int m_attack;
	float m_velocity;
	int m_bulletGlod;
};

#endif // !__CANNON_H__


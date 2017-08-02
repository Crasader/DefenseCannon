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
	*m_drawLine标记是否绘制瞄准线的setter和getter方法
	*/
	void setDrawLine(bool var);
	const bool& getDrawLine() const;

	/*
	*m_attack大炮攻击力的setter和getter方法
	*/
	void setAttack(const int& attack);
	const int& getAttack();

	/*
	*m_velocity大炮发射子弹的速度的setter和getter方法
	*/
	void setVelocity(const float& v);
	const float& getVelocity();

	/*
	*m_bulletGlod一发子弹所需金币的getter方法
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


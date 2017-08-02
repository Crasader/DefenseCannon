#include "Bullet.h"
#include"StaticData.h"
#include"Common.h"
#include<cmath>

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

bool Bullet::init()
{
	if (CCSprite::init())
	{
		initWithFile(STATIC_STRING_DATA("Bullet"));
		setIsDelete(false);
		return true;
	}
	return false;
}

void Bullet::setVelocity(float v, float angle)
{
	m_vx = v*sinf(angle);
	m_vy = v*cosf(angle);
}

float Bullet::getVx()
{
	return m_vx;
}

float Bullet::getVy()
{
	return m_vy;
}

void Bullet::setIsDelete(const bool & b)
{
	m_isDelete = b;
}

const bool & Bullet::getIsDelete()
{
	return m_isDelete;
}

void Bullet::setAttack(const int & attack)
{
	m_attack = attack;
}

const int & Bullet::getAttack()
{
	return m_attack;
}


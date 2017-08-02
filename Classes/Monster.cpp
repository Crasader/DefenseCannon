#include"Monster.h"
#include"Common.h"
#include<cmath>

Monster::Monster()
{
}

Monster::~Monster()
{
}

bool  Monster::init()
{
	if (CCSprite::init())
	{
		return true;
	}
	return false;
}

void  Monster::setVelocity(const float & v, const float & angle)
{
	m_vx = sinf(angle);
	m_vy = cosf(angle);
}

void Monster::move()
{
	CCPoint pos = getPosition();
	this->setPosition(pos.x + m_vx, pos.y + m_vy);
}

void Monster::setLife(const float & life)
{
	m_life = life;
}

const float & Monster::getLife()
{
	return m_life;
}

void Monster::setScore(const int & score)
{
	m_score = score;
}

const int & Monster::getScore()
{
	return m_score;
}

void Monster::setGlod(const int & glod)
{
	m_glod = glod;
}

const int & Monster::getGlod()
{
	return m_glod;
}

Monster * Monster::generiteChild()
{
	return nullptr;
}

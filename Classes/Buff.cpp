#include "Buff.h"
#include"Common.h"

Buff::Buff()
{
}

Buff::~Buff()
{
}

bool Buff::init()
{
	if (CCSprite::init())
	{
		setVelocity(1.0f, CC_DEGREES_TO_RADIANS(180));
		m_cd = 60;
		return true;
	}
	return false;
}

void Buff::setVelocity(float v, float angle)
{
	m_vx = v*sinf(angle);
	m_vy = v*cosf(angle);
}

void Buff::move()
{
	setPositionX(getPositionX() + m_vx);
	setPositionY(getPositionY() + m_vy);
}

void Buff::decCd()
{
	--m_cd;
}

const int & Buff::getCd()
{
	return m_cd;
}

void Buff::doBuffThing()
{
}


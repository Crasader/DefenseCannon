#include"HeartBuff.h"
#include"Common.h"
#include"StaticData.h"

HeartBuff::HeartBuff()
{
}

HeartBuff::~HeartBuff()
{
}

bool HeartBuff::init()
{
	if (CCSprite::init())
	{
		initWithFile(STATIC_STRING_DATA("heart"));
		setVelocity(1.0f, CC_DEGREES_TO_RADIANS(180));
		m_cd = 60;
		return true;
	}
	return false;
}

void HeartBuff::setVelocity(float v, float angle)
{
	m_vx = v*sinf(angle);
	m_vy = v*cosf(angle);
}

void HeartBuff::move()
{
	setPositionX(getPositionX() + m_vx);
	setPositionY(getPositionY() + m_vy);
}

void HeartBuff::decCd()
{
	--m_cd;
}

const int & HeartBuff::getCd()
{
	return m_cd;
}

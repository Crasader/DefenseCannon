#include"BossHat.h"
#include"Common.h"
#include"StaticData.h"
#include"Hat.h"

BossHat::BossHat()
{
}

BossHat::~BossHat()
{
}

bool BossHat::init()
{
	if (Monster::init())
	{
		initWithFile(STATIC_STRING_DATA("BossHat"));
		setLife(50);
		setScore(500);
		setGlod(60);
		setVelocity(Velocity_Base, CC_DEGREES_TO_RADIANS(180));
		return true;
	}
	return false;
}

void BossHat::move()
{
	auto size = Director::sharedDirector()->getWinSize();
	setPosition(getPosition().x + m_vx, getPosition().y + m_vy);
	if (getPositionY() < size.height-getContentSize().height*0.28)
	{
		setVelocity(Velocity_Base, CC_DEGREES_TO_RADIANS(90));
		setPositionY(size.height - getContentSize().height*0.26);
	}
	else if (getPositionX() > size.width-getContentSize().width)
	{
		setVelocity(Velocity_Base, CC_DEGREES_TO_RADIANS(270));
	}
	else if (getPositionX() < getContentSize().width)
	{
		setVelocity(Velocity_Base, CC_DEGREES_TO_RADIANS(90));
	}
}

Monster* BossHat::generiteChild()
{
	Hat* hat = Hat::create();
	hat->setScale(0.5f);
	hat->setPosition(this->getPosition());
	hat->setVelocity(Velocity_Base, CC_DEGREES_TO_RADIANS(180));
	return hat;
}


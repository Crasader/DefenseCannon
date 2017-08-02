#include"BossCard.h"
#include"Common.h"
#include"Rectangle.h"
#include"StaticData.h"

BossCard::BossCard()
{
}

BossCard::~BossCard()
{
}

bool BossCard::init()
{
	if (Monster::init())
	{
		initWithFile(STATIC_STRING_DATA("BossCard"));
		setLife(200);
		setScore(1500);
		setGlod(200);
		setVelocity(Velocity_Base, CC_DEGREES_TO_RADIANS(180));
		return true;
	}
	return false;
}

void BossCard::move()
{
	auto size = Director::sharedDirector()->getWinSize();
	setPosition(getPosition().x + m_vx, getPosition().y + m_vy);
	if (getPositionY() < size.height - getContentSize().height*0.28)
	{
		setVelocity(Velocity_Base, CC_DEGREES_TO_RADIANS(90));
		setPositionY(size.height - getContentSize().height*0.26);
	}
	else if (getPositionX() > size.width - getContentSize().width)
	{
		setVelocity(Velocity_Base, CC_DEGREES_TO_RADIANS(270));
	}
	else if (getPositionX() < getContentSize().width)
	{
		setVelocity(Velocity_Base, CC_DEGREES_TO_RADIANS(90));
	}
}

Monster* BossCard::generiteChild()
{
	CocosRectangle* child = CocosRectangle::create();
	child->setScale(0.5f);
	child->setPosition(this->getPosition());
	child->setVelocity(Velocity_Base, CC_DEGREES_TO_RADIANS(180));
	return child;
}

void BossCard::releasingSkills()
{
}

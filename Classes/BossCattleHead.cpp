#include"BossCattleHead.h"
#include"Common.h"
#include"StaticData.h"
#include"CattleHead.h"

BossCattleHead::BossCattleHead()
{
}

BossCattleHead::~BossCattleHead()
{
}

bool BossCattleHead::init()
{
	if (Monster::init())
	{
		initWithFile(STATIC_STRING_DATA("BossCattleHead"));
		setLife(150);
		setScore(1000);
		setGlod(200);
		setVelocity(Velocity_Base, CC_DEGREES_TO_RADIANS(180));
		return true;
	}
	return false;
}

void BossCattleHead::move()
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

Monster * BossCattleHead::generiteChild()
{
	CattleHead* child = CattleHead::create();
	child->setScale(0.5f);
	child->setPosition(this->getPosition());
	child->setVelocity(Velocity_Base, CC_DEGREES_TO_RADIANS(180));
	return child;
}

void BossCattleHead::releaseSkills1()
{
}

void BossCattleHead::releaseSkills2()
{
}

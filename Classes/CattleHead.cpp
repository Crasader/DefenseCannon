#include"CattleHead.h"
#include"Common.h"
#include"StaticData.h"

CattleHead::CattleHead()
{
}

CattleHead::~CattleHead()
{
}

bool CattleHead::init()
{
	if (Monster::init())
	{
		initWithFile(STATIC_STRING_DATA("cattleHead"));
		setLife(2);
		setScore(200);
		setGlod(5);
		setVelocity(Velocity_Base, CC_DEGREES_TO_RADIANS(180));
		CCActionInterval* ai = CCRotateBy::create(0.5f, 360);
		this->runAction(CCRepeatForever::create(ai));

		return true;
	}
	return false;
}

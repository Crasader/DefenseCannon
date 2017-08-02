#include"Hat.h"
#include"StaticData.h"
#include"Common.h"

Hat::Hat()
{
}

Hat::~Hat()
{
}

bool Hat::init()
{
	if (Monster::init())
	{
		initWithFile(STATIC_STRING_DATA("hat"));
		setLife(1);
		setGlod(5);
		setScore(100);
		CCActionInterval* ai = CCRotateBy::create(1.0f, 360);
		this->runAction(CCRepeatForever::create(ai));
		return true;
	}
	return false;
}

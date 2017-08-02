#include"Rectangle.h"
#include"Common.h"

CocosRectangle::CocosRectangle()
{
}

CocosRectangle::~CocosRectangle()
{
}

bool CocosRectangle::init()
{
	if (Monster::init())
	{
		setLife(1);
		setScore(100);
		setGlod(5);
		initWithSpriteFrameName("rect");
		CCActionInterval* ai = CCRotateBy::create(0.5f, 360);
		this->runAction(CCRepeatForever::create(ai));
		return true;
	}
	return false;
}

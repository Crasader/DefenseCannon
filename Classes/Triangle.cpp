#include"Triangle.h"
#include"Common.h"

Triangle::Triangle()
{
}

Triangle::~Triangle()
{
}

bool Triangle::init()
{
	if (Monster::init())
	{
		setLife(1);
		setScore(50);
		setGlod(5);
		CCAnimation* ani = CCAnimationCache::sharedAnimationCache()->getAnimation("triangle");
		CCAnimate* animate = CCAnimate::create(ani);
		this->runAction(CCRepeatForever::create(animate));
		return true;
	}
	return false;
}

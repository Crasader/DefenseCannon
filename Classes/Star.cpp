#include"Star.h"
#include"Common.h"

Star::Star()
{
}

Star::~Star()
{
}

bool Star::init()
{
	if (Monster::init())
	{
		setLife(2);
		setScore(150);
		setGlod(15);
		CCAnimation* ani = CCAnimationCache::sharedAnimationCache()->getAnimation("star");
		CCAnimate* animate = CCAnimate::create(ani);
		this->runAction(CCRepeatForever::create(animate));
		return true;
	}
	return false;
}

#include"SStar.h"
#include"Common.h"

SStar::SStar()
{
}

SStar::~SStar()
{
}

bool SStar::init()
{
	if (Monster::init())
	{
		setLife(3);
		setScore(150);
		setGlod(20);
		CCAnimation* ani = CCAnimationCache::sharedAnimationCache()->getAnimation("sstar");
		CCAnimate* animate = CCAnimate::create(ani);
		this->runAction(CCRepeatForever::create(animate));
		return true;
	}
	return false;
}

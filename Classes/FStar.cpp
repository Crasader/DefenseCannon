#include "FStar.h"
#include"Common.h"

FStar::FStar()
{
}

FStar::~FStar()
{
}

bool FStar::init()
{
	if (Monster::init())
	{
		setLife(2);
		setScore(100);
		setGlod(10);
		CCAnimation* ani = CCAnimationCache::sharedAnimationCache()->getAnimation("fstar");
		CCAnimate* animate = CCAnimate::create(ani);
		this->runAction(CCRepeatForever::create(animate));
		return true;
	}
	return false;
}

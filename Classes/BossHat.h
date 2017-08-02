#pragma once
#ifndef __BOSSHAT_H__
#define __BOSSHAT_H__
#include"cocos2d.h"
#include"Monster.h"

/*
*class BossHat
*帽子怪物Boss
*/
class BossHat :public Monster
{
public:
	BossHat();
	virtual ~BossHat();
	CREATE_FUNC(BossHat);
	bool init();

	virtual void move() override;

	/*
	*generiteChild();
	*生成小分身
	*@return Hat*:生成的小分身
	*/	
	Monster* generiteChild() override;
};

#endif // !__BOSSHAT_H__

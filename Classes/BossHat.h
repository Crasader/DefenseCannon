#pragma once
#ifndef __BOSSHAT_H__
#define __BOSSHAT_H__
#include"cocos2d.h"
#include"Monster.h"

/*
*class BossHat
*ñ�ӹ���Boss
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
	*����С����
	*@return Hat*:���ɵ�С����
	*/	
	Monster* generiteChild() override;
};

#endif // !__BOSSHAT_H__

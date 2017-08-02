#pragma once
#ifndef __BOSSCATTLEHEAD_H__
#define __BOSSCATTLEHEAD_H__
#include"Monster.h"

class CattleHead;

class BossCattleHead :public Monster
{
public:
	BossCattleHead();
	virtual ~BossCattleHead();
	CREATE_FUNC(BossCattleHead);
	bool init();

	virtual void move() override;

	/*
	*generiteChild();
	*����С����
	*/
	Monster* generiteChild() override;

	/*
	*releaseSkills()
	*�ͷż���
	*/
	void releaseSkills1();
	void releaseSkills2();
};

#endif // !__BOSSCATTLEHEAD_H__

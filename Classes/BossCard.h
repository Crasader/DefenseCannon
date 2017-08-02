#pragma once
#ifndef __BOSSCARD_H__
#define __BOSSCARD_H__
#include"Monster.h"

class BossCard :public Monster
{
public:
	BossCard();
	virtual ~BossCard();
	CREATE_FUNC(BossCard);
	bool init() override;

	virtual void move() override;

	/*
	*generite();
	*����С����
	*/
	Monster* generiteChild() override;

	/*
	*releasingSkills()
	*�ͷż���
	*/
	void releasingSkills();
};

#endif // !__BOSSCARD_H__


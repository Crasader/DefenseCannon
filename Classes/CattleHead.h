#pragma once
#ifndef __CATTLEHEAD_H__
#define __CATTLEHEAD_H__
#include"Monster.h"

class CattleHead:public Monster
{
public:
	CattleHead();
	virtual ~CattleHead();
	CREATE_FUNC(CattleHead);
	bool init();
};

#endif // !__CATTLEHEAD_H__


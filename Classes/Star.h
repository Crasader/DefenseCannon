#pragma once
#ifndef __STAR_H__
#define __STAR_H__
#include"Monster.h"

class Star:public Monster
{
public:
	Star();
	virtual ~Star();
	CREATE_FUNC(Star);
	bool init();
};


#endif // !__STAR_H__




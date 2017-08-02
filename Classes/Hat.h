#pragma once
#ifndef __HAT_H__
#define __HAT_H__
#include"Monster.h"

class Hat :public Monster
{
public:
	Hat();
	virtual ~Hat();
	CREATE_FUNC(Hat);
	bool init();
};

#endif // !__HAT_H__


#pragma once
#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__
#include"Monster.h"

class Triangle :public Monster
{
public:
	Triangle();
	virtual ~Triangle();
	CREATE_FUNC(Triangle);
	bool init();
};

#endif // !__TRIANGLE_H__


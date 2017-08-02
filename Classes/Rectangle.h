#pragma once
#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__
#include"Monster.h"

class CocosRectangle :public Monster
{
public:
	CocosRectangle();
	virtual ~CocosRectangle();
	CREATE_FUNC(CocosRectangle);
	bool init();
};

#endif // !__RECTANGLE_H__

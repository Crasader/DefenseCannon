#pragma once
#ifndef __FSTAR_H__
#define __FSTAR_H__
#include"Monster.h"

class FStar :public Monster
{
public:
	FStar();
	virtual ~FStar();
	CREATE_FUNC(FStar);
	bool init();
};

#endif // !




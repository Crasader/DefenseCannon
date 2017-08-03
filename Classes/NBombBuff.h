#pragma once
#ifndef __NBOMB_H__
#define __NBOMB_H__
#include"Buff.h"

class NBombBuff :public Buff
{
public:
	NBombBuff();
	virtual ~NBombBuff();
	CREATE_FUNC(NBombBuff);
	bool init();
	
	/*
	*重写Buff虚函数
	*增加一颗核弹数
	*/
	virtual void doBuffThing() override;
};

#endif // !__NBOMB_H__


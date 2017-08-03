#pragma once
#ifndef __HeartBuff_H__
#define __HeartBuff_H__
#include"Buff.h"

class HeartBuff :public Buff
{
public:
	HeartBuff();
	virtual ~HeartBuff();
	CREATE_FUNC(HeartBuff);
	bool init();

	/*
	*重写Buff虚函数
	*增加一点生命值
	*/
	virtual void doBuffThing() override;
};

#endif // !__HeartBuff_H__


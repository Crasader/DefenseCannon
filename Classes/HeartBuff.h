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
	*��дBuff�麯��
	*����һ������ֵ
	*/
	virtual void doBuffThing() override;
};

#endif // !__HeartBuff_H__


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
	*��дBuff�麯��
	*����һ�ź˵���
	*/
	virtual void doBuffThing() override;
};

#endif // !__NBOMB_H__


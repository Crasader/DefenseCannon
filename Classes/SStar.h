#pragma once
#ifndef __SSTAR_H__
#define __SSTAR_H__
#include"Monster.h"

class SStar:public Monster
{
public:
	SStar();
	virtual ~SStar();
	CREATE_FUNC(SStar);
	bool init();
};

#endif // !__SSTAR_H__


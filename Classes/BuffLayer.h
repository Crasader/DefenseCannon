#pragma once
#ifndef __BUFF_LAYER_H__
#define __BUFF_LAYER_H__
#include"cocos2d.h"
#include<list>

class Buff;

class BuffLayer :public cocos2d::Layer
{
public:
	BuffLayer();
	virtual ~BuffLayer();
	CREATE_FUNC(BuffLayer);
	bool init();

	/*
	*addBuff(cocos2d::CCPoint pos);
	*添加buff
	*/
	void addBuff(cocos2d::CCPoint pos);
private:
	/*
	*用于更新buff位置
	*/
	void update(float dt) override;

	std::list<Buff*> m_buffList;
};

#endif // !__BUFF_LAYER_H__

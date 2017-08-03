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
	*���buff
	*/
	void addBuff(cocos2d::CCPoint pos);
private:
	/*
	*���ڸ���buffλ��
	*/
	void update(float dt) override;

	std::list<Buff*> m_buffList;
};

#endif // !__BUFF_LAYER_H__

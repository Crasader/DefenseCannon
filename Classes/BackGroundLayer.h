#pragma once
#ifndef __BackGroundLayer_H__
#define __BackGroundLayer_H__
#include"cocos2d.h"
#include"Common.h"

class BackGroundLayer :public cocos2d::Layer
{
public:
	BackGroundLayer();
	virtual ~BackGroundLayer();
	static BackGroundLayer* create(Level level= Level_one);
	bool init(Level level);

protected:
	/*
	*callMainMenuBack(cocos2d::CCObject* sender);
	*进入游戏菜单按钮回掉函数
	*@Param sender:消息发送者
	*/
	void callMainMenuBack(cocos2d::CCObject* sender);
};

#endif //__BackGroundLayer_H__


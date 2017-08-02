#pragma once
#ifndef __MENULAYRE_H__
#define __MENULAYRE_H__
#include"cocos2d.h"

class MenuLayer :public cocos2d::Layer
{
public:
	MenuLayer();
	virtual ~MenuLayer();
	CREATE_FUNC(MenuLayer);
	bool init();
protected:
	/*
    *callResumeBack(cocos2d::CCObject* sender);
	*继续游戏菜单项回掉函数
	*@Param sender：消息发送者
	*/
	void callResumeBack(cocos2d::CCObject* sender);

	/*
	 *callOpenMusicBack(cocos2d::CCObject* sender);
	 *打开音乐菜单项回掉函数
	 *@Param sender：消息发送者
	*/
	void callOnOrOffMusicBack(cocos2d::CCObject* sender);

	/*
	*BackToBeginScene(cocos2d::CCObject* sender);
	*返回主菜单项回掉函数
	*@Param sender：消息发送者
	*/
	void BackToBeginScene(cocos2d::CCObject* sender);

	/*
	*generiteMusicSwitch();
	*生成音乐开关菜单项
	*@return CCMenuItemToggle*：生层的菜单项
	*/
	cocos2d::CCMenuItemToggle* generiteMusicSwitch();
};

#endif // !__MENULAYRE_H__

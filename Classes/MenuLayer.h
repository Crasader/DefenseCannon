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
	*������Ϸ�˵���ص�����
	*@Param sender����Ϣ������
	*/
	void callResumeBack(cocos2d::CCObject* sender);

	/*
	 *callOpenMusicBack(cocos2d::CCObject* sender);
	 *�����ֲ˵���ص�����
	 *@Param sender����Ϣ������
	*/
	void callOnOrOffMusicBack(cocos2d::CCObject* sender);

	/*
	*BackToBeginScene(cocos2d::CCObject* sender);
	*�������˵���ص�����
	*@Param sender����Ϣ������
	*/
	void BackToBeginScene(cocos2d::CCObject* sender);

	/*
	*generiteMusicSwitch();
	*�������ֿ��ز˵���
	*@return CCMenuItemToggle*������Ĳ˵���
	*/
	cocos2d::CCMenuItemToggle* generiteMusicSwitch();
};

#endif // !__MENULAYRE_H__

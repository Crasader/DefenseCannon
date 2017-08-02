#pragma once
#ifndef __BEGINLAYER_H__
#define __BEGINLAYER_H__
#include"cocos2d.h"

class BeginLayer :public cocos2d::Layer
{
public:
	BeginLayer();
	virtual ~BeginLayer();
	CREATE_FUNC(BeginLayer);
	bool init();

protected:
	/*
	*CheckAddProgressOrAddBtn()
	*检测添加进度条还是添加按钮
	*/
	void CheckAddProgressOrAddBtn();

	/*
	*addProgressBar();
	*添加进度条
	*/
	void addProgressBar();

	/*
	*addGameBtn();
	*添加开始和继续按钮
	*/
	void addGameBtn();

	/*
	*callStartGameBack(cocos2d::CCObject* sender);
	*有戏开始按钮回掉函数
	*@Param sender：消息发送者
	*/
	void callStartGameBack(cocos2d::CCObject* sender);

	/*
	*callCloseBack(cocos2d::CCObject* sender);
	*关闭游戏按钮回掉函数
	*@Param sender：消息发送者
	*/
	void callCloseBack(cocos2d::CCObject* sender);

	/*
	*callResumeGameBack(cocos2d::CCObject* sender);
	*继续游戏按钮回掉函数
	*@Param sender：消息发送者
	*/
	void callResumeGameBack(cocos2d::CCObject* sender);

	/*
	 *callEndlessGameBack(cocos2d::CCObject* sender);
	 *无尽模式按钮回调函数
	*/
	void callEndlessGameBack(cocos2d::CCObject* sender);

	/*
	*generiteMusicToggle();
	*生成音乐开关按钮
	*/
	cocos2d::CCMenuItemToggle* generiteMusicToggle();

	/*
	*callCloseOrOpenMusicBack(cocos2d::CCObject* sender);
	*关闭或者打开背景音乐按钮回掉函数
	*@Param sender：消息发送者
	*/
	void callCloseOrOpenMusicBack(cocos2d::CCObject* sender);

	/*
	*ObsverProgressBarStatus(float dt);
	*监视定时器状态
	*/
	void ObsverProgressBarStatus(float dt);
private:
	cocos2d::ProgressTimer* m_progressTime;
	cocos2d::CCSprite* progreseBg;
};

#endif // !__BEGINLAYER_H__

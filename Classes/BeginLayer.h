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
	*�����ӽ�����������Ӱ�ť
	*/
	void CheckAddProgressOrAddBtn();

	/*
	*addProgressBar();
	*��ӽ�����
	*/
	void addProgressBar();

	/*
	*addGameBtn();
	*��ӿ�ʼ�ͼ�����ť
	*/
	void addGameBtn();

	/*
	*callStartGameBack(cocos2d::CCObject* sender);
	*��Ϸ��ʼ��ť�ص�����
	*@Param sender����Ϣ������
	*/
	void callStartGameBack(cocos2d::CCObject* sender);

	/*
	*callCloseBack(cocos2d::CCObject* sender);
	*�ر���Ϸ��ť�ص�����
	*@Param sender����Ϣ������
	*/
	void callCloseBack(cocos2d::CCObject* sender);

	/*
	*callResumeGameBack(cocos2d::CCObject* sender);
	*������Ϸ��ť�ص�����
	*@Param sender����Ϣ������
	*/
	void callResumeGameBack(cocos2d::CCObject* sender);

	/*
	 *callEndlessGameBack(cocos2d::CCObject* sender);
	 *�޾�ģʽ��ť�ص�����
	*/
	void callEndlessGameBack(cocos2d::CCObject* sender);

	/*
	*generiteMusicToggle();
	*�������ֿ��ذ�ť
	*/
	cocos2d::CCMenuItemToggle* generiteMusicToggle();

	/*
	*callCloseOrOpenMusicBack(cocos2d::CCObject* sender);
	*�رջ��ߴ򿪱������ְ�ť�ص�����
	*@Param sender����Ϣ������
	*/
	void callCloseOrOpenMusicBack(cocos2d::CCObject* sender);

	/*
	*ObsverProgressBarStatus(float dt);
	*���Ӷ�ʱ��״̬
	*/
	void ObsverProgressBarStatus(float dt);
private:
	cocos2d::ProgressTimer* m_progressTime;
	cocos2d::CCSprite* progreseBg;
};

#endif // !__BEGINLAYER_H__

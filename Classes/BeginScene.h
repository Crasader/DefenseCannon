#pragma once
#ifndef __BEGINSCENE_H__
#define __BEGINSCENE_H__
#include"cocos2d.h"

class BeginLayer;

class BeginScene :public cocos2d::CCScene
{
public:
	BeginScene();
	virtual ~BeginScene();
	CREATE_FUNC(BeginScene);
	bool init();

private:
	/*
	*reloadResource();
	*‘§º”‘ÿ◊ ‘¥
	*/
	void reloadResource();

	BeginLayer* m_beginLayer;
};

#endif // !__BEGINSCENE_H__


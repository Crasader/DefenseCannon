#pragma once
#ifndef __TRANSITSCENE_H__
#define __TRANSITSCENE_H__
#include"cocos2d.h"
#include"Common.h"

class TransitScene:public cocos2d::CCScene
{
public:
	TransitScene();
	virtual ~TransitScene();
	static TransitScene* create(Level level);
	bool init(Level level);

	/*
	*ObsverProgressBarStatus(float dt);
	*¼àÊÓ¶¨Ê±Æ÷×´Ì¬
	*/
	void ObsverProgressBarStatus(float dt);
private:
	cocos2d::ProgressTimer* m_progressTime;
	cocos2d::CCSprite* progreseBg;
	Level m_level;
public:
	int m_glod;
	int m_score;
};

#endif // !__TRANSITSCENE_H__


#pragma once
#ifndef __GAMEOVER_H__
#define __GAMEOVER_H__
#include"cocos2d.h"

class GameOverScene:public cocos2d::CCScene
{
public:
	GameOverScene();
	virtual ~GameOverScene();
	CREATE_FUNC(GameOverScene);
	bool init();

	/*
	*GoBeginScene();
	*ǰ����ʼ����
	*/
	void GoBeginScene(float dt);
};

#endif // !__GAMEOVER_H__


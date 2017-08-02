#pragma once
#ifndef __GAME_END_SCENE_H__
#define __GAME_END_SCENE_H__
#include"cocos2d.h"

class GameEndScene :public cocos2d::CCScene
{
public:
	GameEndScene();
	virtual ~GameEndScene();
	CREATE_FUNC(GameEndScene);
	bool init();

	/*
	*GoBeginScene(float dt);
	*前往开始场景
	*/
	void GoBeginScene(float dt);
};

#endif // !__GAME_END_SCENE_H__


#pragma once

#ifndef __FIRSTLEVELSCENE_H__
#define __FIRSTLEVELSCENE_H__

#include"cocos2d.h"
#include"Common.h"

class BackGroundLayer;
class WeaponLayer;
class MonsterLayer;
class MenuLayer; 
class GameDataLayer;
class BuffLayer;

class GameSecene :public cocos2d::CCScene
{
public:
	GameSecene();
	virtual ~GameSecene();
	static GameSecene* create(Level level = Level_one);
	bool init(Level level);

	/*
	*getWeaponLayer();
	*获得武器层对象
	*@return WeaponLayer*：取得的武层对象指针
	*/
	WeaponLayer* getWeaponLayer();

	/*
	*pauseAllAction();
	*停止节点中以及其子节点的所有动作
	*@Param hoster：主节点
	*/
	void pauseAllAction(cocos2d::Node *hoster);

	/*
	*resumeAllAction();
	*恢复节点中以及其子节点的所有动作
	*@Param hoster：主节点
	*/
	void resumeAllAction(cocos2d::Node* hoster);

	/*
	*addMenuLayer()
	*添加菜单层
	*/
	void addMenuLayer();

	/*
	*removeMenuLayer();
	*移除菜单层
	*/
	void removeMenuLayer();

	/*
	*getGameDataLayer();
	*获得有戏数据层指针
	*@return GameDataLayer* :游戏数据层
	*/
	GameDataLayer* getGameDataLayer();

	/*
	*进入过渡场景
	*/
	void GoingTransitScene(Level level);

	/*
	*GameOver();
	*进入游戏结束场景
	*/
	void GoGameOver();

	/*
	*GoGameEnd()
	*进入游戏通关场景
	*/
	void GoGameEnd();

	/*
	*getBuffLayer();
	*获取BuffLayer指针
	*/
	BuffLayer* getBuffLayer();
private:
	BackGroundLayer* m_backgound;
	WeaponLayer* m_weapon;
	MonsterLayer* m_monsterLayer;
	MenuLayer* m_menuLayer;
	GameDataLayer* m_gameDataLayer;
	BuffLayer* m_buffLayer;
};

#endif  //__FIRSTLEVELSCENE_H__

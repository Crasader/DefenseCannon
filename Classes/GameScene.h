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
	*������������
	*@return WeaponLayer*��ȡ�õ�������ָ��
	*/
	WeaponLayer* getWeaponLayer();

	/*
	*pauseAllAction();
	*ֹͣ�ڵ����Լ����ӽڵ�����ж���
	*@Param hoster�����ڵ�
	*/
	void pauseAllAction(cocos2d::Node *hoster);

	/*
	*resumeAllAction();
	*�ָ��ڵ����Լ����ӽڵ�����ж���
	*@Param hoster�����ڵ�
	*/
	void resumeAllAction(cocos2d::Node* hoster);

	/*
	*addMenuLayer()
	*��Ӳ˵���
	*/
	void addMenuLayer();

	/*
	*removeMenuLayer();
	*�Ƴ��˵���
	*/
	void removeMenuLayer();

	/*
	*getGameDataLayer();
	*�����Ϸ���ݲ�ָ��
	*@return GameDataLayer* :��Ϸ���ݲ�
	*/
	GameDataLayer* getGameDataLayer();

	/*
	*������ɳ���
	*/
	void GoingTransitScene(Level level);

	/*
	*GameOver();
	*������Ϸ��������
	*/
	void GoGameOver();

	/*
	*GoGameEnd()
	*������Ϸͨ�س���
	*/
	void GoGameEnd();

	/*
	*getBuffLayer();
	*��ȡBuffLayerָ��
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

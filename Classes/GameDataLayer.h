#pragma once
#ifndef __GAMEDATALAYRE_H__
#define __GAMEDATALAYRE_H__
#include"cocos2d.h"
#include"Common.h"

/*
*GameDataLayer
*��Ϸ���ݲ�������ʾ��Ϸ����
*/
class GameDataLayer :public cocos2d::Layer
{
public:
	GameDataLayer();
	virtual ~GameDataLayer();
	CREATE_FUNC(GameDataLayer);
	bool init();

	/*
	*m_glod��Ϸ��ҵ�setter��getter����
	*/
	void setGlod(const int& glod);
	const int& getGlod();

	/*
	*m_score��Ϸ������settter��getter����
	*/
	void setScore(const int&  score);
	const int& getScore();

	/*
	*m_level��Ϸ�ؿ���setter��getter����
	*/
	void setLevel(const Level& level);
	const Level& getLevel();

	/*
	*m_heartNum��ϷѪ������setter��getter����
	*/
	void setHeartNum(const int& num);
	const int& getHeartNum();

	/*
	*GameOver()
	*֪ͨ��Ϸ������Ϸ����
	*/
	void GameOver();
private:
	/*
	*callSaveGameBack(cocos2d::CCObject* sender);
	*������Ϸ��ť�ص�����
	*@Param sender:��Ϣ������
	*/
	void callSaveGameBack(cocos2d::CCObject* sender);

	int m_glod;
	int m_score;
	Level m_Level;
	int m_heartNum;
	cocos2d::LabelTTF* m_glodLabel;
	cocos2d::LabelTTF* m_scoreLabel;
	cocos2d::LabelTTF* m_levelLabel;
	cocos2d::LabelTTF* m_heartLabel;
};

#endif // !__GAMEDATALAYRE_H__

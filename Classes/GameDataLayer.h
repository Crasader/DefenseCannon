#pragma once
#ifndef __GAMEDATALAYRE_H__
#define __GAMEDATALAYRE_H__
#include"cocos2d.h"
#include"Common.h"

/*
*GameDataLayer
*游戏数据层用于显示游戏数据
*/
class GameDataLayer :public cocos2d::Layer
{
public:
	GameDataLayer();
	virtual ~GameDataLayer();
	CREATE_FUNC(GameDataLayer);
	bool init();

	/*
	*m_glod游戏金币的setter和getter方法
	*/
	void setGlod(const int& glod);
	const int& getGlod();

	/*
	*m_score游戏分数的settter和getter方法
	*/
	void setScore(const int&  score);
	const int& getScore();

	/*
	*m_level游戏关卡的setter和getter方法
	*/
	void setLevel(const Level& level);
	const Level& getLevel();

	/*
	*m_heartNum游戏血量数的setter和getter方法
	*/
	void setHeartNum(const int& num);
	const int& getHeartNum();

	/*
	*GameOver()
	*通知游戏场景游戏结束
	*/
	void GameOver();
private:
	/*
	*callSaveGameBack(cocos2d::CCObject* sender);
	*保存游戏按钮回调函数
	*@Param sender:消息发送者
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

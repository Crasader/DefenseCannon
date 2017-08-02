#include"GameScene.h"
#include"BackGroundLayer.h"
#include"WeaponLayer.h"
#include"MonsterLayer.h"
#include"MenuLayer.h"
#include"GameDataLayer.h"
#include"TransitScene.h"
#include"GameOverScene.h"
#include"GameEndScene.h"
#include"BuffLayer.h"
#include<thread>
#include<chrono>
using namespace std;

GameSecene::GameSecene()
{
}

GameSecene::~GameSecene()
{
}

GameSecene * GameSecene::create(Level level)
{
	GameSecene* pRet = new GameSecene;
	if (pRet&&pRet->init(level))
	{
		pRet->autorelease();
		return pRet;
	}
	delete pRet;
	pRet = nullptr;
	return nullptr;
}

bool GameSecene::init(Level level)
{
	if (CCScene::init())
	{
		auto size = CCDirector::sharedDirector()->getWinSize();
		m_backgound = BackGroundLayer::create(level);
		this->addChild(m_backgound);

		m_weapon = WeaponLayer::create();
		this->addChild(m_weapon);

		m_monsterLayer = MonsterLayer::create(level);
		this->addChild(m_monsterLayer);

		m_gameDataLayer = GameDataLayer::create();
		m_gameDataLayer->setLevel(level);
		this->addChild(m_gameDataLayer);

		m_buffLayer = BuffLayer::create();
		this->addChild(m_buffLayer);
		return true;
	}
	return false;
}

WeaponLayer * GameSecene::getWeaponLayer()
{
	return m_weapon;
}

void GameSecene::pauseAllAction(cocos2d::Node * hoster)
{
	hoster->pauseSchedulerAndActions();
	auto NodeArray = hoster->getChildren();
	if (NodeArray.size() > 0)
	{
		for (auto it : NodeArray)
		{
			pauseAllAction(it);
		}
	}
}

void GameSecene::resumeAllAction(cocos2d::Node * hoster)
{
	hoster->resumeSchedulerAndActions();
	auto NodeArray = hoster->getChildren();
	if (NodeArray.size() > 0)
	{
		for (auto it : NodeArray)
		{
			resumeAllAction(it);
		}
	}
}

void GameSecene::addMenuLayer()
{
	m_menuLayer = MenuLayer::create();
	this->addChild(m_menuLayer);
}

void GameSecene::removeMenuLayer()
{
	this->removeChild(m_menuLayer);
	m_menuLayer = nullptr;
}

GameDataLayer * GameSecene::getGameDataLayer()
{
	return m_gameDataLayer;
}

void GameSecene::GoingTransitScene(Level level)
{
	Sleep(2000);
	TransitScene* transit = TransitScene::create(level);
	transit->m_glod = m_gameDataLayer->getGlod();
	transit->m_score = m_gameDataLayer->getScore();
	auto reScene = CCTransitionShrinkGrow::create(1.0, transit);
	CCDirector::sharedDirector()->replaceScene(reScene);
}

void GameSecene::GoGameOver()
{
	pauseAllAction(this);
	Sleep(1000);
	GameOverScene* over = GameOverScene::create();
	auto reScene = CCTransitionShrinkGrow::create(1.0, over);
	CCDirector::sharedDirector()->replaceScene(reScene);
}

void GameSecene::GoGameEnd()
{
	pauseAllAction(this);
	Sleep(1000);
	GameEndScene* end = GameEndScene::create();
	auto reScene = CCTransitionShrinkGrow::create(1.0, end);
	CCDirector::sharedDirector()->replaceScene(reScene);
}

BuffLayer * GameSecene::getBuffLayer()
{
	return m_buffLayer;
}


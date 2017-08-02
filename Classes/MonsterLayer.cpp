#include"MonsterLayer.h"
#include"FStar.h"
#include"Star.h"
#include"SStar.h"
#include"Triangle.h"
#include"Rectangle.h"
#include"GameScene.h"
#include"WeaponLayer.h"
#include"GameDataLayer.h"
#include"Hat.h"
#include"CattleHead.h"
#include"BossHat.h"
#include"BossCard.h"
#include"BossCattleHead.h"
#include"BuffLayer.h"
#include<random>
using namespace std;

MonsterLayer::MonsterLayer()
{
}

MonsterLayer::~MonsterLayer()
{
}

MonsterLayer * MonsterLayer::create(const Level level)
{
	MonsterLayer* pRet = new MonsterLayer();
	if (pRet&&pRet->init(level))
	{
		pRet->autorelease();
		return pRet;
	}
	delete pRet;
	pRet = nullptr;
	return nullptr;
}

bool MonsterLayer::init(Level level)
{
	if (Layer::init())
	{
		m_level = level;
		auto size = CCDirector::sharedDirector()->getWinSize();

		this->schedule(schedule_selector(MonsterLayer::CheckCollideWithBomb));
		this->schedule(schedule_selector(MonsterLayer::MoveMonster));
		this->schedule(schedule_selector(MonsterLayer::CreateMonster), 1.0f);

		CreateBoss();
		return true;
	}
	return true;
}

void MonsterLayer::CheckCollideWithBomb(float dt)
{
	GameSecene* gameScene = dynamic_cast<GameSecene*>(getParent());
	WeaponLayer* weaponLayer = gameScene->getWeaponLayer();

	for (auto it = std::begin(m_monsterList); it != std::end(m_monsterList); ++it)
	{
		int attack = weaponLayer->CheckCollideWithMonster(*it);
		if(attack)
		{
			CCActionInterval* ai = CCMoveBy::create(0.4f, ccp(0, 100));
			(*it)->runAction(ai);
			(*it)->setLife((*it)->getLife() - attack);
		}
	}
}

void MonsterLayer::MoveMonster(float dt)
{
	auto size = Director::sharedDirector()->getWinSize();
	for (auto it = std::begin(m_monsterList);it!=std::end(m_monsterList);)
	{
		if ((*it)->getPositionY() < - (*it)->getContentSize().height)
		{
			//游戏血量减一
			GameSecene* gamescene = dynamic_cast<GameSecene*>(getParent());
			GameDataLayer* gameDataLayer = gamescene->getGameDataLayer();
			gameDataLayer->setHeartNum(gameDataLayer->getHeartNum() - 1);
			this->removeChild(*it);
			it = m_monsterList.erase(it);
		}
		else if ((*it)->getLife() <= 0)
		{
			//提升分数和金币
			GameSecene* gamescene = dynamic_cast<GameSecene*>(getParent());
			GameDataLayer* gameDataLayer = gamescene->getGameDataLayer();
			gameDataLayer->setScore(gameDataLayer->getScore() + (*it)->getScore());
			gameDataLayer->setGlod(gameDataLayer->getGlod() + (*it)->getGlod());
			randomCreateBuff((*it)->getPosition());
			this->removeChild(*it);
			it = m_monsterList.erase(it);
		}
		else
		{
			//移动怪物
			(*it)->move();
			++it;
		}
	}
}

void MonsterLayer::CreateMonster(float dt)
{
	switch (m_level)
	{
	case Level_one:
		CreteLevelOneMonster();
		break;
	case Level_Two:
		CreateLevelTwoMonter();
		break;
	case Level_Three:
		CreateLevelThreeMonster();
		break;
	case Level_Endless:
		CreateEndlessMonster();
		break;
	default:
		break;
	}
}

void MonsterLayer::CreteLevelOneMonster()
{
	if (m_count % 8 == 0)
	{
		for (int i = 0; i < 3; ++i)
		{
			CreateOneMonster(MonsterLayer::Monster_Tri);
		}
	}
	else
	{
		CreateOneMonster(MonsterLayer::Monster_Tri);
	}
	++m_count;
}

void MonsterLayer::CreateLevelTwoMonter()
{
	if (m_count % 4 == 0)
	{
		for (int i = 0; i < 3; ++i)
		{
			CreateOneMonster(MonsterLayer::Monster_Tri);
		}
	}
	else if (m_count % 11 == 0)
	{
		for (int i = 0; i < 3; ++i)
		{
			CreateOneMonster(MonsterLayer::Monster_FStar);
		}
		CreateOneMonster(MonsterLayer::Monster_Star);
	}
	else
	{
		CreateOneMonster(MonsterLayer::Monster_Tri);
	}
	++m_count;
}

void MonsterLayer::CreateLevelThreeMonster()
{
	if (m_count % 4 == 0)
	{
		for (int i = 0; i < 3; ++i)
		{
			CreateOneMonster(MonsterLayer::Monster_Tri);
		}
	}
	else if (m_count % 7 == 0)
	{
		for (int i = 0; i < 3; ++i)
		{
			CreateOneMonster(MonsterLayer::Monster_FStar);
		}
		CreateOneMonster(MonsterLayer::Monster_Star);
	}
	else if (m_count % 18 == 0)
	{
		for (int i = 0; i < 4; ++i)
		{
			CreateOneMonster(MonsterLayer::Monster_SStar);
		}
	}
	else
	{
		CreateOneMonster(MonsterLayer::Monster_Tri);
	}
	++m_count;
}

void MonsterLayer::CreateEndlessMonster()
{
	random_device rand;
	CreateOneMonster(MonsterLayer::Monster_Tri);
	if (m_count % 8 == 0)
	{
		int i = rand() % 4;
		auto type = (i == 0 ? MonsterLayer::Monster_Tri :
			i == 1 ? MonsterLayer::Monster_FStar :
			i == 2 ? MonsterLayer::Monster_Star : MonsterLayer::Monster_SStar);
		for (int i = 0; i < 4; ++ i)
		{
			CreateOneMonster(type);
		}
	}
	++m_count;
}

void MonsterLayer::CreateOneMonster(MonsterLayer::Type_Monster type)
{
	random_device rand;
	auto size = Director::sharedDirector()->getWinSize();
	Monster* monster = nullptr;
	switch (type)
	{
	case MonsterLayer::Monster_Tri:
	{
		monster = Triangle::create();
	}
		break;
	case MonsterLayer::Monster_FStar:
	{
		monster = FStar::create();
	}
		break;
	case MonsterLayer::Monster_Star:
	{
		monster = Star::create();
	}
		break;
	case MonsterLayer::Monster_SStar:
	{
		monster = SStar::create();
	}
		break;
	}
	monster->setScale(0.5f);
	monster->setVelocity(1.0f, CC_DEGREES_TO_RADIANS(180));
	float x = rand() % (int)size.width + 105;
	x = x > size.width - 105 ? rand() % (int)(size.width - 105) : x;
	x = x < 105 ? 105 : x;
	float y = size.height + monster->getContentSize().height;
	monster->setPosition(x, y);
	this->addChild(monster);
	m_monsterList.push_back(monster);
}

void MonsterLayer::CreateBoss()
{
	switch (m_level)
	{
	case Level_one:
		this->scheduleOnce(schedule_selector(MonsterLayer::CreateBossHat),98.0f);
		break;
	case Level_Two:
		this->scheduleOnce(schedule_selector(MonsterLayer::CreateBossCard), 128.0f);
		break;
	case Level_Three:
		this->scheduleOnce(schedule_selector(MonsterLayer::CreateBossCattleHead), 188.0f);
		break;
	case Level_Endless:
		this->scheduleOnce(schedule_selector(MonsterLayer::CreateEndlessBoss), 30.0f);
		break;
	default:
		break;
	}
}

void MonsterLayer::CreateBossHat(float dt)
{
	auto size = Director::sharedDirector()->getWinSize();
	m_Boss = BossHat::create();
	m_Boss->setScale(0.5f);
	m_Boss->setPosition(size.width*0.5, size.height +m_Boss->getContentSize().height);
	this->addChild(m_Boss);
	this->schedule(schedule_selector(MonsterLayer::doBossLogic));
}

void MonsterLayer::CreateBossCard(float dt)
{
	auto size = Director::sharedDirector()->getWinSize();
	m_Boss = BossCard::create();
	m_Boss->setScale(0.5f);
	m_Boss->setPosition(size.width*0.5, size.height + m_Boss->getContentSize().height);
	this->addChild(m_Boss);
	this->schedule(schedule_selector(MonsterLayer::doBossLogic));
}

void MonsterLayer::CreateBossCattleHead(float dt)
{
	auto size = Director::sharedDirector()->getWinSize();
	m_Boss = BossCattleHead::create();
	m_Boss->setScale(0.5f);
	m_Boss->setPosition(size.width*0.5, size.height + m_Boss->getContentSize().height);
	this->addChild(m_Boss);
	this->schedule(schedule_selector(MonsterLayer::doBossLogic));
}

void MonsterLayer::CreateEndlessBoss(float dt)
{
	random_device rand;
	int type = rand() % 3;
	switch (type)
	{
	case 0:
		m_Boss = BossHat::create();
		break;
	case 1:
		m_Boss = BossCard::create();
		break;
	case 2:
		m_Boss = BossCattleHead::create();
		break;
	}
	m_Boss->setScale(0.5f);
	m_Boss->setPosition(SCREEN_SIZE.width*0.5, SCREEN_SIZE.height + m_Boss->getContentSize().height);
	this->addChild(m_Boss);
	this->schedule(schedule_selector(MonsterLayer::doBossLogic));
}

void MonsterLayer::doBossLogic(float dt)
{
	GameSecene* gameScene = dynamic_cast<GameSecene*>(getParent());
	WeaponLayer* weaponLayer = gameScene->getWeaponLayer();
	m_Boss->move();
	int attack = weaponLayer->CheckCollideWithMonster(m_Boss);
	if (attack)
	{
		m_Boss->setLife(m_Boss->getLife() - attack);
	}
	if (m_Boss->getLife() <= 0)
	{
		if (m_level != Level_Endless)
		{
			gameScene->getGameDataLayer()->setGlod(
				gameScene->getGameDataLayer()->getGlod() + m_Boss->getGlod());
			gameScene->getGameDataLayer()->setScore(
				gameScene->getGameDataLayer()->getScore() + m_Boss->getScore());
			GoNext();
		}
		else
		{
			this->removeChild(m_Boss);
			this->removeAllMonster();
			this->scheduleOnce(schedule_selector(MonsterLayer::CreateEndlessBoss), 30.0f);
			this->unschedule(schedule_selector(MonsterLayer::doBossLogic));
		}
		return;
	}
	if (m_Mcount % 60 == 0)
	{
		Monster* child = m_Boss->generiteChild();
		this->addChild(child);
		m_monsterList.push_back(child);
	}
	++m_Mcount;
}

void MonsterLayer::GoNext()
{
	this->removeChild(m_Boss);
	this->unscheduleAllSelectors();
	removeAllMonster();
	this->scheduleOnce(schedule_selector(MonsterLayer::GoNext), 2.0f);
}

void MonsterLayer::GoNext(float dt)
{
	GameSecene* gameScene = dynamic_cast<GameSecene*>(getParent());
	gameScene->pauseAllAction(gameScene);
	m_level +1<= 3 ? gameScene->GoingTransitScene((Level)((int)m_level + 1)) :
		gameScene->GoGameEnd();
}

void MonsterLayer::removeAllMonster()
{
	for (auto it : m_monsterList)
	{
		this->removeChild(it);
	}
	m_monsterList.clear();
}

void MonsterLayer::randomCreateBuff(CCPoint pos)
{
	random_device rand;
	if (rand() % 100 < 20)
	{
		GameSecene* gameScene = dynamic_cast<GameSecene*>(getParent());
		gameScene->getBuffLayer()->addBuff(pos);
	}
}

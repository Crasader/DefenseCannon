#include"BuffLayer.h"
#include"Common.h"
#include"Buff.h"
#include"HeartBuff.h"
#include"NBombBuff.h"
#include"GameScene.h"
#include"GameDataLayer.h"
#include"WeaponLayer.h"
#include<random>
using namespace std;

BuffLayer::BuffLayer()
{
}

BuffLayer::~BuffLayer()
{
}

bool BuffLayer::init()
{
	if (Layer::init())
	{
		this->scheduleUpdate();
		return true;
	}
	return false;
}

void BuffLayer::addBuff(cocos2d::CCPoint pos)
{
	random_device rand;
	Buff* buff = nullptr;
	if (rand() % 100 >20 )
	{
		buff = HeartBuff::create();
	}
	else
	{
		buff = NBombBuff::create();
	}
	buff->setPosition(pos);
	CCActionInterval* move = CCMoveBy::create(0.4f, ccp(0, 100));
	buff->runAction(move);
	this->addChild(buff);
	m_buffList.push_back(buff);
}

void BuffLayer::update(float dt)
{
	GameSecene* gamescene = dynamic_cast<GameSecene*>(getParent());
	auto weaponLayer = gamescene->getWeaponLayer();
	for (auto it = m_buffList.begin(); it != m_buffList.end();)
	{
		if ((*it)->getPositionY() <-(*it)->getContentSize().height)
		{
			this->removeChild(*it);
			it = m_buffList.erase(it);
		}
		else if (weaponLayer->CheckCollideWithBuff(*it))
		{
			(*it)->doBuffThing();
			this->removeChild(*it);
			it=m_buffList.erase(it);
		}
		else
		{
			(*it)->decCd();
			(*it)->move();
			++it;
		}
	}
}

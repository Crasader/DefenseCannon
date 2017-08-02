#include"BuffLayer.h"
#include"Common.h"
#include"HeartBuff.h"
#include"GameScene.h"
#include"GameDataLayer.h"
#include"WeaponLayer.h"

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
		CCActionInterval* big = CCScaleTo::create(0.2f, 1.02f);
		CCActionInterval* tiny = CCScaleTo::create(0.2f, 0.98f);
		auto action = CCSequence::create(big, tiny,nullptr);
		this->runAction(CCRepeatForever::create(action));
		return true;
	}
	return false;
}

void BuffLayer::addBuff(cocos2d::CCPoint pos)
{
	HeartBuff* buff = HeartBuff::create();
	buff->setScale(0.5f);
	buff->setPosition(pos);
	CCActionInterval* move = CCMoveBy::create(0.4f, ccp(0, 100));
	buff->runAction(move);
	this->addChild(buff);
	m_buffList.push_back(buff);
}

void BuffLayer::update(float dt)
{
	GameSecene* gamescene = dynamic_cast<GameSecene*>(getParent());
	auto dataLayer = gamescene->getGameDataLayer();
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
			dataLayer->setHeartNum(dataLayer->getHeartNum() + 1);
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

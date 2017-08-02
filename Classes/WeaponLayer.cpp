#include"WeaponLayer.h"
#include"Common.h"
#include"Cannon.h"
#include"Bullet.h"
#include"TouchLayer.h"
#include"Monster.h"
#include"StaticData.h"
#include"GameScene.h"
#include"GameDataLayer.h"
#include"HeartBuff.h"

WeaponLayer::WeaponLayer()
{
}

WeaponLayer::~WeaponLayer()
{
}

bool WeaponLayer::init()
{
	if (Layer::init())
	{
		auto size = CCDirector::sharedDirector()->getWinSize();
		m_pCannon = Cannon::create();
		cocos2d::Size Cansize = m_pCannon->getContentSize();
		m_pCannon->setScale(0.4f);
		m_pCannon->setAnchorPoint(ccp(0.5f, 0.5f));
		m_pCannon->setPosition(size.width*0.5, Cansize.height*0.1);
		this->addChild(m_pCannon);

		m_touchLayer = TouchLayer::create();
		this->addChild(m_touchLayer);

		addCannonAbilityBtn();
		this->schedule(schedule_selector(WeaponLayer::moveBullet));
		return true;
	}
	return false;
}

void WeaponLayer::CannonTurnTo(cocos2d::CCPoint target)
{
	auto size = Director::sharedDirector()->getWinSize();
	CCPoint baseY = ccpMult(ccp(0, 1), size.height * 3);
	float angle = ccpAngleSigned(ccpSub(target, m_pCannon->getPosition()),
		ccpSub(baseY, m_pCannon->getPosition()));
	m_pCannon->setRotation(CC_RADIANS_TO_DEGREES(angle)-15);
	m_pCannon->setDrawLine(true);
}

void WeaponLayer::CannonShot(cocos2d::CCPoint target)
{
	GameSecene* gamescene = dynamic_cast<GameSecene*>(getParent());
	GameDataLayer* dataLayer = gamescene->getGameDataLayer();

	float angle = m_pCannon->getRotation();
	Bullet *bullet = Bullet::create();
	bullet->setRotation(angle);
	bullet->setPosition(m_pCannon->getPosition().x, m_pCannon->getPosition().y);
	bullet->setScale(0.5f);
	bullet->setAnchorPoint(ccp(0.5f, 1.0f));
	this->addChild(bullet);
	m_BulletList.push_back(bullet);

	if (dataLayer->getGlod() >= m_pCannon->getBulletGlod())
	{
		bullet->setVelocity(m_pCannon->getVelocity(), CC_DEGREES_TO_RADIANS(angle));
		bullet->setAttack(m_pCannon->getAttack());
		dataLayer->setGlod(dataLayer->getGlod() - m_pCannon->getBulletGlod());
	}
	else
	{
		bullet->setVelocity(Velocity_Base, CC_DEGREES_TO_RADIANS(angle));
		bullet->setAttack(1);
	}
	m_pCannon->setDrawLine(false);
}

int WeaponLayer::CheckCollideWithMonster(Monster * monster)
{
	auto size = monster->getContentSize();
	CCPoint mPos = monster->getPosition();
	for (auto it : m_BulletList)
	{
		if (it->getPositionX() > mPos.x - size.width*0.3f&&
			it->getPositionX() < mPos.x + size.width*0.3f&&
			it->getPositionY() > mPos.y - size.height*0.3f&&
			it->getPositionY() < mPos.y + size.height*0.3f)
		{
			it->setIsDelete(true);
			return it->getAttack();
		}
	}
	return 0;
}

bool WeaponLayer::CheckCollideWithBuff(HeartBuff * buff)
{
	if (buff->getCd() > 0)
	{
		return false;
	}
	auto size = buff->getContentSize();
	CCPoint mPos = buff->getPosition();
	for (auto it : m_BulletList)
	{
		if (it->getPositionX() > mPos.x - size.width*0.3f&&
			it->getPositionX() < mPos.x + size.width*0.3f&&
			it->getPositionY() > mPos.y - size.height*0.3f&&
			it->getPositionY() < mPos.y + size.height*0.3f)
		{
			it->setIsDelete(true);
			return true;
		}
	}
	return false;
}

void WeaponLayer::moveBullet(float dt)
{
	auto size = Director::sharedDirector()->getWinSize();
	for (auto it = std::begin(m_BulletList); it != std::end(m_BulletList);)
	{
		auto itsize = (*it)->getContentSize();
		if ((*it)->getPosition().x > size.width+itsize.width ||
			(*it)->getPosition().x < -itsize.width||
			(*it)->getPosition().y<-itsize.height ||
			(*it)->getPosition().y>size.height+itsize.height||
			(*it)->getIsDelete())
		{
			this->removeChild((*it), true);
			it = m_BulletList.erase(it);
		}
		else
		{
			(*it)->setPosition((*it)->getPosition().x + (*it)->getVx(), (*it)->getPosition().y + (*it)->getVy());
			++it;
		}
	}
}

void WeaponLayer::addCannonAbilityBtn()
{
	CCMenuItemImage* red1 = CCMenuItemImage::create(STATIC_STRING_DATA("addAttack1"), 
		STATIC_STRING_DATA("addAttack1"));
	CCMenuItemImage* red2 = CCMenuItemImage::create(STATIC_STRING_DATA("addAttack"),
		STATIC_STRING_DATA("addAttack"));
	m_addAttackToggle = CCMenuItemToggle::createWithTarget(this, menu_selector(WeaponLayer::addCannonAttack), red1, red2, nullptr);
	m_addAttackToggle->setScale(0.5f);
	m_addAttackToggle->setPosition(SCREEN_SIZE.width*0.45,
		m_addAttackToggle->getContentSize().height*0.248);

	CCMenuItemImage* green1 = CCMenuItemImage::create(STATIC_STRING_DATA("addVelocity1"),
		STATIC_STRING_DATA("addVelocity1"));
	CCMenuItemImage* green2 = CCMenuItemImage::create(STATIC_STRING_DATA("addVelocity"),
		STATIC_STRING_DATA("addVelocity"));
	m_addVelocityToggle = CCMenuItemToggle::createWithTarget(this, menu_selector(WeaponLayer::addBulletVelocity), green1, green2, nullptr);
	m_addVelocityToggle->setScale(0.5f);
	m_addVelocityToggle->setPosition(SCREEN_SIZE.width*0.55,
		m_addVelocityToggle->getContentSize().height*0.25);
	
	CCMenu* menu = CCMenu::create(m_addAttackToggle, m_addVelocityToggle, nullptr);
	menu->setPosition(ccp(0, 0));
	this->addChild(menu);
}

void WeaponLayer::addCannonAttack(cocos2d::CCObject * sender)
{
	int index=m_addAttackToggle->getSelectedIndex();
	index == 1 ? m_pCannon->setAttack(2) : m_pCannon->setAttack(1);
}

void WeaponLayer::addBulletVelocity(cocos2d::CCObject * sender)
{
	int index = m_addVelocityToggle->getSelectedIndex();
	index == 1 ? m_pCannon->setVelocity(Velocity_Base * 2) :
		m_pCannon->setVelocity(Velocity_Base);
}

#include"Cannon.h"
#include"Common.h"
#include"StaticData.h"

bool Cannon::init()
{
	if (CCSprite::init())
	{
		initWithFile(STATIC_STRING_DATA("Cannon"));
		m_drawNode = DrawNode::create();
		this->addChild(m_drawNode);
		this->setAttack(1);
		this->setVelocity(Velocity_Base);
		m_bulletGlod = 0;
		setDrawLine(false);
		return true;
	}
	return false;
}

void Cannon::setDrawLine(bool var)
{
	drawLine = var;
	if (var == false)
	{
		m_drawNode->clear();
	}
}

const bool & Cannon::getDrawLine() const
{
	return drawLine;
}

void Cannon::setAttack(const int & attack)
{
	m_attack = attack;
	m_attack == 1 ? m_bulletGlod -=10 : m_bulletGlod += 10;
}

const int & Cannon::getAttack()
{
	return m_attack;
}

void Cannon::setVelocity(const float & v)
{
	m_velocity = v;
	m_velocity == Velocity_Base ? m_bulletGlod -= 10 : m_bulletGlod += 10;
}

const float & Cannon::getVelocity()
{
	return m_velocity;
}

const int & Cannon::getBulletGlod()
{
	return m_bulletGlod;
}

void Cannon::draw(cocos2d::Renderer * renderer, const cocos2d::Mat4 & transform, uint32_t flags)
{
	if (drawLine==true)
	{
		static auto size = Director::sharedDirector()->getInstance()->getWinSize();
		static CCPoint start = ccp(32, 64);
		static CCPoint duration = ccpMult(ccp(0, 1), size.height * 3);
		static CCPoint end = ccpAdd(start, duration);
		
		m_drawNode->clear();
		m_drawNode->drawLine(start, end, Color4F(0, 1, 0, 1));
		/*ccDrawColor4B(255, 255, 255, 255);
		ccDrawLine(start, end);*/
	}
	CCSprite::draw(renderer, transform, flags);
}

#include "NBombBuff.h"
#include"Common.h"
#include"StaticData.h"
#include"GameScene.h"
#include"GameDataLayer.h"

NBombBuff::NBombBuff()
{
}

NBombBuff::~NBombBuff()
{
}

bool NBombBuff::init()
{
	if (Buff::init())
	{
		initWithFile(STATIC_STRING_DATA("NBomb"));
		setScale(0.5f);
		CCActionInterval* ai = CCRotateBy::create(1.0f, 360);
		this->runAction(CCRepeatForever::create(ai));
		return true;
	}
	return false;
}

void NBombBuff::doBuffThing()
{
	GameSecene* gamescene = dynamic_cast<GameSecene*>(getParent()->getParent());
	auto dataLayer = gamescene->getGameDataLayer(); 
	dataLayer->setNBomb(dataLayer->getNBomb() + 1);
}

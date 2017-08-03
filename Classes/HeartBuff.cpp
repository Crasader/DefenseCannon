#include"HeartBuff.h"
#include"Common.h"
#include"StaticData.h"
#include"GameScene.h"
#include"GameDataLayer.h"

HeartBuff::HeartBuff()
{
}

HeartBuff::~HeartBuff()
{
}

bool HeartBuff::init()
{
	if (Buff::init())
	{
		initWithFile(STATIC_STRING_DATA("heart"));
		setScale(0.5f);
		CCActionInterval* big = CCScaleTo::create(0.2f, 0.52f);
		CCActionInterval* tiny = CCScaleTo::create(0.2f, 0.48f);
		auto action = CCSequence::create(big, tiny, nullptr);
		this->runAction(CCRepeatForever::create(action));
		return true;
	}
	return false;
}

void HeartBuff::doBuffThing()
{
	GameSecene* gamescene = dynamic_cast<GameSecene*>(getParent()->getParent());
	auto dataLayer = gamescene->getGameDataLayer();
	dataLayer->setHeartNum(dataLayer->getHeartNum() + 1);
}


#include"GameEndScene.h"
#include"Common.h"
#include"StaticData.h"
#include"BeginScene.h"

GameEndScene::GameEndScene()
{
}

GameEndScene::~GameEndScene()
{
}

bool GameEndScene::init()
{
	if (CCScene::init())
	{
		CCSprite* back = CCSprite::create(STATIC_STRING_DATA("end"));
		back->setScale(0.6f);
		back->setPosition(SCREEN_SIZE.width*0.5, SCREEN_SIZE.height*0.5);
		this->addChild(back);

		this->scheduleOnce(schedule_selector(GameEndScene::GoBeginScene), 3.0f);
		return true;
	}
	return false;
}

void GameEndScene::GoBeginScene(float dt)
{
	BeginScene* scene = BeginScene::create();
	auto switchTo = CCTransitionFadeBL::create(2.0f, scene);
	CCDirector::sharedDirector()->replaceScene(switchTo);
}

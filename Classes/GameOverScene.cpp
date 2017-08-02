#include"GameOverScene.h"
#include"Common.h"
#include"StaticData.h"
#include"BeginScene.h"

GameOverScene::GameOverScene()
{
}

GameOverScene::~GameOverScene()
{
}

bool GameOverScene::init()
{
	if (CCScene::init())
	{
		CCSprite* back = CCSprite::create(STATIC_STRING_DATA("gameOver"));
		back->setScale(0.6f);
		back->setPosition(SCREEN_SIZE.width*0.5, SCREEN_SIZE.height*0.5);
		this->addChild(back);

		this->scheduleOnce(schedule_selector(GameOverScene::GoBeginScene), 3.0f);
		return true;
	}
	return false;
}

void GameOverScene::GoBeginScene(float dt)
{
	BeginScene* scene = BeginScene::create();
	auto switchTo = CCTransitionFadeBL::create(2.0f, scene);
	CCDirector::sharedDirector()->replaceScene(switchTo);
}

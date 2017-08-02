#include"TransitScene.h"
#include"StaticData.h"
#include"GameScene.h"
#include"GameDataLayer.h"

TransitScene::TransitScene()
{
}

TransitScene::~TransitScene()
{
}

TransitScene * TransitScene::create(Level level)
{
	TransitScene* pRet = new TransitScene;
	if (pRet&&pRet->init(level))
	{
		pRet->autorelease();
		return pRet;
	}
	delete pRet;
	pRet = nullptr;
	return nullptr;
}

bool TransitScene::init(Level level)
{
	if (CCScene::init())
	{
		m_level = level;
		auto size = CCDirector::sharedDirector()->getWinSize();
		CCSprite *back = CCSprite::create(STATIC_STRING_DATA("transit"));
		back->setScale(0.6f);
		back->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(back);

		progreseBg = CCSprite::create(STATIC_STRING_DATA("progress1"));
		progreseBg->setPosition(size.width*0.5, size.height*0.5);
		CCSprite* progressSprite = CCSprite::create(STATIC_STRING_DATA("progress2"));
		m_progressTime = ProgressTimer::create(progressSprite);
		m_progressTime->setType(ProgressTimer::Type::BAR);
		m_progressTime->setMidpoint(ccp(0, 0)); //起点
		m_progressTime->setBarChangeRate(ccp(1, 0));  //变化方式从左到右
		m_progressTime->setPosition(size.width*0.5, size.height*0.5);
		m_progressTime->runAction(CCProgressTo::create(2.0f, 100));
		this->addChild(progreseBg);
		this->addChild(m_progressTime);
		this->schedule(schedule_selector(TransitScene::ObsverProgressBarStatus));
		return true;
	}
	return false;
}

void TransitScene::ObsverProgressBarStatus(float dt)
{
	if (m_progressTime->getPercentage() == 100)
	{
		this->removeChild(m_progressTime);
		this->removeChild(progreseBg);
		this->unschedule(schedule_selector(TransitScene::ObsverProgressBarStatus));
		Sleep(2000);
		GameSecene* gamescene = GameSecene::create(m_level);
		auto dataLayer = gamescene->getGameDataLayer();
		dataLayer->setGlod(m_glod);
		dataLayer->setScore(m_score);
		auto switchTo = CCTransitionFadeDown::create(1.0f, gamescene);
		CCDirector::sharedDirector()->replaceScene(switchTo);
	}
}

#include"BeginLayer.h"
#include"Common.h"
#include"StaticData.h"
#include"GameScene.h"
#include"CannonBoomData.h"
#include"GameDataLayer.h"
#include"audio\include\SimpleAudioEngine.h"
#include<string>
using namespace CocosDenshion;

BeginLayer::BeginLayer()
{
}

BeginLayer::~BeginLayer()
{
}

bool BeginLayer::init()
{
	if (Layer::init())
	{
		auto size = CCDirector::sharedDirector()->getWinSize();

		CCSprite* back = CCSprite::createWithSpriteFrameName("BeginBg");
		back->setScale(0.6f);
		back->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(back);

		LabelTTF* labelGameName = LabelTTF::create(STATIC_STRING_DATA("GameName"), "仿宋", 60);
		labelGameName->setScale(0.5);
		labelGameName->setColor(ccc3(255, 201, 14));
		labelGameName->setPosition(size.width*0.5, size.height*0.8);
		this->addChild(labelGameName);

		CheckAddProgressOrAddBtn();
		return true;
	}
	return false;
}

void BeginLayer::CheckAddProgressOrAddBtn()
{
	bool b=GETBOOLBYKEY_DATYA("isBegin");
	if (b)
	{
		addProgressBar();
		SETBOOLBYKEY_DATA("isBegin", false);
	}
	else
	{
		addGameBtn();
	}
}

void BeginLayer::addProgressBar()
{
	auto size = CCDirector::sharedDirector()->getWinSize();
	progreseBg = CCSprite::create(STATIC_STRING_DATA("progress1"));
	progreseBg->setPosition(size.width*0.5, size.height*0.5);
	CCSprite* progressSprite = CCSprite::create(STATIC_STRING_DATA("progress2"));
	m_progressTime = ProgressTimer::create(progressSprite);
	m_progressTime->setType(ProgressTimer::Type::BAR);
	m_progressTime->setMidpoint(ccp(0, 0)); //起点
	m_progressTime->setBarChangeRate(ccp(1, 0));  //变化方式从左到右
	m_progressTime->setPosition(size.width*0.5, size.height*0.5);
	m_progressTime->runAction(CCProgressTo::create(1.0f, 100));
	this->addChild(progreseBg);
	this->addChild(m_progressTime);
	this->schedule(schedule_selector(BeginLayer::ObsverProgressBarStatus));
}

void BeginLayer::addGameBtn()
{
	auto size = CCDirector::sharedDirector()->getWinSize();
	MenuItemImage* starBtn = MenuItemImage::create(STATIC_STRING_DATA("starBtn"),
		STATIC_STRING_DATA("starBtn"),
		this,
		menu_selector(BeginLayer::callStartGameBack));
	starBtn->setScale(0.5f);
	starBtn->setPosition(size.width*0.5, size.height*0.6);

	MenuItemImage* resumeGame = MenuItemImage::create(STATIC_STRING_DATA("resumeGame"),
		STATIC_STRING_DATA("resumeGame"),
		this,
		menu_selector(BeginLayer::callResumeGameBack));
	resumeGame->setScale(0.5f);
	resumeGame->setPosition(size.width*0.5, size.height*0.5);

	MenuItemImage* Endless = MenuItemImage::create(STATIC_STRING_DATA("Endless"),
		STATIC_STRING_DATA("Endless"),
		this,
		menu_selector(BeginLayer::callEndlessGameBack));
	Endless->setScale(0.5f);
	Endless->setPosition(size.width*0.5, size.height*0.4);

	MenuItemToggle* musicToggle = generiteMusicToggle();
	musicToggle->setScale(0.3f);
	musicToggle->setPosition(size.width*0.77f, size.height*0.12f);

	MenuItemImage* closeBtn = MenuItemImage::create(STATIC_STRING_DATA("closeBtn1"),
		STATIC_STRING_DATA("closeBtn2"),
		this,
		menu_selector(BeginLayer::callCloseBack));
	closeBtn->setScale(0.5f);
	closeBtn->setPosition(size.width*0.77f, size.height*0.04f);

	CCMenu* menu = CCMenu::create(starBtn, resumeGame,Endless, musicToggle, closeBtn, nullptr);
	menu->setPosition(ccp(0, 0));
	this->addChild(menu);
}

void BeginLayer::callStartGameBack(cocos2d::CCObject * sender)
{
	GameSecene* gamescene = GameSecene::create();
	auto reScene = CCTransitionTurnOffTiles::create(1.0, gamescene);
    CCDirector::sharedDirector()->replaceScene(reScene);
}

void BeginLayer::callCloseBack(cocos2d::CCObject * sender)
{
	CCDirector::sharedDirector()->end();
}

void BeginLayer::callResumeGameBack(cocos2d::CCObject * sender)
{
	int glod = GETINTBYKEY_DATA("GameDlod");
	int score = GETINTBYKEY_DATA("GameScore");
	Level level = (Level)GETINTBYKEY_DATA("GameLevel");
	GameSecene* gamescene = GameSecene::create(level);
	auto dataLayer = gamescene->getGameDataLayer();
	dataLayer->setGlod(glod);
	dataLayer->setScore(score);
	auto reScene = CCTransitionTurnOffTiles::create(1.0, gamescene);
	CCDirector::sharedDirector()->replaceScene(reScene);
}

void BeginLayer::callEndlessGameBack(cocos2d::CCObject * sender)
{
	GameSecene* gamescene = GameSecene::create(Level_Endless);
	auto reScene = CCTransitionTurnOffTiles::create(1.0, gamescene);
	CCDirector::sharedDirector()->replaceScene(reScene);
}

cocos2d::CCMenuItemToggle * BeginLayer::generiteMusicToggle()
{
	CCMenuItemImage* onMusic = CCMenuItemImage::create(STATIC_STRING_DATA("openMusic"),
		STATIC_STRING_DATA("openMusic"));
	CCMenuItemImage* offMusic = CCMenuItemImage::create(STATIC_STRING_DATA("closeMusic"),
		STATIC_STRING_DATA("closeMusic"));

	CCMenuItemToggle* musicToggle = CCMenuItemToggle::createWithTarget(this, menu_selector(BeginLayer::callCloseOrOpenMusicBack), onMusic, offMusic, nullptr);
	bool b = CannonBoomData::shareCannonBoomData()->getBoolByKey("MusicIsOn");
	if (b == true)
	{
		musicToggle->setSelectedIndex(0);
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(STATIC_STRING_DATA("sounds_bg").c_str(), true);
	}
	else
	{
		musicToggle->setSelectedIndex(1);
	}
	return musicToggle;
;
}

void BeginLayer::callCloseOrOpenMusicBack(cocos2d::CCObject * sender)
{
	bool b = CannonBoomData::shareCannonBoomData()->getBoolByKey("MusicIsOn");
	if (false == b)
	{
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(STATIC_STRING_DATA("sounds_bg").c_str(), true);
		CannonBoomData::shareCannonBoomData()->setBoolByKey("MusicIsOn", true);
	}
	else
	{
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		CannonBoomData::shareCannonBoomData()->setBoolByKey("MusicIsOn", false);
	}
}

void BeginLayer::ObsverProgressBarStatus(float dt)
{
	if (m_progressTime->getPercentage() == 100)
	{
		this->removeChild(m_progressTime);
		this->removeChild(progreseBg);
		addGameBtn();
		this->unschedule(schedule_selector(BeginLayer::ObsverProgressBarStatus));
	}
}

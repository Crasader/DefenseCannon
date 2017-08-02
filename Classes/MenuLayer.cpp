#include"MenuLayer.h"
#include"Common.h"
#include"GameScene.h"
#include"StaticData.h"
#include"audio\include\SimpleAudioEngine.h"
#include"CannonBoomData.h"
#include"BeginScene.h"
using namespace CocosDenshion;

MenuLayer::MenuLayer()
{
}

MenuLayer::~MenuLayer()
{
}

bool MenuLayer::init()
{
	if (Layer::init())
	{
		auto size = Director::sharedDirector()->getWinSize();
		CCLayerColor* layerColor = CCLayerColor::create(ccc4(195, 195, 195, 200), size.width, size.height);
		this->addChild(layerColor);

		CCLabelTTF* label = CCLabelTTF::create(STATIC_STRING_DATA("resume"), "Î¢ÈíÑÅºÚ", 24);
		label->setColor(ccc3(255,127,39));
		MenuItemLabel* Resume = MenuItemLabel::create(label,this,menu_selector(MenuLayer::callResumeBack));
	
		CCMenuItemToggle* musicTogle = generiteMusicSwitch();

		label = CCLabelTTF::create(STATIC_STRING_DATA("closeGame"), "Î¢ÈíÑÅºÚ", 24);
		label->setColor(ccc3(255, 127, 39));
		MenuItemLabel* closeGame = MenuItemLabel::create(label, this, menu_selector(MenuLayer::BackToBeginScene));

		CCMenu* menu = CCMenu::create(Resume,musicTogle,closeGame, nullptr);
		menu->alignItemsVerticallyWithPadding(20);
		this->addChild(menu);
		return true;
	}
	return false;
}

void MenuLayer::callResumeBack(cocos2d::CCObject * sender)
{
	GameSecene* gameScene = dynamic_cast<GameSecene*>(getParent());
	gameScene->removeMenuLayer();
	gameScene->resumeAllAction(gameScene);
}

void MenuLayer::callOnOrOffMusicBack(cocos2d::CCObject * sender)
{
	bool b=CannonBoomData::shareCannonBoomData()->getBoolByKey("MusicIsOn");
	if (false==b)
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

void MenuLayer::BackToBeginScene(cocos2d::CCObject * sender)
{
	BeginScene* scene = BeginScene::create();
	auto switchTo = CCTransitionFadeBL::create(2.0f, scene);
	CCDirector::sharedDirector()->replaceScene(switchTo);
}

cocos2d::CCMenuItemToggle * MenuLayer::generiteMusicSwitch()
{
	CCLabelTTF* label = CCLabelTTF::create(STATIC_STRING_DATA("onMusic"), "Î¢ÈíÑÅºÚ", 24);
	label->setColor(ccc3(255, 127, 39));
	MenuItemLabel* MusicOn = MenuItemLabel::create(label);
	label = CCLabelTTF::create(STATIC_STRING_DATA("offMusic"), "Î¢ÈíÑÅºÚ", 24);
	label->setColor(ccc3(255, 127, 39));
	MenuItemLabel* MusicOff = MenuItemLabel::create(label);
	CCMenuItemToggle* musicTogle = CCMenuItemToggle::createWithTarget(this,
		menu_selector(MenuLayer::callOnOrOffMusicBack),
		MusicOn, MusicOff, nullptr);
	bool b = CannonBoomData::shareCannonBoomData()->getBoolByKey("MusicIsOn");
	b == true ? musicTogle->setSelectedIndex(1) : musicTogle->setSelectedIndex(0);

	return musicTogle;
}


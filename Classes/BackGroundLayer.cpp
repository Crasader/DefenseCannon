#include"BackGroundLayer.h"
#include"Cannon.h"
#include"StaticData.h"
#include"GameScene.h"
#include"CannonBoomData.h"

BackGroundLayer::BackGroundLayer()
{
}

BackGroundLayer::~BackGroundLayer()
{
}

BackGroundLayer* BackGroundLayer::create(Level level)
{
	BackGroundLayer* pRet = new BackGroundLayer();
	if (pRet&&pRet->init(level))
	{
		return pRet;
	}
	delete pRet;
	pRet = nullptr;
	return nullptr;
}

bool BackGroundLayer::init(Level level)
{
	if (Layer::init())
	{
		auto size = CCDirector::sharedDirector()->getWinSize();
		CCSprite* back = CCSprite::create(STATIC_STRING_DATA("GameBg"));
		back->setScale(0.6);
		back->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(back);

		CCMenuItemImage* menuItem = CCMenuItemImage::create(STATIC_STRING_DATA("closeBtn1"),
			STATIC_STRING_DATA("closeBtn2"),
			this,
			menu_selector(BackGroundLayer::callMainMenuBack));
		menuItem->setScale(0.6f);
		menuItem->setPosition(size.width -115,15);

		CCMenu *menu = CCMenu::create(menuItem, nullptr);
		menu->setPosition(0,0);
		this->addChild(menu);

		return true;
	}
	return false;
}

void BackGroundLayer::callMainMenuBack(cocos2d::CCObject * sender)
{
	GameSecene* gameScene = dynamic_cast<GameSecene*>(getParent());
	gameScene->pauseAllAction(gameScene);
	gameScene->addMenuLayer();
}


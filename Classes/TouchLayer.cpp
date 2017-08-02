#include"TouchLayer.h"
#include"Common.h"
#include"WeaponLayer.h"

TouchLayer::TouchLayer()
{
}

TouchLayer::~TouchLayer()
{
}

bool TouchLayer::init()
{
	if (Layer::init())
	{
		setTouchEnabled(true);
		auto touchListener = EventListenerTouchOneByOne::create();
		touchListener->onTouchBegan = CC_CALLBACK_2(TouchLayer::onTouchBegan, this);
		touchListener->onTouchMoved = CC_CALLBACK_2(TouchLayer::onTouchMoved, this);
		touchListener->onTouchEnded = CC_CALLBACK_2(TouchLayer::onTouchEnded, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
		return true;
	}
	return false;
}

void TouchLayer::CannonTurnTo(cocos2d::CCPoint target)
{
	WeaponLayer *weapon = dynamic_cast<WeaponLayer*>(this->getParent());
	weapon->CannonTurnTo(target);
}

void TouchLayer::CannonShot(cocos2d::CCPoint target)
{
	WeaponLayer *weapon = dynamic_cast<WeaponLayer*>(this->getParent());
	weapon->CannonShot(target);
}

bool TouchLayer::onTouchBegan(Touch * touch, Event * unused_event)
{
	CCPoint target = loactionFromTouch(touch);
	CannonTurnTo(target);
	return true;
}

void TouchLayer::onTouchMoved(Touch * touch, Event * unused_event)
{
	CCPoint target = loactionFromTouch(touch);
	CannonTurnTo(target);
}

void TouchLayer::onTouchEnded(Touch * touch, Event * unused_event)
{
	CCPoint target = loactionFromTouch(touch);
	CannonShot(target);
}

cocos2d::CCPoint TouchLayer::loactionFromTouch(cocos2d::Touch * touch)
{
	return CCDirector::sharedDirector()->convertToGL(touch->getLocationInView());
}

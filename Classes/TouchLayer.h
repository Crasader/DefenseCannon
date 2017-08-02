#pragma once
#ifndef __TOUCHLAYER_H__
#define __TOUCHLAYER_H__
#include"cocos2d.h"

class TouchLayer :public cocos2d::Layer
{
public:
	TouchLayer();
	virtual ~TouchLayer();
	CREATE_FUNC(TouchLayer);
	bool init();

	/*
	*CannonTurnTo(cocos2d::CCPoint target);
	*炮弹瞄准转向
	*@Param target:目标点
	*/
	void CannonTurnTo(cocos2d::CCPoint target);

	/*
	*CannonShot(cocos2d::CCPoint target);
	*发射炮弹
	*@Param target：目标点
	*/
	void CannonShot(cocos2d::CCPoint target);
protected:
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	/*
	loactionFromTouch(cocos2d::Touch * touch)
	转换触摸点坐标到实际坐标
	@Param touch：当前触摸实例
	*/
	cocos2d::CCPoint loactionFromTouch(cocos2d::Touch * touch);
};

#endif // !__TOUCHLAYER_H__


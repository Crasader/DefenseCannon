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
	*�ڵ���׼ת��
	*@Param target:Ŀ���
	*/
	void CannonTurnTo(cocos2d::CCPoint target);

	/*
	*CannonShot(cocos2d::CCPoint target);
	*�����ڵ�
	*@Param target��Ŀ���
	*/
	void CannonShot(cocos2d::CCPoint target);
protected:
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	/*
	loactionFromTouch(cocos2d::Touch * touch)
	ת�����������굽ʵ������
	@Param touch����ǰ����ʵ��
	*/
	cocos2d::CCPoint loactionFromTouch(cocos2d::Touch * touch);
};

#endif // !__TOUCHLAYER_H__


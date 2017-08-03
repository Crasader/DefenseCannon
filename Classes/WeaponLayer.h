#pragma once
#ifndef  __WEAPON_H__
#define __WEAPON_H__
#include"cocos2d.h"
#include<list>

class Cannon;
class Bullet;
class TouchLayer;
class Monster;
class HeartBuff;
class Buff;

/*
*WeaponLayer
*�����ڡ��ӵ�����������һ��
*/
class WeaponLayer :public cocos2d::Layer
{
public:
	WeaponLayer();
	virtual ~WeaponLayer();
	CREATE_FUNC(WeaponLayer);
	bool init();

	/*
	CannonTurnTo(cocos2d::CCPoint target);
	������ת��ָ������
	@Param target:ָ���ķ���
	*/
	void CannonTurnTo(cocos2d::CCPoint target);

	/*
	CannonShot(cocos2d::CCPoint target);
	�ڵ�����
	@Param target��Ŀ���
	*/
	void CannonShot(cocos2d::CCPoint target);

	/*
	*CheckCollideWithMonster(Monster* monster);
	*����ӵ��Ƿ�����﷢����ײ
	*@Param monster:�������ָ��
	*@return int��������ײ�����ӵ���������δ��ײ����0
	*/
    int CheckCollideWithMonster(Monster* monster);

	/*
	*CheckCollideWithBuff(HeartBuff* buff);
	*����ӵ��Ƿ���ײbuff
	*@Param buff��buff����ָ��
	*@return bool��true��ײ��falseδ��ײ
	*/
	bool CheckCollideWithBuff(Buff* buff);
private:
	/*
	*moveBullet(float dt)
	*�ƶ��ӵ�
	*@Param dt����ʱ����ʱ
	*/
	void moveBullet(float dt);

	/*
	*addBulletAbilityBtn();
	*������Ӵ���������ť
	*/
	void addCannonAbilityBtn();

	/*
	*addCannonAttack(cocos2d::CCObject* sender);
	*���Ӵ��ڹ�������ť�ص�����
	*/
	void addCannonAttack(cocos2d::CCObject* sender);

	/*
	*addBulletVelocity(cocos2d::CCObject* sender);
	*���Ӵ����ӵ��ٶȰ�ť�ص�����
	*/
	void addBulletVelocity(cocos2d::CCObject* sender);

	/*
	*releaseNBomb(cocos2d::CCObject* sender);
	*�ͷź˵�
	*/
	void releaseNBomb(cocos2d::CCObject* sender);

	void removeRedLayer(float dt);

	Cannon* m_pCannon;
	std::list<Bullet*> m_BulletList;
	TouchLayer* m_touchLayer;
	cocos2d::CCMenuItemToggle* m_addAttackToggle;
	cocos2d::CCMenuItemToggle* m_addVelocityToggle;
};

#endif // ! __WEAPON_H__


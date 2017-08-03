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
*集大炮、子弹、触摸层于一身
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
	将大炮转向指定方向
	@Param target:指定的方向
	*/
	void CannonTurnTo(cocos2d::CCPoint target);

	/*
	CannonShot(cocos2d::CCPoint target);
	炮弹发射
	@Param target：目标点
	*/
	void CannonShot(cocos2d::CCPoint target);

	/*
	*CheckCollideWithMonster(Monster* monster);
	*检测子弹是否与怪物发生碰撞
	*@Param monster:怪物对象指针
	*@return int：发生碰撞返回子弹攻击力，未碰撞返回0
	*/
    int CheckCollideWithMonster(Monster* monster);

	/*
	*CheckCollideWithBuff(HeartBuff* buff);
	*检测子弹是否碰撞buff
	*@Param buff：buff对象指针
	*@return bool：true碰撞，false未碰撞
	*/
	bool CheckCollideWithBuff(Buff* buff);
private:
	/*
	*moveBullet(float dt)
	*移动子弹
	*@Param dt：定时器延时
	*/
	void moveBullet(float dt);

	/*
	*addBulletAbilityBtn();
	*添加增加大炮能力按钮
	*/
	void addCannonAbilityBtn();

	/*
	*addCannonAttack(cocos2d::CCObject* sender);
	*增加大炮攻击力按钮回调函数
	*/
	void addCannonAttack(cocos2d::CCObject* sender);

	/*
	*addBulletVelocity(cocos2d::CCObject* sender);
	*增加大炮子弹速度按钮回调函数
	*/
	void addBulletVelocity(cocos2d::CCObject* sender);

	/*
	*releaseNBomb(cocos2d::CCObject* sender);
	*释放核弹
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


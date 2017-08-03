#pragma once
#ifndef  __MONSTERLAYER_H__
#define __MONSTERLAYER_H__
#include"cocos2d.h"
#include"Common.h"
#include<list>

class Monster;
class FStar;
class CocosRectangle;

/*
*class MonsterLayer
*怪物层产生怪物，并处理怪物的一些逻辑
*/
class MonsterLayer :public cocos2d::Layer
{
public:
	enum Type_Monster
	{
		Monster_Tri,
		Monster_FStar,
		Monster_Star,
		Monster_SStar,
	};

	MonsterLayer();
	virtual ~MonsterLayer();
	static MonsterLayer* create(const Level level=Level_one);
	bool init(Level level);

	/*
	*remveAllMonster();
	*移除所有怪物
	*/
	void removeAllMonster();
private:
	/*
	*CheckCollideWithBomb(float dt);
	*检测怪物是否与子弹发生碰撞
	*@Param dt：定时器时延
	*/
	void CheckCollideWithBomb(float dt);

	/*
	*MoveMonster(float dt)
	*移动怪物
	*@Param dt:定时器时延
	*/
	void MoveMonster(float dt);

	/*
	*CreateMonster(float dt)
	*每隔一定时间产生一些怪物怪物
	*@Param dt：定时器时延
	*/
	void CreateMonster(float dt);

	/*
	*CreteLevelOneMonster();
	*产生关卡一的怪物
	*/
	void CreteLevelOneMonster();

	/*
	*CreateLevelTwoMonter();
	*产生关卡二的怪物
	*/
	void CreateLevelTwoMonter();

	/*
	*CreateLevelThreeMonster();
	*产生关卡三的怪物
	*/
	void CreateLevelThreeMonster();

	/*
	*CreateEndlessMonster();
	*创建无尽模式的怪物
	*/
	void CreateEndlessMonster();

	/*
	*void CreateOneMonster(int type);
	*产生单个怪物
	*@Param type：怪物类型
	*/
	void CreateOneMonster(Type_Monster type);

	void CreateBoss();

	/*
	*CreateBossHat();
	*创建Boss
	*/
	void CreateBossHat(float dt);
	void CreateBossCard(float dt);
	void CreateBossCattleHead(float dt);
	void CreateEndlessBoss(float dt);

	/*
	*doBossLogic(float dt);
	*处理Boss的行为逻辑
	*/
	void doBossLogic(float dt);

	/*
	*GoNext();
	*进入下一关
	*/
	void GoNext();
	void GoNext(float dt);

	/*
	*randomCreateBuff();
	*随机产生buff
	*/
	void randomCreateBuff(cocos2d::CCPoint pos);

	std::list<Monster*> m_monsterList;
	Level m_level;
	Monster* m_Boss;

	//纪录游戏进行时间
	__int64 m_count = 1; 
	__int64 m_Mcount = 1;
};

#endif // ！__MONSTERLAYER_H__
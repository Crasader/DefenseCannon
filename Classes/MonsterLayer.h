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
*���������������������һЩ�߼�
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
	*�Ƴ����й���
	*/
	void removeAllMonster();
private:
	/*
	*CheckCollideWithBomb(float dt);
	*�������Ƿ����ӵ�������ײ
	*@Param dt����ʱ��ʱ��
	*/
	void CheckCollideWithBomb(float dt);

	/*
	*MoveMonster(float dt)
	*�ƶ�����
	*@Param dt:��ʱ��ʱ��
	*/
	void MoveMonster(float dt);

	/*
	*CreateMonster(float dt)
	*ÿ��һ��ʱ�����һЩ�������
	*@Param dt����ʱ��ʱ��
	*/
	void CreateMonster(float dt);

	/*
	*CreteLevelOneMonster();
	*�����ؿ�һ�Ĺ���
	*/
	void CreteLevelOneMonster();

	/*
	*CreateLevelTwoMonter();
	*�����ؿ����Ĺ���
	*/
	void CreateLevelTwoMonter();

	/*
	*CreateLevelThreeMonster();
	*�����ؿ����Ĺ���
	*/
	void CreateLevelThreeMonster();

	/*
	*CreateEndlessMonster();
	*�����޾�ģʽ�Ĺ���
	*/
	void CreateEndlessMonster();

	/*
	*void CreateOneMonster(int type);
	*������������
	*@Param type����������
	*/
	void CreateOneMonster(Type_Monster type);

	void CreateBoss();

	/*
	*CreateBossHat();
	*����Boss
	*/
	void CreateBossHat(float dt);
	void CreateBossCard(float dt);
	void CreateBossCattleHead(float dt);
	void CreateEndlessBoss(float dt);

	/*
	*doBossLogic(float dt);
	*����Boss����Ϊ�߼�
	*/
	void doBossLogic(float dt);

	/*
	*GoNext();
	*������һ��
	*/
	void GoNext();
	void GoNext(float dt);

	/*
	*randomCreateBuff();
	*�������buff
	*/
	void randomCreateBuff(cocos2d::CCPoint pos);

	std::list<Monster*> m_monsterList;
	Level m_level;
	Monster* m_Boss;

	//��¼��Ϸ����ʱ��
	__int64 m_count = 1; 
	__int64 m_Mcount = 1;
};

#endif // ��__MONSTERLAYER_H__
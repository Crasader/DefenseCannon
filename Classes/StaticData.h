#pragma once
#ifndef __STATIC_DATA_H__
#define __STATIC_DATA_H__

#include"cocos2d.h"
#include<string>

#define STATIC_INT_DATA StaticData::shareStaticData()->intFromKey
#define STATIC_FLOAT_DATA StaticData::shareStaticData()->floatFromKey
#define STATIC_STRING_DATA StaticData::shareStaticData()->stringFromKey
#define STATIC_POINT_DATA StaticData::shareStaticData()->pointFromKey
#define STATIC_BOOL_DATD StaticData::shareStaticData()->boolFromKey
#define STATIC_RECT_DATA StaticData::shareStaticData()->rectFromKey
#define STATIC_SIZE_DATA StaticData::shareStaticData()->sizeFromKey
#define STATIC_DATA_PATH StaticData::shareStaticData()->getStaticDataPath

/*
class StaticData
用于读取和操作游戏的静态数据
*/
class StaticData :public cocos2d::CCObject
{
public:
	static StaticData* shareStaticData();

	virtual const std::string& getStaticDataPath();

	std::string stringFromKey(const char* key);

	int intFromKey(const char* key);

	float floatFromKey(const  char* key);

	bool boolFromKey(const char* key);

	cocos2d::CCPoint pointFromKey(const char* key);

	cocos2d::CCRect rectFromKey(const char* key);

	cocos2d::CCSize sizeFromKey(const char* key);

	/*
	*purge();
	*释放单实例对象
	*/
	void purge();
protected:
	//数据保存的路径
	std::string m_statciDataPath;

	//数据字典
	cocos2d::CCDictionary* m_pDictionary;
private:
	StaticData();
	virtual ~StaticData();
	bool init();
};

#endif // !__STATIC_DATA_H__


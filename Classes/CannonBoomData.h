#pragma once

#ifndef __CANNONBOOM_H_
#define __CANNONBOOM_H_
#include"cocos2d.h"
#include<string>
#include<map>

#define SETINTBYKEY_DATA CannonBoomData::shareCannonBoomData()->setIntByKey
#define SETFLOATBYKEY_DATA CannonBoomData::shareCannonBoomData()->setFloatByKey
#define SETBOOLBYKEY_DATA CannonBoomData::shareCannonBoomData()->setBoolByKey
#define SETSTRINGBYKEY_DATA CannonBoomData::shareCannonBoomData()->setStringByKey

#define GETINTBYKEY_DATA CannonBoomData::shareCannonBoomData()->getIntByKey
#define GETFLOATBYKEY_DATA CannonBoomData:shareCannonBoomData()->getFloatByKey
#define GETBOOLBYKEY_DATYA CannonBoomData::shareCannonBoomData()->getBoolByKey
#define GETSTRINGBYKEY_DATA CannonBoomData::shareCannonBoomData()->getStringByKey

/*
*class CannonBoomData
*用于读取和设置游戏中的动态数据
*/
class CannonBoomData:public cocos2d::CCObject
{
public:
	/*
	*shareCannonBoomData();
	*单例设计模式，利用一个共享的静态单例操作游戏的动态数据
	@return static CannonBoomData* ：共享的单例
	*/
	static CannonBoomData* shareCannonBoomData();

	/*
	*setIntByKey(const std::string& key,const int& v);
	*设置值为int型的游戏数据
	*@Param key：key值
	*@Param v：value值
	*/
	void setIntByKey(const std::string& key,const int& v);

	/*
	*setFloatByKey(const std::string& key, const float& v);
	*设置值为float型的游戏数据
	*@Param key：key值
	*@Parma v：value值
	*/
	void setFloatByKey(const std::string& key, const float& v);

	/*
	*setBoolByKey(const std::string& key, const float& v);
	*设置值为bool型的游戏数据
	*@Param key：key值
	*@Param float v：value值
	*/
	void setBoolByKey(const std::string& key, const bool& v);

	/*
	*setStringByKey(const std::string& key, const std::string& v);
	*设置值为string型的游戏数据
	*@Param key：key值
	*@Param v：value值
	*/
	void setStringByKey(const std::string& key, const std::string& v);

	/*
	*getIntByKey(const std::string& key);
	*通过key值获取int型数据
	*@return int：获取的int数据
	*/
	int getIntByKey(const std::string& key);

	/*
	*getFloatByKey(const std::string& key);
	*通过key值获取float型的值
	*@return float：获取的float数据
	*/
	float getFloatByKey(const std::string& key);

	/*
	*getBoolByKey(const std::string& key);
	*通过key值获取boo型的数据
	*@return bool：获取的bool数据
	*/
	bool getBoolByKey(const std::string& key);

	/*
	*getStringByKey(const std::string& key);
	*同过key值获取string型的数据
	*@return string ：获取的string数据
	*/
	std::string getStringByKey(const std::string& key);

	/*
	*purge();
	*释放单实例对象
	*/
	void purge();

	/*
	*flush();
	*将数据保存到文件
	*/
	void flush();
protected:
	/*
	*initDataFromFile();
	*从文件中读取游戏数据进行初始化
	*@return true：读取成功
	*@return false：读取失败
	*/
	bool initDataFromFile();

	//用于保存游戏数据的map
	std::map<std::string, std::string> m_mapData;
private:
	CannonBoomData();
	virtual ~CannonBoomData();
	bool init();
};


#endif // !__CANNONBOOM_H_

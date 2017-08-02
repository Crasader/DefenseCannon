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
*���ڶ�ȡ��������Ϸ�еĶ�̬����
*/
class CannonBoomData:public cocos2d::CCObject
{
public:
	/*
	*shareCannonBoomData();
	*�������ģʽ������һ������ľ�̬����������Ϸ�Ķ�̬����
	@return static CannonBoomData* ������ĵ���
	*/
	static CannonBoomData* shareCannonBoomData();

	/*
	*setIntByKey(const std::string& key,const int& v);
	*����ֵΪint�͵���Ϸ����
	*@Param key��keyֵ
	*@Param v��valueֵ
	*/
	void setIntByKey(const std::string& key,const int& v);

	/*
	*setFloatByKey(const std::string& key, const float& v);
	*����ֵΪfloat�͵���Ϸ����
	*@Param key��keyֵ
	*@Parma v��valueֵ
	*/
	void setFloatByKey(const std::string& key, const float& v);

	/*
	*setBoolByKey(const std::string& key, const float& v);
	*����ֵΪbool�͵���Ϸ����
	*@Param key��keyֵ
	*@Param float v��valueֵ
	*/
	void setBoolByKey(const std::string& key, const bool& v);

	/*
	*setStringByKey(const std::string& key, const std::string& v);
	*����ֵΪstring�͵���Ϸ����
	*@Param key��keyֵ
	*@Param v��valueֵ
	*/
	void setStringByKey(const std::string& key, const std::string& v);

	/*
	*getIntByKey(const std::string& key);
	*ͨ��keyֵ��ȡint������
	*@return int����ȡ��int����
	*/
	int getIntByKey(const std::string& key);

	/*
	*getFloatByKey(const std::string& key);
	*ͨ��keyֵ��ȡfloat�͵�ֵ
	*@return float����ȡ��float����
	*/
	float getFloatByKey(const std::string& key);

	/*
	*getBoolByKey(const std::string& key);
	*ͨ��keyֵ��ȡboo�͵�����
	*@return bool����ȡ��bool����
	*/
	bool getBoolByKey(const std::string& key);

	/*
	*getStringByKey(const std::string& key);
	*ͬ��keyֵ��ȡstring�͵�����
	*@return string ����ȡ��string����
	*/
	std::string getStringByKey(const std::string& key);

	/*
	*purge();
	*�ͷŵ�ʵ������
	*/
	void purge();

	/*
	*flush();
	*�����ݱ��浽�ļ�
	*/
	void flush();
protected:
	/*
	*initDataFromFile();
	*���ļ��ж�ȡ��Ϸ���ݽ��г�ʼ��
	*@return true����ȡ�ɹ�
	*@return false����ȡʧ��
	*/
	bool initDataFromFile();

	//���ڱ�����Ϸ���ݵ�map
	std::map<std::string, std::string> m_mapData;
private:
	CannonBoomData();
	virtual ~CannonBoomData();
	bool init();
};


#endif // !__CANNONBOOM_H_

#include"CannonBoomData.h"
#include"Common.h"
#include<fstream>
#include<regex>
using namespace std;
USING_NS_CC;

static CannonBoomData* _shareCannonData = nullptr;

#define CannonBoomDataPath "CannonData.xml"

CannonBoomData * CannonBoomData::shareCannonBoomData()
{
	if (_shareCannonData == nullptr)
	{
		_shareCannonData = new CannonBoomData();
		_shareCannonData->init();
	}
	return _shareCannonData;
}

void CannonBoomData::setIntByKey(const std::string & key, const int & v)
{
	stringstream sstream;
	sstream << v;
	sstream >> m_mapData[key];
}

void CannonBoomData::setFloatByKey(const std::string & key, const float & v)
{
	stringstream sstream;
	sstream << v;
	sstream >> m_mapData[key];
}

void CannonBoomData::setBoolByKey(const std::string & key, const bool & v)
{
	if (v == true)
	{
		m_mapData[key] = "true";
	}
	else
	{
		m_mapData[key] = "false";
	}
}

void CannonBoomData::setStringByKey(const std::string & key, const std::string & v)
{
	m_mapData[key] = v;
}

int CannonBoomData::getIntByKey(const std::string & key)
{
	if (m_mapData.find(key) != m_mapData.end())
	{
		return stoi(m_mapData[key]);
	}
	return -1;
}

float CannonBoomData::getFloatByKey(const std::string & key)
{
	if (m_mapData.find(key) != m_mapData.end())
	{
		return stof(m_mapData[key]);
	}
	return -1.0f;
}

bool CannonBoomData::getBoolByKey(const std::string & key)
{
	if (m_mapData.find(key) != m_mapData.end())
	{
		if (m_mapData[key] == "true")
		{
			return true;
		}
	}
	return false;
}

std::string CannonBoomData::getStringByKey(const std::string & key)
{
	if (m_mapData.find(key) != m_mapData.end())
	{
		return m_mapData[key];
	}
	return "";
}

void CannonBoomData::purge()
{
	CC_SAFE_RELEASE_NULL(_shareCannonData);
}

void CannonBoomData::flush()
{
	ofstream fout(CannonBoomDataPath,ios::out);
	if (fout.fail()==true)
	{
		return;
	}
	for (const auto& it : m_mapData)
	{
		fout << it.first << ":" << it.second << endl;
	}
	fout.close();
}

bool CannonBoomData::initDataFromFile()
{
	ifstream fin(CannonBoomDataPath, ios::in);
	if (fin.fail() == true)
	{
		return false;
	}
	string temp;
	while (fin>>temp)
	{
		//ÇÐ¸î×Ö·û´®
		regex split(("\\s*[:]\\s*"));
		const sregex_token_iterator send;
		string keyValue[3];
		int i = 0;
		for (sregex_token_iterator iter(temp.cbegin(), temp.cend(), split, -1); iter != send; ++iter)
		{
			keyValue[i++] = *iter;
		}
		m_mapData[keyValue[0]] = keyValue[1];
	}
	fin.close();
	return true;
}

CannonBoomData::CannonBoomData()
{
}

CannonBoomData::~CannonBoomData()
{
	flush();
	m_mapData.clear();
}

bool CannonBoomData::init()
{
	m_mapData.clear();
	initDataFromFile();
	return true;
}

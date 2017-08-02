#include"StaticData.h"
#include"Common.h"
USING_NS_CC;
using namespace std;

#define StaticFileName "static_data.plist"

static StaticData* _shareStaticData = nullptr;

StaticData * StaticData::shareStaticData()
{
	if (_shareStaticData == nullptr)
	{
		_shareStaticData = new StaticData();
		if (false == _shareStaticData->init())
		{
			return nullptr;
		}
	}
	return _shareStaticData;
}

const std::string & StaticData::getStaticDataPath()
{
	return m_statciDataPath;
}

std::string StaticData::stringFromKey(const char* key)
{
	return m_pDictionary->valueForKey(key)->getCString();
}

int StaticData::intFromKey(const char* key)
{
	return m_pDictionary->valueForKey(key)->intValue();
}

float StaticData::floatFromKey(const  char* key)
{
	return m_pDictionary->valueForKey(key)->floatValue();
}

bool StaticData::boolFromKey(const char* key)
{
	return m_pDictionary->valueForKey(key)->boolValue();
}

cocos2d::CCPoint StaticData::pointFromKey(const char* key)
{
	return PointFromString(m_pDictionary->valueForKey(key)->getCString());
}

cocos2d::CCRect StaticData::rectFromKey(const char* key)
{
	return RectFromString(m_pDictionary->valueForKey(key)->getCString());
}

cocos2d::CCSize StaticData::sizeFromKey(const char* key)
{
	return SizeFromString(m_pDictionary->valueForKey(key)->getCString());
}

void StaticData::purge()
{
	CC_SAFE_RELEASE_NULL(_shareStaticData);
}

StaticData::StaticData()
{
	m_statciDataPath = StaticFileName;
}

StaticData::~StaticData()
{
	CC_SAFE_RELEASE_NULL(m_pDictionary);
}

bool StaticData::init()
{
	m_pDictionary = CCDictionary::createWithContentsOfFile(m_statciDataPath.c_str());
	if (m_pDictionary == nullptr)
	{
		return false;
	}
	CC_SAFE_RETAIN(m_pDictionary);
	return true;
}
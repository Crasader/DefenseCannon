#include"GameDataLayer.h"
#include"StaticData.h"
#include"CannonBoomData.h"
#include"GameScene.h"
#include<sstream>
#include<string>
using namespace std;

GameDataLayer::GameDataLayer()
{
}

GameDataLayer::~GameDataLayer()
{
}

bool GameDataLayer::init()
{
	if (Layer::init())
	{
		stringstream sstream;
		string str;
		auto size = CCDirector::sharedDirector()->getWinSize();
		LabelTTF* glodTextLabel = LabelTTF::create(STATIC_STRING_DATA("glodText"), "楷体", 24);
		glodTextLabel->setColor(ccc3(255,127,39));
		glodTextLabel->setScale(0.5f);
		glodTextLabel->setPosition(size.width*0.26, size.height*0.97);
		this->addChild(glodTextLabel);
		
		sstream << m_glod;
		sstream >> str;
		m_glodLabel = LabelTTF::create(str, "楷体", 24);
		m_glodLabel->setColor(ccc3(255, 242, 0));
		m_glodLabel->setScale(0.5f);
		m_glodLabel->setAnchorPoint(ccp(0, 0.5f));
		m_glodLabel->setPosition(size.width*0.30, size.height*0.97);
		this->addChild(m_glodLabel);
		
		LabelTTF* scoreTextLabel = LabelTTF::create(STATIC_STRING_DATA("scoreText"), "楷体", 24);
		scoreTextLabel->setColor(ccc3(34, 177, 76));
		scoreTextLabel->setScale(0.5f);
		scoreTextLabel->setPosition(size.width*0.26, size.height*0.92);
		this->addChild(scoreTextLabel);
		
		sstream << m_score;
		sstream >> str;
		m_scoreLabel = LabelTTF::create(str, "楷体", 24);
		m_scoreLabel->setColor(ccc3(0, 162, 232));
		m_scoreLabel->setScale(0.5f);
		m_scoreLabel->setAnchorPoint(ccp(0, 0.5f));
		m_scoreLabel->setPosition(size.width*0.30, size.height*0.92);
		this->addChild(m_scoreLabel);

		LabelTTF* levelTextLabel = LabelTTF::create(STATIC_STRING_DATA("levelText"), "楷体", 24);
		levelTextLabel->setColor(ccc3(181, 230, 29));
		levelTextLabel->setScale(0.5f);
		levelTextLabel->setPosition(size.width*0.26, size.height*0.87);
		this->addChild(levelTextLabel);
		
		sstream << m_Level;
		sstream >> str;
		m_levelLabel = LabelTTF::create(str, "楷体", 24);
		m_levelLabel->setColor(ccc3(153, 217, 234));
		m_levelLabel->setScale(0.5f);
		m_levelLabel->setAnchorPoint(ccp(0, 0.5));
		m_levelLabel->setPosition(size.width*0.3, size.height*0.87);
		this->addChild(m_levelLabel);

		CCSprite* spriteHeart = CCSprite::create(STATIC_STRING_DATA("heart"));
		spriteHeart->setScale(0.3f);
		spriteHeart->setPosition(size.width*0.24, size.height*0.8);
		this->addChild(spriteHeart);

		sstream << ":" << m_heartNum;
		sstream >> str;
		m_heartLabel = LabelTTF::create(str,"楷体",24);
		m_heartLabel->setColor(ccc3(255, 0, 0));
		m_heartLabel->setScale(0.5f);
		m_heartLabel->setAnchorPoint(ccp(0, 0.5));
		m_heartLabel->setPosition(size.width*0.26, size.height*0.8);
		this->addChild(m_heartLabel);

		CCSprite* spriteBomb = CCSprite::create(STATIC_STRING_DATA("NBomb"));
		spriteBomb->setScale(0.35f);
		spriteBomb->setPosition(size.width*0.24, size.height*0.74);
		this->addChild(spriteBomb);

		sstream << ":" << m_heartNum;
		sstream >> str;
		m_nBombLabel = LabelTTF::create(str, "楷体", 24);
		m_nBombLabel->setColor(ccc3(255, 0, 0));
		m_nBombLabel->setScale(0.5f);
		m_nBombLabel->setAnchorPoint(ccp(0, 0.5));
		m_nBombLabel->setPosition(size.width*0.26, size.height*0.74);
		this->addChild(m_nBombLabel);

		CCMenuItemImage* saveGame = CCMenuItemImage::create(STATIC_STRING_DATA("saveGame"),
			STATIC_STRING_DATA("saveGame1"),
			this,
			menu_selector(GameDataLayer::callSaveGameBack));
		saveGame->setScale(0.3f);
		saveGame->setPosition(size.width*0.75, size.height*0.95);
		CCMenu* menu = CCMenu::create(saveGame, nullptr);
		menu->setPosition(ccp(0, 0));
		this->addChild(menu);

		setGlod(0);
		setScore(0);
		setNBomb(2);
		setHeartNum(10);
		return true;
	}
	return false;
}

void GameDataLayer::setGlod(const int & glod)
{
	m_glod = glod;
	stringstream sstream;
	string str;
	sstream << m_glod;
	sstream >> str;
	m_glodLabel->setString(str);
}

void GameDataLayer::setScore(const int & score)
{
	m_score = score;
	stringstream sstream;
	string str;
	sstream << m_score;
	sstream >> str;
	m_scoreLabel->setString(str);
}

const int & GameDataLayer::getScore()
{
	return m_score;
}

void GameDataLayer::setLevel(const Level & level)
{
	m_Level = level;
	stringstream sstream;
	string str;
	sstream << m_Level;
	sstream >> str;
	m_levelLabel->setString(str);
}

const Level & GameDataLayer::getLevel()
{
	return m_Level;
}

void GameDataLayer::setHeartNum(const int & num)
{
	m_heartNum = num;
	stringstream sstream;
	string str;
	sstream << m_heartNum;
	sstream >> str;
	m_heartLabel->setString(str);
	m_heartNum < 0 ? GameOver() : 0;
}

const int & GameDataLayer::getHeartNum()
{
	return m_heartNum;
}

void GameDataLayer::setNBomb(const int & n)
{
	m_nBomb = n >= MAX_NBOMB ? MAX_NBOMB : n;
	stringstream sstream;
	string str;
	sstream << m_nBomb;
	sstream >> str;
	m_nBombLabel->setString(str);
}

const int & GameDataLayer::getNBomb()
{
	return m_nBomb;
}

void GameDataLayer::GameOver()
{
	GameSecene* gamescene = dynamic_cast<GameSecene*>(getParent());
	gamescene->GoGameOver();
}

const int & GameDataLayer::getGlod()
{
	return m_glod;
}

void GameDataLayer::callSaveGameBack(cocos2d::CCObject * sender)
{
	SETINTBYKEY_DATA("GameLevel", m_Level);
	SETINTBYKEY_DATA("GameScore", m_score);
	SETINTBYKEY_DATA("GameDlod", m_glod);
}


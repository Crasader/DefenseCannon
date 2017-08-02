#include"BeginScene.h"
#include"BeginLayer.h"
#include"Common.h"
#include"StaticData.h"
#include"audio\include\SimpleAudioEngine.h"
using namespace CocosDenshion;

BeginScene::BeginScene()
{
}

BeginScene::~BeginScene()
{
}

bool BeginScene::init()
{
	if (CCScene::init())
	{
		reloadResource();
		m_beginLayer = BeginLayer::create();
		this->addChild(m_beginLayer);

		return true;
	}
	return false;
}

void BeginScene::reloadResource()
{

	CCTexture2D* textture = CCTextureCache::sharedTextureCache()->addImage(STATIC_STRING_DATA("fstar"));
	float w = textture->getContentSize().width;
	float h = textture->getContentSize().height / STATIC_FLOAT_DATA("star_frame_count");
	CCAnimation* fstar = CCAnimation::create();
	fstar->setDelayPerUnit(STATIC_FLOAT_DATA("star_frame_delay"));
	for (int i = 0; i < STATIC_INT_DATA("star_frame_count"); ++i)
	{
		fstar->addSpriteFrameWithTexture(textture, CCRectMake(0, i*h, w, h));
	}
	CCAnimationCache::sharedAnimationCache()->addAnimation(fstar, "fstar");

	textture = CCTextureCache::sharedTextureCache()->addImage(STATIC_STRING_DATA("sstar"));
	w = textture->getContentSize().width;
	h = textture->getContentSize().height / STATIC_FLOAT_DATA("star_frame_count");
	CCAnimation* sstar = CCAnimation::create();
	sstar->setDelayPerUnit(STATIC_FLOAT_DATA("star_frame_delay"));
	for (int i = 0; i < STATIC_INT_DATA("star_frame_count"); ++i)
	{
		sstar->addSpriteFrameWithTexture(textture, CCRectMake(0, i*h, w, h));
	}
	CCAnimationCache::sharedAnimationCache()->addAnimation(sstar, "sstar");

	textture = CCTextureCache::sharedTextureCache()->addImage(STATIC_STRING_DATA("star"));
	w = textture->getContentSize().width;
	h = textture->getContentSize().height / STATIC_FLOAT_DATA("star_frame_count");
	CCAnimation* star = CCAnimation::create();
	star->setDelayPerUnit(STATIC_FLOAT_DATA("star_frame_delay"));
	for (int i = 0; i < STATIC_INT_DATA("star_frame_count"); ++i)
	{
		star->addSpriteFrameWithTexture(textture, CCRectMake(0, i*h, w, h));
	}
	CCAnimationCache::sharedAnimationCache()->addAnimation(star, "star");

	textture = CCTextureCache::sharedTextureCache()->addImage(STATIC_STRING_DATA("triangle"));
	w = textture->getContentSize().width;
	h = textture->getContentSize().height / STATIC_FLOAT_DATA("star_frame_count");
	CCAnimation* triangle = CCAnimation::create();
	triangle->setDelayPerUnit(STATIC_FLOAT_DATA("star_frame_delay"));
	for (int i = 0; i < STATIC_INT_DATA("star_frame_count"); ++i)
	{
		triangle->addSpriteFrameWithTexture(textture, CCRectMake(0, i*h, w, h));
	}
	CCAnimationCache::sharedAnimationCache()->addAnimation(triangle, "triangle");

	textture = CCTextureCache::sharedTextureCache()->addImage(STATIC_STRING_DATA("rect"));
	w = textture->getContentSize().width;
	h = textture->getContentSize().height;
	CCSpriteFrame* rect = CCSpriteFrame::createWithTexture(textture, CCRectMake(0, 0, w, h));
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(rect, "rect");

	textture = CCTextureCache::sharedTextureCache()->addImage(STATIC_STRING_DATA("closeBtn1"));
	w = textture->getContentSize().width;
	h = textture->getContentSize().height;
	CCSpriteFrame* close1 = CCSpriteFrame::createWithTexture(textture, CCRectMake(0, 0, w, h));
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(close1, "close1");

	textture = CCTextureCache::sharedTextureCache()->addImage(STATIC_STRING_DATA("closeBtn2"));
	w = textture->getContentSize().width;
	h = textture->getContentSize().height;
	CCSpriteFrame* close2 = CCSpriteFrame::createWithTexture(textture, CCRectMake(0, 0, w, h));
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(close2, "close2");

	textture = CCTextureCache::sharedTextureCache()->addImage(STATIC_STRING_DATA("BeginBg"));
	w = textture->getContentSize().width;
	h = textture->getContentSize().height;
	CCSpriteFrame* BeginBg = CCSpriteFrame::createWithTexture(textture, CCRectMake(0, 0, w, h));
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(BeginBg, "BeginBg");

	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(STATIC_STRING_DATA("sounds_bg").c_str());
}

#include "StartScene.h"
#include "BubbleConstant.h"
#include "GameScene.h"

using namespace cocos2d;

StartLayer::StartLayer()
{
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("main_music.mp3", true);
}

StartLayer::~StartLayer()
{
	
}

CCScene* StartLayer::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        StartLayer *layer = StartLayer::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool StartLayer::init()
{
    bool bRet = false;
    do 
    {
        CC_BREAK_IF(! CCLayer::init());

		CCSize winSize = CCDirector::sharedDirector()->getWinSize();

		CCLabelTTF *label = CCLabelTTF::create("New Game", "Arial", 24 * 2);
		CCMenuItemLabel *pMenuItem = CCMenuItemLabel::create(label, this, menu_selector(StartLayer::menuNewGameCallback));
		pMenuItem->setTag(1);
		pMenuItem->setPosition(winSize.width / 2, winSize.height / 2);
		
        CCMenu* pMenu = CCMenu::create(pMenuItem, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);
        this->addChild(pMenu, 1);

        CCLabelTTF* pLabel = CCLabelTTF::create("Bubble Cat 2014", "Arial", 24 * 3);
        CC_BREAK_IF(! pLabel);
        pLabel->setPosition(ccp(winSize.width / 2, winSize.height - 50));
        this->addChild(pLabel, 1);

        CCSprite* pSprite = CCSprite::create("StartScene_CN.jpg");
        CC_BREAK_IF(! pSprite);
        pSprite->setPosition(ccp(winSize.width/2, winSize.height/2));
        this->addChild(pSprite, 0);

        bRet = true;
    } while (0);

    return bRet;
}

void StartLayer::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}

void StartLayer::menuNewGameCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(GameScene::scene());
}


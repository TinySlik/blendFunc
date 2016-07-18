#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

struct PicUnit {
    String name ;
    BlendFunc bl ;
};

PicUnit BLEND_TABLE [16] =
{
    {
        "SRC_ALPHA,ONE_MINUS_SRC_ALPHA",
        {GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA}
    },
    {
        "GL_DST_COLOR, GL_ZERO",
        {GL_DST_COLOR, GL_ZERO}
    },
    {
        "GL_ONE, GL_ZERO",
        {GL_ONE, GL_ZERO}
    },
    {
        "GL_DST_ALPHA, GL_ZERO",
        {GL_DST_ALPHA, GL_ZERO}
    },
    {
        "GL_ONE, GL_ONE_MINUS_SRC_ALPHA",
        {GL_ONE, GL_ONE_MINUS_SRC_ALPHA}
    },
    {
        "GL_ZERO, GL_ONE",
        {GL_ZERO, GL_ONE}
    },
    {
        "GL_DST_COLOR, GL_SRC_COLOR",
        {GL_DST_COLOR, GL_SRC_COLOR}
    },
    {
        "GL_DST_COLOR, GL_SRC_COLOR",
        {GL_DST_COLOR, GL_SRC_COLOR}
    },
    {
        "GL_DST_COLOR, GL_SRC_COLOR",
        {GL_DST_COLOR, GL_SRC_COLOR}
    },
    {
        "GL_DST_COLOR, GL_SRC_COLOR",
        {GL_DST_COLOR, GL_SRC_COLOR}
    },
    {
        "GL_DST_COLOR, GL_SRC_COLOR",
        {GL_DST_COLOR, GL_SRC_COLOR}
    },
    {
        "GL_DST_COLOR, GL_SRC_COLOR",
        {GL_DST_COLOR, GL_SRC_COLOR}
    },
    {
        "GL_DST_COLOR, GL_SRC_COLOR",
        {GL_DST_COLOR, GL_SRC_COLOR}
    },
    
};


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

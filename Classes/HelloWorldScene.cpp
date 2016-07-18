#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

struct PicUnit {
    String name ;
    BlendFunc bl ;
};

PicUnit BLEND_TABLE [22] =
{
    {
        "SRC_ALPHA,\nONE_MINUS_SRC_ALPHA",
        {GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA}
    },
    {
        "GL_DST_COLOR,\nGL_ZERO",
        {GL_DST_COLOR, GL_ZERO}
    },
    {
        "GL_ONE,\nGL_ZERO",
        {GL_ONE, GL_ZERO}
    },
    {
        "GL_DST_ALPHA,\nGL_ZERO",
        {GL_DST_ALPHA, GL_ZERO}
    },
    {
        "GL_ONE,\nGL_ONE_MINUS_SRC_ALPHA",
        {GL_ONE, GL_ONE_MINUS_SRC_ALPHA}
    },
    {
        "GL_ZERO,\nGL_ONE",
        {GL_ZERO, GL_ONE}
    },
    {
        "GL_DST_COLOR,\nGL_SRC_COLOR",
        {GL_DST_COLOR, GL_SRC_COLOR}
    },
    {
        "GL_DST_COLOR,\nGL_ONE_MINUS_SRC_ALPHA",
        {GL_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA}
    },
    {
        "GL_DST_COLOR,\nGL_ONE",
        {GL_DST_COLOR, GL_ONE}
    },
    {
        "GL_ONE_MINUS_DST_COLOR,\nGL_ONE",
        {GL_ONE_MINUS_DST_COLOR, GL_ONE}
    },
    {
        "GL_ONE,\nGL_ONE",
        {GL_ONE, GL_ONE}
    },
    {
        "GL_SRC_ALPHA,\nGL_ONE",
        {GL_SRC_ALPHA, GL_ONE}
    },
    {
        "GL_SRC_ALPHA,\nGL_ONE_MINUS_SRC_ALPHA",
        {GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA}
    },
    {
        "GL_ZERO,\nGL_SRC_COLOR",
        {GL_ZERO, GL_SRC_COLOR}
    },
    {
        "GL_DST_COLOR,\nGL_ZERO",
        {GL_DST_COLOR, GL_ZERO}
    },
    {
        "GL_ZERO,\nGL_DST_ALPHA",
        {GL_ZERO, GL_DST_ALPHA}
    },
    {
        "GL_DST_COLOR,\nGL_ONE_MINUS_SRC_ALPHA",
        {GL_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA}
    },
    {
        "GL_ZERO,\nGL_ONE_MINUS_DST_ALPHA",
        {GL_ZERO, GL_ONE_MINUS_DST_ALPHA}
    },
    {
        "GL_ONE,\nGL_ZERO",
        {GL_ONE, GL_ZERO}
    },
    {
        "GL_ONE,\nGL_ONE",
        {GL_ONE, GL_ONE}
    },
    {
        "GL_ONE,\nGL_DST_COLOR",
        {GL_ONE, GL_DST_COLOR}
    },
    {
        "GL_ONE,\nGL_SRC_ALPHA",
        {GL_ONE, GL_SRC_ALPHA}
    }
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

    
    log("%f,%f",visibleSize.width,visibleSize.height);
    
    for (int i = 0; i < 22; i ++) {
        auto bf = BLEND_TABLE[i].bl;
        auto label = Label::createWithTTF (BLEND_TABLE[i].name.getCString(),"fonts/Marker Felt.ttf", 4) ;
        auto point = Vec2(( i % 11 ) * visibleSize.width/11 + visibleSize.width/22  + origin.x, (i/11) * (visibleSize.height /2) + visibleSize.height / 4  + origin.y);
        label->setAnchorPoint(Vec2(0.5, 0.5));
        label->setPosition(ccpAdd(point, Vec2(0, -50)) );
        addChild(label);
        auto sp_bg = Sprite::create("cubeBg.png");
        auto sp_light = Sprite::create("light.png");
        sp_bg -> setPosition(point);
        sp_light -> setPosition(point);
        addChild(sp_bg,1);
        addChild(sp_light,2);
        sp_light -> setBlendFunc(bf);
    }
    
    
    
    
    return true;
}



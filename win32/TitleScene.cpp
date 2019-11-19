#include "TitleScene.h"
#include "MainScene.h"
#include "Singleton.h"

CCScene* TitleScene::scene()
{
	CCScene* pScene = CCScene::node();
	TitleScene* pLyayer = TitleScene::node();
	pScene->addChild( pLyayer );
	return pScene;
}

bool TitleScene::init()
{
	if( !CCLayer::init() ) return false;
	this->setIsTouchEnabled( true );

	m_fFrameTime	= 0.f;
	
	m_pBGA = CCSprite::spriteWithFile("Tower/title.jpg");
	m_pBGA->setAnchorPoint( ccp(0,0) );
	this->addChild( m_pBGA );

	CGSize winsize = CCDirector::sharedDirector()->getWinSize();

	this->setScaleX( winsize.width / 1280.f );
	this->setScaleY( winsize.height / 720.f );	
	this->initWithMenu();

	Singleton::call()->init( this );
	Singleton::call()->SM.play( BACKGROUND_SOUND );
	schedule( schedule_selector(TitleScene::tick) );
	return true;
}

void TitleScene::tick(ccTime dt)
{

}

void TitleScene::initWithMenu()
{
	CCMenuItemImage* pItem1 = CCMenuItemImage::itemFromNormalImage( "Tower/start1.png", "Tower/start2.png", this, 
		menu_selector( TitleScene::CallbackFN1 ));
	pItem1->setScale( 0.7f );
	
	CCMenu* pMenu = CCMenu::menuWithItems( pItem1, NULL );
//	pMenu->alignItemsVerticallyWithPadding( 15.f );
	pMenu->setPosition( ccp(629,254) );
	this->addChild(pMenu);
}

void TitleScene::CallbackFN1( NSObject* pSender )
{
	Singleton::call()->SM.play( CLICK_BTN );
	Singleton::call()->SM.stop( BACKGROUND_SOUND );
	CCScene* pScene = CCTransitionCrossFade::transitionWithDuration( 2, MainScene::scene() );  
	CCDirector::sharedDirector()->replaceScene( pScene );
}

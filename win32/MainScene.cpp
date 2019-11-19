#include "MainScene.h"
#include "Singleton.h"
#include "Hero.h"
#include "UILayer.h"
#include "WindMill.h"

Singleton* Singleton::instance = NULL;
CGSize winsize;
int OrgeCount = 0;

CCScene* MainScene::scene()
{
	CCScene* pScene = CCScene::node();
	MainScene* pLyayer = MainScene::node();
	pScene->addChild( pLyayer );
	return pScene;
}

bool MainScene::init()
{
	if( !CCLayer::init() ) return false;
	this->setIsTouchEnabled( true );
	this->setAnchorPoint( ccp(0,0) );

	winsize = CCDirector::sharedDirector()->getWinSize();
	this->setScaleX( winsize.width / 1027 );
	this->setScaleY( winsize.height / 768 );
	
	m_fFrameTime	= 0.5f;

	this->initWithObject(); 	//  Bga, Hero, UILayer, Land, Window, Tower, Bullet, Enemy, Sound. Effect

	Singleton::call()->SM.play( BACKGROUND_SOUND );
	Singleton::call()->SM.play( CROW );
	
	schedule( schedule_selector( MainScene::tick ) );
	return true;
}

void MainScene::initWithObject()
{
	CCSprite* pBga = CCSprite::spriteWithFile( "Tower/towerbga1.png" );
	pBga->setAnchorPoint( ccp(0,0) );
	this->addChild( pBga );

	WindMill* pWindMill = new WindMill;
	pWindMill->init();
	pWindMill->setPosition( ccp(738,443) );
	this->addChild( pWindMill );

	WindMill* pWindMill2 = new WindMill;
	pWindMill2->init();
	pWindMill2->setPosition( ccp(798,403) );
	this->addChild( pWindMill2 );

	Hero* pHero = new Hero;
	pHero->init();
	pHero->setPosition( ccp(200,200) );
	pHero->setScale( 0.65f );
	this->addChild( pHero );

	UILayer* pUILayer = new UILayer;
	pUILayer->init();
	pUILayer->autorelease();
	this->addChild( pUILayer );

	Singleton::call()->init( this );	// Enemy, Bullet, Tower, Land, Window, Sound. Effect
}

void MainScene::tick(ccTime dt)
{	
	this->generateEnemy( dt );
	Singleton::call()->EM.zOrderByYPos( dt );
	Singleton::call()->EM.matchTower();			// Tower와 Enemy 매칭
	Singleton::call()->BM.checkCollision();		// Enemy와 충돌체크후 dealloc
	Singleton::call()->EM.checkAlive();			// 사망조건 체크
	Singleton::call()->EfM.dealloc();			// m_bActive로 판정
}

void MainScene::generateEnemy( ccTime dt )
{
	m_fFrameTime += dt;
	if( m_fFrameTime > 2.5f ){ 
		Singleton::call()->EM.createEnemy( ccp(483,761), rand()%2 );
		m_fFrameTime = 0.f;
	}
}

void MainScene::ccTouchesBegan( NSSet *pTouches, UIEvent *pEvent )
{
	CCTouch*	pT		= (CCTouch*)pTouches->anyObject();
	CGPoint		po		= pT->locationInView( pT->view() );
	CGPoint		realP	= CCDirector::sharedDirector()->convertToGL( po );

	realP.x = realP.x * ( 1027 / winsize.width );
	realP.y = realP.y * ( 768 / winsize.height );

	Singleton::call()->LM.selectLand( realP );	// Land 선택을 위해 좌표정보 넘김
	if( GetAsyncKeyState(VK_SPACE) )Singleton::call()->m_realP = realP;
}
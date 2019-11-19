#include "BuildWindow.h"
#include "Singleton.h"

bool BuildWindow::init()
{
	if( !CCSprite::init() ) return false;
	
	m_fFrameTime	= 0.5f;
	m_fRotateTime	= 0.f;
	m_iTowerIndex	= 0;
	m_pTower		= NULL;
	m_pRange		= NULL;
	
	this->initWithFile("Tower/buildw.png");
	this->initWithMenu();

	schedule( schedule_selector( BuildWindow::tick ) );
	return true;
}

void BuildWindow::tick( ccTime dt )
{
	m_fRotateTime += dt * 70.f;
	if( m_pRange != NULL ) m_pRange->setRotation( m_fRotateTime ); 
	
	if( m_fFrameTime > 1.1f ) return;
	m_fFrameTime += 1.9f * dt;
	this->setScale( m_fFrameTime );
}

void BuildWindow::popupRange()
{
	m_pRange = CCSprite::spriteWithFile( "Tower/circle.png" );
	m_pRange->setPosition( ccp(75,85) );
	m_pRange->setScale( m_pTower->getRange() / 100.f );
	this->addChild( m_pRange );
}

void BuildWindow::initWithMenu()
{ 
	m_pItemArrow = CCMenuItemImage::itemFromNormalImage( "Tower/arrow.png", "Tower/arrow2.png", this, 
		menu_selector( BuildWindow::CallbackFN2 ));
	m_pItemArrow->setPosition(ccp(30,90));
	m_pItemShield = CCMenuItemImage::itemFromNormalImage( "Tower/shield.png", "Tower/shield2.png", this, 
		menu_selector( BuildWindow::CallbackFN1 ));
	m_pItemShield->setPosition(ccp(120,90));
	m_pItemMagic = CCMenuItemImage::itemFromNormalImage( "Tower/magic.png", "Tower/magic2.png", this, 
		menu_selector( BuildWindow::CallbackFN3 ));
	m_pItemMagic->setPosition(ccp(30,-10));
	m_pItemBomb = CCMenuItemImage::itemFromNormalImage( "Tower/bomb.png", "Tower/bomb2.png", this, 
		menu_selector( BuildWindow::CallbackFN1 ));
	m_pItemBomb->setPosition(ccp(120,-10));
	m_pItemUpgrade = CCMenuItemImage::itemFromNormalImage( "Tower/upgrade.png", "Tower/upgrade2.png", this, 
		menu_selector( BuildWindow::CallbackFN5 ));
	m_pItemUpgrade->setPosition( ccp(75, 100) );
	m_pItemSell = CCMenuItemImage::itemFromNormalImage( "Tower/sell.png", "Tower/sell2.png", this, 
		menu_selector( BuildWindow::CallbackFN6 ));
	m_pItemSell->setPosition( ccp(75,-20) );
	m_pItemSell->setScale( 0.9f );
	m_pItemNone = CCMenuItemImage::itemFromNormalImage( "Tower/None.png", "Tower/None2.png", this, 
		menu_selector( BuildWindow::CallbackFN7 ));
	m_pItemNone->setPosition( ccp(75, 100) );
	m_pItemNone->setScale( 0.75f );
}

void BuildWindow::CallbackFN1( NSObject* pSender )
{
	m_pTower = CallBackSwitch( BOMB );
}

void BuildWindow::CallbackFN2( NSObject* pSender )
{
	m_pTower = CallBackSwitch( ARCHER );
}

void BuildWindow::CallbackFN3( NSObject* pSender )
{
	m_pTower = CallBackSwitch( MAGIC );
}

Tower* BuildWindow::CallBackSwitch( int _type )
{
	Tower* pTower;

	switch( _type ){
	case ARCHER:
		pTower = Singleton::call()->TM.createTower( this->getPosition(), TOWER_ARCHER );
		if( pTower == NULL ) return NULL;
		Singleton::call()->SM.play( BUILD_ARCHER );
		break;
	case BOMB:
		pTower = Singleton::call()->TM.createTower( this->getPosition(), TOWER_BOMB );
		if( pTower == NULL ) return NULL;
		Singleton::call()->SM.play( BUILD_BOMB );
		break;
	case MAGIC:
		pTower = Singleton::call()->TM.createTower( this->getPosition(), TOWER_MAGIC );
		if( pTower == NULL ) return NULL;
		Singleton::call()->SM.play( BUILD_MAGIC );
		break;
	}

	Singleton::call()->LM.setTowerByIndex( pTower, m_iTowerIndex );
	Singleton::call()->WM.closeWindow();
	return pTower;	
}

void BuildWindow::CallbackFN5( NSObject* pSender )		// 업그레이드 버튼
{
	if( Singleton::call()->m_nGold < 100 ) return;
	switch( m_pTower->getTowerType() )
	{
	case BOMB:
		{
			CCTexture2D* t	= CCTextureCache::sharedTextureCache()->addImage( "Tower/tower_bomb2.png" );
			CGSize s = t->getContentSize();
			m_pTower->setTexture(t);
			m_pTower->setTextureRect( CGRectMake(0,0,s.width,s.height) );

			int Damage = m_pTower->getDamage();
			Damage += 40;
			m_pTower->setDamage( Damage );

			m_pTower->setRange( 180.f );
			Singleton::call()->m_nGold	-= 100;
			Singleton::call()->SM.play( BUILD_BOMB );
			m_pTower->setTowerType( BOMB2 );
			break;
		}
	case ARCHER:
		{
			CCTexture2D* t	= CCTextureCache::sharedTextureCache()->addImage( "Tower/tower_archer2.png" );
			CGSize s = t->getContentSize();
			m_pTower->setTexture(t);
			m_pTower->setTextureRect( CGRectMake(0,0,s.width,s.height) );

			int Damage = m_pTower->getDamage();
			Damage += 10;
			m_pTower->setDamage( Damage );
			
			m_pTower->setPace( 0.4f );

			Singleton::call()->m_nGold	-= 100;
			Singleton::call()->SM.play( BUILD_ARCHER );
			m_pTower->setTowerType( ARCHER2 );
			break;
		}
	case MAGIC:
		{
			CCTexture2D* t	= CCTextureCache::sharedTextureCache()->addImage( "Tower/tower_magic2.png" );
			CGSize s = t->getContentSize();
			m_pTower->setTexture(t);
			m_pTower->setTextureRect( CGRectMake(0,0,s.width,s.height) );

			int Damage = m_pTower->getDamage();
			Damage += 50;
			m_pTower->setDamage( Damage );

			Singleton::call()->m_nGold	-= 100;
			Singleton::call()->SM.play( BUILD_MAGIC );
			m_pTower->setTowerType( MAGIC2 );
			break;
		}
	}

	Singleton::call()->WM.closeWindow();
	Singleton::call()->LM.setTowerByIndex( m_pTower, m_iTowerIndex );
}

void BuildWindow::CallbackFN6( NSObject* pSender )
{
	m_pTower->setLiveFlag( false );
	m_pTower = NULL;

	Singleton::call()->TM.dealloc();
	Singleton::call()->WM.closeWindow();
	Singleton::call()->LM.setTowerByIndex( m_pTower, m_iTowerIndex );
}

void BuildWindow::CallbackFN7( NSObject* pSender )
{
	// None
}
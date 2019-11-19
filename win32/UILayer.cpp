#include "UILayer.h"
#include "Singleton.h"

char szLife[30] = {0};
char szGold[30] = {0};
char szCoor[30] = {0};
char szWave[30] = {0};

bool UILayer::init()
{
	if( !CCLayer::init() ) return false;
	this->setIsTouchEnabled( true );
	
	this->initWithLabel();
	
	schedule( schedule_selector( UILayer::tick ) );
	return true;
}

void UILayer::tick(ccTime dt)
{
	this->updateLabel();	// Life, Gold, Coor, Wave
}

void UILayer::initWithLabel()
{
	m_pLifeLabel = CCLabelTTF::labelWithString( szLife, "arial", 16 );		// Life 
	m_pLifeLabel->setPosition( ccp(100,745) );
	this->addChild( m_pLifeLabel );
	m_pGoldLabel = CCLabelTTF::labelWithString( szGold, "arial", 16 );		// Gold
	m_pGoldLabel->setPosition( ccp(160,745) );
	this->addChild( m_pGoldLabel );
	m_pWaveLabel = CCLabelTTF::labelWithString( szWave, "arial", 16 );		// Wave
	m_pWaveLabel->setPosition( ccp(220,745) );
	this->addChild( m_pWaveLabel );
	m_pCoorLabel = CCLabelTTF::labelWithString( szCoor, "arial", 16 );		// Coor
	m_pCoorLabel->setPosition( ccp(550,749) );
	m_pCoorLabel->setColor( ccc3(0,0,0) );
	this->addChild( m_pCoorLabel );
}

void UILayer::updateLabel()
{
	sprintf_s( szLife, "%d", Singleton::call()->m_nLife );
	m_pLifeLabel->setString(szLife);
	sprintf_s( szGold, "%d", Singleton::call()->m_nGold );
	m_pGoldLabel->setString(szGold);
	sprintf_s( szWave, "%d", Singleton::call()->m_nWave );
	m_pGoldLabel->setString(szGold);
}

void UILayer::ccTouchesBegan( NSSet *pTouches, UIEvent *pEvent )
{
	CCTouch*	pT		= (CCTouch*)pTouches->anyObject();
	CGPoint		po		= pT->locationInView( pT->view() );
	CGPoint		realP	= CCDirector::sharedDirector()->convertToGL( po );

	sprintf_s( szCoor, "X:%d Y:%d", (int)realP.x, (int)realP.y );
	m_pCoorLabel->setString( szCoor );
}

void UILayer::ccTouchesMoved( NSSet *pTouches, UIEvent *pEvent )
{
	CCTouch*	pT		= (CCTouch*)pTouches->anyObject();
	CGPoint		po		= pT->locationInView( pT->view() );
	CGPoint		realP	= CCDirector::sharedDirector()->convertToGL( po );

	sprintf_s( szCoor, "X:%d Y:%d", (int)realP.x, (int)realP.y );
	m_pCoorLabel->setString( szCoor );
}
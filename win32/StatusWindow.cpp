#include "StatusWindow.h"
#include "Singleton.h"

char szPace[50] = {0};
char szRange[50] = {0};
char szDamage[50] = {0};

bool StatusWindow::init()
{
	if( !CCSprite::init() ) return false;
	m_fFrameTime = -40.f;	
	
	this->initWithFile( "Tower/status.png" );
	this->setAnchorPoint( ccp(0,0) );
	this->setPosition( ccp(360,-40) );
	this->setScaleX(1.1f);

	this->initWithLabel();

	schedule( schedule_selector( StatusWindow::tick ) );
	return true;
}

void StatusWindow::tick( ccTime dt )
{
	if( m_fFrameTime > 0.f ) return;
	this->action( dt );
}

void StatusWindow::action( ccTime dt )
{
	m_fFrameTime += dt * 120.f;
	CGPoint pos = this->getPosition();
	this->setPosition( ccp( pos.x, m_fFrameTime ) );
}

void StatusWindow::initWithLabel()
{
	m_pTowerDamageLabel = CCLabelTTF::labelWithString(szDamage, CGSizeMake(160,30),UITextAlignmentLeft, "arial", 18);		// Damage
	m_pTowerDamageLabel->setPosition(ccp(170,24));
	this->addChild(m_pTowerDamageLabel);
	m_pTowerRangeLabel	= CCLabelTTF::labelWithString(szRange,	CGSizeMake(160,30),UITextAlignmentLeft, "arial", 18);		// Range
	m_pTowerRangeLabel->setPosition(ccp(280,24));
	this->addChild(m_pTowerRangeLabel);
	m_pTowerPaceLabel	= CCLabelTTF::labelWithString(szPace,	CGSizeMake(160,30),UITextAlignmentLeft, "arial", 17);		// Pace
	m_pTowerPaceLabel->setPosition(ccp(370,24));
	this->addChild(m_pTowerPaceLabel);	
}

void StatusWindow::updateTowerLabel()
{
	sprintf_s( szDamage, "%d", m_nTowerDamage );
	m_pTowerDamageLabel->setString(szDamage);
	sprintf_s( szRange, "%d", m_nTowerRange );
	m_pTowerRangeLabel->setString(szRange);
	sprintf_s( szPace, "%d¹ø / 100sec", (int)m_fTowerPace );
	m_pTowerPaceLabel->setString(szPace);
}

void StatusWindow::updateTowerInfo( Tower* _pTower )
{
	m_nTowerDamage	=			   _pTower->getDamage();
	m_nTowerRange	= ( int )	   _pTower->getRange();
	m_fTowerPace	= ( int )(100 *_pTower->getPace());
}
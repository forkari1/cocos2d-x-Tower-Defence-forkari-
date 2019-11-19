#include "Enemy_Goblin.h"

bool Enemy_Goblin::init()
{
	if( !Enemy::init() ) return false;

	m_nHP			= 150;	
	m_nMaxHP		= 150.f;
	m_iMaxFrame		= 0;
	m_fFrame		= 0.f;
	m_fSpeed		= 100.f;

	this->initWithFile("Tower/goblin.png");
	this->initWithHPBar();
	this->setScale(0.85f);
//	this->initWithAnimation();

	this->schedule(schedule_selector( Enemy_Goblin::tick ));
	return true;
}

void Enemy_Goblin::initWithHPBar()
{
	m_pHP = CCSprite::spriteWithFile("Tower/hp.png");
	m_pHP->setPosition( ccp(-10, 50) );
	m_pHP->setScaleY( 1.2f );
	m_pHP->setScaleX( 0.6f );
	m_pHP->setAnchorPoint( ccp(0.f, 1.f) );
	this->addChild(m_pHP);
}

void Enemy_Goblin::tick( ccTime dt )
{
	Enemy::action(dt);
//	this->animation(dt);

	m_pHP->setScaleX( m_nHP / m_nMaxHP );
}

/*
void Enemy_Normal::animation( ccTime dt )
{
	m_fFrame += dt * 5;
	m_iMaxFrame = this->animationByName( getNameByState(m_iState) )->getFrames()->count();	// MaxFrame by State
	this->setDisplayFrame( getNameByState(m_iState), ( (int)m_fFrame)%m_iMaxFrame );		
}

void Enemy_Normal::initWithAnimation()
{
	m_pAni = new CCAnimation;
	m_pAni->initWithName( "WALK" );

	CCTexture2D* t	= CCTextureCache::sharedTextureCache()->addImage( "Tower/title1.png" );
	CGSize size		= t->getContentSize();
	m_pAni->addFrameWithTexture(t, CGRectMake( 165, 30, 21, 23 ));

	this->addAnimation( m_pAni );
}

char* Enemy_Normal::getNameByState( int _state )		// enum to string func
{
	switch( _state ){
	case STAND: return "STAND";		
	case WALK:	return "WALK";
	}
}
*/
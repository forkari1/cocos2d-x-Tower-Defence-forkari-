#include "Enemy_Boss.h"

bool Enemy_Boss::init()
{
	if( !Enemy::init() ) return false;

	m_nHP			= 2000;	
	m_nMaxHP		= 2000.f;
	m_iMaxFrame		= 0;
	m_fFrame		= 0.f;
	m_fSpeed		= 10.f;

	this->initWithFile("Tower/boss.png");
	this->initWithHPBar();
	this->setScale(0.5f);
//	this->initWithAnimation();

	this->schedule(schedule_selector( Enemy_Boss::tick ));
	return true;
}

void Enemy_Boss::initWithHPBar()
{
	m_pHP = CCSprite::spriteWithFile("Tower/hp.png");
	m_pHP->setPosition( ccp(5, 70) );
	m_pHP->setScaleY( 1.2f );
	m_pHP->setAnchorPoint( ccp(0.f, 0.5f) );
	this->addChild(m_pHP);
}

void Enemy_Boss::tick( ccTime dt )
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
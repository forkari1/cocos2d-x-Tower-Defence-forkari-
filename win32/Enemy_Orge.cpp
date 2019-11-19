#include "Enemy_Orge.h"

bool Enemy_Orge::init()
{
	if( !Enemy::init() ) return false;

	m_nHP			= 500;	
	m_nMaxHP		= 500.f;
	m_iMaxFrame		= 0;
	m_fFrame		= 0.f;
	m_iState		= WALK;
	m_fSpeed		= rand()%30 + 30.f;

	this->initWithFile("Tower/orge.png");
	this->initWithHPBar();
	this->setScale(0.85f);
	this->initWithAnimation();

	this->schedule(schedule_selector( Enemy_Orge::tick ));
	return true;
}

void Enemy_Orge::initWithHPBar()
{
	m_pHP = CCSprite::spriteWithFile("Tower/hp.png");
	m_pHP->setPosition( ccp(5, 70) );
	m_pHP->setScaleY( 1.2f );
	m_pHP->setAnchorPoint( ccp(0.f, 0.5f) );
	this->addChild(m_pHP);
}

void Enemy_Orge::tick( ccTime dt )
{
	Enemy::action(dt);
//	this->animation(dt);

	m_pHP->setScaleX( m_nHP / m_nMaxHP );
}

void Enemy_Orge::initWithAnimation()
{
	CCAnimation* pAni = new CCAnimation;
	pAni->initWithName( "WALK" );

	char szTemp1[30] = {0};
	for( int i = 0; i <= 14; i++){
		sprintf_s( szTemp1, "Tower/enemy_orge/Frame%d.png", i );
		pAni->addFrameWithFileName( szTemp1 );
	}
	this->addAnimation( pAni );
}

void Enemy_Orge::animation( ccTime dt )
{
	m_fFrame += dt * 8;
	m_iMaxFrame = this->animationByName( getNameByState(WALK) )->getFrames()->count();	// MaxFrame by State
	this->setDisplayFrame( getNameByState(WALK), ( (int)m_fFrame)%m_iMaxFrame );		
}

char* Enemy_Orge::getNameByState( int _state )		// enum to string func
{
	switch( _state ){
	case WALK: return "WALK";
	}
}
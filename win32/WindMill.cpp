#include "WindMill.h"

bool WindMill::init()
{
	if(!CCSprite::init()) return false;

	m_fFrameTime	= 0.f; 
	m_fFrame		= 0.f;
	m_iMaxFrame		= 0;

	this->initWithFile("Tower/windmill/Frame1.png");
	this->initWithAnimation();
	
	this->schedule(schedule_selector( WindMill::tick ));
	return true;
}

void WindMill::initWithAnimation()
{
	CCAnimation* pAni = new CCAnimation;
	pAni->initWithName( "WINDMILL" );

	char szTemp1[30] = {0};
	for( int i = 1; i <= 5; i++){
		sprintf_s( szTemp1, "Tower/windmill/Frame%d.png", i );
		pAni->addFrameWithFileName( szTemp1 );
	}
	this->addAnimation( pAni );
}

void WindMill::tick(ccTime dt)
{
	this->animation(dt);
}

void WindMill::animation( ccTime dt )
{
	m_fFrame += dt * 8;
	m_iMaxFrame = this->animationByName( getNameByState(WINDMILL) )->getFrames()->count();	// MaxFrame by State
	this->setDisplayFrame( getNameByState(WINDMILL), ( (int)m_fFrame)%m_iMaxFrame );		
}

char* WindMill::getNameByState( int _state )		// enum to string func
{
	switch( _state ){
	case WINDMILL: return "WINDMILL";
	}
}
#include "Hero.h"
#include "Singleton.h"

bool Hero::init()
{
	if(!CCSprite::init()) return false;

	m_fSpeed		= 140.f;
	m_fFrameTime	= 0.f; 

	this->initWithFile("Tower/alleric.png");

	this->schedule(schedule_selector( Hero::tick ));
	return true;
}

void Hero::tick(ccTime dt)
{
	float fDistance = Singleton::call()->getDistance( Singleton::call()->m_realP, this->getPosition() );	
	if( fDistance < 20.f ) return;
	
	this->action( dt );
}

void Hero::action( ccTime dt )
{
	CGPoint Vec;

	Vec	= Singleton::call()->setVector( Singleton::call()->m_realP, this->getPosition() );
	Vec = Singleton::call()->Normalize( Vec );
	
	if( Vec.x > 0 ) this->setFlipX( true );
	else			this->setFlipX( false );

	CGPoint pos = this->getPosition();
	
	pos.x += Vec.x * dt * m_fSpeed;
	pos.y += Vec.y * dt * m_fSpeed;

	this->setPosition( pos );
}

#include "Bullet_Archer.h"

bool Bullet_Archer::init()
{
	if( !Bullet::init() ) return false;

	m_nDamage		= 0;
	m_fSpeed		= 500.f;
	m_iType			= BULLET_ARCHER;

	this->initWithFile("Tower/arrow3.png");

	this->schedule(schedule_selector( Bullet_Archer::tick ));
	return true;
}

void Bullet_Archer::tick( ccTime dt )
{
	Bullet::action( dt );
}
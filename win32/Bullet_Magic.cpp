#include "Bullet_Magic.h"

bool Bullet_Magic::init()
{
	if( !Bullet::init() ) return false;

	m_nDamage		= 0;
	m_fSpeed		= 500.f;
	m_iType			= BULLET_MAGIC;

	this->initWithFile("DNF/boom4.png");

	this->schedule(schedule_selector( Bullet_Magic::tick ));
	return true;
}

void Bullet_Magic::tick( ccTime dt )
{
	Bullet::action( dt );
}
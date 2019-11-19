#include "Bullet_Bomb.h"

bool Bullet_Bomb::init()
{
	if( !Bullet::init() ) return false;

	m_nDamage		= 0;
	m_fSpeed		= 500.f;
	m_iType			= BULLET_BOMB;

	this->initWithFile("DNF/boom1.png");

	this->schedule(schedule_selector( Bullet_Bomb::tick ));
	return true;
}

void Bullet_Bomb::tick( ccTime dt )
{
	Bullet::action( dt );
}
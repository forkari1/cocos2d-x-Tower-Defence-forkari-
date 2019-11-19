#include "Tower_Magic.h"
#include "Singleton.h"

bool Tower_Magic::init()
{
	if( !Tower::init() ) return false;

	m_iTowerType	= MAGIC;
	m_nCost			= 100;	
	m_FireRange		= 160.f;
	m_nDamage		= 40;
	m_FirePace		= 1.5f;	
	m_LiveFlag		= TRUE;

	this->initWithFile("Tower/tower_magic.png");
	this->setScale( 0.65f );

	this->schedule(schedule_selector( Tower_Magic::tick ));
	return true;
}

void Tower_Magic::tick( ccTime dt )
{
	Tower::action( dt, BULLET_MAGIC );
}
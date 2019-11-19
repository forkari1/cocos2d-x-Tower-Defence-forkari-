#include "Tower_Bomb.h"
#include "Singleton.h"

bool Tower_Bomb::init()
{
	if( !Tower::init() ) return false;

	m_iTowerType	= BOMB;
	m_nCost			= 120;	
	m_FireRange		= 120.f;
	m_nDamage		= 50;
	m_FirePace		= 2.f;	
	m_LiveFlag		= TRUE;

	this->initWithFile("Tower/tower_bomb.png");
	this->setScale(0.47f);
	
	this->schedule(schedule_selector( Tower_Bomb::tick ));
	return true;
}

void Tower_Bomb::tick( ccTime dt )
{
	Tower::action( dt, BULLET_BOMB );
}
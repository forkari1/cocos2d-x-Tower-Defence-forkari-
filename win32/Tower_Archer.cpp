#include "Tower_Archer.h"
#include "Singleton.h"

bool Tower_Archer::init()
{
	if( !Tower::init() ) return false;

	m_iTowerType	= ARCHER;
	m_nCost			= 70;	
	m_nDamage		= 20;
	m_FireRange		= 140.f;
	m_FirePace		= 1.f;	
	m_LiveFlag		= TRUE;

	this->initWithFile("Tower/tower_archer.png");
	this->setScale(0.50f);
	
	this->schedule(schedule_selector( Tower_Archer::tick ));
	return true;
}

void Tower_Archer::tick( ccTime dt )
{
	Tower::action( dt, BULLET_ARCHER );
}
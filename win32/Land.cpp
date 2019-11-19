#include "Land.h"
#include "Singleton.h"
#include "SoundManager.h"


bool Land::init()
{
	if( !CCSprite::init() ) return false;

	m_pTower		= NULL;
	m_MousePos		= ccp(0,0);
	m_fFrameTime	= 0.6f;

	this->initWithFile("Tower/land1.png");	

	return true;
}

bool Land::setMousePos( CGPoint _pos )
{
	m_MousePos = _pos;

	float fDistance = Singleton::call()->getDistance( m_MousePos, this->getPosition() );
	
	if( fDistance < 30.f )	return true;
	else					return false;
}
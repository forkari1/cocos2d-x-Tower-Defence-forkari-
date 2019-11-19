#include "Enemy.h"
#include "Singleton.h"

#define END_LINE		1013

bool Enemy::init()
{
	if(!CCSprite::init()) return false;

	m_nHP			= 0;	
	m_nMaxHP		= 0.f;
	m_fSpeed		= 0.f;
	m_endFlag		= true;			// checkEndPoint

	m_nWayCount		= 0;
	m_fFrameTime	= 0.f;

	this->initWithWayPoint();
	return true;
}

void Enemy::initWithWayPoint()
{
	m_WayPoint[0] = ccp( 471,499 );
	m_WayPoint[1] = ccp( 337,436 );
	m_WayPoint[2] = ccp( 274,340 );
	m_WayPoint[3] = ccp( 355,225 );
	m_WayPoint[4] = ccp( 479,227 );
	m_WayPoint[5] = ccp( 564,238 );
	m_WayPoint[6] = ccp( 676,216 );
	m_WayPoint[7] = ccp( 832,318 );
	m_WayPoint[8] = ccp( 1013,320 );
}

void Enemy::action( ccTime dt )
{
	if( dt > 1.f ) return;		// 딜레이가 길어지면 action 차단

	this->moveWayPoint(dt);
	this->checkEndLine();
}

bool Enemy::checkEndLine()
{
	if( this->getPosition().x >= END_LINE ) m_endFlag = false;
	return m_endFlag;
}

void Enemy::moveWayPoint( ccTime dt )
{
	CGPoint Vec = Singleton::call()->setVector( m_WayPoint[ m_nWayCount ], this->getPosition() );
	
	float fDistance = sqrtf( Vec.x * Vec.x + Vec.y * Vec.y );
	if( fDistance < 20.f ) m_nWayCount++;
	if( m_nWayCount > MAX_WAYPOINT - 1 ) m_nWayCount = MAX_WAYPOINT -1;
	
	Vec = Singleton::call()->Normalize( Vec );
	if( Vec.x > 0 )	this->setFlipX( true );
	else			this->setFlipX( false );

	CGPoint pos = this->getPosition();
	
	pos.x += Vec.x * dt * m_fSpeed;
	pos.y += Vec.y * dt * m_fSpeed;

	this->setPosition( pos );
}
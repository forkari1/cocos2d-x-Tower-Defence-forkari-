#include "Bullet.h"
#include "Singleton.h"

bool Bullet::init()
{
	if( !CCSprite::init() ) return false;

	m_fFrameTime	= 0.f;
	m_pTarget		= NULL;			// Enemy
	m_Vec			= ccp( 0,0 );	
	m_fDistance		= 0.f;
	m_fDegree		= 0.f;
	
	return true; 
}

void Bullet::action( ccTime dt )
{
	if( dt > 0.5f ) return;
	if( m_pTarget == NULL ) return;

	this->moveToTarget( dt );
	if( m_fDistance < 30.f ) this->damageEnemy();
}

void Bullet::moveToTarget( ccTime dt )			
{
	m_Vec = Singleton::call()->setVector( m_pTarget->getPosition(), this->getPosition() );
	m_fDistance = sqrtf( m_Vec.x * m_Vec.x + m_Vec.y * m_Vec.y );
	m_Vec = Singleton::call()->Normalize( m_Vec );

	m_fDegree = atan2f( m_Vec.y , m_Vec.x ) * 180 / 3.14f;	
	this->setRotation( -m_fDegree );
	
	CGPoint pos = this->getPosition();

	pos.x += m_Vec.x * m_fSpeed * dt;
	pos.y += m_Vec.y * m_fSpeed * dt;

	this->setPosition(pos);
}

void Bullet::damageEnemy()
{
	int hp = m_pTarget->getHP();
	hp -= m_nDamage;
	m_pTarget->setHP( hp ); 

	if( m_iType == BULLET_BOMB ) Singleton::call()->EfM.createEffect( this->getPosition(), EFFECT );
}
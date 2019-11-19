#include "Tower.h"
#include "Singleton.h"

bool Tower::init()
{
	if( !CCSprite::init() ) return false;
	
	m_nCost			= 0;		// 타워를 건설 비용
	m_FirePace		= 0.f;		// 공격
	m_FireRange		= 0.f;		// 공격 범위
	m_nDamage		= 0;

	m_LiveFlag		= false;
	m_pTarget		= NULL;		// 공격할 대상
	m_fDistance		= 0.f;		// 대상과의 거리	
	m_fFrameTime	= 0.f;		// += dt;

	return true;
}

void Tower::action( ccTime dt, int _type )
{
	if( m_pTarget == NULL ) return;
	
	m_fDistance = Singleton::call()->getDistance( m_pTarget->getPosition(), this->getPosition() );
	
	this->checkTarget();
	this->attack( dt, _type );
}

void Tower::checkTarget()
{
	if( m_pTarget->getHP() <= 0 ){
		m_pTarget = NULL; 
		return;
	}
	if( m_pTarget->getEndFlag() == false ){
		m_pTarget = NULL;
		return;
	}
	if( m_fDistance > m_FireRange ){
		m_pTarget = NULL;
		return;
	}
}

void Tower::attack( ccTime dt, int _type )
{
	m_fFrameTime += dt;

	if( m_fFrameTime > m_FirePace ){
		m_fFrameTime = 0.f;
		Singleton::call()->BM.createBullet( m_pTarget, this->getPosition(), _type, m_nDamage );

		// Sound
		switch( _type ){
		case BULLET_BOMB:
			Singleton::call()->SM.play( BOMB_ATTACK );
			break;
		case BULLET_ARCHER:
			Singleton::call()->SM.play( ARCHER_ATTACK );
			break;
		case BULLET_MAGIC:
			Singleton::call()->SM.play( MAGIC_ATTACK );
			break;
		}
	}
}

void Tower::setTarget( Enemy* _pEnemy )
{
	if( m_pTarget != NULL ) return;		// 타겟이 존재한다면 반드시 FireRange 범위 안에 존재

	m_fDistance = Singleton::call()->getDistance( _pEnemy->getPosition(), this->getPosition() );
	if( m_fDistance < m_FireRange )	m_pTarget = _pEnemy;
}

/*
void Tower::animation( ccTime dt )
{
	m_fFrame += dt * 5;
	m_iMaxFrame = this->animationByName( getNameByState(m_iState) )->getFrames()->count();	// MaxFrame by State
	this->setDisplayFrame( getNameByState(m_iState), ( (int)m_fFrame)%m_iMaxFrame );		
}

void Tower::initWithAnimation()
{
	m_pAni = new CCAnimation;
	m_pAni->initWithName( "WALK" );

	CCTexture2D* t	= CCTextureCache::sharedTextureCache()->addImage( "Tower/tower_bomb_upgrade.png" );
	CGSize size		= t->getContentSize();
	this->setTexture(t);
	m_pAni->addFrameWithTexture( t, CGRectMake(0, 0, 189, 132) );
	m_pAni->addFrameWithTexture( t, CGRectMake(190, 0, 183, 132) );
	this->addAnimation( m_pAni );
}

char* Tower::getNameByState( int _state )		// enum to string func
{
	switch( _state ){
	case STAND: return "STAND";		
	case WALK:	return "WALK";
	}
}
*/
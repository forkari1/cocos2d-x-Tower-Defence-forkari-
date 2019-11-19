#include "Singleton.h"
#include "BulletManager.h"
#include "Bullet_Archer.h"
#include "Bullet_Bomb.h"
#include "Bullet_Magic.h"

void BulletManager::init()
{
	memset( m_pBullet, NULL, sizeof(m_pBullet) );
	m_pLayer = NULL;
}

void BulletManager::createBullet( Enemy* _pTarget, CGPoint _pos, int _type, int _nDamage )
{
	if( m_pLayer == NULL ) return;
	for( int i = 0; i < MAX_BULLET; i++ )
	{  
		if( m_pBullet[i] != NULL ) continue;
		switch( _type )
		{
		case BULLET_ARCHER:
			{
				Bullet_Archer* p = new Bullet_Archer;
				p->init();
				p->setPosition( _pos );
				p->setTarget( _pTarget );
				p->setDamage( _nDamage );
				m_pBullet[i] = p;
				break;
			}
		case BULLET_BOMB:
			{
				Bullet_Bomb* p = new Bullet_Bomb;
				p->init();
				p->setPosition(_pos);
				p->setTarget( _pTarget );
				p->setDamage( _nDamage );
				m_pBullet[i] = p;
				break;
			}
		case BULLET_MAGIC:
			{
				Bullet_Magic* p = new Bullet_Magic;
				p->init();
				p->setPosition( _pos );
				p->setTarget( _pTarget );
				p->setDamage( _nDamage );
				m_pBullet[i] = p;
				break;
			}
		}
		m_pLayer->addChild( m_pBullet[i], 622);		// 2번째 매개변수:zOrder
		break;
	}
}

void BulletManager::setLayer( CCLayer* _pLayer )
{
	m_pLayer = _pLayer;
}

void BulletManager::checkCollision()
{
	for( int i = 0 ; i < MAX_BULLET ; i++ )
	{
		if( m_pBullet[i] == NULL ) continue;
		if( m_pBullet[i]->getDistance() < 30.f ){
			m_pLayer->removeChild( m_pBullet[i], true );	// dealloc
			m_pBullet[i] = NULL;
		}
	}
}

/*****************************************************************************************

 Bullet이 충돌 할때마다 m_pTarget의 HP 감소	bullet 이 공격하는 타겟			BulletManager
 if ( m_pEnemy[i]->HP < 0 ) 이면 dealloc( removechild , NULL ) - 문제발생	EnemyManager
 if( m_pTarget->HP < 0 ) 이면 m_pTarget = NULL								Tower
 
 타워에서 타겟을 NULL로 바꿔주면 Tower에서 createBullet(Target) 실행하기 때문에
 타워의 타겟만 NULL로 해주면 끝

******************************************************************************************/

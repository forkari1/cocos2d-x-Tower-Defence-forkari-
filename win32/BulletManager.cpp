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
		m_pLayer->addChild( m_pBullet[i], 622);		// 2��° �Ű�����:zOrder
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

 Bullet�� �浹 �Ҷ����� m_pTarget�� HP ����	bullet �� �����ϴ� Ÿ��			BulletManager
 if ( m_pEnemy[i]->HP < 0 ) �̸� dealloc( removechild , NULL ) - �����߻�	EnemyManager
 if( m_pTarget->HP < 0 ) �̸� m_pTarget = NULL								Tower
 
 Ÿ������ Ÿ���� NULL�� �ٲ��ָ� Tower���� createBullet(Target) �����ϱ� ������
 Ÿ���� Ÿ�ٸ� NULL�� ���ָ� ��

******************************************************************************************/

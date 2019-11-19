#include "TowerManager.h"
#include "Singleton.h"
#include "Tower_Bomb.h"
#include "Tower_Archer.h"
#include "Tower_Magic.h"

void TowerManager::init()
{
	memset( m_pTower, NULL, sizeof(m_pTower));
	m_pLayer = NULL;
}

Tower* TowerManager::createTower( CGPoint _pos, int _type  )		// Scene에서
{
	if( m_pLayer == NULL ) return NULL;

	for( int i = 0 ; i < MAX_TOWER ; i++ )
	{  
		if( m_pTower[i] != NULL ) continue;
		switch( _type )
		{
		case TOWER_BOMB:
			{
				Tower_Bomb *p = new Tower_Bomb;
				p->init();
				p->setPosition( _pos );
				m_pTower[i] = p;
				break;
			}
		case TOWER_ARCHER:
			{
				Tower_Archer *p = new Tower_Archer;
				p->init();
				p->setPosition( _pos );
				m_pTower[i] = p;
				break;
			}
		case TOWER_MAGIC:
			{
				Tower_Magic *p = new Tower_Magic;
				p->init();
				p->setPosition( _pos );
				m_pTower[i] = p;
				break;
			}
		}
		if( Singleton::call()->m_nGold <= m_pTower[i]->getTowerCost() ){
			m_pTower[i] = NULL;
			return NULL;
		}
		Singleton::call()->m_nGold -= m_pTower[i]->getTowerCost();
		m_pLayer->addChild( m_pTower[i], 3 );
		m_pTower[i]->setLiveFlag( true );
		
		return m_pTower[i];					
	}
	return NULL;
}

void TowerManager::setLayer( CCLayer* _pLayer )
{
	m_pLayer = _pLayer;
}

void TowerManager::matchTarget( Enemy* _pEnemy )		// 타워와 Enemy간의 충돌체크와 동시에 타겟팅
{
	for( int i = 0 ; i < MAX_TOWER ; i ++ )	{
		if( m_pTower[i] == NULL ) continue;
		if( m_pTower[i]->getTarget() != NULL ) continue;
		m_pTower[i]->setTarget( _pEnemy );
	}
}

void TowerManager::dealloc()
{
	for( int i = 0 ; i < MAX_TOWER ; i ++ ){
		if( m_pTower[i] == NULL ) continue;
		if( m_pTower[i]->getLiveFlag() == true ) continue;
		m_pLayer->removeChild( m_pTower[i], true );
		m_pTower[i] = NULL;
	}
}

/************************************************

	타워와 타겟의 거리에 따른 3가지 상태

	1.타겟이 존재 하지 않는다.
	2.타겟이 존재하고 타워의 사정거리에 존재한다.
	3.타겟이 존재하고 타워의 사정거리 밖에 존재 한다.

	새로운 타겟을 정할 수 있는 경우 1,3	
	2번은 continue

*************************************************/
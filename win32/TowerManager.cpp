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

Tower* TowerManager::createTower( CGPoint _pos, int _type  )		// Scene����
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

void TowerManager::matchTarget( Enemy* _pEnemy )		// Ÿ���� Enemy���� �浹üũ�� ���ÿ� Ÿ����
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

	Ÿ���� Ÿ���� �Ÿ��� ���� 3���� ����

	1.Ÿ���� ���� ���� �ʴ´�.
	2.Ÿ���� �����ϰ� Ÿ���� �����Ÿ��� �����Ѵ�.
	3.Ÿ���� �����ϰ� Ÿ���� �����Ÿ� �ۿ� ���� �Ѵ�.

	���ο� Ÿ���� ���� �� �ִ� ��� 1,3	
	2���� continue

*************************************************/
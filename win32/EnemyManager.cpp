#include "EnemyManager.h"
#include "Singleton.h"
#include "Enemy_Orge.h"
#include "Enemy_Boss.h"
#include "Enemy_Goblin.h"

void EnemyManager::init()
{
	m_fFrameTime = 0.f;

	m_WinSize = CCDirector::sharedDirector()->getWinSize();
	memset( m_pEnemy, NULL, sizeof(m_pEnemy) );
	m_pLayer = NULL;
}

void EnemyManager::setLayer( CCLayer* _pLayer )
{
	m_pLayer = _pLayer;
}

void EnemyManager::createEnemy( CGPoint _pos, int _type )
{
	if( m_pLayer == NULL ) return;

	for( int i = 0; i < MAX_ENEMY; i++ )
	{  
		if( m_pEnemy[i] != NULL ) continue;
		switch( _type )
		{
		case ENEMY_ORGE:
			{
				Enemy_Orge* p = new Enemy_Orge;
				p->init();
				p->setPosition(_pos);
				m_pEnemy[i] = p;
				break;
			}
		case ENEMY_GOBLIN:
			{
				Enemy_Goblin* p = new Enemy_Goblin;
				p->init();
				p->setPosition(_pos);
				m_pEnemy[i] = p;
				break;
			}
		case ENEMY_BOSS:
			{
				Enemy_Boss* p = new Enemy_Boss;
				p->init();
				p->setPosition(_pos);
				m_pEnemy[i] = p;
				break;
			}
		}
		m_pLayer->addChild( m_pEnemy[i], 1 );
		break;
	}
}

void EnemyManager::matchTower()
{	
	for( int i = 0 ; i < MAX_ENEMY ; i++ ){
		if( m_pEnemy[i] == NULL ) continue;
		Singleton::call()->TM.matchTarget( m_pEnemy[i] );	// Tower, Enemy Matching(연결) 반드시 실시간, 이중 for문으로
	}
}

void EnemyManager::zOrderByYPos( ccTime dt )
{
	m_fFrameTime += dt;	

	if( m_fFrameTime > 0.1f ){
		for( int i = 0 ; i < MAX_ENEMY ; i ++ ){
			if( m_pEnemy[i] == NULL ) continue;
			m_pLayer->reorderChild( m_pEnemy[i], (int)m_WinSize.height - (int)m_pEnemy[i]->getPosition().y );
		}
		m_fFrameTime = 0.f;
	}
}

void EnemyManager::checkAlive()
{
	for( int i = 0 ; i < MAX_ENEMY ; i++ )
	{
		if( m_pEnemy[i] == NULL ) continue;
		if( m_pEnemy[i]->getHP() <= 0 ){
			Singleton::call()->m_nGold += 20;
			Singleton::call()->SM.play( ENEMY_DEAD );
			Singleton::call()->EfM.createEffect( m_pEnemy[i]->getPosition(), LILITH );
			m_pLayer->removeChild( m_pEnemy[i], true );
			m_pEnemy[i] = NULL;
		}
		else if( !m_pEnemy[i]->checkEndLine() ){		// Enemy EndLine 도착시 false 리턴
			Singleton::call()->m_nLife--;
			Singleton::call()->SM.play( ENDLINE );
			m_pLayer->removeChild( m_pEnemy[i], true );
			m_pEnemy[i] = NULL;
		}
	}
}
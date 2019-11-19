#include "LandManager.h"
#include "Singleton.h"

void LandManager::init()
{
	memset( m_pLand, NULL, sizeof(m_pLand) );
	m_pLayer = NULL;
}

void LandManager::createLand()
{
	for( int i = 0 ; i < MAX_LAND ; i++ )
	{
		m_pLand[i] = new Land;
		m_pLand[i]->init();
		m_pLayer->addChild( m_pLand[i], 2 );
	}

	m_pLand[0]->setPosition( ccp(590,634) );
	m_pLand[1]->setPosition( ccp(380,556) );
	m_pLand[2]->setPosition( ccp(390,344) );
	m_pLand[3]->setPosition( ccp(266,178) );
	m_pLand[4]->setPosition( ccp(659,311) );
	m_pLand[5]->setPosition( ccp(550,159) );
	m_pLand[6]->setPosition( ccp(842,208) );
	m_pLand[7]->setPosition( ccp(187,370) );
	m_pLand[8]->setPosition( ccp(527,310) );
	m_pLand[9]->setPosition( ccp(277,488) );
}

void LandManager::selectLand( CGPoint _pos )
{
	for( int i = 0 ; i < MAX_LAND ; i++ ){
		if( m_pLand[i] == NULL ) continue;
		if( m_pLand[i]->setMousePos( _pos ) == true ){
			if( Singleton::call()->WM.getWindow() != NULL ) Singleton::call()->WM.closeWindow();
			Singleton::call()->WM.createWindow( m_pLand[i], i );
			Singleton::call()->SM.play( CLICK_BTN );
			return;
		}
	}
	if( Singleton::call()->WM.getWindow() != NULL ) Singleton::call()->WM.closeWindow();
}

void LandManager::setTowerByIndex( Tower* _pTower, int _TowerIndex )
{
	for( int i = 0 ; i < MAX_LAND ; i ++ ){
		if( m_pLand[i] == NULL ) continue;
		if( _TowerIndex == i ){
			m_pLand[i]->setTower( _pTower );
			break;
		}
	}
}

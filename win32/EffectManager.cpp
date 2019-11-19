#include "EffectManager.h"

void EffectManager::init()
{
	m_pLayer = NULL;
	memset( m_pEffect, NULL, sizeof(m_pEffect) );
	this->initWithAnimation();
}

void EffectManager::initWithAnimation()
{
	char szTemp1[20] = {0};
	m_pEffectAni[0] = new CCAnimation;
	m_pEffectAni[0]->initWithName( "EFFECT" );
	for( int i = 1; i <= 20; i++) 
	{
		sprintf_s( szTemp1, "DNF/boom%d.png", i );
		m_pEffectAni[0]->addFrameWithFileName( szTemp1 );
	}

	char szTemp2[20] = {0};
	m_pEffectAni[1] = new CCAnimation;
	m_pEffectAni[1]->initWithName( "LILITH" );
	for( int i = 0 ; i <= 12 ; i++) 
	{
		sprintf_s( szTemp2, "Test/hero%d.png", i );
		m_pEffectAni[1]->addFrameWithFileName( szTemp2 );
	}
}

void EffectManager::createEffect( CGPoint _pos, int _iType )
{
	if( m_pLayer == NULL ) return;
	for( int i = 0 ; i < MAX_EFFECT ; i++ ){
		if( m_pEffect[i] != NULL ) continue;
		m_pEffect[i] = new Effect;
		
		switch( _iType ){
		case EFFECT:
			m_pEffect[i]->initWithEffectAni( m_pEffectAni[0], "EFFECT" );
			break;
		case LILITH:
			m_pEffect[i]->initWithEffectAni( m_pEffectAni[1], "LILITH" );
			break;
		}

		m_pEffect[i]->setPosition( _pos );
		m_pLayer->addChild( m_pEffect[i], 1000 );
		break;
	}
}

void EffectManager::dealloc()
{
	if( m_pLayer == NULL ) return;
	for( int i = 0 ; i < MAX_EFFECT ; i ++ ){
		if( m_pEffect[i] == NULL ) continue;
		if( m_pEffect[i]->getActive() == true ){
			m_pLayer->removeChild( m_pEffect[i], true );
			m_pEffect[i] = NULL;
		}
	}
}
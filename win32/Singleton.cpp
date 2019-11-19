#include "Singleton.h"

void Singleton::init( CCLayer* _pLayer )
{
	m_nLife	= 20;
	m_nGold	= 600;
	m_nWave = 1;
	m_realP = ccp( 199,199 );

	SM.init();					// Sound
	SM.loading();
	TM.init();					// Tower
	TM.setLayer( _pLayer );
	EfM.init();					// Effect
	EfM.setLayer( _pLayer );
	EM.init();					// Enemy 
	EM.setLayer( _pLayer );
	BM.init();					// Bullet
	BM.setLayer( _pLayer );		
	LM.init();					// Land
	LM.setLayer( _pLayer );
	LM.createLand();	
	WM.init();					// Window
	WM.setLayer( _pLayer );	
}

CGPoint Singleton::setVector( CCNode* _dest , CCNode* _sour )
{
	CGPoint	_destPos = _dest->getPosition();
	CGPoint	_sourPos = _sour->getPosition();
	CGPoint Vec = setVector( _destPos, _sourPos );
	
	return Vec;
}

CGPoint Singleton::setVector( CGPoint _dest, CGPoint _sour )
{
	CGPoint Vec;

	Vec.x = _dest.x - _sour.x;		// 목적지 앞에 오도록
	Vec.y = _dest.y - _sour.y;

	return Vec;
}

float Singleton::getDistance( CCNode* _dest , CCNode* _sour )
{
	CGPoint Vec	= setVector( _dest, _sour );
	float	fD	= sqrtf( Vec.x * Vec.x + Vec.y * Vec.y );

	return fD;
}

float Singleton::getDistance( CGPoint _dest , CGPoint _sour )
{
	CGPoint Vec	= setVector( _dest, _sour );
	float	fD	= sqrtf( Vec.x * Vec.x + Vec.y * Vec.y );

	return fD;
}

CGPoint Singleton::Normalize( CGPoint _Vec )
{
	float fD = sqrtf( _Vec.x * _Vec.x + _Vec.y * _Vec.y );
	
	_Vec.x /= fD;
	_Vec.y /= fD;
	
	return _Vec;
}
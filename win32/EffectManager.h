#pragma once
#include "cocos2d.h"
#include "Effect.h"

#define MAX_EFFECT		52
#define MAX_EFFECT_ANI	10		

using namespace cocos2d;

class EffectManager 
{
private:
	Effect*			m_pEffect[ MAX_EFFECT ];
	CCAnimation*	m_pEffectAni[ MAX_EFFECT_ANI ];			// EffectÀÇ Á¾·ù
	CCLayer*		m_pLayer;

public:
	void init();
	void initWithAnimation();

	void setLayer( CCLayer* _pLayer ){ m_pLayer = _pLayer; }
	void createEffect( CGPoint _pos, int _iType );
	void dealloc();
};


enum { EFFECT, LILITH };
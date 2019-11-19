#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class Effect : public CCSprite 
{
protected:
	char*	m_pType;
	float	m_fFrame;
	float	m_fMaxFrame;
	bool	m_bActive;

public: 
	bool initWithEffectAni( CCAnimation* _pEffectAni, char* _pType );
	void tick( ccTime dt );	
	bool getActive(){ return m_bActive; }
};
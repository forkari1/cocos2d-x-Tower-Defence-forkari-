#include "EFfect.h"

bool Effect::initWithEffectAni( CCAnimation* _pEffectAni, char* _pType )  
{
	if( !CCSprite::init() ) return false;
	
	m_fFrame	= 0.f;
	m_bActive	= false;
	m_pType		= _pType;
	
	m_fMaxFrame = _pEffectAni->getFrames()->count();
	this->addAnimation( _pEffectAni );
	
	this->schedule(schedule_selector( Effect::tick ));
	return true;
}

void Effect::tick( ccTime dt ) 
{
	m_fFrame += dt * 20;					// 20Àº ¼Óµµ
	
	if(m_fFrame >= m_fMaxFrame){
		m_bActive = true;	
		return;
	}
	this->setDisplayFrame( m_pType, m_fFrame );
}
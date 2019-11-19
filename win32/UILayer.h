#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class UILayer : public CCLayer
{
private:
	CCLabelTTF*		m_pLifeLabel;
	CCLabelTTF*		m_pGoldLabel;
	CCLabelTTF*		m_pCoorLabel;
	CCLabelTTF*		m_pWaveLabel;
	
public:
	virtual bool init();
			void initWithLabel();
			void tick( ccTime dt );
			void updateLabel();

	virtual void ccTouchesBegan( NSSet *pTouches, UIEvent *pEvent );
	virtual void ccTouchesMoved( NSSet *pTouches, UIEvent *pEvent );
	virtual void ccTouchesEnded( NSSet *pTouches, UIEvent *pEvent ){;}
};

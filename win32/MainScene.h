#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class MainScene : public CCLayer
{
private:
	float		m_fFrameTime;
	
public:
	LAYER_NODE_FUNC( MainScene );
	static CCScene* scene();
	
	virtual bool init();
			void initWithObject();
			void tick			( ccTime dt );
			void generateEnemy	( ccTime dt );
			
	virtual void ccTouchesBegan( NSSet *pTouches, UIEvent *pEvent );
	virtual void ccTouchesMoved( NSSet *pTouches, UIEvent *pEvent ){;}
	virtual void ccTouchesEnded( NSSet *pTouches, UIEvent *pEvent ){;}
};
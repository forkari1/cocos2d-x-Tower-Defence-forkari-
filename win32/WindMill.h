#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class WindMill : public CCSprite
{
private:
	float		m_fFrameTime;
	float		m_fFrame;
	int			m_iMaxFrame;

public:
	virtual bool init();
			void initWithAnimation();

			void tick		( ccTime dt );
			void animation	( ccTime dt );
			char* getNameByState( int _state );
};

enum{ WINDMILL };
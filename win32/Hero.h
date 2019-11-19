#pragma once
#include "cocos2d.h"
#include "Enemy.h"
using namespace cocos2d;

class Hero : public CCSprite
{
private:
	float		m_fSpeed;
	float		m_fFrameTime;

public:
	virtual bool init();

			void tick	( ccTime dt );
			void action	( ccTime dt );
};
#pragma once
#include "cocos2d.h"
#include "Tower.h"

using namespace cocos2d;

class Land : public CCSprite
{
private:
	float		m_fFrameTime;

	Tower*		m_pTower;
	CGPoint		m_MousePos;

public:
	virtual bool init();			
			bool setMousePos( CGPoint _pos );
			Tower* getTower(){return m_pTower;}
			void setTower( Tower* _pTower ){m_pTower = _pTower;}
};


// Land의 위치와 Mouse의 위치를 계산해서 특정거리 이하면 true, 아니면 false return
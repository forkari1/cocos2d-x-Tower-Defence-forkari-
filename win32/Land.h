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


// Land�� ��ġ�� Mouse�� ��ġ�� ����ؼ� Ư���Ÿ� ���ϸ� true, �ƴϸ� false return
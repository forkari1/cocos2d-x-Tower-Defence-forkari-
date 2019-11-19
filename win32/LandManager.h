#pragma once
#include "Land.h"
#include "cocos2d.h"
using namespace cocos2d;

#define MAX_LAND		10

class LandManager
{
private:
	Land*		m_pLand[ MAX_LAND ];
	CCLayer*	m_pLayer;

public:
	void init();

	void setLayer		 ( CCLayer*	_pLayer ) { m_pLayer = _pLayer; }
	void selectLand		 ( CGPoint _pos );
	void createLand();
	void setTowerByIndex ( Tower* _pTower, int _TowerIndex );
};
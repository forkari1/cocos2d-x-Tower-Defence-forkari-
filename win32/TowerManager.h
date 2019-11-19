#pragma once
#include "Tower.h"
#include "Enemy.h"
#include "cocos2d.h"
using namespace cocos2d;

#define MAX_TOWER			10

class TowerManager
{
private:
	Tower*		m_pTower[ MAX_TOWER ];
	CCLayer*	m_pLayer;
	
public:
	void init();

	void	setLayer	( CCLayer*	_pLayer );
	Tower*	createTower	( CGPoint	_pos, int _type	);
	void	matchTarget	( Enemy*	_pEnemy );
	void	dealloc();
};

enum{ TOWER_BOMB = 0, TOWER_ARCHER, TOWER_MAGIC };
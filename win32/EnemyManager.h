#pragma  once
#include "Enemy.h"
#include "cocos2d.h"

using namespace cocos2d;

#define MAX_ENEMY		10

class EnemyManager
{
private:
	float		m_fFrameTime;

	Enemy*		m_pEnemy[ MAX_ENEMY ];
	CCLayer*	m_pLayer;
	CGSize		m_WinSize;

public:
	void init();
	void setLayer		( CCLayer* _pLayer );
	void matchTower();
	void createEnemy	( CGPoint _pos, int _type );
	void zOrderByYPos	( ccTime dt );
	void checkAlive();
};

enum{ ENEMY_ORGE, ENEMY_GOBLIN, ENEMY_BOSS };
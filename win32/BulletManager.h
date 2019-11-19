#pragma  once
#include "Bullet.h"
#include "Enemy.h"
#include "cocos2d.h"

#define MAX_BULLET	15

using namespace cocos2d;

class BulletManager
{
private:
	Bullet*		m_pBullet[MAX_BULLET];
	CCLayer*	m_pLayer;
	
public:
	void init();
	void createBullet	( Enemy* _pTarget, CGPoint _pos, int _type, int _nDamage );
	void setLayer		( CCLayer* _pLayer );
	void checkCollision();
};
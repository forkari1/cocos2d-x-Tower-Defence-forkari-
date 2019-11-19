#pragma once
#include "Enemy.h"
#include "cocos2d.h"
using namespace cocos2d;

class Bullet : public CCSprite
{
protected:
	int		m_iType;
	float	m_fFrameTime;
	int		m_nDamage;
	float	m_fSpeed;
	float	m_fDegree;		// Bullet 과 Enemy 두 점을 지나는 한 직선과 x축이 이루는 각도
	
	CGPoint	m_Vec;			// 타겟으로의 Bullet의 벡터
	Enemy*	m_pTarget;
	float	m_fDistance;	// 타겟과의 거리

public:
	virtual bool init();

	virtual void tick			( ccTime dt ) = 0;
			void action			( ccTime dt );
			void moveToTarget	( ccTime dt );
			void damageEnemy();

			void setDamage( int _nDamage ){ m_nDamage = _nDamage; }
			int getDamage(){return m_nDamage;}
			void setTarget( Enemy* _pTarget )	{ m_pTarget = _pTarget; }
			float getDistance(){ return m_fDistance; }
};

enum{ BULLET_MAGIC, BULLET_ARCHER, BULLET_BOMB };
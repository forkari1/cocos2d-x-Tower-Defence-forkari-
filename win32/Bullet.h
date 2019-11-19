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
	float	m_fDegree;		// Bullet �� Enemy �� ���� ������ �� ������ x���� �̷�� ����
	
	CGPoint	m_Vec;			// Ÿ�������� Bullet�� ����
	Enemy*	m_pTarget;
	float	m_fDistance;	// Ÿ�ٰ��� �Ÿ�

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
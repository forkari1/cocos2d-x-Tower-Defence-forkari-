#pragma once
#include "cocos2d.h"
#include "Enemy.h"
using namespace cocos2d;

class Tower : public CCSprite
{
protected:
	int				m_iTowerType;		// 타워 종류
	int				m_nCost;			// 타워 건설 비용
	int				m_nDamage;			// 데미지
	float			m_FireRange;		// 사격 가능한 범위
	float			m_FirePace;			// 연사속도
	float			m_fDistance;		// 에너미와의 거리
	float			m_fFrameTime;

	bool			m_LiveFlag;
	Enemy*			m_pTarget;			// 공격 대상
	CCAnimation*	m_pAni;
	
public:
	virtual bool init();
	virtual void tick	( ccTime dt ) = 0;
			void action	( ccTime dt, int _type );
			void attack	( ccTime dt, int _type );
			void checkTarget();

			void setTowerCost( int _nConst )	{ m_nCost = _nConst; }
			int	getTowerCost()					{ return m_nCost; }
			void setLiveFlag( bool _LiveFlag )	{ m_LiveFlag = _LiveFlag; }
			bool getLiveFlag()					{ return m_LiveFlag; }
			void setDamage( int _nDamage )		{ m_nDamage = _nDamage; }
			int getDamage()						{ return m_nDamage; }
			void setTarget( Enemy* _pEnemy );
			Enemy* getTarget()					{ return m_pTarget; }
			void setRange( float _FireRange )	{ m_FireRange = _FireRange; }
			float getRange()					{ return m_FireRange; }
			void setPace( float _FirePace )		{ m_FirePace = _FirePace;}
			float getPace()						{ return m_FirePace; }
			void setTowerType( int _iTowerType ){ m_iTowerType = _iTowerType;}
			int getTowerType()					{ return m_iTowerType; }
};
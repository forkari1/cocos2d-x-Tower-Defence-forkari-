#pragma once
#include "cocos2d.h"
using namespace cocos2d;

#define	MAX_WAYPOINT		9

class Enemy : public CCSprite
{
protected:
	int			m_nHP;						
	float		m_nMaxHP;					
	float		m_fSpeed;					
	float		m_fFrameTime;					
	bool		m_endFlag;

	CGPoint		m_WayPoint[ MAX_WAYPOINT ];	// °æÀ¯Áö
	int			m_nWayCount;

public:
	virtual bool init();
			void initWithWayPoint();

	virtual void tick			( ccTime dt ) = 0;
			void action			( ccTime dt );
			void moveWayPoint	( ccTime dt );
			bool checkEndLine();

			void setHP( int _nHP )			{ m_nHP = _nHP; }
			int	getHP()						{ return m_nHP; }
			void setEndFlag( bool _endFlag ){ m_endFlag = _endFlag; }
			bool getEndFlag()				{ return m_endFlag; }
			void setSpeed( float _fSpeed )	{ m_fSpeed = _fSpeed; }
			float getSpeed()				{ return m_fSpeed; }
};

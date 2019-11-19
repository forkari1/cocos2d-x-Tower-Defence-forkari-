#pragma once
#include "cocos2d.h"
#include "Tower.h"
using namespace cocos2d;

class StatusWindow : public CCSprite
{
private:
	float		m_fFrameTime;
	int			m_nTowerDamage;	
	int			m_nTowerRange;	
	float		m_fTowerPace;		

	CCLabelTTF*	m_pTowerDamageLabel;
	CCLabelTTF*	m_pTowerPaceLabel;
	CCLabelTTF*	m_pTowerRangeLabel;

public:
	virtual bool init();
			void initWithLabel();

			void tick( ccTime dt );
			void action( ccTime dt );
			void updateTowerLabel();
			void updateTowerInfo( Tower* _pTower );
};
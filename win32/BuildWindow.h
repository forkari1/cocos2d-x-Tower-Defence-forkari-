#pragma once
#include "cocos2d.h"
#include "Tower.h"
#include "StatusWindow.h"
using namespace cocos2d;

class BuildWindow : public CCSprite
{
public:
	Tower*			m_pTower;		// Build가 popup되는 Land의 Tower정보와 index
	int				m_iTowerIndex;
	float			m_fFrameTime;
	float			m_fRotateTime;
	
	CCMenu*			m_pMenu;		// Build창에 띄우는 Menu버튼
	CCSprite*		m_pRange;		// Tower공격범위를 보여주는 원
	StatusWindow*	m_pStatus;		// Tower정보를 보여주는 창

	CCMenuItemImage* m_pItemArrow;
	CCMenuItemImage* m_pItemMagic;
	CCMenuItemImage* m_pItemBomb;
	CCMenuItemImage* m_pItemShield;
	CCMenuItemImage* m_pItemUpgrade;
	CCMenuItemImage* m_pItemSell;
	CCMenuItemImage* m_pItemNone;

public:
	virtual bool init();
			void initWithMenu();
			void tick( ccTime dt );
			void popupRange();

			Tower* getTower(){return m_pTower;}
			void setTower( Tower* _pTower ){m_pTower = _pTower;}
			int getTowerIndex(){return m_iTowerIndex;}
			void setTowerIndex( int _iTowerIndex ){m_iTowerIndex = _iTowerIndex;}
	
			void CallbackFN1( NSObject* pSender );
			void CallbackFN2( NSObject* pSender );
			void CallbackFN3( NSObject* pSender );
			void CallbackFN5( NSObject* pSender );
			void CallbackFN6( NSObject* pSender );
			void CallbackFN7( NSObject* pSender );
			Tower* CallBackSwitch( int _type );
};

enum{ ARCHER, MAGIC, BOMB, ARCHER2, MAGIC2, BOMB2 };
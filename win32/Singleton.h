#pragma once
#include "cocos2d.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "TowerManager.h"
#include "LandManager.h"
#include "WindowManager.h"
#include "SoundManager.h"
#include "EffectManager.h"
using namespace cocos2d;

class Singleton
{
public:
	static Singleton* instance;
	static Singleton* call()
	{
		if( instance == NULL ) instance = new Singleton;
		return instance;
	}

public:
	int	m_nLife;
	int	m_nGold;
	int m_nWave;
	CGPoint m_realP;

	BulletManager	BM;
	TowerManager	TM;
	EnemyManager	EM;
	LandManager		LM;
	WindowManager	WM;
	SoundManager	SM;
	EffectManager	EfM;
	
public:
	void	init		( CCLayer* _pLayer );
	CGPoint Normalize	( CGPoint _Vec );
	CGPoint setVector	( CCNode* _dest, CCNode* _sour );
	CGPoint setVector	( CGPoint _dest, CGPoint _sour );
	float	getDistance	( CCNode* _dest, CCNode* _sour );
	float	getDistance	( CGPoint _dest, CGPoint _sour );
};
#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class TitleScene : public CCLayer
{
public:
	float			m_fFrameTime;	// dt ����
	CCSprite*		m_pBGA;			// ���

public:
	LAYER_NODE_FUNC(TitleScene);
	static CCScene* scene();

	bool init();
	void initWithMenu();
	void tick(ccTime dt);
	void CallbackFN1( NSObject* pSender );	
};



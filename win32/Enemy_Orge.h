#pragma  once
#include "Enemy.h"
#include "cocos2d.h"

using namespace cocos2d;

class Enemy_Orge : public Enemy
{
private:
	int			m_iState;
	float		m_fFrame;	// flaot ������ �Ű������� �Ѿ�� int�� ĳ���õ�
	int			m_iMaxFrame;

	CCSprite*	 m_pHP;
	CCAnimation* m_pAni;

public:
	virtual bool init();
			void initWithHPBar();
			void initWithAnimation();
			
	virtual	void tick		( ccTime dt );
			void animation	( ccTime dt );
			char* getNameByState( int _state );
};

enum { WALK };
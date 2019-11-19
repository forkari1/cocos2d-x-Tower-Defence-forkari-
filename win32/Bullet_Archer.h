#pragma  once
#include "Bullet.h"
#include "cocos2d.h"

using namespace cocos2d;

class Bullet_Archer : public Bullet
{
public:
	virtual bool init();
	virtual void tick( ccTime dt );
};
#pragma  once
#include "Tower.h"
#include "cocos2d.h"

using namespace cocos2d;

class Tower_Bomb: public Tower
{
private:

public:
	virtual bool init();
	virtual void tick( ccTime dt );
};
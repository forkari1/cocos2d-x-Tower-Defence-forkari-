#pragma once
#include "fmod.hpp"
#include "cocos2d.h"
#pragma comment(lib, "fmodex_vc.lib")

using namespace FMOD;
using namespace cocos2d;

class SoundManager
{
private:
	System*		pFmod;
	Channel*	ch[15];
	Sound*		music[15];
	FMOD_RESULT	r;

public:
	void init();
	void loading();
	void play( int _type );
	void stop( int _chNum );
	void ErrorCheck(FMOD_RESULT _r);
};


enum Sound{
	BACKGROUND_SOUND = 0, ARCHER_ATTACK, MAGIC_ATTACK, BOMB_ATTACK,
	BUILD_BOMB,	BUILD_MAGIC, BUILD_ARCHER, CLICK_BTN, BUILD_BTN,
	ENEMY_DEAD,	ARCHER_GETHIT, BOMB_GETHIT, FANFARE, CROW, ENDLINE, TITLE_SOUND
};
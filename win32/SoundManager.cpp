#include "SoundManager.h"
#include "fmod_errors.h"

void SoundManager::init()
{
	r = System_Create(&pFmod);
	ErrorCheck(r);
	r = pFmod->init(100, FMOD_INIT_NORMAL, NULL);
	ErrorCheck(r);
}

void SoundManager::loading()
{
	r = pFmod->createSound("Sound/bga.mp3", FMOD_LOOP_NORMAL, NULL, &music[BACKGROUND_SOUND]);
	ErrorCheck(r);
	r = pFmod->createSound("Sound/archer_attack.wav", FMOD_DEFAULT, NULL, &music[ARCHER_ATTACK]);
	ErrorCheck(r);
	r = pFmod->createSound("Sound/magic_attack.wav", FMOD_DEFAULT, NULL, &music[MAGIC_ATTACK]);
	ErrorCheck(r);
	r = pFmod->createSound("Sound/bomb_attack.wav", FMOD_DEFAULT, NULL, &music[BOMB_ATTACK]);
	ErrorCheck(r);
	r = pFmod->createSound("Sound/bomb.wav", FMOD_DEFAULT, NULL, &music[BUILD_BOMB]);
	ErrorCheck(r);
	r = pFmod->createSound("Sound/magic.wav", FMOD_DEFAULT, NULL, &music[BUILD_MAGIC]);
	ErrorCheck(r);
	r = pFmod->createSound("Sound/archer.wav", FMOD_DEFAULT, NULL, &music[BUILD_ARCHER]);
	ErrorCheck(r);
	r = pFmod->createSound("Sound/click.wav", FMOD_DEFAULT, NULL, &music[CLICK_BTN]);
	ErrorCheck(r);
	r = pFmod->createSound("Sound/build.wav", FMOD_DEFAULT, NULL, &music[BUILD_BTN]);
	ErrorCheck(r);
	r = pFmod->createSound("Sound/enemy_dead.wav", FMOD_DEFAULT, NULL, &music[ENEMY_DEAD]);
	ErrorCheck(r);
	r = pFmod->createSound("Sound/archer_gethit.wav", FMOD_DEFAULT, NULL, &music[ARCHER_GETHIT]);
	ErrorCheck(r);
	r = pFmod->createSound("Sound/bomb_gethit.wav", FMOD_DEFAULT, NULL, &music[BOMB_GETHIT]);
	ErrorCheck(r);
	r = pFmod->createSound("Sound/fanfarea.wav", FMOD_DEFAULT, NULL, &music[FANFARE]);
	ErrorCheck(r);
	r = pFmod->createSound("Sound/crow.wav", FMOD_DEFAULT, NULL, &music[CROW]);
	ErrorCheck(r);
	r = pFmod->createSound("Sound/endline.wav", FMOD_DEFAULT, NULL, &music[ENDLINE]);
	ErrorCheck(r);
	r = pFmod->createSound("Sound/title.mp3", FMOD_LOOP_NORMAL, NULL, &music[TITLE_SOUND]);
	ErrorCheck(r);
}

void SoundManager::play(int _type)
{
	pFmod->update();
   	r =  pFmod->playSound(FMOD_CHANNEL_FREE, music[_type], false, &ch[_type]);
	
	ErrorCheck(r);
}

void SoundManager::stop(int _chNum)
{
	ch[_chNum]->stop();
}

void SoundManager::ErrorCheck(FMOD_RESULT _r)
{
	if(_r != FMOD_OK){
		//CString szStr[256] = {0};
		//MultiByteToWideChar(CP_ACP, NULL, FMOD_ErrorString(r), -1, szStr, 256);
		//MessageBox(NULL, szStr, L"Sound Error", MB_OK);
	}
}

/*
	�ý��� ����
	FMOD::System * pfmod;
	FMOD::System_Create(&pfmod);

	�ý��� �ʱ�ȭ( ä�� ����, �ʱ�ȭ ���, �ٸ� ����̹� )
	pfmod->init(  10,     FMOD_INIT_NORMAL,    NULL);

	FMOD::Channel * ch;		//ä��
	FMOD::Sound * SoundFile; //���� ���� ������

	���� �ε�( ���ϸ�, �ʱ�ȭ ���, ��������, ���� ���� ������)
	pfmod->createSound("".FMOD_DEFAULT, NULL, &SoundFile);

	���� ��� ( ����� ������ ä��, ���� ���� ������, ���۽� ������ ����, ä��);
	pfmod->playSound(FMOD_CHANNEL_FREE , SoundFile, false. &ch);
*/
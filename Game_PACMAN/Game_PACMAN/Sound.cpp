#include"DxLib.h"
#include"Image.h"
#include"Pink.h"
#include"Red.h"
#include "Sound.h"

Sound sound;

/***********************************************
 * �����ǂݍ���
 ***********************************************/
int Sound::LoadSounds()
{
	//�G�̓���SE
	if ((g_Sound = LoadSoundMem("sounds/move.mp3")) == -1) return -1;

	return 0;
}

int Sound::PlayMoveSounds() {

	if (CheckSoundMem(g_Sound) == 0) {

		PlaySoundMem(g_Sound, DX_PLAYTYPE_BACK);
	}

	return 0;
}
#include"DxLib.h"
#include"sounds.h"

Sounds sound;

//�����ǂݍ���
int Sounds::LoadSounds()
{
	if ((PlayerMove = LoadSoundMem("sounds/Normal.wav")) == -1) return -1;   //�v���C���[�ړ�
	if ((PlayerEat = LoadSoundMem("sounds/playeat.wav")) == -1) return -1;    //�G�T��H�ׂ�
	if ((PlayerDestroy = LoadSoundMem("sounds/PlayerDestroy .wav")) == -1) return -1;    //�v���C���[���ŉ�
	if ((Select = LoadSoundMem("sounds/Select.wav")) == -1) return -1;   //�v���C���[�ړ�
	//if ((IjikeEat = LoadSoundMem("sounds/")) == -1) return -1;     //�C�W�P��ߐH
	//if ((EnemyEye = LoadSoundMem("sounds/")) == -1) return -1;     //�ڏ�Ԃő��ɖ߂�
	//if (( = LoadSoundMem("sounds/")) == -1) return -1;
	//if (( = LoadSoundMem("sounds/")) == -1) return -1;

	return 0;
}

void Sounds::PlayPlayerMove()
{
	PlaySoundMem(PlayerMove, DX_PLAYTYPE_BACK);
}


void Sounds::PlayPlayerEat()
{
	PlaySoundMem(PlayerEat, DX_PLAYTYPE_BACK);
}
void Sounds::StopPlayerEat()
{
	StopSoundMem(PlayerEat);
}

void Sounds::PlayerDestroySound()
{
	PlaySoundMem(PlayerDestroy, DX_PLAYTYPE_BACK);
}

void Sounds::SelectSE()
{
	PlaySoundMem(Select, DX_PLAYTYPE_BACK);
}

void Sounds::PlayIjikeEat()
{
	PlaySoundMem(IjikeEat, DX_PLAYTYPE_BACK);
}

void Sounds::PlayEnemyEye()
{
	PlaySoundMem(EnemyEye, DX_PLAYTYPE_LOOP);
}
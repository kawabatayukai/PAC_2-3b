#include"DxLib.h"
#include"sounds.h"

//�����ǂݍ���
int Sounds::LoadSounds()
{
	if ((PlayerMove = LoadSoundMem("sounds/")) == -1) return -1;   //�v���C���[�ړ�
	if ((PlayerEat = LoadSoundMem("sounds/")) == -1) return -1;    //�G�T��H�ׂ�
	if ((IjikeEat = LoadSoundMem("sounds/")) == -1) return -1;     //�C�W�P��ߐH
	if ((EnemyEye = LoadSoundMem("sounds/")) == -1) return -1;     //�ڏ�Ԃő��ɖ߂�
	//if (( = LoadSoundMem("sounds/")) == -1) return -1;
	//if (( = LoadSoundMem("sounds/")) == -1) return -1;

	return 0;
}

void Sounds::PlayPlayerMove()
{
	PlaySoundMem(PlayerMove, DX_PLAYTYPE_LOOP);
}


void Sounds::PlayPlayerEat()
{
	PlaySoundMem(PlayerEat, DX_PLAYTYPE_LOOP);
}

void Sounds::PlayIjikeEat()
{
	PlaySoundMem(IjikeEat, DX_PLAYTYPE_BACK);
}

void Sounds::PlayEnemyEye()
{
	PlaySoundMem(EnemyEye, DX_PLAYTYPE_LOOP);
}
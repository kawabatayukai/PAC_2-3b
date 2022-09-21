#include"DxLib.h"
#include"sounds.h"

Sounds sound;

//�����ǂݍ���
int Sounds::LoadSounds()
{
	if ((PlayerMove = LoadSoundMem("sounds/Normal3.wav")) == -1) return -1;   //�v���C���[�ړ�
	if ((PlayerEat = LoadSoundMem("sounds/playeat2.wav")) == -1) return -1;    //�G�T��H�ׂ�
	if ((PlayerDestroy = LoadSoundMem("sounds/PlayerDestroy .wav")) == -1) return -1;    //�v���C���[���ŉ�
	if ((Select = LoadSoundMem("sounds/Select.wav")) == -1) return -1;   //�I��
	if ((Input = LoadSoundMem("sounds/Input.wav")) == -1) return -1;    //A�{�^��
	if ((IjikeEat = LoadSoundMem("sounds/eatIJIKE.wav")) == -1) return -1;     //�C�W�P��ߐH
	if ((EnemyEye = LoadSoundMem("sounds/Eye2.wav")) == -1) return -1;     //�ڏ�Ԃő��ɖ߂�
	if ((FruitEat = LoadSoundMem("sounds/EatFruit.wav")) == -1) return -1;
	if ((IjikeMove = LoadSoundMem("sounds/IjikeMove2.wav")) == -1) return -1;

	return 0;
}

void Sounds::PlayPlayerMove()
{
	if (CheckSoundMem(PlayerMove) == 0)
	{
		PlaySoundMem(PlayerMove, DX_PLAYTYPE_BACK);
	}

}


void Sounds::PlayPlayerEat()
{
	ChangeVolumeSoundMem(330, PlayerEat);
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

void Sounds::InputSE()
{
	PlaySoundMem(Input, DX_PLAYTYPE_BACK);
}

void Sounds::PlayIjikeEat()
{
	PlaySoundMem(IjikeEat, DX_PLAYTYPE_BACK);
}

void Sounds::PlayEnemyEye()
{
	if (CheckSoundMem(EnemyEye) == 0)
	{
		PlaySoundMem(EnemyEye, DX_PLAYTYPE_BACK);
	}
	
}

void Sounds::PlayFruitEat()
{
	PlaySoundMem(FruitEat, DX_PLAYTYPE_BACK);
}

void Sounds::PlayIjikeMove()
{
	
	if (CheckSoundMem(IjikeMove) == 0)
	{
		PlaySoundMem(IjikeMove, DX_PLAYTYPE_BACK);
	}
}

void Sounds::StopIjikeMove()
{
	StopSoundMem(IjikeMove);
}
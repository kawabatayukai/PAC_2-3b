#include"DxLib.h"
#include"sounds.h"

Sounds sound;

//音声読み込み
int Sounds::LoadSounds()
{
	if ((PlayerMove = LoadSoundMem("sounds/Normal.wav")) == -1) return -1;   //プレイヤー移動
	if ((PlayerEat = LoadSoundMem("sounds/playeat.wav")) == -1) return -1;    //エサを食べる
	if ((PlayerDestroy = LoadSoundMem("sounds/PlayerDestroy .wav")) == -1) return -1;    //プレイヤー消滅音
	if ((Select = LoadSoundMem("sounds/Select.wav")) == -1) return -1;   //プレイヤー移動
	//if ((IjikeEat = LoadSoundMem("sounds/")) == -1) return -1;     //イジケを捕食
	//if ((EnemyEye = LoadSoundMem("sounds/")) == -1) return -1;     //目状態で巣に戻る
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
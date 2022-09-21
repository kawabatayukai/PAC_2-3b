#include"DxLib.h"
#include"sounds.h"

//音声読み込み
int Sounds::LoadSounds()
{
	if ((PlayerMove = LoadSoundMem("sounds/")) == -1) return -1;   //プレイヤー移動
	if ((PlayerEat = LoadSoundMem("sounds/")) == -1) return -1;    //エサを食べる
	if ((IjikeEat = LoadSoundMem("sounds/")) == -1) return -1;     //イジケを捕食
	if ((EnemyEye = LoadSoundMem("sounds/")) == -1) return -1;     //目状態で巣に戻る
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
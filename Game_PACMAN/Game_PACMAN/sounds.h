#pragma once

class Sounds
{
public:
	int LoadSounds(); //音声読み込み

	void PlayPlayerMove();
	void PlayPlayerEat();
	void StopPlayerEat();

	void PlayIjikeEat();
	void PlayEnemyEye();

private:
	int PlayerMove;  //プレイヤー移動
	int PlayerEat;   //エサを食べる

	int IjikeEat;    //イジケを捕食
	int EnemyEye;    //目状態で巣に戻る
};

extern Sounds sound;

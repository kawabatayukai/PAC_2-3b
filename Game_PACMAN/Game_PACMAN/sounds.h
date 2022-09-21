#pragma once

class Sounds
{
public:
	int LoadSounds(); //音声読み込み

	void PlayPlayerMove();
	void PlayPlayerEat();
	void StopPlayerEat();
	void PlayerDestroySound();
	void SelectSE();
	void InputSE();

	void PlayIjikeEat();
	void PlayEnemyEye();
	void PlayFruitEat();
	void PlayIjikeMove();
	void StopIjikeMove();


private:
	int PlayerMove;  //プレイヤー移動
	int PlayerEat;   //エサを食べる
	int PlayerDestroy;  //プレイヤー消滅音
	int Select;    //選択ボタン
	int Input;     //Aボタン

	int IjikeEat;    //イジケを捕食
	int EnemyEye;    //目状態で巣に戻る
	int FruitEat;
	int IjikeMove;   //イジケ時
};

extern Sounds sound;

#pragma once
#include"enemy.h"
//#include"player.h"

//フルーツ最大描画数
#define MAX_DRAW_F 8 

class DISPLAY
{
public:
	//画像読み込み
	int LoadImages();
	//音声読み込み
	int LoadSounds();

	void DispInit(int ClearCnt);        //初期化
	void DrawStartDisp(GAME_STATE* state, ENEMY_BASE* enemy);   //ゲームスタート時
	void DrawOverDisp(GAME_STATE* state);    //ゲームオーバー時

	void DrawPlayerLife(int LifeCnt);        //残機描画
	void DrawStageFruit(int ClearCnt);       //クリア面によるフルーツ描画
	void SetDrawFruit(int ClearCnt);         //クリア面による描画フルーツのセット
	void ResetDrawFruit();                   //表示用フルーツ配列をリセット（new を使えばいらない）

private:
	int CircleImage;  //プレイヤーの"●"画像
	int PacImage;     //残機用プレイヤー画像

	int StartImage;   //"Ready!"画像
	int OverImage;    //"Game Over" 画像
	int PlayImage;    //"Player"画像
	int StartBGM;     //スタートBGM

	int Img_Fruits[MAX_DRAW_F];//フルーツ最大表示数
	int index = 0;

	int counter = 0;  //フレームカウント
	int clearcount = 0;
};

extern DISPLAY Disp;

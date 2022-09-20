#pragma once
#include"enemy.h"
//#include"player.h"

class DISPLAY
{
public:
	//画像読み込み
	int LoadImages();
	//音声読み込み
	int LoadSounds();

	void DispInit();        //初期化
	void DrawStartDisp(GAME_STATE* state, ENEMY_BASE* enemy);   //ゲームスタート時
	void DrawOverDisp(GAME_STATE* state);    //ゲームオーバー時

	int PacManImage[12];			// 画像用変数
	int PacManDamageImage[12];			// 画像用変数
	int	g_StageImage;			// 画像用変数
	int	g_StageImageW;			// 画像用変数
private:
	int CircleImage;  //プレイヤーの"●"画像


	int StartImage;   //"Ready!"画像
	int OverImage;    //"Game Over" 画像
	int PlayImage;    //"Player"画像
	int StartBGM;     //スタートBGM

	int counter = 0;  //フレームカウント
	int clearcount = 0;

};

extern DISPLAY Disp;

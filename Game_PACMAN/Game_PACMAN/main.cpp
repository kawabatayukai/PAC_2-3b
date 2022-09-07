#include "DxLib.h"
#include <stdio.h>
#include <tchar.h>
#include <map>
#include "Stage.h"
#include "Image.h"
#include"Common.h"
#include "Player.h"
#include "A_star.h"
#include "Enemy.h"
#include "Enemy2.h"

int	oldKey;				// 前回の入力キー
int	nowKey;				// 今回の入力キー
int	keyFlg;				// 入力キー情報

int InitFlg = false;


//メイン
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("パックマン");       //タイトルを設定
	ChangeWindowMode(TRUE);                //ウィンドウモードで起動
	SetGraphMode(1280, 720, 32);
	if (DxLib_Init() == -1) return -1;     //DXライブラリの初期化処理
	SetDrawScreen(DX_SCREEN_BACK);         //描画先画面を裏にする

	if (image.LoadImages() == -1)return -1;


	//ゲームループ              
	while (ProcessMessage() == 0)
	{
		oldKey = nowKey;
		nowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		keyFlg = nowKey & ~oldKey;

		//画面の初期化
		ClearDrawScreen();

		if (InitFlg == false) {
			g_player.PlayerInit();
			g_enemy.EnemyInit();
			g_enemy2.EnemyInit();
			a_star.A_starInit();
			//a_star.SetDefault();
			//a_star.ResetSearchStatus();
			InitFlg = true;
		}

		//ステージの描画
		//DrawGraph(0, 30, image.g_StageImage, TRUE);
		//a_star.A_starInit();
		stage.DrawMap();
		g_player.PlayerController();
		//a_star.main(int plX, int plY, int enX, int enY);
		a_star.main(/*g_player.PXC, g_player.PYC, g_enemy.EXC, g_enemy.EYC*/);
		g_enemy.MapCopy();
		g_enemy.EnemyController();
		//a_star.main(/*g_player.PXC, g_player.PYC, g_enemy2.EXC, g_enemy2.EYC*/);
		//g_enemy2.MapCopy();
		//g_enemy2.EnemyController();
		//DrawPixel(g_player.PX, g_player.PY, 0xff00ff);
		//DrawBox(g_player.PX, g_player.PY, 1000, 200, 0xff00ff, false);
		
		
	

		//裏画面の内容を表画面に反映
		ScreenFlip();

		if (keyFlg == 1024) DxLib_End();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
#include "DxLib.h"
#include "Stage.h"
#include "Image.h"
#include"Common.h"
#include "Player.h"
#include"Title.h"
#include"Fps.h"

int	oldKey;				// 前回の入力キー
int	nowKey;				// 今回の入力キー
int	keyFlg;				// 入力キー情報

int g_State;

int destroyFlg;

//メイン
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("パックマン");       //タイトルを設定
	ChangeWindowMode(TRUE);                //ウィンドウモードで起動
	SetGraphMode(1280, 720, 32);
	if (DxLib_Init() == -1) return -1;     //DXライブラリの初期化処理
	SetDrawScreen(DX_SCREEN_BACK);         //描画先画面を裏にする

	if (image.LoadImages() == -1)return -1;
	Fps fps;

	//ゲームループ              
	while (ProcessMessage() == 0)
	{
		oldKey = nowKey;
		nowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		keyFlg = nowKey & ~oldKey;

		fps.Update();

		//画面の初期化
		ClearDrawScreen();
		if (title.g_GameTitleFlg == FALSE) {
			title.DrawTitle();
		}
		//ステージの描画
		//DrawGraph(0, 30, image.g_StageImage, TRUE);
		else if(destroyFlg==FALSE){
			stage.DrawMap();
			g_player.PlayerController();
			DrawPixel(g_player.PX, g_player.PY, 0xff00ff);
			DrawBox(g_player.PX, g_player.PY, 1000, 200, 0xff00ff, false);

			DrawFormatString(50, 50, 0xFFFFFF, "%d", DRAW_POINT_X);
			DrawFormatString(50, 100, 0xFFFFFF, "%d", DRAW_POINT_Y);
			if (keyFlg & PAD_INPUT_A) {
				destroyFlg = true;
			}
		}
		else {
			g_player.PlayerDestroy();
		}
		//裏画面の内容を表画面に反映
		ScreenFlip();
		fps.Wait();

		if (keyFlg == 1024) DxLib_End();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
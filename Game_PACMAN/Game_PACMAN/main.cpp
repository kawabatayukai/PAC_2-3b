#include "DxLib.h"
#include "Stage.h"
#include "Image.h"

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
		//画面の初期化
		ClearDrawScreen();

		//ステージの描画
		//DrawGraph(0, 30, image.g_StageImage, TRUE);
		stage.DrawMap();
		
	

		//裏画面の内容を表画面に反映
		ScreenFlip();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
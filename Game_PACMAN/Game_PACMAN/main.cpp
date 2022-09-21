#include "DxLib.h"
#include"coffebrake.h"


//メイン
int oldKey;				// 前回の入力キー
int nowKey;				// 今回の入力キー
int keyFlg;				// 入力キー情報

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	oldKey = nowKey;
	nowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	keyFlg = nowKey & ~oldKey;
	SetMainWindowText("パックマン");       //タイトルを設定
	ChangeWindowMode(TRUE);                //ウィンドウモードで起動
	SetGraphMode(1280, 720, 32);
	if (DxLib_Init() == -1) return -1;     //DXライブラリの初期化処理
	SetDrawScreen(DX_SCREEN_BACK);         //描画先画面を裏にする
          
	//ゲームループ              
	while (ProcessMessage() == 0)
	{
		//coffebrake
		animasion_Initialize();
		animasion1();
		animasion2();
		animasion3();

		////裏画面の内容を表画面に反映
		ScreenFlip();

		if (keyFlg == 1024) DxLib_End();
	}


	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}


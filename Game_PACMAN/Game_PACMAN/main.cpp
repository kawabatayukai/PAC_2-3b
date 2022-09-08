#include "DxLib.h"
#include "Stage.h"
#include "Image.h"

//ゲームステート列挙体
enum class GAME_STATE
{
	DRAW_TITLE = 0,     //タイトル
	GAME_INIT,          //初期処理
	GAME_MAIN,          //メイン
	GAME_CLEAR,         //ゲームクリア
	GAME_OVER,          //ゲームオーバー
	GAME_END = 99       //ゲーム終了
};


//変数
GAME_STATE g_GameState;  //ゲームステート
int g_OldKey;            // 前回の入力キー 
int g_NowKey;            // 今回の入力キー 
int g_KeyFlg;            // 入力キー情報  

//関数
void DrawGameTitle();    //タイトル描画
void GameInit();         //初期処理
void GameMain();         //メイン
void DrawGameClear();    //ゲームクリア描画
void DrawGameOver();     //ゲームオーバー描画

//メイン
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("パックマン");       //タイトルを設定
	ChangeWindowMode(TRUE);                //ウィンドウモードで起動
	SetGraphMode(1280, 720, 32);
	if (DxLib_Init() == -1) return -1;     //DXライブラリの初期化処理
	SetDrawScreen(DX_SCREEN_BACK);         //描画先画面を裏にする

	if (image.LoadImages() == -1)return -1;//画像読み込み



	//ゲームループ              
	while (ProcessMessage() == 0)
	{
		//画面の初期化
		ClearDrawScreen();
		//キー入力取得 
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1); 
		g_KeyFlg = g_NowKey & ~g_OldKey;


		switch (g_GameState)
		{
		case GAME_STATE::DRAW_TITLE:

			DrawGameTitle();  //タイトル
			break;

		case GAME_STATE::GAME_INIT:

			GameInit();       //初期処理
			break;

		case GAME_STATE::GAME_MAIN:

			GameMain();       //ゲームメイン
			break;

		case GAME_STATE::GAME_CLEAR:

			DrawGameClear();  //ゲームクリア描画
			break;

		case GAME_STATE::GAME_OVER:

			DrawGameOver();   //ゲームオーバー描画
			break;

		default:
			break;
		}


		//裏画面の内容を表画面に反映
		ScreenFlip();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}


//タイトル描画
void DrawGameTitle()
{

	//初期処理へ
	g_GameState = GAME_STATE::GAME_INIT;
}

//初期処理
void GameInit()
{

	//ゲームメインへ
	g_GameState = GAME_STATE::GAME_MAIN;
}

//ゲームメイン
void GameMain()
{

	//ステージの描画
	stage.DrawMap();
}

//ゲームクリア
void DrawGameClear()
{

}

//ゲームオーバー
void DrawGameOver()
{

}
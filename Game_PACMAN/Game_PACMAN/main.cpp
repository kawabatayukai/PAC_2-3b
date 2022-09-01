#include "DxLib.h"
#include "Stage.h"
#include "Image.h"

#include"Pink.h"
#include"Red.h"
#include"TestPlayer.h"

int	g_OldKey;				// 前回の入力キー
int	g_NowKey;				// 今回の入力キー
int	g_KeyFlg;				// 入力キー情報

//初期化
void GameInit();

//2次元配列を戻り値にしたかった
int MapData2[MAP_HEIGHT][MAP_WIDTH] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
	{1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1,0,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,},
	{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,},
	{1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,},
	{0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,},
	{0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,0,0,},
	{1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,},
	{0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,},
	{1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,},
	{0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,0,0,},
	{0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,},
	{1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,},
	{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
	{1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,},
	{1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,},
	{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,},
	{1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
};

//メイン
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("パックマン");       //タイトルを設定
	ChangeWindowMode(TRUE);                //ウィンドウモードで起動
	SetGraphMode(1280, 720, 32);
	if (DxLib_Init() == -1) return -1;     //DXライブラリの初期化処理
	SetDrawScreen(DX_SCREEN_BACK);         //描画先画面を裏にする

	if (image.LoadImages() == -1)return -1;
	GameInit();  //初期処理

	//ゲームループ              
	while (ProcessMessage() == 0)
	{
		// 入力キー取得
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		//画面の初期化
		ClearDrawScreen();

		//ステージの描画
		//DrawGraph(0, 30, image.g_StageImage, TRUE);
		stage.DrawMap();

		Red.TargetCtrl(Player.GetPlayerX(), Player.GetPlayerY(), Player.GetPlayerD()); //ターゲットを設定
		Red.MoveEnemy2(MapData2);                                 //ターゲットに基づく移動
		Red.DrawEnemy();                                          //敵描画

		Pink.TargetCtrl(Player.GetPlayerX(), Player.GetPlayerY(), Player.GetPlayerD()); //ターゲットを設定
		Pink.MoveEnemy2(MapData2);                                 //ターゲットに基づく移動
		Pink.DrawEnemy();                                          //敵描画

		if (g_NowKey & PAD_INPUT_M) Red.SetSortie();
		if (g_NowKey & PAD_INPUT_A) Red.InitEnemy();

		if (g_NowKey & PAD_INPUT_M) Pink.SetSortie();
		if (g_NowKey & PAD_INPUT_A) Pink.InitEnemy();

		Player.MovePlayer(g_NowKey, MapData2); //プレイヤー移動テスト
		Player.DrawPlayer();                  //プレイヤー描画

		//裏画面の内容を表画面に反映
		ScreenFlip();
	}

	DxLib::DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

//初期化
void GameInit()
{
	Red.InitEnemy();    //赤初期化
	Pink.InitEnemy();   //ピンク初期化
	Player.PlayerInit(); //テストプレイヤー初期化
}
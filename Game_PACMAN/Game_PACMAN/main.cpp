#include "DxLib.h"
#include"pink.h"
#include"red.h"
#include"blue.h"
#include"orange.h"

#include"NewPlayer.h"
#include"Info.h"
#include"Display.h"
#include"Bait.h"
#include"Stage.h"

//変数
int	g_OldKey;				// 前回の入力キー
int	g_NowKey;				// 今回の入力キー
int	g_KeyFlg;				// 入力キー情報

int ClearCount = 0;         //クリア回数　ファイル分け対象

int g_GameTitleImage = 0;
GAME_STATE g_GameState = GAME_STATE::DRAW_TITLE;

//関数
void DrawGameTitle();    //タイトル描画
void GameInit();         //初期処理
void GameStarter();      //スタート（READY!）
void GameMain();         //メイン
void DrawGameClear();    //ゲームクリア描画
void DrawGameOver();     //ゲームオーバー描画
int LoadImages();        //画像読み込み
int LoadSounds();        //音声読み込み

void NewGameMain();

/********* ～ テスト用マップ ～ *********/


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

int MapData3[MAP_HEIGHT][MAP_WIDTH] =
{
	//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	//{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,},
	//{0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,},
	//{0,0,0,1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,0,0,},
	//{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,},
	//{0,0,0,1,0,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,0,0,0,},
	//{0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,},
	//{0,0,0,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,0,0,0,},
	//{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,},
	//{0,0,0,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,0,0,0,0,0,},
	//{0,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,0,0,0,},
	//{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
	//{0,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,0,0,0,},
	//{0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,0,0,},
	//{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,},
	//{0,0,0,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,0,0,0,},
	//{0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,},
	//{0,0,0,1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,0,0,},
	//{0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,},
	//{0,0,0,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,0,0,0,},
	//{0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,},
	//{0,0,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,0,0,},
	//{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,},
	//{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,},
	//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,},
	{1,1,1,1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,1,1,1,},
	{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,},
	{1,1,1,1,0,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,1,1,},
	{1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,},
	{1,1,1,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,},
	{1,1,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,1,1,},
	{1,1,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,0,0,1,1,1,},
	{1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,},
	{1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,},
	{1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,},
	{1,1,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,0,0,1,1,1,},
	{1,1,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,1,1,},
	{1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,},
	{1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,},
	{1,1,1,1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,1,1,1,},
	{1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,},
	{1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,},
	{1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,},
	{1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,},
	{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
};

//map上の"〇マス目"をウィンドウ上の座標に変換
int MapPointX(int mapX) { return mapX * MAP_SIZE; }
int MapPointY(int mapY) { return mapY * MAP_SIZE; }


//描画
void DrawMap()
{
	//DrawFormatString(0, 40, 0xffffff, "%d", DRAW_POINT_X);
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			int x = MapPointX(j) + DRAW_POINT_X;
			int y = MapPointY(i) + DRAW_POINT_Y;
			if (MapData3[i][j] == 1 && i > 2 && j > 2)
			{
				DrawBox(x, y, (x + MAP_SIZE), (y + MAP_SIZE), 0x00ff00, TRUE);
			}
			SetFontSize(12);
			if (i == 0) DrawFormatString(x + 5, y + 5, 0xffffff, "%d", j);
			if (j == 0) DrawFormatString(x + 5, y + 5, 0xffffff, "%d", i);

			if (j == 23) break;
		}
		if (i == 25) break;
	}
}

/****************************************/

//マス
void DrawSquare()
{
	int x1 = 0;
	int x2 = 0;
	int y1 = DRAW_POINT_Y;
	int y2 = DRAW_POINT_Y + (MAP_SIZE * MAP_HEIGHT);

	for (int i = 0; i < MAP_WIDTH + 1; i++)
	{
		x1 = i * MAP_SIZE + DRAW_POINT_X;
		x2 = x1;
		DrawLine(x1, y1, x2, y2, 0xffffff);
	}

	x1 = DRAW_POINT_X;
	x2 = DRAW_POINT_X + (MAP_SIZE * MAP_WIDTH);
	y1 = 0;
	y2 = 0;

	for (int j = 0; j < MAP_HEIGHT + 1; j++)
	{
		y1 = j * MAP_SIZE + DRAW_POINT_Y;
		y2 = y1;
		DrawLine(x1, y1, x2, y2, 0xffffff);
	}
}

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("パックマン");       //タイトルを設定
	ChangeWindowMode(TRUE);                //ウィンドウモードで起動
	SetGraphMode(1280, 720, 32);
	if (DxLib_Init() == -1) return -1;     //DXライブラリの初期化処理
	SetDrawScreen(DX_SCREEN_BACK);         //描画先画面を裏にする

	//画像読み込み
	if (LoadImages() == -1) return -1;
	//音声読み込み
	if (LoadSounds() == -1) return -1;

	while (ProcessMessage() == 0 && !(g_KeyFlg & PAD_INPUT_START))
	{
		// 入力キー取得
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		//画面初期処理
		ClearDrawScreen();

		switch (g_GameState)
		{
		case GAME_STATE::DRAW_TITLE:
			DrawGameTitle();

			break;

		case GAME_STATE::GAME_INIT:

			GameInit();       //初期処理
			break;

		case GAME_STATE::GAME_START:

			GameStarter();    //スタート時
			break;

		case GAME_STATE::GAME_MAIN:

			NewGameMain();       //ゲームメイン
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

	DxLib::DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

//タイトル描画
void DrawGameTitle()
{
	DrawGraph(150, 30, g_GameTitleImage, FALSE);

	SetFontSize(40);
	SetFontThickness(9);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	DrawString(500, 360, "GAME START", 0xffffff);
	if (g_NowKey & PAD_INPUT_A) {
		g_GameState = GAME_STATE::GAME_INIT;
	}
}

//初期処理
void GameInit()
{
	//すべてのEnemyを初期化 親クラスENEMY_BASEの静的メンバ関数
	ENEMY_BASE::AllEnemyInit();

	g_player.PlayerInit();
	Disp.DispInit();
	bait.CreateBait();
	stage.StageInit();

	g_GameState = GAME_STATE::GAME_START;
}

//スタート時
void GameStarter()
{
	DrawMap();
	Disp.DrawStartDisp(&g_GameState, &Pink);

	//g_GameState = GAME_STATE::GAME_MAIN;
}

//ゲームメイン
void GameMain()
{
	////アカ
	//Red.TargetCtrl(BasePlayer.GetPlayerX(), BasePlayer.GetPlayerY(), BasePlayer.GetPlayerD()); //ターゲットを設定
	//Red.MoveEnemy2(MapData2);                                 //ターゲットに基づく移動
	//Red.DrawEnemy();                                          //敵描画                                         //敵描画


	////ピンク
	//Pink.TargetCtrl(BasePlayer.GetPlayerX(), BasePlayer.GetPlayerY(), BasePlayer.GetPlayerD()); //ターゲットを設定
	//Pink.MoveEnemy2(MapData2);                                 //ターゲットに基づく移動
	//Pink.DrawEnemy();                                          //敵描画                                         //敵描画

	////アオ
	//Blue.TargetCtrl(BasePlayer.GetPlayerX(), BasePlayer.GetPlayerY(), BasePlayer.GetPlayerD()); //ターゲットを設定
	//Blue.MoveEnemy2(MapData2);                                 //ターゲットに基づく移動
	//Blue.DrawEnemy();

	////オレンジ
	//Orange.TargetCtrl(BasePlayer.GetPlayerX(), BasePlayer.GetPlayerY(), BasePlayer.GetPlayerD()); //ターゲットを設定
	//Orange.MoveEnemy2(MapData2);                                 //ターゲットに基づく移動
	//Orange.DrawEnemy();

	//ENEMY_BASE::SoltieControl(g_KeyFlg, bait.GetBaitCount(), ClearCount);

	//if (g_NowKey & PAD_INPUT_2) Pink.SetEnemyMode(MODE::EYE);
	//if (g_NowKey & PAD_INPUT_A) Pink.InitEnemy();

	//if (g_NowKey & PAD_INPUT_2) Red.SetIjike();
	//if (g_NowKey & PAD_INPUT_A) Red.InitEnemy();

	//if (g_NowKey & PAD_INPUT_2) Orange.SetIjike();
	//if (g_NowKey & PAD_INPUT_A) Orange.InitEnemy();

	//if (g_NowKey & PAD_INPUT_2) Blue.SetIjike();
	//if (g_NowKey & PAD_INPUT_A) Blue.InitEnemy();


	//ENEMY_BASE::DrawAllInfo();
	//DrawString(30, 300, "スペースキーを押すごとに出撃", 0x00faff);
	////DrawString(30, 320, "8秒間は巡回モード", 0x00faff);
	////DrawString(30, 340, "巡回後20秒間追跡", 0x00faff);

	//BasePlayer.MovePlayer(g_NowKey, MapData2); //プレイヤー移動テスト
	//BasePlayer.DrawPlayer();                  //プレイヤー描画
	////g_player.PlayerController(g_KeyFlg, MapData2);

	//bait.BaitController(BasePlayer.GetPlayerX(), BasePlayer.GetPlayerY());
	////bait.BaitController(g_player.GetPlayerX(), g_player.GetPlayerY());

	//DrawMap();                         //マップ描画テスト
	//DrawSquare();

}

void NewGameMain()
{
	//エサの移動・描画を管理
	bait.BaitController(g_player.GetPlayerX() + DRAW_POINT_X, g_player.GetPlayerY() + DRAW_POINT_Y);

	//フルーツの出現
	stage.DrawFruit(bait.GetBaitCount(), ClearCount);

	//プレイヤーの移動・描画を管理
	g_player.PlayerController(g_KeyFlg, MapData3);

	//アカ
	Red.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //ターゲットを設定
	Red.MoveEnemy2(MapData3);                                 //ターゲットに基づく移動
	Red.DrawEnemy();                                          //敵描画                                         

	//ピンク
	Pink.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //ターゲットを設定
	Pink.MoveEnemy2(MapData3);                                 //ターゲットに基づく移動
	Pink.DrawEnemy();                                          //敵描画                                         //敵描画

	//アオ
	Blue.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //ターゲットを設定
	Blue.MoveEnemy2(MapData3);                                 //ターゲットに基づく移動
	Blue.DrawEnemy();

	//オレンジ
	Orange.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //ターゲットを設定
	Orange.MoveEnemy2(MapData3);                                 //ターゲットに基づく移動
	Orange.DrawEnemy();

	//if (g_NowKey & PAD_INPUT_2) Pink.SetEnemyMode(MODE::EYE);

	//if (g_NowKey & PAD_INPUT_2) Red.SetIjike();

	//if (g_NowKey & PAD_INPUT_2) Orange.SetIjike();

	//if (g_NowKey & PAD_INPUT_2) Blue.SetIjike();

	ENEMY_BASE::IjikeControl(bait.GetPowerFlg());  //イジケ状態を管理

	ENEMY_BASE::SoltieControl(g_KeyFlg, bait.GetBaitCount(), ClearCount);  //敵の出撃を管理
	ENEMY_BASE::DrawAllInfo();            //敵の情報を表示

	DrawFormatString(30, 320, 0xffffff, "playerX : %d", g_player.GetPlayerX());
	DrawFormatString(30, 340, 0xffffff, "playerY : %d", g_player.GetPlayerY());




	DrawMap();                         //マップ描画テスト
	DrawSquare();                      //テスト用　枠表示

	//テスト　クリア処理
	if (bait.GetBaitCount() == BAIT_MAX)
	{
		ClearCount++;
		g_GameState = GAME_STATE::GAME_CLEAR;
	}
}

//ゲームクリア
void DrawGameClear()
{

	static int timer;
	DrawMap();                         //マップ描画テスト

	//テスト　3秒で次へ
	if (++timer > 180)
	{
		g_GameState = GAME_STATE::GAME_INIT;
		timer = 0;
	}
}

//ゲームオーバー
void DrawGameOver()
{
	DrawMap();
	Disp.DrawOverDisp(&g_GameState);
}

//画像読み込み
int LoadImages()
{
	if ((Red.Loadimages()) == -1) return -1;
	if ((Pink.Loadimages()) == -1) return -1;
	if ((Blue.Loadimages()) == -1) return -1;
	if ((Orange.Loadimages()) == -1) return -1;

	if ((g_player.LoadImages()) == -1) return -1;
	if ((Disp.LoadImages()) == -1) return -1;
	if ((bait.LoadImages()) == -1) return -1;
	if ((stage.LoadImages()) == -1) return -1;

	if ((g_GameTitleImage = LoadGraph("images/PAC-MAN_Classic_Logo.png")) == -1)return -1;

	return 0;
}

//音声読み込み
int LoadSounds()
{
	if ((Disp.LoadSounds()) == -1) return -1;
}

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

#include"Enemy_Red.h"
#include"display.h"
//#include"A_star.h"
//#include"A_star_PINKY.h"
//#include"A_star_INKY.h"
//#include"A_star_CLYDE.h"
#include"coffeebreak.h"
#include"Enemy.h"

//変数
int	g_OldKey;				// 前回の入力キー
int	g_NowKey;				// 今回の入力キー
int	g_KeyFlg;				// 入力キー情報

int ClearCount = 0;         //クリア回数　ファイル分け対象

int g_GameTitleImage = 0;
GAME_STATE g_GameState = GAME_STATE::DRAW_TITLE;

int InitFlg = false;

//関数
void DrawGameTitle();    //タイトル描画
void GameInit();         //初期処理
void GameStarter();      //スタート（READY!）
void GameMain();         //メイン
void DrawGameClear();    //ゲームクリア描画
void DrawGameOver();     //ゲームオーバー描画
void DrawCoffee();
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

		case GAME_STATE::COFFEE:
			DrawCoffee();     //コーヒーブレイク
			break;

		default:
			break;
		}


		//裏画面の内容を表画面に反映
		ScreenFlip();

		//if (keyFlg == 1024) DxLib_End();
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
		ClearCount = 0;
		stage.FruitCount = 0;
		g_player.LifeUPFlg = false;
		InitFlg = false;
		g_GameState = GAME_STATE::GAME_INIT;
	}
}

//初期処理
void GameInit()
{
	//すべてのEnemyを初期化 親クラスENEMY_BASEの静的メンバ関数
	EnemyManager->AllEnemyInit(ClearCount);

	g_player.PlayerInit();
	Disp.DispInit();
	bait.CreateBait();
	stage.StageInit();
	/*a_star.A_starInit();
	a_star_pink.A_starInit();
	a_star_inky.A_starInit();
	a_star_clyde.A_starInit();*/
	g_enemy_Red.EnemyInit();

	g_GameState = GAME_STATE::GAME_START;
}

//スタート時
void GameStarter()
{
	stage.DrawMapImageV3();
	//DrawMap();
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
	//敵の当たり判定はStageに
	if (stage.HitCircle() == true/* || g_KeyFlg & PAD_INPUT_A*/)
	{
		g_player.PlayerDestroyFlg = true;
		if (g_player.PlayerDestroyFlg == true) {
			g_GameState = GAME_STATE::GAME_OVER;
		}
	}

	stage.DrawMapImageV3();
	stage.DrawMapScore(ClearCount);
	//エサの移動・描画を管理
	bait.BaitController(g_player.GetPlayerX() + DRAW_POINT_X, g_player.GetPlayerY() + DRAW_POINT_Y);

	//フルーツの出現
	//stage.DrawFruit(bait.GetBaitCount(), ClearCount);
	stage.FruitControl(ClearCount, bait.GetBaitCount());
	stage.DrawFruit(ClearCount);

	//プレイヤーの移動・描画を管理
	g_player.PlayerController(g_KeyFlg, MapData3);

	//アカ
	Red.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //ターゲットを設定
	if (Red.GetEnemyMode() == TRACK) //{
		Red.main();
		Red.MapCopy();
	//}
	//Red.EnemyController();
	Red.DrawEnemy();                                          //敵描画 
	Red.MoveEnemy2(MapData3);                                 //ターゲットに基づく移動
	//イジケの時食われる
	Red.Eaten_OnIjike((float)g_player.GetPlayerX(), (float)g_player.GetPlayerY(), 6.5f, stage.Score);

	/*DrawFormatString(1100, 700, 0xffffff, "%d", Red.EXC);
	DrawFormatString(1130, 700, 0xffffff, "%d", Red.EYC);
	DrawFormatString(1100, 650, 0xffffff, "%d", Red.EX);
	DrawFormatString(1130, 650, 0xffffff, "%d", Red.EY);
	DrawFormatString(1190, 650, 0xffffff, "%d", Red.GetEnemyX());
	DrawFormatString(1190, 650, 0xffffff, "%d", Red.GetEnemyY());
	DrawCircle(g_player.PX, g_player.PY, 14.5f, GetColor(125, 125, 125));*/
	//for (int i = 0; i < 27; i++) {
	//	for (int j = 0; j < 29; j++) {
	//		if (Red.MapData[j][i] == 1) {
	//			DrawFormatString(10 + (i * 20), 20 + (j * 20), 0xff0000, "%d", Red.MapData[j][i]);
	//		}
	//		else if (Red.MapData[j][i] == 0) {
	//			DrawFormatString(10 + (i * 20), 20 + (j * 20), 0xffffff, "%d", Red.MapData[j][i]);
	//		}
	//		else if (Red.MapData[j][i] == 2) {
	//			DrawFormatString(10 + (i * 20), 20 + (j * 20), 0xff00ff, "%d", Red.MapData[j][i]);
	//		}
	//		else {
	//			DrawFormatString(10 + (i * 20), 20 + (j * 20), 0x0000ff, "%d", Red.MapData[j][i]);
	//		}
	//		//DrawFormatString(10 + (i * 30), 20 + (j * 30), 0xffffff, "%d" ,stage.getMap[j][i]);
	//	}
	//}

	//ピンク
	Pink.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //ターゲットを設定
	if (Pink.GetEnemyMode() == TRACK) Pink.main();
		Pink.MapCopy();
	Pink.DrawEnemy();                                          //敵描画                                         //敵描画
	Pink.MoveEnemy2(MapData3);                                 //ターゲットに基づく移動
	//イジケの時食われる
	Pink.Eaten_OnIjike((float)g_player.GetPlayerX(), (float)g_player.GetPlayerY(), 6.5f, stage.Score);

	//アオ
	Blue.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //ターゲットを設定
	if (Blue.GetEnemyMode() == TRACK) Blue.main();
		Blue.MapCopy();
	Blue.DrawEnemy();
	Blue.MoveEnemy2(MapData3);                                 //ターゲットに基づく移動
	//イジケの時食われる
	Blue.Eaten_OnIjike((float)g_player.GetPlayerX(), (float)g_player.GetPlayerY(), 6.5f, stage.Score);

	//オレンジ
	Orange.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //ターゲットを設定
	if (Orange.GetEnemyMode() == TRACK) Orange.main();
		Orange.MapCopy();
	Orange.DrawEnemy();
	Orange.MoveEnemy2(MapData3);                                 //ターゲットに基づく移動
	//イジケの時食われる
	Orange.Eaten_OnIjike((float)g_player.GetPlayerX(), (float)g_player.GetPlayerY(), 6.5f, stage.Score);

	
	
	
	

	ENEMY_BASE::IjikeControl(bait.GetPowerFlg());  //イジケ状態を管理

	ENEMY_BASE::SoltieControl(g_KeyFlg, bait.GetBaitCount(), ClearCount);  //敵の出撃を管理
	ENEMY_BASE::DrawAllInfo();            //敵の情報を表示

	DrawFormatString(30, 320, 0xffffff, "playerX : %d", g_player.GetPlayerX());
	DrawFormatString(30, 340, 0xffffff, "playerY : %d", g_player.GetPlayerY());

	if (g_KeyFlg & PAD_INPUT_A) {
		stage.Score += 1000;
	}
	if (stage.HScore < stage.Score)stage.HScore = stage.Score;

	//DrawMap();                         //マップ描画テスト
	//DrawSquare();                      //テスト用　枠表示

	//テスト　クリア処理
	if (bait.GetBaitCount() == BAIT_MAX || g_KeyFlg & PAD_INPUT_A)
	{
		ClearCount++;
		//ClearCount+=15;
		//g_GameState = GAME_STATE::GAME_INIT;
		g_GameState = GAME_STATE::GAME_CLEAR;
	}

	////敵の当たり判定はStageに
	//if (stage.HitCircle() == true/* || g_KeyFlg & PAD_INPUT_A*/)
	//{
	//	g_player.PlayerDestroyFlg = true;
	//	if (g_player.PlayerDestroyFlg == true) {
	//		g_GameState = GAME_STATE::GAME_OVER;
	//	}
	//}
}

//ゲームクリア
void DrawGameClear()
{

	static int timer;
	//DrawMap();                         //マップ描画テスト

	//テスト　3秒で次へ
	/*if (++timer > 180)
	{
		g_GameState = GAME_STATE::GAME_INIT;
		timer = 0;
	}*/
	stage.DrawMapImageV3();
	DrawGraph(g_player.PX - 15, g_player.PY - 15, Disp.PacManImage[g_player.PacMan_index + g_player.PacMan_dir * 3], TRUE);
	if (timer++ <= 280) {
		if (timer >= 80)stage.flashingMapImageV3();
		DrawGraph(g_player.PX - 15, g_player.PY - 15, Disp.PacManImage[g_player.PacMan_index + g_player.PacMan_dir * 3], TRUE);
	}
	else {
		timer = 0;
		g_GameState = GAME_STATE::COFFEE;
		//g_GameState = GAME_STATE::GAME_INIT;
	}

}

//ゲームオーバー
void DrawGameOver()
{
	//DrawMap();
	stage.DrawMapImageV3();
	if (InitFlg == false) {
		static int Timer = 0;
		Timer++;
		if (Timer < 60) {//1秒間静止
			Red.DrawEnemy();
			Pink.DrawEnemy();
			Blue.DrawEnemy();
			Orange.DrawEnemy();
			DrawGraph(g_player.PX - 15, g_player.PY - 15, Disp.PacManImage[g_player.PacMan_index + g_player.PacMan_dir * 3], TRUE);
		}
		else if (Timer <= 180) {//2秒間アニメーション
			g_player.PlayerDestroy();
		}
		else {
			g_player.PacManDamage_wait = 0;
			Timer = 0;
			InitFlg = true;
		}
	}
	else if (InitFlg == true) {
		if (g_player.Life >= 0) {//残機あり
			g_player.Life--;
			stage.oldLife = g_player.Life;
			//すべてのEnemyを初期化 親クラスENEMY_BASE型ポインタ
			EnemyManager->AllEnemyInit(ClearCount);
			g_player.PlayerInit();
			g_player.Life = stage.oldLife;
			InitFlg = false;
			g_player.PlayerDestroyFlg = false;
			g_GameState = GAME_STATE::GAME_START;
		}
		else {//残機なし
			stage.Score = 0;
			Disp.DrawOverDisp(&g_GameState);//ゲームオーバー画面
		}
	}
}

//コーヒーブレイク
void DrawCoffee()
{
	//アニメーション  2,5,9,13,17
	if (ClearCount == 2) animasion1();   //
	if (ClearCount == 5) animasion1();
	if (ClearCount == 9) animasion1();
	if (ClearCount == 13) animasion1();
	if (ClearCount == 17) animasion1();
	g_GameState = GAME_STATE::GAME_INIT;
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

	animasion_Initialize();

	if ((g_GameTitleImage = LoadGraph("images/PAC-MAN_Classic_Logo.png")) == -1)return -1;

	return 0;
}

//音声読み込み
int LoadSounds()
{
	if ((Disp.LoadSounds()) == -1) return -1;
}

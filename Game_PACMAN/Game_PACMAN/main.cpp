#include "DxLib.h"
#include "Stage.h"
#include "Image.h"

#include"Red.h"
#include"Pink.h"
#include"Blue.h"
#include"Orange.h"
#include"NewPlayer.h"

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

int MapData2[MAP_HEIGHT][MAP_WIDTH] =
{
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,},
{0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,},
{0,0,0,1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,0,0,},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,},
{0,0,0,1,0,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,0,0,0,},
{0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,},
{0,0,0,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,0,0,0,},
{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,},
{0,0,0,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,0,0,0,0,0,},
{0,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,0,0,0,},
{0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,0,0,},
{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,},
{0,0,0,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,0,0,0,},
{0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,},
{0,0,0,1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,0,0,},
{0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,},
{0,0,0,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,0,0,0,},
{0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,},
{0,0,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,0,0,},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,},
{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
};


//メイン
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("パックマン");       //タイトルを設定
	ChangeWindowMode(TRUE);                //ウィンドウモードで起動
	SetGraphMode(1280, 720, 32);
	if (DxLib_Init() == -1) return -1;     //DXライブラリの初期化処理
	SetDrawScreen(DX_SCREEN_BACK);         //描画先画面を裏にする

	if (image.LoadImages() == -1)return -1;//画像読み込み
	if ((Red.Loadimages()) == -1) return -1;
	if ((Pink.Loadimages()) == -1) return -1;
	if ((Blue.Loadimages()) == -1) return -1;
	if ((Orange.Loadimages()) == -1) return -1;

	if ((g_player.LoadImages()) == -1) return -1;


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
	//すべてのEnemyを初期化 親クラスENEMY_BASEの静的メンバ関数
	ENEMY_BASE::AllEnemyInit();

	g_player.PlayerInit();

	//ゲームメインへ
	g_GameState = GAME_STATE::GAME_MAIN;
}

//ゲームメイン
void GameMain()
{
	//アカ
	//Red.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //ターゲットを設定
	//Red.MoveEnemy2(MapData2);                                 //ターゲットに基づく移動
	//Red.DrawEnemy();                                          //敵描画                                         //敵描画


	//ピンク
	Pink.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //ターゲットを設定
	Pink.MoveEnemy2(MapData2);                                 //ターゲットに基づく移動
	Pink.DrawEnemy();                                          //敵描画                                         //敵描画

	////アオ
	//Blue.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //ターゲットを設定
	//Blue.MoveEnemy2(MapData2);                                 //ターゲットに基づく移動
	//Blue.DrawEnemy();

	////オレンジ
	//Orange.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //ターゲットを設定
	//Orange.MoveEnemy2(MapData2);                                 //ターゲットに基づく移動
	//Orange.DrawEnemy();

	//ENEMY_BASE::SoltieControl(g_KeyFlg);
	if (g_NowKey & PAD_INPUT_M) Pink.SetSortie();
	if (g_NowKey & PAD_INPUT_2) Pink.SetEnemyMode(MODE::EYE);
	if (g_NowKey & PAD_INPUT_A) Pink.InitEnemy();

	if (g_NowKey & PAD_INPUT_M) Red.SetSortie();
	if (g_NowKey & PAD_INPUT_2) Red.SetIjike();
	if (g_NowKey & PAD_INPUT_A) Red.InitEnemy();

	if (g_NowKey & PAD_INPUT_M) Orange.SetSortie();
	if (g_NowKey & PAD_INPUT_2) Orange.SetIjike();
	if (g_NowKey & PAD_INPUT_A) Orange.InitEnemy();

	if (g_NowKey & PAD_INPUT_M) Blue.SetSortie();
	if (g_NowKey & PAD_INPUT_2) Blue.SetIjike();
	if (g_NowKey & PAD_INPUT_A) Blue.InitEnemy();

	//if (g_NowKey & PAD_INPUT_M) DrawString(0, 0, "SSSSSSSS", 0xffffff);

	ENEMY_BASE::DrawAllInfo();
	DrawString(30, 300, "スペースキーを押すごとに出撃", 0x00faff);
	DrawString(30, 320, "8秒間は巡回モード", 0x00faff);
	DrawString(30, 340, "巡回後20秒間追跡", 0x00faff);


	g_player.PlayerController(g_KeyFlg, MapData2);
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
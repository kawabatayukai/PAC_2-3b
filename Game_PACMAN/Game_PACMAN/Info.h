#pragma once

#define SCREEN_WIDTH  1280 //スクリーン幅
#define SCREEN_HEIGHT  720 //スクリーン高さ

//#define MAP_WIDTH  21    //Map X方向のチップ数
//#define MAP_HEIGHT  23   //Map Y方向のチップ数
#define MAP_WIDTH   27    //Map X方向のチップ数
#define MAP_HEIGHT  29   //Map Y方向のチップ数

#define MAP_SIZE  30     //Map 一つのチップのサイズ (20 * 20)

//#define PLUS_MAP 3

//描画開始位置(スクリーンサイズ - ステージ全体の幅/高さ / ２)
//#define DRAW_POINT_X  330//(SCREEN_WIDTH - (MAP_WIDTH * MAP_SIZE)) / 2   = 330
#define DRAW_POINT_X  (SCREEN_WIDTH - (MAP_WIDTH * MAP_SIZE)) / 2    //= 
#define DRAW_POINT_Y  (SCREEN_HEIGHT - (MAP_HEIGHT * MAP_SIZE)) / 2  //= 

//ゲームステート
enum class GAME_STATE
{
	DRAW_TITLE = 0,     //タイトル
	GAME_INIT,          //初期処理
	GAME_START,         //スタート時(READY!)
	GAME_MAIN,          //メイン
	GAME_CLEAR,         //ゲームクリア
	GAME_OVER,          //ゲームオーバー(GAME OVER)
	COFFEE,
	GAME_END = 99       //ゲーム終了
};

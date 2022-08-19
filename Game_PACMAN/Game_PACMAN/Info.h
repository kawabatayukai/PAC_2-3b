#pragma once

#define SCREEN_WIDTH  1280 //スクリーン幅
#define SCREEN_HEIGHT  720 //スクリーン高さ

#define MAP_WIDTH  31    //Map X方向のチップ数
#define MAP_HEIGHT  33   //Map Y方向のチップ数
#define MAP_SIZE  20     //Map 一つのチップのサイズ (20 * 20)

//描画開始位置(スクリーンサイズ - ステージ全体の幅/高さ / ２)
#define DRAW_POINT_X  330  //(SCREEN_WIDTH - (MAP_WIDTH * MAP_SIZE)) / 2   = 330
#define DRAW_POINT_Y  33   //(SCREEN_HEIGHT - (MAP_HEIGHT * MAP_SIZE)) / 2  = 30


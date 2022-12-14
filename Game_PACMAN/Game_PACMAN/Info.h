#pragma once

#define SCREEN_WIDTH  1280 //スクリーン幅
#define SCREEN_HEIGHT  720 //スクリーン高さ

#define MAP_WIDTH   27     //Map X方向のチップ数              
#define MAP_HEIGHT  29     //Map Y方向のチップ数                            
#define MAP_SIZE    30     //Map 一つのチップのサイズ

//描画開始位置(スクリーンサイズ - ステージ全体の幅or高さ / ２)
#define DRAW_POINT_X  (SCREEN_WIDTH - (MAP_WIDTH * MAP_SIZE)) / 2  
#define DRAW_POINT_Y  (SCREEN_HEIGHT - (MAP_HEIGHT * MAP_SIZE)) / 2 


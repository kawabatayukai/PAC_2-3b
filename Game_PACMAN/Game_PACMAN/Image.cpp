#include"DxLib.h"
#include"Image.h"

Image image;

Image::Image() {
	g_StageImage = 0;			// 画像用変数
	PlayerImage = 0;
	PlayerImageL = 0;
	PlayerImageR = 0;
	PlayerImageU = 0;
	PlayerImageD = 0;
}
/***********************************************
 * 画像読み込み
 ***********************************************/
int Image::LoadImages()
{
	//ステージ背景
	if ((g_StageImage = LoadGraph("images/maze_blue.png")) == -1) return -1;
	//プレイヤー画像
	if ((PlayerImage = LoadGraph("images/02_2.png")) == -1)return -1;
	if ((PlayerImageL = LoadGraph("images/01_2L.png")) == -1)return -1;
	if ((PlayerImageR = LoadGraph("images/01_2R.png")) == -1)return -1;
	if ((PlayerImageU = LoadGraph("images/01_2U.png")) == -1)return -1;
	if ((PlayerImageD = LoadGraph("images/01_2D.png")) == -1)return -1;

	return 0;
}
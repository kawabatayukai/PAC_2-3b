#include"DxLib.h"
#include"Image.h"

Image image;

Image::Image() {
	g_StageImage = 0;			// 画像用変数
}
/***********************************************
 * 画像読み込み
 ***********************************************/
int Image::LoadImages()
{
	//ステージ背景
	if ((g_StageImage = LoadGraph("images/maze_blue.png")) == -1) return -1;
	return 0;
}
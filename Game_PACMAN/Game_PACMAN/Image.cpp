#include"DxLib.h"
#include"Image.h"

Image image;

Image::Image() {
	g_StageImagePx[17] = 0;
	EsaImage = 0;
	PowerEsaImage = 0;
	g_StageImage = 0;			// 画像用変数
	g_PlayerImage = 0;			// 画像用変数
	g_T01Image = 0;			// 画像用変数
	g_GameTitleImage = 0;
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
	////ステージピクセル
	if ((g_StageImagePx[1] = LoadGraph("images/Stage1.png")) == -1) return -1;
	if ((g_StageImagePx[2] = LoadGraph("images/Stage2.png")) == -1) return -1;
	if ((g_StageImagePx[3] = LoadGraph("images/Stage3.png")) == -1) return -1;
	if ((g_StageImagePx[4] = LoadGraph("images/Stage4.png")) == -1) return -1;
	if ((g_StageImagePx[5] = LoadGraph("images/Stage5.png")) == -1) return -1;
	if ((g_StageImagePx[6] = LoadGraph("images/Stage6.png")) == -1) return -1;
	if ((g_StageImagePx[7] = LoadGraph("images/Stage7.png")) == -1) return -1;
	if ((g_StageImagePx[8] = LoadGraph("images/Stage8.png")) == -1) return -1;
	if ((g_StageImagePx[9] = LoadGraph("images/Stage9.png")) == -1) return -1;
	if ((g_StageImagePx[10] = LoadGraph("images/Stage10.png")) == -1) return -1;
	if ((g_StageImagePx[11] = LoadGraph("images/Stage13.png")) == -1) return -1;
	if ((g_StageImagePx[12] = LoadGraph("images/Stage14.png")) == -1) return -1;
	if ((g_StageImagePx[13] = LoadGraph("images/Stage15.png")) == -1) return -1;
	if ((g_StageImagePx[14] = LoadGraph("images/Stage16.png")) == -1) return -1;
	if ((g_StageImagePx[15] = LoadGraph("images/Stage17.png")) == -1) return -1;
	if ((g_StageImagePx[16] = LoadGraph("images/Stage18.png")) == -1) return -1;
	if ((g_StageImagePx[17] = LoadGraph("images/Stage19.png")) == -1) return -1;

	if ((g_GameTitleImage = LoadGraph("images/PAC-MAN_Classic_Logo.png")) == -1)return -1;
	//餌
	if ((EsaImage = LoadGraph("images/Esa.png")) == -1)return -1;
	if ((PowerEsaImage = LoadGraph("images/Esa.png")) == -1)return -1;
	//プレイヤー画像
	if ((g_PlayerImage = LoadGraph("images/02_2.png")) == -1)return -1;
	if ((PlayerImageL = LoadGraph("images/01_2L.png")) == -1)return -1;
	if ((PlayerImageR = LoadGraph("images/01_2R.png")) == -1)return -1;
	if ((PlayerImageU = LoadGraph("images/01_2U.png")) == -1)return -1;
	if ((PlayerImageD = LoadGraph("images/01_2D.png")) == -1)return -1;
	if ((g_StageImage = LoadGraph("images/T01.png")) == -1) return -1;
	return 0;
}
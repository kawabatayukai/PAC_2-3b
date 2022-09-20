#include"DxLib.h"
#include"Image.h"

Image image;

Image::Image() {
	g_StageImage = 0;			// 画像用変数
	g_PlayerImage = 0;			// 画像用変数
	g_T01Image = 0;			// 画像用変数
	g_T02Image = 0;			// 画像用変数
	g_T03Image = 0;			// 画像用変数
	g_T04Image = 0;			// 画像用変数
	PlayerImageL = 0;
	PlayerImageR = 0;
	PlayerImageU = 0;
	PlayerImageD = 0;
	EsaImage = 0;
	PowerEsaImage = 0;
	PacManImage[0] = 0;
	g_StageImagePx[0] = 0;
	g_StageImagePxW[0] = 0;
	g_StageImageV3 = 0;
	g_StageImageV3_W = 0;
}
/***********************************************
 * 画像読み込み
 ***********************************************/
int Image::LoadImages()
{
	//ステージ背景
	if ((g_StageImage = LoadGraph("images/maze_blue.png")) == -1) return -1;
	//プレイヤー画像
	if ((g_PlayerImage = LoadGraph("images/02_2.png")) == -1)return -1;
	if ((PlayerImageL = LoadGraph("images/01_2L.png")) == -1)return -1;
	if ((PlayerImageR = LoadGraph("images/01_2R.png")) == -1)return -1;
	if ((PlayerImageU = LoadGraph("images/01_2U.png")) == -1)return -1;
	if ((PlayerImageD = LoadGraph("images/01_2D.png")) == -1)return -1;
	if ((g_T01Image = LoadGraph("images/T01.png")) == -1) return -1;
	if ((g_T02Image = LoadGraph("images/T02.png")) == -1) return -1;
	if ((g_T03Image = LoadGraph("images/T03.png")) == -1) return -1;
	if ((g_T04Image = LoadGraph("images/T04.png")) == -1) return -1;
	if ((EsaImage = LoadGraph("images/Esa_V2.png")) == -1) return -1;
	if ((PowerEsaImage = LoadGraph("images/PowerEsa_V2.png")) == -1) return -1;
	if ((LoadDivGraph("images/PacMan.png", 12, 3, 4, 30, 30, PacManImage)) == -1)return -1;

	if ((g_StageImagePx[0] = LoadGraph("images/maze_blueV2_px_38.png")) == -1) return -1;
	if ((g_StageImagePx[1] = LoadGraph("images/maze_blueV2_px_6.png")) == -1) return -1;
	if ((g_StageImagePx[2] = LoadGraph("images/maze_blueV2_px_39.png")) == -1) return -1;
	if ((g_StageImagePx[3] = LoadGraph("images/maze_blueV2_px_8.png")) == -1) return -1;
	if ((g_StageImagePx[4] = LoadGraph("images/maze_blueV2_px_40.png")) == -1) return -1;
	if ((g_StageImagePx[5] = LoadGraph("images/maze_blueV2_px_2.png")) == -1) return -1;
	if ((g_StageImagePx[6] = LoadGraph("images/maze_blueV2_px_41.png")) == -1) return -1;
	if ((g_StageImagePx[7] = LoadGraph("images/maze_blueV2_px_4.png")) == -1) return -1;
	if ((g_StageImagePx[8] = LoadGraph("images/maze_blueV2_px_9.png")) == -1) return -1;
	if ((g_StageImagePx[9] = LoadGraph("images/maze_blueV2_px_10.png")) == -1) return -1;
	if ((g_StageImagePx[10] = LoadGraph("images/maze_blueV2_px_11.png")) == -1) return -1;
	if ((g_StageImagePx[11] = LoadGraph("images/maze_blueV2_px_12.png")) == -1) return -1;
	if ((g_StageImagePx[12] = LoadGraph("images/maze_blueV2_px_13.png")) == -1) return -1;
	if ((g_StageImagePx[13] = LoadGraph("images/maze_blueV2_px_14.png")) == -1) return -1;
	if ((g_StageImagePx[14] = LoadGraph("images/maze_blueV2_px_15.png")) == -1) return -1;
	if ((g_StageImagePx[15] = LoadGraph("images/maze_blueV2_px_16.png")) == -1) return -1;
	if ((g_StageImagePx[16] = LoadGraph("images/maze_blueV2_px_17.png")) == -1) return -1;
	if ((g_StageImagePx[17] = LoadGraph("images/maze_blueV2_px_18.png")) == -1) return -1;
	if ((g_StageImagePx[18] = LoadGraph("images/maze_blueV2_px_19.png")) == -1) return -1;
	if ((g_StageImagePx[19] = LoadGraph("images/maze_blueV2_px_20.png")) == -1) return -1;
	if ((g_StageImagePx[20] = LoadGraph("images/maze_blueV2_px_21.png")) == -1) return -1;
	if ((g_StageImagePx[21] = LoadGraph("images/maze_blueV2_px_22.png")) == -1) return -1;
	if ((g_StageImagePx[22] = LoadGraph("images/maze_blueV2_px_23.png")) == -1) return -1;
	if ((g_StageImagePx[23] = LoadGraph("images/maze_blueV2_px_24.png")) == -1) return -1;
	if ((g_StageImagePx[24] = LoadGraph("images/maze_blueV2_px_25.png")) == -1) return -1;
	if ((g_StageImagePx[25] = LoadGraph("images/maze_blueV2_px_26.png")) == -1) return -1;
	if ((g_StageImagePx[26] = LoadGraph("images/maze_blueV2_px_27.png")) == -1) return -1;
	if ((g_StageImagePx[27] = LoadGraph("images/maze_blueV2_px_28.png")) == -1) return -1;
	if ((g_StageImagePx[28] = LoadGraph("images/maze_blueV2_px_29.png")) == -1) return -1;
	if ((g_StageImagePx[29] = LoadGraph("images/maze_blueV2_px_30.png")) == -1) return -1;
	if ((g_StageImagePx[30] = LoadGraph("images/maze_blueV2_px_31.png")) == -1) return -1;
	if ((g_StageImagePx[31] = LoadGraph("images/maze_blueV2_px_32.png")) == -1) return -1;
	if ((g_StageImagePx[32] = LoadGraph("images/maze_blueV2_px_33.png")) == -1) return -1;
	if ((g_StageImagePx[33] = LoadGraph("images/maze_blueV2_px_34.png")) == -1) return -1;
	if ((g_StageImagePx[34] = LoadGraph("images/maze_blueV2_px_35.png")) == -1) return -1;
	if ((g_StageImagePx[35] = LoadGraph("images/maze_blueV2_px_36.png")) == -1) return -1;
	if ((g_StageImagePx[36] = LoadGraph("images/maze_blueV2_px_37.png")) == -1) return -1;
	if ((g_StageImagePx[37] = LoadGraph("images/maze_blue_px_1.png")) == -1) return -1;
	if ((g_StageImagePx[38] = LoadGraph("images/maze_blueV2_px_3.png")) == -1) return -1;
	if ((g_StageImagePx[39] = LoadGraph("images/maze_blueV2_px_5.png")) == -1) return -1;
	if ((g_StageImagePx[40] = LoadGraph("images/maze_blueV2_px_7.png")) == -1) return -1;
	if ((g_StageImagePx[41] = LoadGraph("images/maze_blueV2_px_42.png")) == -1) return -1;
	if ((g_StageImagePx[42] = LoadGraph("images/maze_blueV2_px_43.png")) == -1) return -1;
	if ((g_StageImagePx[43] = LoadGraph("images/maze_blueV2_px_44.png")) == -1) return -1;
	if ((g_StageImagePx[44] = LoadGraph("images/maze_blueV2_px_45.png")) == -1) return -1;
	if ((g_StageImagePx[45] = LoadGraph("images/maze_blueV2_px_46.png")) == -1) return -1;
	if ((g_StageImagePx[46] = LoadGraph("images/maze_blueV2_px_47.png")) == -1) return -1;
	if ((g_StageImagePx[47] = LoadGraph("images/maze_blueV2_px_48.png")) == -1) return -1;

	if ((g_StageImagePxW[0] = LoadGraph("images/maze_blueV2_px_38_w.png")) == -1) return -1;
	if ((g_StageImagePxW[1] = LoadGraph("images/maze_blueV2_px_6_w.png")) == -1) return -1;
	if ((g_StageImagePxW[2] = LoadGraph("images/maze_blueV2_px_39_w.png")) == -1) return -1;
	if ((g_StageImagePxW[3] = LoadGraph("images/maze_blueV2_px_8_w.png")) == -1) return -1;
	if ((g_StageImagePxW[4] = LoadGraph("images/maze_blueV2_px_40_w.png")) == -1) return -1;
	if ((g_StageImagePxW[5] = LoadGraph("images/maze_blueV2_px_2_w.png")) == -1) return -1;
	if ((g_StageImagePxW[6] = LoadGraph("images/maze_blueV2_px_41_w.png")) == -1) return -1;
	if ((g_StageImagePxW[7] = LoadGraph("images/maze_blueV2_px_4_w.png")) == -1) return -1;
	if ((g_StageImagePxW[8] = LoadGraph("images/maze_blueV2_px_9_w.png")) == -1) return -1;
	if ((g_StageImagePxW[9] = LoadGraph("images/maze_blueV2_px_10_w.png")) == -1) return -1;
	if ((g_StageImagePxW[10] = LoadGraph("images/maze_blueV2_px_11_w.png")) == -1) return -1;
	if ((g_StageImagePxW[11] = LoadGraph("images/maze_blueV2_px_12_w.png")) == -1) return -1;
	if ((g_StageImagePxW[12] = LoadGraph("images/maze_blueV2_px_13_w.png")) == -1) return -1;
	if ((g_StageImagePxW[13] = LoadGraph("images/maze_blueV2_px_14_w.png")) == -1) return -1;
	if ((g_StageImagePxW[14] = LoadGraph("images/maze_blueV2_px_15_w.png")) == -1) return -1;
	if ((g_StageImagePxW[15] = LoadGraph("images/maze_blueV2_px_16_w.png")) == -1) return -1;
	if ((g_StageImagePxW[16] = LoadGraph("images/maze_blueV2_px_17_w.png")) == -1) return -1;
	if ((g_StageImagePxW[17] = LoadGraph("images/maze_blueV2_px_18_w.png")) == -1) return -1;
	if ((g_StageImagePxW[18] = LoadGraph("images/maze_blueV2_px_19_w.png")) == -1) return -1;
	if ((g_StageImagePxW[19] = LoadGraph("images/maze_blueV2_px_20_w.png")) == -1) return -1;
	if ((g_StageImagePxW[20] = LoadGraph("images/maze_blueV2_px_21_w.png")) == -1) return -1;
	if ((g_StageImagePxW[21] = LoadGraph("images/maze_blueV2_px_22_w.png")) == -1) return -1;
	if ((g_StageImagePxW[22] = LoadGraph("images/maze_blueV2_px_23_w.png")) == -1) return -1;
	if ((g_StageImagePxW[23] = LoadGraph("images/maze_blueV2_px_24_w.png")) == -1) return -1;
	if ((g_StageImagePxW[24] = LoadGraph("images/maze_blueV2_px_25_w.png")) == -1) return -1;
	if ((g_StageImagePxW[25] = LoadGraph("images/maze_blueV2_px_26_w.png")) == -1) return -1;
	if ((g_StageImagePxW[26] = LoadGraph("images/maze_blueV2_px_27_w.png")) == -1) return -1;
	if ((g_StageImagePxW[27] = LoadGraph("images/maze_blueV2_px_28_w.png")) == -1) return -1;
	if ((g_StageImagePxW[28] = LoadGraph("images/maze_blueV2_px_29_w.png")) == -1) return -1;
	if ((g_StageImagePxW[29] = LoadGraph("images/maze_blueV2_px_30_w.png")) == -1) return -1;
	if ((g_StageImagePxW[30] = LoadGraph("images/maze_blueV2_px_31_w.png")) == -1) return -1;
	if ((g_StageImagePxW[31] = LoadGraph("images/maze_blueV2_px_32_w.png")) == -1) return -1;
	if ((g_StageImagePxW[32] = LoadGraph("images/maze_blueV2_px_33_w.png")) == -1) return -1;
	if ((g_StageImagePxW[33] = LoadGraph("images/maze_blueV2_px_34_w.png")) == -1) return -1;
	if ((g_StageImagePxW[34] = LoadGraph("images/maze_blueV2_px_35_w.png")) == -1) return -1;
	if ((g_StageImagePxW[35] = LoadGraph("images/maze_blueV2_px_36_w.png")) == -1) return -1;
	if ((g_StageImagePxW[36] = LoadGraph("images/maze_blueV2_px_37_w.png")) == -1) return -1;
	if ((g_StageImagePxW[37] = LoadGraph("images/maze_blue_px_1_w.png")) == -1) return -1;
	if ((g_StageImagePxW[38] = LoadGraph("images/maze_blueV2_px_3_w.png")) == -1) return -1;
	if ((g_StageImagePxW[39] = LoadGraph("images/maze_blueV2_px_5_w.png")) == -1) return -1;
	if ((g_StageImagePxW[40] = LoadGraph("images/maze_blueV2_px_7_w.png")) == -1) return -1;
	if ((g_StageImagePxW[41] = LoadGraph("images/maze_blueV2_px_42_w.png")) == -1) return -1;
	if ((g_StageImagePxW[42] = LoadGraph("images/maze_blueV2_px_43_w.png")) == -1) return -1;
	if ((g_StageImagePxW[43] = LoadGraph("images/maze_blueV2_px_44_w.png")) == -1) return -1;
	if ((g_StageImagePxW[44] = LoadGraph("images/maze_blueV2_px_45_w.png")) == -1) return -1;
	if ((g_StageImagePxW[45] = LoadGraph("images/maze_blueV2_px_46_w.png")) == -1) return -1;
	if ((g_StageImagePxW[46] = LoadGraph("images/maze_blueV2_px_47_w.png")) == -1) return -1;
	if ((g_StageImagePxW[47] = LoadGraph("images/maze_blueV2_px_48_w.png")) == -1) return -1;

	if ((g_StageImageV3 = LoadGraph("images/maze_blueV3.1.png")) == -1) return -1;
	if ((g_StageImageV3_W = LoadGraph("images/maze_blueV3.1_w.png")) == -1) return -1;

	return 0;
}
#pragma once
class Image {
public:
	int	g_StageImage;			// 画像用変数
	int	g_PlayerImage;			// 画像用変数
	int PlayerImageL;
	int PlayerImageR;
	int PlayerImageU;
	int PlayerImageD;
	int	g_T01Image;			// 画像用変数
	int	g_T02Image;			// 画像用変数
	int	g_T03Image;			// 画像用変数
	int	EsaImage;			// 画像用変数
	int	PowerEsaImage;			// 画像用変数
	int g_GameTitleImage;
	int PacManImage[12];

	int g_StageImagePx[48];
	int g_StageImagePxW[48];

	int g_StageImageV3;
	int g_StageImageV3_W;

	Image();

	int LoadImages();
};
extern Image image;
#pragma once
class Image {
public:
	int	g_StageImage;			// 画像用変数
	int g_StageImagePx[17];
	int	g_PlayerImage;			// 画像用変数
	int PlayerImageL;
	int PlayerImageR;
	int PlayerImageU;
	int PlayerImageD;
	int EsaImage;
	int PowerEsaImage;
	int	g_T01Image;			// 画像用変数
	int g_GameTitleImage;
	int PacManImage[12];
	int PacManDestroy[11];

	Image();

	int LoadImages();
};
extern Image image;
#pragma once
class Image {
public:
	int	g_StageImage;			// ‰æ‘œ—p•Ï”
	int g_StageImagePx[17];
	int	g_PlayerImage;			// ‰æ‘œ—p•Ï”
	int PlayerImageL;
	int PlayerImageR;
	int PlayerImageU;
	int PlayerImageD;
	int EsaImage;
	int PowerEsaImage;
	int	g_T01Image;			// ‰æ‘œ—p•Ï”
	int g_GameTitleImage;
	int PacManImage[12];

	Image();

	int LoadImages();
};
extern Image image;
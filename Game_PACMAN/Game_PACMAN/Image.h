#pragma once
class Image {
public:
	int	g_StageImage;			// �摜�p�ϐ�
	int g_StageImagePx[17];
	int	g_PlayerImage;			// �摜�p�ϐ�
	int PlayerImageL;
	int PlayerImageR;
	int PlayerImageU;
	int PlayerImageD;
	int EsaImage;
	int PowerEsaImage;
	int	g_T01Image;			// �摜�p�ϐ�
	int g_GameTitleImage;
	int PacManImage[12];

	Image();

	int LoadImages();
};
extern Image image;
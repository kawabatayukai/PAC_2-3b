#pragma once
class Image {
public:
	int	g_StageImage;			// �摜�p�ϐ�
	int	g_PlayerImage;			// �摜�p�ϐ�
	int PlayerImageL;
	int PlayerImageR;
	int PlayerImageU;
	int PlayerImageD;
	int	g_T01Image;			// �摜�p�ϐ�
	int	g_T02Image;			// �摜�p�ϐ�
	int	g_T03Image;			// �摜�p�ϐ�
	int	EsaImage;			// �摜�p�ϐ�
	int	PowerEsaImage;			// �摜�p�ϐ�
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
#pragma once
class Image {
public:
	int	g_StageImage;			// �摜�p�ϐ�
	int PlayerImageL;
	int PlayerImageR;
	int PlayerImageU;
	int PlayerImageD;

	Image();

	int LoadImages();
};
extern Image image;
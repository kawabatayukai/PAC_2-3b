#pragma once
class Image {
public:
	int	g_StageImage;			// ‰æ‘œ—p•Ï”
	int PlayerImageL;
	int PlayerImageR;
	int PlayerImageU;
	int PlayerImageD;

	Image();

	int LoadImages();
};
extern Image image;
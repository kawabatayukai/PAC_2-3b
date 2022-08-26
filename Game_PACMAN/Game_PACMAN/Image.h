#pragma once
class Image {
public:
	int	g_StageImage;			// ‰æ‘œ—p•Ï”
	int	g_PlayerImage;			// ‰æ‘œ—p•Ï”
	int PlayerImageL;
	int PlayerImageR;
	int PlayerImageU;
	int PlayerImageD;
	int	g_T01Image;			// ‰æ‘œ—p•Ï”

	Image();

	int LoadImages();
};
extern Image image;
#pragma once
#include"Info.h"
#define D_START (0)
#define D_RANKING (1)
#define D_HELP (2)
#define D_END (3)

class Title
{
private:
public:
	int g_GameTitleFlg;
	int g_MenuSelect[4];
	Title();
	void DrawTitle();
	int	g_MenuNumber;		// ���j���[�J�[�\���ʒu
	int g_MenuY;				// ���j���[�J�[�\���̂x���W
};
extern Title title;
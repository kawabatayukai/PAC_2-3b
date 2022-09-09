#include"DxLib.h"
#include "Stage.h"
#include "Image.h"
#include"Common.h"
#include "Player.h"
#include"Title.h"
#define XINPUT_BUTTON_START		(4)	// START�{�^��



Title title;
Title::Title() {
	g_GameTitleFlg = FALSE;
    g_MenuNumber = 0;		// ���j���[�J�[�\���ʒu
	
}

void Title::DrawTitle()
{
	DrawGraph(150, 30, image.g_GameTitleImage, FALSE);

	DrawString(600, 360, "GAME STATE", 0xffffff);
	if (keyFlg & PAD_INPUT_A) {
		g_GameTitleFlg = TRUE;
		return stage.DrawMap();
	}
	//���j���[�J�[�\���i�O�p�`�j�̕\��
	g_MenuY = g_MenuNumber * 52;
	DrawTriangle(555, 360 + g_MenuY, 570, 370 + g_MenuY, 555, 380 + g_MenuY, GetColor(255, 0, 0), TRUE);
}
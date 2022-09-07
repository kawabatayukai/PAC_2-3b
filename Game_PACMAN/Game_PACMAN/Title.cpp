#include"DxLib.h"
#include "Stage.h"
#include "Image.h"
#include"Common.h"
#include "Player.h"
#include"Title.h"
#define XINPUT_BUTTON_START		(4)	// STARTƒ{ƒ^ƒ“

Title title;
Title::Title() {
	g_GameTitleFlg = FALSE;
}

void Title::DrawTitle()
{
	DrawGraph(150, 30, image.g_GameTitleImage, FALSE);
	DrawString(600, 360, "GAME STATE", 0xffffff);
	if (keyFlg & PAD_INPUT_A) {
		g_GameTitleFlg = TRUE;
		return stage.DrawMap();
	}
}
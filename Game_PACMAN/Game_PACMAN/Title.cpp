#include"DxLib.h"
#include "Stage.h"
#include "Image.h"
#include"Common.h"
#include "Player.h"
#include"Title.h"

Title title;
Title::Title() {
	g_GameTitleFlg = FALSE;
}

void Title::DrawTitle()
{
	DrawGraph(150, 30, image.g_GameTitleImage, FALSE);
	if (keyFlg & PAD_INPUT_A) {
		g_GameTitleFlg = TRUE;
		return stage.DrawMap();
	}
}
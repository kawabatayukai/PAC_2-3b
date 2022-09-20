#include"DxLib.h"
#include "Stage.h"
#include "Image.h"
#include"Common.h"
#include "Player.h"
#include"Title.h"
#define XINPUT_BUTTON_START		(4)	// STARTボタン



Title title;
Title::Title() {
	g_GameTitleFlg = FALSE;
    g_MenuNumber = 0;		// メニューカーソル位置
	g_MenuY;				// メニューカーソルのＹ座標
	
}

void Title::DrawTitle()
{
	DrawGraph(150, 30, image.g_GameTitleImage, FALSE);
	DrawString(600, 360, "GAME STATE", 0xffffff);
	if (keyFlg & PAD_INPUT_A)/*g_GameState = MenuNo + 1; */{
		g_GameTitleFlg = TRUE;
		return stage.DrawMap();
	}
	//メニューカーソル（三角形）の表示
	g_MenuY = g_MenuNumber * 52;
	DrawTriangle(555, 360 + g_MenuY, 570, 370 + g_MenuY, 555, 380 + g_MenuY, GetColor(255, 0, 0), TRUE);
	DrawString(600, 400, "GAME END", 0xffffff);
}
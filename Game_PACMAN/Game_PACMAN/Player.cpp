#include "DxLib.h"
#include <math.h>
#include "Player.h"
#include"Image.h"
#include "Common.h"

Player g_player;

/***********************************************
 * コンストラクタ
 ***********************************************/
Player::Player() {
	//InitXY();
	/*PlayerImageL = LoadGraph("images/01_2.png");
	PlayerImageR = LoadGraph("images/01_2R.png");
	PlayerImageU = LoadGraph("images/01_2U.png");
	PlayerImageD = LoadGraph("images/01_2D.png");*/
	width = 60;
	height = 8;
	PX = 630;
	PY = 405;
}

///***********************************************
// * プレイヤーの座標初期化処理
// ***********************************************/
//void Player::InitXY() {
//	PX = 630;
//	PY = 520;
//	
//	if (keyFlg & PAD_INPUT_A) {
//		PX = 630;
//		PY = 520;
//	}
//}

/***********************************************
 * プレイヤーのコントロール
 ***********************************************/
void Player::PlayerControl() {
	/*KEYFLG = 0;
	NEXTFLG = 0;*/
	FLG = false;
	g_Vector = 0;
	PX_2 = PX, PY_2 = PY;
	if (keyFlg & PAD_INPUT_LEFT) KEYFLG = LEFT, g_Vector = -3;
	if (keyFlg & PAD_INPUT_RIGHT) KEYFLG = RIGHT, g_Vector = 3;
	if (keyFlg & PAD_INPUT_UP)KEYFLG = UP, g_Vector = -3;
	if (keyFlg & PAD_INPUT_DOWN)KEYFLG = DOWN, g_Vector = 3;
	switch (KEYFLG)
	{
	case LEFT:
		//if (Map[PYC][PXC - 1] == 0)
		PX -= 3;
		//if (Map[syC][sxC] != 0 || Map[syC1][sxC] != 0/* && Map[syC][sxC] != 3 && Map[syC1][sxC] != 3*/)PX = PX_2, KEYFLG = 0;
		//if (Map[syC][sxC] == 0 || Map[syC1][sxC] == 0/* && Map[syC][sxC] != 3 && Map[syC1][sxC] != 3*/)PX -= 3;
		//DrawGraph(PX - 5, PY - 5, PlayerImageL, TRUE);
		DrawGraph(PX, PY, image.PlayerImageL, TRUE);
		break;
	case RIGHT:
		PX += 3;
		//if (Map[PYC][PXC + 1] == 0)
		//if (Map[syC][sxC1] != 0 || Map[syC1][sxC1] != 0/* && Map[syC][sxC1] != 3 && Map[syC1][sxC1] != 3*/)PX = PX_2, KEYFLG = 0;
		//if (Map[syC][sxC1] == 0 || Map[syC1][sxC1] == 0/* && Map[syC][sxC1] != 3 && Map[syC1][sxC1] != 3*/)PX += 3;
		//DrawGraph(PX - 5, PY - 5, PlayerImageR, TRUE);
		DrawGraph(PX, PY, image.PlayerImageR, TRUE);
		break;
	case UP:
		PY -= 3;
		//if (Map[PYC - 1][PXC] == 0)
		//if (Map[syC][sxC] != 0 || Map[syC][sxC1] != 0/* && Map[syC][sxC] != 3 && Map[syC][sxC1] != 3*/)PY = PY_2, KEYFLG = 0;
		//if (Map[syC][sxC] == 0 || Map[syC][sxC1] == 0/* && Map[syC][sxC] != 3 && Map[syC][sxC1] != 3*/)PY -= 3;
		//DrawGraph(PX - 5, PY - 5, PlayerImageU, TRUE);
		DrawGraph(PX, PY, image.PlayerImageU, TRUE);
		break;
	case DOWN:
		PY += 3;
		//if (Map[PYC + 1][PXC] == 0)
		//if (Map[syC1][sxC] != 0 || Map[syC1][sxC1] != 0/* && Map[syC1][sxC] != 3 && Map[syC1][sxC1] != 3*/)PY = PY_2, KEYFLG = 0;
		//if (Map[syC1][sxC] == 0 || Map[syC1][sxC1] == 0/* && Map[syC1][sxC] != 3 && Map[syC1][sxC1] != 3*/)PY += 3;
		//DrawGraph(PX - 5, PY - 5, PlayerImageD, TRUE);
		DrawGraph(PX, PY, image.PlayerImageD, TRUE);
		break;
	default:
		//DrawGraph(PX - 5, PY - 5, PlayerImageL, TRUE);
		DrawGraph(PX, PY, image.PlayerImage, TRUE);
		break;
	}
}

//int HitBoxPlayer() {
//	/*PX = 630;
//	PY = 520;*/
//	PX = 630;
//	PY = 405;
//
//	int sx = PX - 10;
//	int sy = PY - 10;
//	int sx1 = sx + 30;
//	int sy1 = sy + 30;
//	int sxC = (PX / 10) - 15;
//	int syC = (PY / 10);
//	int sxC1 = (PX / 10) - 15;
//	int syC1 = (PY / 10);
//
//	DrawBox(sx, sy, sx1, sy1, 0xfffffff, false);
//
//	switch (KEYFLG) {
//	case LEFT:
//		if (Map[syC][sxC - 1] == 0)return true;
//		break;
//	case RIGHT:
//		if (Map[syC][sxC + 1] == 0)return true;
//		break;
//	case UP:
//		if (Map[syC - 1][sxC] == 0)return true;
//		break;
//	case DOWN:
//		if (Map[syC + 1][sxC] == 0)return true;
//		break;
//	}
//
//
//
//
//
//}
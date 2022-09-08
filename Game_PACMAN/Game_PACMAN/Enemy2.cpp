#include "DxLib.h"
#include "Enemy2.h"
#include "Info.h"
#include "Image.h"
#include "A_star.h"
#include "Stage.h"
#include "Player.h"
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

Enemy2 g_enemy2;

Enemy2::Enemy2() {
	EX = 370;
	EY = 60;
	EXC = (EX - DRAW_POINT_X) / 30;
	EYC = (EY - DRAW_POINT_Y) / 30;
	oldX = 0;
	oldY = 0;
}

void Enemy2::EnemyInit() {
	EX = 370;
	EY = 60;
	EXC = (EX - DRAW_POINT_X) / 30;
	EYC = (EY - DRAW_POINT_Y) / 30;
	oldX = 0;
	oldY = 0;
}

void Enemy2::EnemyController() {
	EXC = (EX - DRAW_POINT_X) / 30;
	EYC = (EY - DRAW_POINT_Y) / 30;

	BOX				box[783] = { 0 };
	BOX1			boxP[4] = { 0 };

	oldX = EX;
	oldY = EY;

	OldKeyFlg = VectorFlg;

	if (a_star.data[EYC][EXC - 1].status == 1) {
		if (LC >= 783) {
			VectorFlg = LEFT;
			NEXTFLG = 0;
		}
		else if (LC <= 782) {
			NEXTFLG = LEFT;
		}
	}
	if (a_star.data[EYC][EXC + 1].status == 1) {
		if (RC >= 783) {
			VectorFlg = RIGHT;
			NEXTFLG = 0;
		}
		else if (RC <= 782) {
			NEXTFLG = RIGHT;
		}
	}
	if (a_star.data[EYC - 1][EXC].status == 1) {
		if (UC >= 783) {
			VectorFlg = UP;
			NEXTFLG = 0;
		}
		else if (UC <= 782) {
			NEXTFLG = UP;
		}
	}
	if (a_star.data[EYC + 1][EXC].status == 1) {
		if (DC >= 783) {
			VectorFlg = DOWN;
			NEXTFLG = 0;
		}
		else if (DC <= 782) {
			NEXTFLG = DOWN;
		}
	}

	/*if (MapData[EYC][EXC - 1] == 1) {
		if (LC >= 783) {
			VectorFlg = LEFT;
			NEXTFLG = 0;
		}
		else if (LC <= 782) {
			NEXTFLG = LEFT;
		}
	}
	if (MapData[EYC][EXC + 1] == 1) {
		if (RC >= 783) {
			VectorFlg = RIGHT;
			NEXTFLG = 0;
		}
		else if (RC <= 782) {
			NEXTFLG = RIGHT;
		}
	}
	if (MapData[EYC - 1][EXC] == 1) {
		if (UC >= 783) {
			VectorFlg = UP;
			NEXTFLG = 0;
		}
		else if (UC <= 782) {
			NEXTFLG = UP;
		}
	}
	if (MapData[EYC + 1][EXC] == 1) {
		if (DC >= 783) {
			VectorFlg = DOWN;
			NEXTFLG = 0;
		}
		else if (DC <= 782) {
			NEXTFLG = DOWN;
		}
	}*/

	//if (a_star.data[EYC][EXC - 1].status == 1/* && FLG_MAX_L == true*/) {
	//	VectorFlg = LEFT;
	//}
	//if (a_star.data[EYC][EXC + 1].status == 1/* && FLG_MAX_R == true*/) {
	//	VectorFlg = RIGHT;
	//}
	//if (a_star.data[EYC - 1][EXC].status == 1/* && FLG_MAX_U == true*/) {
	//	VectorFlg = UP;
	//}
	//if (a_star.data[EYC + 1][EXC].status == 1/* && FLG_MAX_D == true*/) {
	//	VectorFlg = DOWN;
	//}

	switch (VectorFlg)
	{
	case LEFT:
		//PX -= 3;
		if (FLG_MAX_L == true && NEXTFLG == LEFT) {
			EX -= 4;
		}
		else {
			EX -= 3;
		}
		//DrawGraph(PX, PY, image.PlayerImageL, TRUE);
		//DrawGraph(PX - 15, PY - 15, image.PlayerImageL, TRUE);
		DrawGraph(EX - 15, EY - 15, image.g_T01Image, TRUE);
		break;
	case RIGHT:
		//PX += 3;
		if (FLG_MAX_R == true && NEXTFLG == RIGHT) {
			EX += 4;
		}
		else {
			EX += 3;
		}
		//DrawGraph(PX - 15, PY - 15, image.PlayerImageR, TRUE);
		DrawGraph(EX - 15, EY - 15, image.g_T01Image, TRUE);
		break;
	case UP:
		//PY -= 3;
		if (FLG_MAX_U == true && NEXTFLG == UP) {
			EY -= 4;
		}
		else {
			EY -= 3;
		}
		//DrawGraph(PX - 15, PY - 15, image.PlayerImageU, TRUE);
		DrawGraph(EX - 15, EY - 15, image.g_T01Image, TRUE);
		break;
	case DOWN:
		//PY += 3;
		if (FLG_MAX_D == true && NEXTFLG == DOWN) {
			EY += 4;
		}
		else {
			EY += 3;
		}
		//DrawGraph(PX, PY, image.PlayerImageD, TRUE);
		//DrawGraph(PX - 15, PY - 15, image.PlayerImageD, TRUE);
		break;
	default:
		//DrawGraph(PX, PY, image.g_PlayerImage, TRUE);
		//DrawGraph(PX - 15, PY - 15, image.g_PlayerImage, TRUE);
		DrawGraph(EX - 15, EY - 15, image.g_T01Image, TRUE);
		break;

	}

	CIRCLE			circle;

	circle.x = EX;
	circle.y = EY;
	circle.r = 14.5f;

	C = 0;
	CF = 0;
	for (I = 0; I < MAP_HEIGHT; I++) {
		for (J = 0; J < MAP_WIDTH; J++) {

			try {


				if (stage.getMap(I, J) != 0) {
					box[C].fLeft[CF] = DRAW_POINT_X + (J * 30);
					box[C].fTop[CF] = DRAW_POINT_Y + (I * 30);
					box[C].fRight[CF] = DRAW_POINT_X + (J * 30) + 30;
					box[C].fBottom[CF] = DRAW_POINT_Y + (I * 30) + 30;


					if (CheckHit(box[C], circle))
					{
						//DrawCircle(circle.x, circle.y, circle.r, GetColor(125, 125, 125));
						//DrawBox(box[C].fLeft[CF], box[C].fTop[CF], box[C].fRight[CF], box[C].fBottom[CF], GetColor(125, 125, 125), true);
						NextKeyFlg = VectorFlg;
						EX = oldX;
						EY = oldY;
						VectorFlg = OldKeyFlg;
					}
					else
					{
						//DrawCircle(circle.x, circle.y, circle.r, GetColor(255, 255, 255));
						//DrawBox(box[C].fLeft[CF], box[C].fTop[CF], box[C].fRight[CF], box[C].fBottom[CF], GetColor(125, 125, 125), true);
					}
					//DrawFormatString(box[C].fLeft[C], box[C].fTop[C], 0xFF00FF, "%d", C);

				}
			}
			catch (int p) {
				break;
			}

			C++;
		}
	}
	I = 0;
	J = 0;
	C = 0;

	LC = 0;
	RC = 0;
	UC = 0;
	DC = 0;
	for (CI = 0; CI < 783; CI++) {
		for (I = 0; I < 4; I++) {

			switch (I)
			{
			case 0://Left
				boxP[I].fLeft[I] = EX - 20;
				boxP[I].fTop[I] = EY - 15;
				boxP[I].fRight[I] = EX - 15 + 30.0f;
				boxP[I].fBottom[I] = EY - 15 + 30.0f;
				break;
			case 1://Up
				boxP[I].fLeft[I] = EX - 15;
				boxP[I].fTop[I] = EY - 20;
				boxP[I].fRight[I] = EX - 15 + 30.0f;
				boxP[I].fBottom[I] = EY - 10 + 25.0f;
				break;
			case 2://Right
				boxP[I].fLeft[I] = EX - 15;
				boxP[I].fTop[I] = EY - 15;
				boxP[I].fRight[I] = EX - 15 + 35.0f;
				boxP[I].fBottom[I] = EY - 15 + 30.0f;
				break;
			case 3://Down
				boxP[I].fLeft[I] = EX - 15;
				boxP[I].fTop[I] = EY - 15;
				boxP[I].fRight[I] = EX - 15 + 30.0f;
				boxP[I].fBottom[I] = EY - 15 + 35.0f;
				break;

			default:
				break;
			}

			if (CheckHitBOX(box[CI], boxP[I]))
			{
				//DrawCircle(circle.x, circle.y, circle.r, GetColor(125, 125, 125));
				/*if (I == 0)DrawBox(boxP[I].fLeft[I], boxP[I].fTop[I], boxP[I].fRight[I], boxP[I].fBottom[I], GetColor(75, 75, 125), true);
				if (I == 1)DrawBox(boxP[I].fLeft[I], boxP[I].fTop[I], boxP[I].fRight[I], boxP[I].fBottom[I], GetColor(75, 95, 55), true);
				if (I == 2)DrawBox(boxP[I].fLeft[I], boxP[I].fTop[I], boxP[I].fRight[I], boxP[I].fBottom[I], GetColor(95, 0, 125), true);
				if (I == 3)DrawBox(boxP[I].fLeft[I], boxP[I].fTop[I], boxP[I].fRight[I], boxP[I].fBottom[I], GetColor(25, 30, 185), true);*/

				/*EX = oldX;
				EY = oldY;*/

				if (I == 0)FLG_L = CI;
				if (I == 1)FLG_U = CI;
				if (I == 2)FLG_R = CI;
				if (I == 3)FLG_D = CI;

				NextKeyFlg = VectorFlg;


			}
			else
			{
				//DrawCircle(circle.x, circle.y, circle.r, GetColor(255, 255, 255));
				/*if (I == 0)DrawBox(boxP[I].fLeft[I], boxP[I].fTop[I], boxP[I].fRight[I], boxP[I].fBottom[I], GetColor(75, 75, 125), false);
				if (I == 1)DrawBox(boxP[I].fLeft[I], boxP[I].fTop[I], boxP[I].fRight[I], boxP[I].fBottom[I], GetColor(75, 95, 55), false);
				if (I == 2)DrawBox(boxP[I].fLeft[I], boxP[I].fTop[I], boxP[I].fRight[I], boxP[I].fBottom[I], GetColor(95, 0, 125), false);
				if (I == 3)DrawBox(boxP[I].fLeft[I], boxP[I].fTop[I], boxP[I].fRight[I], boxP[I].fBottom[I], GetColor(25, 30, 185), false);*/

				if (I == 0)LC++;
				if (I == 1)UC++;
				if (I == 2)RC++;
				if (I == 3)DC++;

			}
			//DrawFormatString(boxP[I].fLeft[I], boxP[I].fTop[I], 0xFF00FF, "%d", I);
		}

		I = 0;
	}
	CI = 0;

	if (LC >= 783) {
		FLG_MAX_L = true;
	}
	else if (LC <= 782) {
		FLG_MAX_L = false;
	}
	if (RC >= 783) {
		FLG_MAX_R = true;
	}
	else if (RC <= 782) {
		FLG_MAX_R = false;
	}
	if (UC >= 783) {
		FLG_MAX_U = true;
	}
	else if (UC <= 782) {
		FLG_MAX_U = false;
	}
	if (DC >= 783) {
		FLG_MAX_D = true;
	}
	else if (DC <= 782) {
		FLG_MAX_D = false;
	}

	if (NEXTFLG != 0) {
		if (FLG_MAX_L == true && NEXTFLG == LEFT) {
			VectorFlg = NEXTFLG;
			NEXTFLG = 0;
		}
		if (FLG_MAX_R == true && NEXTFLG == RIGHT) {
			VectorFlg = NEXTFLG;
			NEXTFLG = 0;
		}
		if (FLG_MAX_U == true && NEXTFLG == UP) {
			VectorFlg = NEXTFLG;
			NEXTFLG = 0;
		}
		if (FLG_MAX_D == true && NEXTFLG == DOWN) {
			VectorFlg = NEXTFLG;
			NEXTFLG = 0;
		}
	}

	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 29; j++) {
			if (MapData[j][i] == 1) {
				DrawFormatString(630+10 + (i * 20), 20 + (j * 20), 0xff0000, "%d", MapData[j][i]);
			}
			else if (MapData[j][i] == 0) {
				DrawFormatString(630+10 + (i * 20), 20 + (j * 20), 0xffffff, "%d", MapData[j][i]);
			}
			else {
				DrawFormatString(630+10 + (i * 20), 20 + (j * 20), 0x0000ff, "%d", MapData[j][i]);
			}
			//DrawFormatString(10 + (i * 30), 20 + (j * 30), 0xffffff, "%d" ,stage.getMap[j][i]);
		}
	}
	DrawFormatString(1100, 220, 0x0000ff, "%d", EYC);
	DrawFormatString(1100, 230, 0x0000ff, "%d", EY);
	DrawFormatString(1100, 260, 0x0000ff, "%d", VectorFlg);
	DrawFormatString(1100, 280, 0x0000ff, "%d", NextKeyFlg);
	//DrawCircle(circle.x, circle.y, circle.r, GetColor(255, 255, 255));
	DrawGraph(EX - 15, EY - 15, image.g_T01Image, TRUE);
	//DrawCircle(circle.x, circle.y, circle.r, GetColor(255, 255, 255));

	//a_star.main(g_player.PXC, g_player.PYC, EXC, EYC);

	if (EX <= 340 && EY == 330 && VectorFlg == LEFT) {
		EX = 940;
	}
	if (EX >= 940 && EY == 330 && VectorFlg == RIGHT) {
		EX = 340;
	}

	if (EX <= 429 && EY == 330 && VectorFlg == LEFT) {
		EX += 1;
	}
	if (EX <= 429 && EY == 330 && VectorFlg == RIGHT) {
		EX -= 1;
	}
	if (EX >= 851 && EY == 330 && VectorFlg == LEFT) {
		EX += 1;
	}
	if (EX >= 851 && EY == 330 && VectorFlg == RIGHT) {
		EX -= 1;
	}

}

float Enemy2::DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2) {
	float dx = t_x2 - t_x1;
	float dy = t_y2 - t_y1;

	return (dx * dx) + (dy * dy);
}

bool Enemy2::CheckHit(const BOX& t_box, const CIRCLE& t_circle) {
	bool nResult = false;

	// éläpå`ÇÃélï”Ç…ëŒÇµÇƒâ~ÇÃîºåaï™ÇæÇØë´ÇµÇΩÇ∆Ç´â~Ç™èdÇ»Ç¡ÇƒÇ¢ÇΩÇÁ
	if ((t_circle.x > t_box.fLeft[CF] - t_circle.r) &&
		(t_circle.x < t_box.fRight[CF] + t_circle.r) &&
		(t_circle.y > t_box.fTop[CF] - t_circle.r) &&
		(t_circle.y < t_box.fBottom[CF] + t_circle.r))
	{
		nResult = true;
		float fl = t_circle.r * t_circle.r;


		// ç∂
		if (t_circle.x < t_box.fLeft[CF])
		{
			// ç∂è„
			if ((t_circle.y < t_box.fTop[CF]))
			{
				if ((DistanceSqrf(t_box.fLeft[CF], t_box.fTop[CF], t_circle.x, t_circle.y) >= fl))
				{
					nResult = false;
				}
			}
			else
			{
				// ç∂â∫
				if ((t_circle.y > t_box.fBottom[CF]))
				{
					if ((DistanceSqrf(t_box.fLeft[CF], t_box.fBottom[CF], t_circle.x, t_circle.y) >= fl))
					{
						nResult = false;
					}
				}
			}
		}
		else
		{
			// âE
			if (t_circle.x > t_box.fRight[CF])
			{
				// âEè„
				if ((t_circle.y < t_box.fTop[CF]))
				{
					if ((DistanceSqrf(t_box.fRight[CF], t_box.fTop[CF], t_circle.x, t_circle.y) >= fl))
					{
						nResult = false;
					}
				}
				else
				{
					// âEâ∫
					if ((t_circle.y > t_box.fBottom[CF]))
					{
						if ((DistanceSqrf(t_box.fRight[CF], t_box.fBottom[CF], t_circle.x, t_circle.y) >= fl))
						{
							nResult = false;
						}
					}
				}
			}
		}
	}

	return nResult;
}

bool Enemy2::CheckHit(const BOX1& t_box, const CIRCLE& t_circle) {
	bool nResult = false;

	// éläpå`ÇÃélï”Ç…ëŒÇµÇƒâ~ÇÃîºåaï™ÇæÇØë´ÇµÇΩÇ∆Ç´â~Ç™èdÇ»Ç¡ÇƒÇ¢ÇΩÇÁ
	if ((t_circle.x > t_box.fLeft[I] - t_circle.r) &&
		(t_circle.x < t_box.fRight[I] + t_circle.r) &&
		(t_circle.y > t_box.fTop[I] - t_circle.r) &&
		(t_circle.y < t_box.fBottom[I] + t_circle.r))
	{
		nResult = true;
		float fl = t_circle.r * t_circle.r;


		// ç∂
		if (t_circle.x < t_box.fLeft[I])
		{
			// ç∂è„
			if ((t_circle.y < t_box.fTop[I]))
			{
				if ((DistanceSqrf(t_box.fLeft[I], t_box.fTop[I], t_circle.x, t_circle.y) >= fl))
				{
					nResult = false;
				}
			}
			else
			{
				// ç∂â∫
				if ((t_circle.y > t_box.fBottom[I]))
				{
					if ((DistanceSqrf(t_box.fLeft[I], t_box.fBottom[I], t_circle.x, t_circle.y) >= fl))
					{
						nResult = false;
					}
				}
			}
		}
		else
		{
			// âE
			if (t_circle.x > t_box.fRight[I])
			{
				// âEè„
				if ((t_circle.y < t_box.fTop[I]))
				{
					if ((DistanceSqrf(t_box.fRight[I], t_box.fTop[I], t_circle.x, t_circle.y) >= fl))
					{
						nResult = false;
					}
				}
				else
				{
					// âEâ∫
					if ((t_circle.y > t_box.fBottom[I]))
					{
						if ((DistanceSqrf(t_box.fRight[I], t_box.fBottom[I], t_circle.x, t_circle.y) >= fl))
						{
							nResult = false;
						}
					}
				}
			}
		}
	}

	return nResult;
}

bool Enemy2::CheckHitBOX(const BOX& t_direA, const BOX1& t_direB)
{
	if ((t_direA.fRight[CF] > t_direB.fLeft[I]) &&
		(t_direA.fLeft[CF] < t_direB.fRight[I]))
	{
		if ((t_direA.fBottom[CF] > t_direB.fTop[I]) &&
			(t_direA.fTop[CF] < t_direB.fBottom[I]))
		{
			return true;
		}
	}

	return false;
}

void Enemy2::MapCopy() {
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			MapData[h][w] = a_star.data[h][w].status;
		}
	}
}
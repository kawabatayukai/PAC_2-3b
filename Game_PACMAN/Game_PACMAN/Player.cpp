#include "DxLib.h"
#include "Player.h"
#include "Image.h"
#include "Common.h"
#include "Info.h"
#include "Stage.h"
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

Player g_player;

Player::Player() {

}

void Player::PlayerInit(){
	PX = 640;
	PY = 540;
	KEYFLG = 0;
	NEXTFLG = 0;
	LEFT_FLG = false;
	RIGHT_FLG = false;
	UP_FLG = false;
	DOWN_FLG = false;
	PXC = 0;
	PYC = 0;
	oldX = 0;
	oldY = 0;
	I = 0;
	J = 0;
	C = 0;
	S = 0;
	CI = 0;
	CF = 0;
	FLG_L = 0;
	FLG_R = 0;
	FLG_U = 0;
	FLG_D = 0;
	LC = 0;
	RC = 0;
	UC = 0;
	DC = 0;
	FLG_MAX_L = false;
	FLG_MAX_R = false;
	FLG_MAX_U = false;
	FLG_MAX_D = false;
	PXC = (PX - DRAW_POINT_X) / 30;
	PYC = (PY - DRAW_POINT_Y) / 30;
	OldKeyFlg = 0;
	NextKeyFlg = 0;

	/*BOX				box[783];
	for (int i = 0; i < 783; i++) {
		box[i] = 0;
	}*/

}

void Player::PlayerController() {

	PXC = (PX - DRAW_POINT_X) / 30;
	PYC = (PY - DRAW_POINT_Y) / 30;

	BOX				box[783] = { 0 };
	BOX1			boxP[4] = { 0 };

	//PXC = (PX - DRAW_POINT_X) / MAP_SIZE;
	//PYC = (PY - DRAW_POINT_Y) / MAP_SIZE;

	int a = (1 - DRAW_POINT_X) / MAP_SIZE;
	int b = (3 - DRAW_POINT_Y) / MAP_SIZE;

	/*DrawFormatString(150, 150, 0xFFFFFF, "%d", a);
	DrawFormatString(150, 200, 0xFFFFFF, "%d", b);*/

	oldX = PX;
	oldY = PY;

	/*DrawFormatString(50, 50, 0xFFFFFF, "%d", PXC);
	DrawFormatString(50, 100, 0xFFFFFF, "%d", PYC);

	DrawFormatString(50, 400, 0xFFFFFF, "%d", stage.getMap(PYC, PXC));

	DrawFormatString(50, 150, 0xFFFFFF, "%d", PX);
	DrawFormatString(50, 200, 0xFFFFFF, "%d", PY);

	DrawFormatString(250, 300, 0xFFFFFF, "%d", I);
	DrawFormatString(250, 340, 0xFFFFFF, "%d", J);

	DrawFormatString(100, 50, 0xFFFFFF, "%d", DRAW_POINT_X);
	DrawFormatString(100, 100, 0xFFFFFF, "%d", DRAW_POINT_Y);*/

	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			DrawBox(DRAW_POINT_X + (j * MAP_SIZE), DRAW_POINT_Y + (i * MAP_SIZE), DRAW_POINT_X + (j * MAP_SIZE) + MAP_SIZE, DRAW_POINT_Y + (i * MAP_SIZE) + MAP_SIZE, 0xffffff, false);
		}
	}

	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			DrawBox(DRAW_POINT_X + (j * MAP_SIZE), DRAW_POINT_Y + (i * MAP_SIZE), DRAW_POINT_X + (j * MAP_SIZE) + MAP_SIZE, DRAW_POINT_Y + (i * MAP_SIZE) + MAP_SIZE, 0xffffff, false);
		}
	}

	OldKeyFlg = KEYFLG;

	if (keyFlg & PAD_INPUT_LEFT) {
		if (LC >= 783) {
			KEYFLG = LEFT;
			NEXTFLG = 0;
		}
		else if (LC <= 782) {
			NEXTFLG = LEFT;
		}
	}
		if (keyFlg & PAD_INPUT_RIGHT) {
			if (RC >= 783) {
				KEYFLG = RIGHT;
				NEXTFLG = 0;
			}
			else if (RC <= 782) {
				NEXTFLG = RIGHT;
			}
		}
	if (keyFlg & PAD_INPUT_UP) {
		if (UC >= 783) {
			KEYFLG = UP;
			NEXTFLG = 0;
		}
		else if (UC <= 782) {
			NEXTFLG = UP;
		}
	}
	if (keyFlg & PAD_INPUT_DOWN) {
		if (DC >= 783) {
			KEYFLG = DOWN;
			NEXTFLG = 0;
		}
		else if (DC <= 782) {
			NEXTFLG = DOWN;
		}
	}


	switch (KEYFLG)
	{
	case LEFT:
		//PX -= 3;
		if (FLG_MAX_L == true && NEXTFLG == LEFT) {
			PX -= 4;
		}
		else {
			PX -= 3;
		}
		//DrawGraph(PX, PY, image.PlayerImageL, TRUE);
		DrawGraph(PX-15, PY-15, image.PlayerImageL, TRUE);
		break;
	case RIGHT:
		//PX += 3;
		if (FLG_MAX_R == true && NEXTFLG == RIGHT) {
			PX += 4;
		}
		else {
			PX += 3;
		}
		DrawGraph(PX - 15, PY - 15, image.PlayerImageR, TRUE);
		break;
	case UP:
		//PY -= 3;
		if (FLG_MAX_U == true && NEXTFLG == UP) {
			PY -= 4;
		}
		else {
			PY -= 3;
		}
		DrawGraph(PX - 15, PY - 15, image.PlayerImageU, TRUE);
		break;
	case DOWN:
		//PY += 3;
		if (FLG_MAX_D == true && NEXTFLG == DOWN) {
			PY += 4;
		}
		else {
			PY += 3;
		}
		//DrawGraph(PX, PY, image.PlayerImageD, TRUE);
		DrawGraph(PX-15, PY-15, image.PlayerImageD, TRUE);
		break;
	default:
		//DrawGraph(PX, PY, image.g_PlayerImage, TRUE);
		DrawGraph(PX-15, PY-15, image.g_PlayerImage, TRUE);
		break;

	}


	//BOX				box[783];
	//BOX1			boxP[4];
	CIRCLE			circle;

	circle.x = PX;
	circle.y = PY;
	circle.r = 14.5f;

	if (CheckHitBOX(box[FLG_L], boxP[0]) && NEXTFLG != 0) {
		KEYFLG = NEXTFLG;
		NEXTFLG = 0;
	}
	if (CheckHitBOX(box[FLG_R], boxP[2]) && NEXTFLG != 0) {
		KEYFLG = NEXTFLG;
		NEXTFLG = 0;
	}
	if (CheckHitBOX(box[FLG_U], boxP[1]) && NEXTFLG != 0) {
		KEYFLG = NEXTFLG;
		NEXTFLG = 0;
	}
	if (CheckHitBOX(box[FLG_D], boxP[3]) && NEXTFLG != 0) {
		KEYFLG = NEXTFLG;
		NEXTFLG = 0;
	}

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
							DrawBox(box[C].fLeft[CF], box[C].fTop[CF], box[C].fRight[CF], box[C].fBottom[CF], GetColor(125, 125, 125), true);
							NextKeyFlg = KEYFLG;
							PX = oldX;
							PY = oldY;
							KEYFLG = OldKeyFlg;
						}
						else
						{
							//DrawCircle(circle.x, circle.y, circle.r, GetColor(255, 255, 255));
							DrawBox(box[C].fLeft[CF], box[C].fTop[CF], box[C].fRight[CF], box[C].fBottom[CF], GetColor(125, 125, 125), true);
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
				boxP[I].fLeft[I] = PX - 20;
				boxP[I].fTop[I] = PY - 15;
				boxP[I].fRight[I] = PX - 15 + 30.0f;
				boxP[I].fBottom[I] = PY - 15 + 30.0f;
				break;
			case 1://Up
				boxP[I].fLeft[I] = PX - 15;
				boxP[I].fTop[I] = PY - 20;
				boxP[I].fRight[I] = PX - 15 + 30.0f;
				boxP[I].fBottom[I] = PY - 10 + 25.0f;
				break;
			case 2://Right
				boxP[I].fLeft[I] = PX - 15;
				boxP[I].fTop[I] = PY - 15;
				boxP[I].fRight[I] = PX - 15 + 35.0f;
				boxP[I].fBottom[I] = PY - 15 + 30.0f;
				break;
			case 3://Down
				boxP[I].fLeft[I] = PX - 15;
				boxP[I].fTop[I] = PY - 15;
				boxP[I].fRight[I] = PX - 15 + 30.0f;
				boxP[I].fBottom[I] = PY - 15 + 35.0f;
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

				if (I == 0)FLG_L = CI;
				if (I == 1)FLG_U = CI;
				if (I == 2)FLG_R = CI;
				if (I == 3)FLG_D = CI;

				NextKeyFlg = KEYFLG;

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
			KEYFLG = NEXTFLG;
			NEXTFLG = 0;
		}
		if (FLG_MAX_R == true && NEXTFLG == RIGHT) {
			KEYFLG = NEXTFLG;
			NEXTFLG = 0;
		}
		if (FLG_MAX_U == true && NEXTFLG == UP) {
			KEYFLG = NEXTFLG;
			NEXTFLG = 0;
		}
		if (FLG_MAX_D == true && NEXTFLG == DOWN) {
			KEYFLG = NEXTFLG;
			NEXTFLG = 0;
		}
	}

	if (PX <= 340 && PY == 330 && KEYFLG == LEFT) {
		PX = 940;
	}
	if (PX >= 940 && PY == 330 && KEYFLG == RIGHT) {
		PX = 340;
	}

	/*DrawFormatString(PX, PY-5, 0xFFFFFF, "%d", (g_player.PX - MAP_WIDTH) / 30 - 10);
	DrawFormatString(PX, PY+5, 0xFFFFFF, "%d", (g_player.PY - MAP_HEIGHT) / 30);*/

	/*DrawFormatString(50, 250, 0xFFFFFF, "%d", oldX - PX);
	DrawFormatString(50, 300, 0xFFFFFF, "%d", oldY - PY);

	DrawFormatString(50, 500, 0xFFFFFF, "%d", DRAW_POINT_X);
	DrawFormatString(50, 550, 0xFFFFFF, "%d", DRAW_POINT_Y);*/

	DrawFormatString(1000, 500, 0xFFFFFF, "%d", PXC);
	DrawFormatString(1000, 550, 0xFFFFFF, "%d", PYC);

}

float Player::DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2) {
	float dx = t_x2 - t_x1;
	float dy = t_y2 - t_y1;

	return (dx * dx) + (dy * dy);
}

bool Player::CheckHit(const BOX& t_box, const CIRCLE& t_circle) {
	bool nResult = false;

	// �l�p�`�̎l�ӂɑ΂��ĉ~�̔��a�������������Ƃ��~���d�Ȃ��Ă�����
	if ((t_circle.x > t_box.fLeft[CF] - t_circle.r) &&
		(t_circle.x < t_box.fRight[CF] + t_circle.r) &&
		(t_circle.y > t_box.fTop[CF] - t_circle.r) &&
		(t_circle.y < t_box.fBottom[CF] + t_circle.r))
	{
		nResult = true;
		float fl = t_circle.r * t_circle.r;


		// ��
		if (t_circle.x < t_box.fLeft[CF])
		{
			// ����
			if ((t_circle.y < t_box.fTop[CF]))
			{
				if ((DistanceSqrf(t_box.fLeft[CF], t_box.fTop[CF], t_circle.x, t_circle.y) >= fl))
				{
					nResult = false;
				}
			}
			else
			{
				// ����
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
			// �E
			if (t_circle.x > t_box.fRight[CF])
			{
				// �E��
				if ((t_circle.y < t_box.fTop[CF]))
				{
					if ((DistanceSqrf(t_box.fRight[CF], t_box.fTop[CF], t_circle.x, t_circle.y) >= fl))
					{
						nResult = false;
					}
				}
				else
				{
					// �E��
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

bool Player::CheckHit(const BOX1& t_box, const CIRCLE& t_circle) {
	bool nResult = false;

	// �l�p�`�̎l�ӂɑ΂��ĉ~�̔��a�������������Ƃ��~���d�Ȃ��Ă�����
	if ((t_circle.x > t_box.fLeft[I] - t_circle.r) &&
		(t_circle.x < t_box.fRight[I] + t_circle.r) &&
		(t_circle.y > t_box.fTop[I] - t_circle.r) &&
		(t_circle.y < t_box.fBottom[I] + t_circle.r))
	{
		nResult = true;
		float fl = t_circle.r * t_circle.r;


		// ��
		if (t_circle.x < t_box.fLeft[I])
		{
			// ����
			if ((t_circle.y < t_box.fTop[I]))
			{
				if ((DistanceSqrf(t_box.fLeft[I], t_box.fTop[I], t_circle.x, t_circle.y) >= fl))
				{
					nResult = false;
				}
			}
			else
			{
				// ����
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
			// �E
			if (t_circle.x > t_box.fRight[I])
			{
				// �E��
				if ((t_circle.y < t_box.fTop[I]))
				{
					if ((DistanceSqrf(t_box.fRight[I], t_box.fTop[I], t_circle.x, t_circle.y) >= fl))
					{
						nResult = false;
					}
				}
				else
				{
					// �E��
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

bool Player::CheckHitBOX(const BOX& t_direA, const BOX1& t_direB)
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
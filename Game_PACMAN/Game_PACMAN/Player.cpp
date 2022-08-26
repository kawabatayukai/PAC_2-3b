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
	PX = 655;
	PY = 555;
	KEYFLG = 0;
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
}

void Player::PlayerController() {

	PXC = (PX - DRAW_POINT_X) / MAP_SIZE;
	PYC = (PY - DRAW_POINT_Y) / MAP_SIZE;

	int a = (1 - DRAW_POINT_X) / MAP_SIZE;
	int b = (3 - DRAW_POINT_Y) / MAP_SIZE;

	DrawFormatString(150, 150, 0xFFFFFF, "%d", a);
	DrawFormatString(150, 200, 0xFFFFFF, "%d", b);

	oldX = PX;
	oldY = PY;

	DrawFormatString(50, 50, 0xFFFFFF, "%d", PXC);
	DrawFormatString(50, 100, 0xFFFFFF, "%d", PYC);

	DrawFormatString(50, 400, 0xFFFFFF, "%d", stage.getMap(PYC, PXC));

	DrawFormatString(50, 150, 0xFFFFFF, "%d", PX);
	DrawFormatString(50, 200, 0xFFFFFF, "%d", PY);

	DrawFormatString(250, 300, 0xFFFFFF, "%d", I);
	DrawFormatString(250, 340, 0xFFFFFF, "%d", J);

	DrawFormatString(100, 50, 0xFFFFFF, "%d", DRAW_POINT_X);
	DrawFormatString(100, 100, 0xFFFFFF, "%d", DRAW_POINT_Y);

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


	if (keyFlg & PAD_INPUT_LEFT) KEYFLG = LEFT;
	if (keyFlg & PAD_INPUT_RIGHT) KEYFLG = RIGHT;
	if (keyFlg & PAD_INPUT_UP)KEYFLG = UP;
	if (keyFlg & PAD_INPUT_DOWN)KEYFLG = DOWN;

	//if (stage.getMap(PYC, PXC) != 0) {
	//	PX = oldX;
	//	PY = oldY;
	//}

	switch (KEYFLG)
	{
	case LEFT:
		PX -= 3;
		/*if (stage.getMap(PYC,PXC - 1) == 0)PX -= 3;
		if (stage.getMap(PYC, PXC) != 0) {
			PX = oldX;
			PY = oldY;
		}*/
		//DrawGraph(PX, PY, image.PlayerImageL, TRUE);
		DrawGraph(PX-15, PY-15, image.PlayerImageL, TRUE);
		break;
	case RIGHT:
		PX += 3;
		/*if (stage.getMap(PYC, PXC + 1) == 0)PX += 3;
		if (stage.getMap(PYC, PXC) != 0) {
			PX = oldX;
			PY = oldY;
		}*/
		DrawGraph(PX - 15, PY - 15, image.PlayerImageR, TRUE);
		break;
	case UP:
		PY -= 3;
		/*if (stage.getMap(PYC - 1, PXC) == 0)PY -= 3;
		if (stage.getMap(PYC, PXC) != 0) {
			PX = oldX;
			PY = oldY;
		}*/
		DrawGraph(PX - 15, PY - 15, image.PlayerImageU, TRUE);
		break;
	case DOWN:
		PY += 3;
		/*if (stage.getMap(PYC + 1, PXC) == 0)PY += 3;
		if (stage.getMap(PYC, PXC) != 0) {
			PX = oldX;
			PY = oldY;
		}*/
		//DrawGraph(PX, PY, image.PlayerImageD, TRUE);
		DrawGraph(PX-15, PY-15, image.PlayerImageD, TRUE);
		break;
	default:
		//DrawGraph(PX, PY, image.g_PlayerImage, TRUE);
		DrawGraph(PX-15, PY-15, image.g_PlayerImage, TRUE);
		break;

	}

	BOX				box[483];
	CIRCLE			circle;

	circle.x = PX;
	circle.y = PY;
	circle.r = 14.0f;

	for (I = 0; I < MAP_HEIGHT; I++) {
		for (J = 0; J < MAP_WIDTH; J++) {
			if (stage.getMap(I, J) != 0) {
				box[C].fLeft[C] = DRAW_POINT_X + (J * 30);
				box[C].fTop[C] = DRAW_POINT_Y + (I * 30);
				box[C].fRight[C] = DRAW_POINT_X + (J * 30) + 30.0f;
				box[C].fBottom[C] = DRAW_POINT_Y + (I * 30) + 30.0f;

				if (CheckHit(box[C], circle))
				{
					//DrawCircle(circle.x, circle.y, circle.r, GetColor(125, 125, 125));
					DrawBox(box[C].fLeft[C], box[C].fTop[C], box[C].fRight[C], box[C].fBottom[C], GetColor(125, 125, 125), true);
					PX = oldX;
					PY = oldY;
				}
				else
				{
					//DrawCircle(circle.x, circle.y, circle.r, GetColor(255, 255, 255));
					DrawBox(box[C].fLeft[C], box[C].fTop[C], box[C].fRight[C], box[C].fBottom[C], GetColor(125, 125, 125), true);
				}
				DrawFormatString(box[C].fLeft[C], box[C].fTop[C], 0xFF00FF, "%d", C);

			}
			C++;
		}
	}
	I = 0;
	J = 0;
	C = 0;

	DrawFormatString(50, 500, 0xFFFFFF, "%d", CheckHit(box[C], circle));

	//if (CheckHit(box[S], circle)) {
	//	PX = oldX;
	//	PY = oldY;
	//}

	//if (S >= 483) {
	//	S = 0;
	//}
	//else {
	//	S++;
	//}
}

float Player::DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2) {
	float dx = t_x2 - t_x1;
	float dy = t_y2 - t_y1;

	return (dx * dx) + (dy * dy);
}

bool Player::CheckHit(const BOX& t_box, const CIRCLE& t_circle) {
	bool nResult = false;

	// éläpå`ÇÃélï”Ç…ëŒÇµÇƒâ~ÇÃîºåaï™ÇæÇØë´ÇµÇΩÇ∆Ç´â~Ç™èdÇ»Ç¡ÇƒÇ¢ÇΩÇÁ
	if ((t_circle.x > t_box.fLeft[C] - t_circle.r) &&
		(t_circle.x < t_box.fRight[C] + t_circle.r) &&
		(t_circle.y > t_box.fTop[C] - t_circle.r) &&
		(t_circle.y < t_box.fBottom[C] + t_circle.r))
	{
		nResult = true;
		float fl = t_circle.r * t_circle.r;


		// ç∂
		if (t_circle.x < t_box.fLeft[C])
		{
			// ç∂è„
			if ((t_circle.y < t_box.fTop[C]))
			{
				if ((DistanceSqrf(t_box.fLeft[C], t_box.fTop[C], t_circle.x, t_circle.y) >= fl))
				{
					nResult = false;
				}
			}
			else
			{
				// ç∂â∫
				if ((t_circle.y > t_box.fBottom[C]))
				{
					if ((DistanceSqrf(t_box.fLeft[C], t_box.fBottom[C], t_circle.x, t_circle.y) >= fl))
					{
						nResult = false;
					}
				}
			}
		}
		else
		{
			// âE
			if (t_circle.x > t_box.fRight[C])
			{
				// âEè„
				if ((t_circle.y < t_box.fTop[C]))
				{
					if ((DistanceSqrf(t_box.fRight[C], t_box.fTop[C], t_circle.x, t_circle.y) >= fl))
					{
						nResult = false;
					}
				}
				else
				{
					// âEâ∫
					if ((t_circle.y > t_box.fBottom[C]))
					{
						if ((DistanceSqrf(t_box.fRight[C], t_box.fBottom[C], t_circle.x, t_circle.y) >= fl))
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
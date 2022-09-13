#include "DxLib.h"
#include "bait.h"
#include "Image.h"
#include "Player.h"
#include "Info.h"

Bait bait;

Bait::Bait() {
	I = 0;
}

void Bait::BaitInit() {

}

void Bait::CreateBait() {

	for (I = 0; I < BAIT_MAX; I++) {

		if (bait[I].flg == false) {
			bait[I] = bait00;

			//if (I == 30 || I == 35 || I == 152 || I == 171) {
			if (I == 18 || I == 23 || I == 107 || I == 122) {
				bait[I].type = 1;
			}
			if (bait[I].type == 0)bait[I].img = image.EsaImage;
			if (bait[I].type == 1)bait[I].img = image.PowerEsaImage;

			
		}
	}
}

void Bait::BaitController() {
	for (I = 0; I < BAIT_MAX; I++) {
		CIRCLE circlebait[BAIT_MAX], circleP;

		circlebait[I].x = bait[I].x;
		circlebait[I].y = bait[I].y;
		circlebait[I].r = 3.0f;

		circleP.x = g_player.PX;
		circleP.y = g_player.PY;
		circleP.r = 6.5f;
		DrawFormatString(1000,700,0xffffff,"%d",pscore);
		DrawCircle(circleP.x, circleP.y, circleP.r, GetColor(255, 255, 255));
		if (bait[I].flg == true) {
			//for (int j = 0; j < BAIT_MAX; j++) {

				if (I < 9) {//1—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * I;
				circlebait[I].y = bait[I].y;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}else if (I < 18) {//1—ñ–Ú
					circlebait[I].x = bait[I].x + MAP_SIZE * I + 30;
					circlebait[I].y = bait[I].y;
					DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
					//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}else if (I < 19) {//2—ñ–Ú
					circlebait[I].x = bait[I].x;
					circlebait[I].y = bait[I].y + 33;
					DrawGraph(circlebait[I].x - 7, circlebait[I].y - 10, bait[I].img, true);
					//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 20) {//2—ñ–Ú
					circlebait[I].x = bait[I].x + MAP_SIZE * 3;
					circlebait[I].y = bait[I].y + MAP_SIZE;
					DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
					//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 21) {//2—ñ–Ú
					circlebait[I].x = bait[I].x + MAP_SIZE * 8;
					circlebait[I].y = bait[I].y + MAP_SIZE;
					DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
					//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 22) {//2—ñ–Ú
					circlebait[I].x = bait[I].x + MAP_SIZE * 10;
					circlebait[I].y = bait[I].y + MAP_SIZE;
					DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
					//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 23) {//2—ñ–Ú
					circlebait[I].x = bait[I].x + MAP_SIZE * 15;
					circlebait[I].y = bait[I].y + MAP_SIZE;
					DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
					//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 24) {//2—ñ–Ú
					circlebait[I].x = bait[I].x + MAP_SIZE * 18;
					circlebait[I].y = bait[I].y + 33;
					DrawGraph(circlebait[I].x - 7, circlebait[I].y - 10, bait[I].img, true);
					//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 43) {//3—ñ–Ú
					circlebait[I].x = bait[I].x + MAP_SIZE * (I - 24);
					circlebait[I].y = bait[I].y + MAP_SIZE * 2;
					DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
					//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 44) {//4—ñ–Ú
					circlebait[I].x = bait[I].x;
					circlebait[I].y = bait[I].y + MAP_SIZE * 3;
					DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
					//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 45) {//4—ñ–Ú
					circlebait[I].x = bait[I].x + MAP_SIZE * 3;
					circlebait[I].y = bait[I].y + MAP_SIZE * 3;
					DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
					//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 46) {//4—ñ–Ú
					circlebait[I].x = bait[I].x + MAP_SIZE * 5;
					circlebait[I].y = bait[I].y + MAP_SIZE * 3;
					DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
					//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 47) {//4—ñ–Ú
					circlebait[I].x = bait[I].x + MAP_SIZE * 13;
					circlebait[I].y = bait[I].y + MAP_SIZE * 3;
					DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
					//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 48) {//4—ñ–Ú
					circlebait[I].x = bait[I].x + MAP_SIZE * 15;
					circlebait[I].y = bait[I].y + MAP_SIZE * 3;
					DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
					//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 49) {//4—ñ–Ú
					circlebait[I].x = bait[I].x + MAP_SIZE * 18;
					circlebait[I].y = bait[I].y + MAP_SIZE * 3;
					DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
					//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 53) {//5—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 49);
				circlebait[I].y = bait[I].y + MAP_SIZE * 4;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 57) {//5—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 48);
				circlebait[I].y = bait[I].y + MAP_SIZE * 4;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 61) {//5—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 47);
				circlebait[I].y = bait[I].y + MAP_SIZE * 4;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 65) {//5—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 46);
				circlebait[I].y = bait[I].y + MAP_SIZE * 4;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 74) {
				circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				circlebait[I].y = bait[I].y + MAP_SIZE * (I - 60);
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 83) {
				circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				circlebait[I].y = bait[I].y + MAP_SIZE * (I - 69);
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}else if (I < 92) {//1—ñ–Ú
					circlebait[I].x = bait[I].x + MAP_SIZE * (I - 83);
					circlebait[I].y = bait[I].y + MAP_SIZE * 14;
					DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
					//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 101) {//1—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 82);
				circlebait[I].y = bait[I].y + MAP_SIZE * 14;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 102) {//2—ñ–Ú
				circlebait[I].x = bait[I].x;
				circlebait[I].y = bait[I].y + MAP_SIZE * 15;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 103) {//2—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				circlebait[I].y = bait[I].y + MAP_SIZE * 15;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 104) {//2—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * 8;
				circlebait[I].y = bait[I].y + MAP_SIZE * 15;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 105) {//2—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * 10;
				circlebait[I].y = bait[I].y + MAP_SIZE * 15;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 106) {//2—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				circlebait[I].y = bait[I].y + MAP_SIZE * 15;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 107) {//2—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				circlebait[I].y = bait[I].y + MAP_SIZE * 15;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 108) {//2—ñ–Ú(power)
				circlebait[I].x = bait[I].x;
				circlebait[I].y = bait[I].y + 33 + MAP_SIZE * 15;
					DrawGraph(circlebait[I].x - 7, circlebait[I].y - 10, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 109) {//2—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE;
				circlebait[I].y = bait[I].y + MAP_SIZE * 16;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 115) {//2—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 106);
				circlebait[I].y = bait[I].y + MAP_SIZE * 16;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 121) {//2—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 105);
				circlebait[I].y = bait[I].y + MAP_SIZE * 16;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				
				else if (I < 122) {//2—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * 17;
				circlebait[I].y = bait[I].y + MAP_SIZE * 16;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 123) {//2—ñ–Ú(power)
				circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				circlebait[I].y = bait[I].y + 33 + MAP_SIZE * 15;
				DrawGraph(circlebait[I].x - 7, circlebait[I].y - 10, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 124) {//2—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE;
				circlebait[I].y = bait[I].y + MAP_SIZE * 17;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 125) {//2—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				circlebait[I].y = bait[I].y + MAP_SIZE * 17;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 126) {//2—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * 5;
				circlebait[I].y = bait[I].y + MAP_SIZE * 17;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 127) {//2—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * 13;
				circlebait[I].y = bait[I].y + MAP_SIZE * 17;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 128) {//2—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				circlebait[I].y = bait[I].y + MAP_SIZE * 17;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 129) {//2—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * 17;
				circlebait[I].y = bait[I].y + MAP_SIZE * 17;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 133) {//5—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 129);
				circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 137) {//5—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 128);
				circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 141) {//5—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 127);
				circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 145) {//5—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 126);
				circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 146) {//5—ñ–Ú
				circlebait[I].x = bait[I].x;
				circlebait[I].y = bait[I].y + MAP_SIZE * 19;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 147) {//5—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * 8;
				circlebait[I].y = bait[I].y + MAP_SIZE * 19;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 148) {//5—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * 10;
				circlebait[I].y = bait[I].y + MAP_SIZE * 19;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 149) {//5—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				circlebait[I].y = bait[I].y + MAP_SIZE * 19;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				else if (I < 168) {//3—ñ–Ú
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 149);
				circlebait[I].y = bait[I].y + MAP_SIZE * 20;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

				}
				
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
			//}
			//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
			if (CheckHit(circlebait[I], circleP)) {
				pscore++;
				bait[I].flg = false;
			}
		}
	}
}

bool Bait::CheckHit(const CIRCLE& t_circleA, const CIRCLE& t_circleB)
{
	float dx = t_circleA.x - t_circleB.x;
	float dy = t_circleA.y - t_circleB.y;
	float dr = dx * dx + dy * dy;

	float ar = t_circleA.r + t_circleB.r;
	float dl = ar * ar;
	if (dr < dl)
	{
		return true;
	}

	return false;
}

//if (I < 12) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + I * 22;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//	//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 24) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + 36 + I * 22;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//	//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}


				//if (I == 0) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I == 1) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + 25;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I == 2) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 15;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I == 3) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 35;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I == 4) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 60;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I == 5) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 85;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I == 6) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 105;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I == 7) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 125;
				//	circlebait[I].y = bait[I].y ;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I == 8) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 147;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 10) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 169;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 11) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 190;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 12) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 210;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}else if (I < 13) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 270;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 14) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 290;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 15) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 310;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 16) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 331;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 17) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 352;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 18) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 373;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 19) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 395;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 20) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 420;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 21) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 445;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 22) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 468;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 23) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 490;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 24) {//1—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE + 510;
				//	circlebait[I].y = bait[I].y;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 25) {//2—ñ–Ú
				//	circlebait[I].x = bait[I].x;
				//	circlebait[I].y = bait[I].y+15;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 26) {//2—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//	circlebait[I].y = bait[I].y + 15;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 27) {//2—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE * 8;
				//	circlebait[I].y = bait[I].y + 15;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 28) {//2—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE * 10;
				//	circlebait[I].y = bait[I].y + 15;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 29) {//2—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//	circlebait[I].y = bait[I].y + 15;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 30) {//2—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				//	circlebait[I].y = bait[I].y + 15;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 31) {//3—ñ–Ú(power)
				//	circlebait[I].x = bait[I].x;
				//	circlebait[I].y = bait[I].y + 33;
				//	DrawGraph(circlebait[I].x - 7, circlebait[I].y - 10, bait[I].img, true);
				//	//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 32) {//3—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//	circlebait[I].y = bait[I].y + MAP_SIZE;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 33) {//3—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE * 8;
				//	circlebait[I].y = bait[I].y + MAP_SIZE;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 34) {//3—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE * 10;
				//	circlebait[I].y = bait[I].y + MAP_SIZE;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 35) {//3—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//	circlebait[I].y = bait[I].y + MAP_SIZE;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 36) {//3—ñ–Ú(power)
				//	circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				//	circlebait[I].y = bait[I].y + 33;
				//	DrawGraph(circlebait[I].x - 7, circlebait[I].y - 10, bait[I].img, true);
				//	//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));}
				//}
				//else if (I < 37) {//4—ñ–Ú
				//	circlebait[I].x = bait[I].x;
				//	circlebait[I].y = bait[I].y + MAP_SIZE + 18;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 38) {//4—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//	circlebait[I].y = bait[I].y + MAP_SIZE + 18;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 39) {//4—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE * 8;
				//	circlebait[I].y = bait[I].y + MAP_SIZE + 18;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 40) {//4—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE * 10;
				//	circlebait[I].y = bait[I].y + MAP_SIZE + 18;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 41) {//4—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//	circlebait[I].y = bait[I].y + MAP_SIZE + 18;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 42) {//4—ñ–Ú
				//	circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				//	circlebait[I].y = bait[I].y + MAP_SIZE + 18;
				//	DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 43) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 44) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + 25;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 45) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 46) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 35;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 47) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 60;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 48) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 85;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 49) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 105;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 50) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 125;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 51) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 147;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 52) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 169;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 53) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 190;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 54) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 210;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 55) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 240;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 56) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 270;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 57) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 290;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 58) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 310;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 59) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 331;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 60) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 352;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 61) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 373;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 62) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 395;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 63) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 420;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 64) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 445;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 65) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 468;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 66) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 490;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 67) {//5—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 510;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 30;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 69) {//6—ñ–Ú
				//circlebait[I].x = bait[I].x;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 45;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 70) {//6—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 45;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 71) {//6—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 5;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 45;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 72) {//6—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 13;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 45;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 73) {//6—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 45;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 74) {//6—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 45;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 75) {//7—ñ–Ú
				//circlebait[I].x = bait[I].x;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 60;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 76) {//7—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 60;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 77) {//7—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 5;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 60;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 78) {//7—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 13;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 60;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 79) {//7—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 60;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 80) {//7—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 60;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 84) {//8—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * (I - 80);
				//circlebait[I].y = bait[I].y + MAP_SIZE + 90;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 88) {//8—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * (I - 79);
				//circlebait[I].y = bait[I].y + MAP_SIZE + 90;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 92) {//8—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * (I - 78);
				//circlebait[I].y = bait[I].y + MAP_SIZE + 90;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 96) {//8—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * (I - 77);
				//circlebait[I].y = bait[I].y + MAP_SIZE + 90;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 97) {//9—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 117;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 98) {//9—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 117;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 99) {//10—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 144;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 100) {//10—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 144;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 101) {//11—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 171;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 102) {//11—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 171;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 103) {//12—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 198;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 104) {//12—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 198;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 105) {//13—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 225;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 106) {//13—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 225;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 107) {//14—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 252;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 108) {//14—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 252;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 109) {//15—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 279;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 110) {//15—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 279;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 111) {//16—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 306;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 112) {//16—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 306;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 113) {//17—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 333;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 114) {//17—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 333;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 115) {//18—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 360;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 116) {//18—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 360;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 117) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//if (I < 118 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + 25;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 119 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 120 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 35;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 121 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 60;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 122 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 85;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 123 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 105;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 124 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 125;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 125 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 147;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 126 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 169;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 127 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 190;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 128 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 210;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 129 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 270;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 130 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 290;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 131 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 310;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 132 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 331;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 133 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 352;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 134 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 373;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 135 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 395;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 136 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 420;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 137 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 445;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 138 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 468;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 139 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 490;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 140 && I > 116) {//19—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE + 510;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 390;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 141 && I > 116) {//20—ñ–Ú
				//circlebait[I].x = bait[I].x;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 410;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 142 && I > 116) {//20—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 410;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 143 && I > 116) {//20—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 8;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 410;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 144 && I > 116) {//20—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 10;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 410;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 145 && I > 116) {//20—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 410;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 146 && I > 116) {//20—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 410;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 147 && I > 116) {//21—ñ–Ú
				//circlebait[I].x = bait[I].x;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 425;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 148 && I > 116) {//21—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 425;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 149 && I > 116) {//21—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 8;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 425;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 150 && I > 116) {//21—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 10;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 425;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 151 && I > 116) {//21—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 425;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 152 && I > 116) {//21—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 425;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//}
				//else if (I < 153 && I > 116) {//22—ñ–Ú(power)
				//circlebait[I].x = bait[I].x;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 425 + 28;
				//DrawGraph(circlebait[I].x - 7, circlebait[I].y - 10, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 154 && I > 116) {//22—ñ–Ú
				//circlebait[I].x = bait[I].x + 17;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 450;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 155 && I > 116) {//22—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 450;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 156 && I > 116) {//22—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 450;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 157 && I > 116) {//22—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3 + 24;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 450;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 158 && I > 116) {//22—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3 + 48;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 450;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 159 && I > 116) {//22—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3 + 72;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 450;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 160 && I > 116) {//22—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3 + 96;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 450;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 161 && I > 116) {//22—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3 + 120;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 450;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 162 && I > 116) {//22—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 8;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 450;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 163 && I > 116) {//22—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 10;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 450;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 164 && I > 116) {//22—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 10 + 24;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 450;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 165 && I > 116) {//22—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 10 + 48;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 450;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 166 && I > 116) {//22—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 10 + 72;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 450;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 167 && I > 116) {//22—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 10 + 96;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 450;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 168 && I > 116) {//22—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 10 + 120;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 450;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 169 && I > 116) {//22—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 450;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 170 && I > 116) {//22—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 17;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 450;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 171 && I > 116) {//22—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 17 + 17;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 450;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 172 && I > 116) {//22—ñ–Ú(power)
				//circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 425 + 28;
				//DrawGraph(circlebait[I].x - 7, circlebait[I].y - 10, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 173 && I > 116) {//23—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 470;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 174 && I > 116) {//23—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 470;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 175 && I > 116) {//23—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 5;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 470;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 176 && I > 116) {//23—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 13;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 470;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 177 && I > 116) {//23—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 470;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 178 && I > 116) {//23—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 17;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 470;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 179 && I > 116) {//24—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 487;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 180 && I > 116) {//24—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 487;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 181 && I > 116) {//24—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 5;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 487;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 182 && I > 116) {//24—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 13;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 487;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 183 && I > 116) {//24—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 487;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 184 && I > 116) {//24—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 17;
				//circlebait[I].y = bait[I].y + MAP_SIZE + 487;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 185 && I > 116) {//25—ñ–Ú
				//circlebait[I].x = bait[I].x;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 186 && I > 116) {//25—ñ–Ú
				//circlebait[I].x = bait[I].x + 18;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 187 && I > 116) {//25—ñ–Ú
				//circlebait[I].x = bait[I].x + 35;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 188 && I > 116) {//25—ñ–Ú
				//circlebait[I].x = bait[I].x + 52;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 189 && I > 116) {//25—ñ–Ú
				//circlebait[I].x = bait[I].x + 69;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 190 && I > 116) {//25—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 194 && I > 116) {//25—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE *  (I - 185);
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 198 && I > 116) {//25—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * (I - 184);
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 199 && I > 116) {//25—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 200 && I > 116) {//25—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15 + 18;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 201 && I > 116) {//25—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15 + 35;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 202 && I > 116) {//25—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15 + 52;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 203 && I > 116) {//25—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 15 + 69;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 204 && I > 116) {//25—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 205 && I > 116) {//26—ñ–Ú
				//circlebait[I].x = bait[I].x;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18 + 20;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 206 && I > 116) {//26—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 8;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18 + 20;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 207 && I > 116) {//26—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 10;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18 + 20;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 208 && I > 116) {//26—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18 + 20;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 209 && I > 116) {//27—ñ–Ú
				//circlebait[I].x = bait[I].x;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18 + 40;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 210 && I > 116) {//27—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 8;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18 + 40;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 211 && I > 116) {//27—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 10;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18 + 40;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 212 && I > 116) {//27—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 18 + 40;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 213 && I > 116) {//28—ñ–Ú
				//circlebait[I].x = bait[I].x;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 20;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 227 && I > 116) {//28—ñ–Ú
				//circlebait[I].x = bait[I].x + (MAP_SIZE * (I - 212))/2;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 20;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 230 && I > 116) {//28—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * (I - 219);
				//circlebait[I].y = bait[I].y + MAP_SIZE * 20;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 237 && I > 116) {//28—ñ–Ú
				//circlebait[I].x = bait[I].x + (MAP_SIZE * (I - 208)) / 2;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 20;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 243 && I > 116) {//28—ñ–Ú
				//circlebait[I].x = bait[I].x + (MAP_SIZE * (I - 207))/2;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 20;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
				//else if (I < 244 && I > 116) {//28—ñ–Ú
				//circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				//circlebait[I].y = bait[I].y + MAP_SIZE * 20;
				//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				////DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
				//}
#include "DxLib.h"
#include "bait.h"
#include "Info.h"
#include "Stage.h"
#include"sounds.h"

Bait bait;

Bait::Bait() {
	I = 0;
	Timer = 0;
}

int Bait::LoadImages()
{
	if ((BaitImage = LoadGraph("images/Esa_V2.png")) == -1) return -1;
	if ((PowerImage = LoadGraph("images/PowerEsa_V2.png")) == -1) return -1;
}

void Bait::BaitInit() {

}

void Bait::CreateBait() {

	pscore = 0;  //食べた数初期化

	for (I = 0; I < BAIT_MAX; I++) {

		if (bait[I].flg == false) {
			bait[I] = bait00;

			//if (I == 30 || I == 35 || I == 152 || I == 171) {
			if (I == 18 || I == 23 || I == 107 || I == 122) {
				bait[I].type = 1;
			}
			if (bait[I].type == 0)bait[I].img = BaitImage;
			if (bait[I].type == 1)bait[I].img = PowerImage;


		}
	}
}

void Bait::BaitController(int playerX, int playerY)
{
	if (Timer++ >= 20)Timer = 0;
	for (I = 0; I < BAIT_MAX; I++) {
		CIRCLE circlebait[BAIT_MAX], circleP;

		circlebait[I].x = bait[I].x;
		circlebait[I].y = bait[I].y;
		circlebait[I].r = 3.0f;

		circleP.x = playerX;
		circleP.y = playerY;
		circleP.r = 6.5f;
		DrawFormatString(1000, 700, 0xffffff, "%d", pscore);
		//DrawCircle(circleP.x, circleP.y, circleP.r, GetColor(255, 255, 255));
		if (bait[I].flg == true) {
			//for (int j = 0; j < BAIT_MAX; j++) {

			if (I < 9) {//1列目
				circlebait[I].x = bait[I].x + MAP_SIZE * I;
				circlebait[I].y = bait[I].y;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 18) {//1列目
				circlebait[I].x = bait[I].x + MAP_SIZE * I + 30;
				circlebait[I].y = bait[I].y;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 19) {//2列目
				circlebait[I].x = bait[I].x;
				circlebait[I].y = bait[I].y + 33;
				if (Timer <= 10) {
					DrawGraph(circlebait[I].x - 7, circlebait[I].y - 10, bait[I].img, true);
				}
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 20) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				circlebait[I].y = bait[I].y + MAP_SIZE;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 21) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 8;
				circlebait[I].y = bait[I].y + MAP_SIZE;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 22) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 10;
				circlebait[I].y = bait[I].y + MAP_SIZE;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 23) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				circlebait[I].y = bait[I].y + MAP_SIZE;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 24) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				circlebait[I].y = bait[I].y + 33;
				if (Timer <= 10) {
					DrawGraph(circlebait[I].x - 7, circlebait[I].y - 10, bait[I].img, true);
				}
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 43) {//3列目
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 24);
				circlebait[I].y = bait[I].y + MAP_SIZE * 2;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 44) {//4列目
				circlebait[I].x = bait[I].x;
				circlebait[I].y = bait[I].y + MAP_SIZE * 3;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 45) {//4列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				circlebait[I].y = bait[I].y + MAP_SIZE * 3;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 46) {//4列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 5;
				circlebait[I].y = bait[I].y + MAP_SIZE * 3;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 47) {//4列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 13;
				circlebait[I].y = bait[I].y + MAP_SIZE * 3;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 48) {//4列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				circlebait[I].y = bait[I].y + MAP_SIZE * 3;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 49) {//4列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				circlebait[I].y = bait[I].y + MAP_SIZE * 3;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 53) {//5列目
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 49);
				circlebait[I].y = bait[I].y + MAP_SIZE * 4;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 57) {//5列目
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 48);
				circlebait[I].y = bait[I].y + MAP_SIZE * 4;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 61) {//5列目
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 47);
				circlebait[I].y = bait[I].y + MAP_SIZE * 4;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 65) {//5列目
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

			}
			else if (I < 92) {//1列目
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 83);
				circlebait[I].y = bait[I].y + MAP_SIZE * 14;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 101) {//1列目
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 82);
				circlebait[I].y = bait[I].y + MAP_SIZE * 14;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 102) {//2列目
				circlebait[I].x = bait[I].x;
				circlebait[I].y = bait[I].y + MAP_SIZE * 15;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 103) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				circlebait[I].y = bait[I].y + MAP_SIZE * 15;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 104) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 8;
				circlebait[I].y = bait[I].y + MAP_SIZE * 15;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 105) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 10;
				circlebait[I].y = bait[I].y + MAP_SIZE * 15;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 106) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				circlebait[I].y = bait[I].y + MAP_SIZE * 15;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 107) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				circlebait[I].y = bait[I].y + MAP_SIZE * 15;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 108) {//2列目(power)
				circlebait[I].x = bait[I].x;
				circlebait[I].y = bait[I].y + 33 + MAP_SIZE * 15;
				if (Timer <= 10) {
					DrawGraph(circlebait[I].x - 7, circlebait[I].y - 10, bait[I].img, true);
				}
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 109) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE;
				circlebait[I].y = bait[I].y + MAP_SIZE * 16;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 115) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 106);
				circlebait[I].y = bait[I].y + MAP_SIZE * 16;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 121) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 105);
				circlebait[I].y = bait[I].y + MAP_SIZE * 16;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}

			else if (I < 122) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 17;
				circlebait[I].y = bait[I].y + MAP_SIZE * 16;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 123) {//2列目(power)
				circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				circlebait[I].y = bait[I].y + 33 + MAP_SIZE * 15;
				if (Timer <= 10) {
					DrawGraph(circlebait[I].x - 7, circlebait[I].y - 10, bait[I].img, true);
				}
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 124) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE;
				circlebait[I].y = bait[I].y + MAP_SIZE * 17;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 125) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 3;
				circlebait[I].y = bait[I].y + MAP_SIZE * 17;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 126) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 5;
				circlebait[I].y = bait[I].y + MAP_SIZE * 17;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 127) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 13;
				circlebait[I].y = bait[I].y + MAP_SIZE * 17;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 128) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 15;
				circlebait[I].y = bait[I].y + MAP_SIZE * 17;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 129) {//2列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 17;
				circlebait[I].y = bait[I].y + MAP_SIZE * 17;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 133) {//5列目
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 129);
				circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 137) {//5列目
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 128);
				circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 141) {//5列目
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 127);
				circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 145) {//5列目
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 126);
				circlebait[I].y = bait[I].y + MAP_SIZE * 18;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 146) {//5列目
				circlebait[I].x = bait[I].x;
				circlebait[I].y = bait[I].y + MAP_SIZE * 19;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 147) {//5列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 8;
				circlebait[I].y = bait[I].y + MAP_SIZE * 19;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 148) {//5列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 10;
				circlebait[I].y = bait[I].y + MAP_SIZE * 19;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 149) {//5列目
				circlebait[I].x = bait[I].x + MAP_SIZE * 18;
				circlebait[I].y = bait[I].y + MAP_SIZE * 19;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}
			else if (I < 168) {//3列目
				circlebait[I].x = bait[I].x + MAP_SIZE * (I - 149);
				circlebait[I].y = bait[I].y + MAP_SIZE * 20;
				DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
				//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));

			}

			//DrawGraph(circlebait[I].x, circlebait[I].y, bait[I].img, true);
		//}
		//DrawCircle(circlebait[I].x, circlebait[I].y, circlebait[I].r, GetColor(255, 255, 255));
			if (CheckHit(circlebait[I], circleP))
			{
				if (bait[I].type == 0) {
					stage.Score += 10;
				}else if (bait[I].type == 1) {
					stage.Score += 50;
				}
				pscore++;              //食べたエサ数を加算
				bait[I].flg = false;   //表示OFF
				
				sound.PlayPlayerEat();

				if (bait[I].type == 1) PowerFlg = true;  //パワーエサ食った
				else PowerFlg = false;
			}
			//else
			//{
			//	sound.PlayPlayerMove();
			//}
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
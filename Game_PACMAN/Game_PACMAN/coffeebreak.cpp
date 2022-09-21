#include "DxLib.h"
#include"time.h"
#include"coffeebreak.h"

int PlayerX, PlayerY;
int EnemyX, EnemyY;
int PlayerSpeed;
int EnemySpeed;
int g_PlayerImage[5];
int g_EnemyImage[17];

void animasion_Initialize() {
	g_PlayerImage[0] = LoadGraph("images/02_2.png");
	g_PlayerImage[1] = LoadGraph("images/01_2R.png");
	g_PlayerImage[2] = LoadGraph("images/03_R.png");
	g_PlayerImage[3] = LoadGraph("images/01_2L.png");
	g_PlayerImage[4] = LoadGraph("images/03_L.png");
	g_EnemyImage[0] = LoadGraph("images/enemy_animasionL.png");
	g_EnemyImage[1] = LoadGraph("images/enemy_animasionL2.png");
	g_EnemyImage[2] = LoadGraph("images/Blue.png");
	g_EnemyImage[3] = LoadGraph("images/enemy_animasion1.png");
	g_EnemyImage[4] = LoadGraph("images/enemy_animasion2.png");
	g_EnemyImage[5] = LoadGraph("images/enemy_animasion3.png");
	g_EnemyImage[6] = LoadGraph("images/enemy_animasion4.png");
	g_EnemyImage[7] = LoadGraph("images/enemy_animasion5.png");
	g_EnemyImage[8] = LoadGraph("images/enemy_animasion6.png");
	g_EnemyImage[9] = LoadGraph("images/enemy_animasion7.png");
	g_EnemyImage[10] = LoadGraph("images/enemy_animasion8.png");
	g_EnemyImage[11] = LoadGraph("images/enemy_animasion9.png");
	g_EnemyImage[12] = LoadGraph("images/enemy_animasion10.png");
	g_EnemyImage[13] = LoadGraph("images/enemy_animasion11.png");
	g_EnemyImage[14] = LoadGraph("images/enemy_animasion12.png");
	g_EnemyImage[15] = LoadGraph("images/enemy_animasion13.png");
	g_EnemyImage[16] = LoadGraph("images/enemy_animasion14.png");
}

void animasion1() {

	PlayerX = 1300;
	PlayerY = 360;
	EnemyX = 1280;
	EnemyY = 360;

	EnemySpeed = 10;
	PlayerSpeed = 11;

	for (int i = 0; i < 135; i++) {
		ClearDrawScreen();
		PlayerX -= EnemySpeed;
		WaitTimer(70);
		if (i % 3 == 0) {
			DrawGraph(PlayerX, PlayerY, g_PlayerImage[0], FALSE);
		}
		else if (i % 3 == 1) {
			DrawGraph(PlayerX, PlayerY, g_PlayerImage[3], FALSE);
		}
		else if (i % 3 == 2) {
			DrawGraph(PlayerX, PlayerY, g_PlayerImage[4], FALSE);
		}

		if (i >= 17) {//è≠Çµéûä‘Ç™ÇΩÇ¬Ç∆ìGÇ™èoÇÈ
			EnemyX -= PlayerSpeed;
			if (i % 2 == 0) {
				DrawGraph(EnemyX, EnemyY, g_EnemyImage[0], FALSE);//ìG
			}
			else if (i % 2 == 1) {
				DrawGraph(EnemyX, EnemyY, g_EnemyImage[1], FALSE);//ìG
			}
		}
		//ó†âÊñ ÇÃì‡óeÇï\âÊñ Ç…îΩâf
		ScreenFlip();
	}

	PlayerX = -60;
	PlayerY = 360;
	EnemyX = -20;
	EnemyY = 360;

	for (int i = 0; i < 140; i++) {
		ClearDrawScreen();
		EnemyX += EnemySpeed;
		WaitTimer(70);
		DrawGraph(EnemyX, EnemyY, g_EnemyImage[2], FALSE);//ìG
		if (i >= 30) {
			PlayerX += PlayerSpeed + 2;
			if (i % 3 == 0) {
				DrawRotaGraph(PlayerX, PlayerY + 20, 2.5, 0, g_PlayerImage[0], FALSE);
			}
			else if (i % 3 == 1) {
				DrawRotaGraph(PlayerX, PlayerY + 20, 2.5, 0, g_PlayerImage[1], FALSE);
			}
			else if (i % 3 == 2) {
				DrawRotaGraph(PlayerX, PlayerY + 20, 2.5, 0, g_PlayerImage[2], FALSE);
			}
		}
		//ó†âÊñ ÇÃì‡óeÇï\âÊñ Ç…îΩâf
		ScreenFlip();
	}
}

void animasion2() {
	PlayerX = 1295;
	PlayerY = 360;
	EnemyX = 1295;
	EnemyY = 360;
	EnemySpeed = 10;
	PlayerSpeed = 11;
	int enemy_Count = 11;

	for (int i = 0; i < 135; i++) {
		ClearDrawScreen();
		DrawBox(920, 390, 923, 380, 0xffff00, TRUE);//â©êFÇÃñ_ÇÃï`âÊ
		PlayerX -= EnemySpeed;
		WaitTimer(70);
		if (i % 3 == 0) {//é©ã@ÇÃï`âÊ
			DrawGraph(PlayerX, PlayerY, g_PlayerImage[0], FALSE);
		}
		else if (i % 3 == 1) {
			DrawGraph(PlayerX, PlayerY, g_PlayerImage[3], FALSE);
		}
		else if (i % 3 == 2) {
			DrawGraph(PlayerX, PlayerY, g_PlayerImage[4], FALSE);
		}

		if (i >= 13) {
			EnemyX -= PlayerSpeed;
			if (i % 2 == 0) {
				DrawGraph(EnemyX, EnemyY, g_EnemyImage[0], FALSE);//ìG
			}
			else if (i % 2 == 1) {
				DrawGraph(EnemyX, EnemyY, g_EnemyImage[1], FALSE);//ìG
			}
			if (EnemyX <= 925) {
				PlayerSpeed = PlayerSpeed * 0.9;//â©êFÇ¢ñ_ÇâﬂÇ¨ÇƒèôÅXÇ…å∏ë¨ i=46
				switch (enemy_Count) {
				case 1:
					DrawGraph(EnemyX, EnemyY, g_EnemyImage[13], FALSE);//ìG
					break;
				case 2:
					DrawGraph(EnemyX, EnemyY, g_EnemyImage[12], FALSE);//ìG
					break;
				case 3:
					DrawGraph(EnemyX, EnemyY, g_EnemyImage[11], FALSE);//ìG
					break;
				case 4:
					DrawGraph(EnemyX, EnemyY, g_EnemyImage[10], FALSE);//ìG
					break;
				case 5:
					DrawGraph(EnemyX, EnemyY, g_EnemyImage[9], FALSE);//ìG
					break;
				case 6:
					DrawGraph(EnemyX, EnemyY, g_EnemyImage[8], FALSE);//ìG
					break;
				case 7:
					DrawGraph(EnemyX, EnemyY, g_EnemyImage[7], FALSE);//ìG
					break;
				case 8:
					DrawGraph(EnemyX, EnemyY, g_EnemyImage[6], FALSE);//ìG
					break;
				case 9:
					DrawGraph(EnemyX, EnemyY, g_EnemyImage[5], FALSE);//ìG
					break;
				case 10:
					DrawGraph(EnemyX, EnemyY, g_EnemyImage[4], FALSE);//ìG
					break;
				case 11:
					DrawGraph(EnemyX, EnemyY, g_EnemyImage[3], FALSE);//ìG
					break;
				default:
					DrawGraph(EnemyX, EnemyY, g_EnemyImage[13], FALSE);//ìG
					break;
				}
				enemy_Count--;
			}
		}
		//ó†âÊñ ÇÃì‡óeÇï\âÊñ Ç…îΩâf
		ScreenFlip();
	}
}

void animasion3() {
	PlayerX = 1280;
	PlayerY = 360;
	EnemyX = 1300;
	EnemyY = 360;

	EnemySpeed = 10;
	PlayerSpeed = 11;

	for (int i = 0; i < 135; i++) {
		ClearDrawScreen();
		PlayerX -= EnemySpeed;
		WaitTimer(70);
		if (i % 3 == 0) {
			DrawGraph(PlayerX, PlayerY, g_PlayerImage[0], FALSE);
		}
		else if (i % 3 == 1) {
			DrawGraph(PlayerX, PlayerY, g_PlayerImage[3], FALSE);
		}
		else if (i % 3 == 2) {
			DrawGraph(PlayerX, PlayerY, g_PlayerImage[4], FALSE);
		}
		if (i >= 13) {
			EnemyX -= PlayerSpeed;
			DrawGraph(EnemyX, EnemyY, g_EnemyImage[14], FALSE);//ìG
		}
		//ó†âÊñ ÇÃì‡óeÇï\âÊñ Ç…îΩâf
		ScreenFlip();
	}
	EnemyX = 0;
	EnemyY = 360;
	for (int i = 0; i < 130; i++) {
		ClearDrawScreen();
		EnemyX += EnemySpeed;
		WaitTimer(50);
		if (i % 2 == 0) {
			DrawGraph(EnemyX, EnemyY - 2, g_EnemyImage[15], FALSE);//ìG
		}
		else if (i % 2 == 1) {
			DrawGraph(EnemyX, EnemyY, g_EnemyImage[16], FALSE);//ìG
		}
		WaitTimer(70);
		//ó†âÊñ ÇÃì‡óeÇï\âÊñ Ç…îΩâf
		ScreenFlip();
	}

}
#include "DxLib.h"
#include"coffebrake.h"

int PlayerX, PlayerY;
int EnemyX, EnemyY;
int PlayerSpeed;
int EnemySpeed;
int g_PlayerImage[5];
int g_EnemyImage[8];

void animasion_Initialize() {
	g_PlayerImage[0] = LoadGraph("images/01.png");
	g_PlayerImage[1] = LoadGraph("images/02.png");
	g_PlayerImage[2] = LoadGraph("images/03.png");
	g_PlayerImage[3] = LoadGraph("images/04.png");
	g_PlayerImage[4] = LoadGraph("images/05.png");
	g_EnemyImage[0] = LoadGraph("images/enemy_animasion1.png");
	g_EnemyImage[1] = LoadGraph("images/enemy_animasion2.png");
	g_EnemyImage[2] = LoadGraph("images/enemy_animasion3.png");
	g_EnemyImage[3] = LoadGraph("images/enemy_animasion4.png");
	g_EnemyImage[4] = LoadGraph("images/enemy_animasion5.png");
	g_EnemyImage[5] = LoadGraph("images/enemy_animasion6.png");
	g_EnemyImage[6] = LoadGraph("images/enemy_animasion7.png");
	g_EnemyImage[7] = LoadGraph("images/enemy_animasion8.png");
}

void animasion1() {
	PlayerX = 0;
	PlayerY = 360;

	EnemyX = -20;
	EnemyY = 360;

	EnemySpeed = 10;
	PlayerSpeed = 11;

	for (int i = 0; i < 135; i++) {
			ClearDrawScreen();
			PlayerX += EnemySpeed;
			WaitTimer(70);
			if (i % 3 == 0) {
				DrawGraph(PlayerX, PlayerY, g_PlayerImage[1], FALSE);
			}
			else if (i % 3 == 1) {
				DrawGraph(PlayerX, PlayerY, g_PlayerImage[4], FALSE);
			}
			else if (i % 3 == 2) {
				DrawGraph(PlayerX, PlayerY, g_PlayerImage[3], FALSE);
			}

			if (i >= 11) {//­‚µŠÔ‚ª‚½‚Â‚Æ“G‚ªo‚é
				EnemyX += PlayerSpeed;
				DrawGraph(EnemyX, EnemyY, g_PlayerImage[1], FALSE);//“G
			}
			//— ‰æ–Ê‚Ì“à—e‚ğ•\‰æ–Ê‚É”½‰f
			ScreenFlip();
		}

	PlayerX = 1300;
	PlayerY = 360;
	EnemyX = 1280;
	EnemyY = 360;

	for (int i = 0; i < 135; i++) {
		ClearDrawScreen();
		EnemyX -= EnemySpeed;
		WaitTimer(70);
		DrawGraph(EnemyX, EnemyY, g_PlayerImage[1], FALSE);//“G
		if (i >= 11) {
			PlayerX -= PlayerSpeed;
			if (i % 3 == 0) {
				DrawGraph(PlayerX, PlayerY, g_PlayerImage[1], FALSE);
			}
			else if (i % 3 == 1) {
				DrawGraph(PlayerX, PlayerY, g_PlayerImage[0], FALSE);
			}
			else if (i % 3 == 2) {
				DrawGraph(PlayerX, PlayerY, g_PlayerImage[2], FALSE);
			}
		}
		//— ‰æ–Ê‚Ì“à—e‚ğ•\‰æ–Ê‚É”½‰f
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
	for (int i = 0; i < 135; i++) {
		ClearDrawScreen();
		DrawBox(930, 370, 933, 360, 0xffff00, TRUE);//‰©F‚Ì–_‚Ì•`‰æ
		PlayerX -= EnemySpeed;
		WaitTimer(50);
		if (i % 3 == 0) {//©‹@‚Ì•`‰æ
			DrawGraph(PlayerX, PlayerY, g_PlayerImage[1], FALSE);
		}else if (i % 3 == 1) {
			DrawGraph(PlayerX, PlayerY, g_PlayerImage[0], FALSE);
		}else if (i % 3 == 2) {
			DrawGraph(PlayerX, PlayerY, g_PlayerImage[2], FALSE);
		}

		if (i >= 11) {
			EnemyX -= PlayerSpeed;
			DrawGraph(EnemyX, EnemyY, g_EnemyImage[6], FALSE);//“G‚Ì•`‰æ
			if(EnemyX <= 930){
				PlayerSpeed = PlayerSpeed * 0.9;//‰©F‚¢–_‚ğ‰ß‚¬‚Ä™X‚ÉŒ¸‘¬
				WaitTimer(500);
				if (PlayerSpeed == 5) {
					DrawGraph(EnemyX, EnemyY, g_EnemyImage[0], FALSE);
				}
				else if (PlayerSpeed == 4) {
					DrawGraph(EnemyX, EnemyY, g_EnemyImage[1], FALSE);
				}
				else if (PlayerSpeed == 3) {
					DrawGraph(EnemyX, EnemyY, g_EnemyImage[2], FALSE);
				}
				else if (PlayerSpeed == 2) {
					DrawGraph(EnemyX, EnemyY, g_EnemyImage[3], FALSE);					}
				else if (PlayerSpeed == 1) {
					DrawGraph(EnemyX, EnemyY, g_EnemyImage[4], FALSE);
				}
				else if (PlayerSpeed == 0) {
					WaitTimer(400);

					DrawGraph(EnemyX, EnemyY, g_EnemyImage[5], FALSE);
				}
			}
		}
		//— ‰æ–Ê‚Ì“à—e‚ğ•\‰æ–Ê‚É”½‰f
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
			DrawGraph(PlayerX, PlayerY, g_PlayerImage[1], FALSE);
		}else if (i % 3 == 1) {
			DrawGraph(PlayerX, PlayerY, g_PlayerImage[0], FALSE);
		}else if (i % 3 == 2) {
			DrawGraph(PlayerX, PlayerY, g_PlayerImage[2], FALSE);
		}
		if (i >= 11) {
			EnemyX -= PlayerSpeed;
			DrawGraph(EnemyX, EnemyY, g_EnemyImage[6], FALSE);//“G
		}
		//— ‰æ–Ê‚Ì“à—e‚ğ•\‰æ–Ê‚É”½‰f
		ScreenFlip();
	}
	EnemyX = 0;
	EnemyY = 360;
	for (int i = 0; i < 130; i++) {
		ClearDrawScreen();
		EnemyX += EnemySpeed;
		DrawGraph(EnemyX, EnemyY, g_EnemyImage[7], FALSE);//“G
		WaitTimer(70);
		//— ‰æ–Ê‚Ì“à—e‚ğ•\‰æ–Ê‚É”½‰f
		ScreenFlip();
	}

}


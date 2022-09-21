#include "DxLib.h"

#include "Stage.h"
#include "display.h"
#include "NewPlayer.h"
#include "Red.h"
#include "Pink.h"
#include "Blue.h"
#include "Orange.h"
#include "Info.h"
#include "display.h"
#include"sounds.h"

Stage stage;

Stage::Stage()
{
	//フルーツのスコア
	FruitScore[0] = 100;  //cherry
	FruitScore[1] = 300;  //strawberry
	FruitScore[2] = 500;  //orange
	FruitScore[3] = 700;  //apple
	FruitScore[4] = 1000; //meron
	FruitScore[5] = 2000; //Galaxian
	FruitScore[6] = 3000; //bell
	FruitScore[7] = 5000; //key
}

//map上の"〇マス目"をウィンドウ上の座標に変換
int Stage::MapPointX(int mapX) { return mapX * MAP_SIZE; }
int Stage::MapPointY(int mapY) { return mapY * MAP_SIZE; }

//描画
void Stage::DrawMap()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if (MapData[i][j] == 1)
			{
				int x = MapPointX(j) + DRAW_POINT_X;
				int y = MapPointY(i) + DRAW_POINT_Y;
				DrawBox(x, y, (x + MAP_SIZE), (y + MAP_SIZE), 0x00ff00, TRUE);
			}
		}
	}
}

//初期処理
void Stage::StageInit()
{
	//DrawTime = 0;
	DrawTime_F = 0;
	DrawTime_S = 0;
	DrawCnt = 0;
	oldLife = 0;

	DrawFlg_F = false;    //フルーツ描画フラグ
	DrawFlg_S = false;    //スコア描画フラグ
}

//画像読み込み
int Stage::LoadImages()
{
	if ((LoadDivGraph("images/All_Fruit.png", 8, 8, 1, 30, 30, FruitImgs)) == -1) return -1;
	//Number
	if ((LoadDivGraph("images/All_Num.png", 10, 10, 1, 10, 14, NumImgs)) == -1) return -1;
}

//フルーツの処理まとめ
void Stage::FruitControl(int ClearCnt, int FoodCnt)
{
	CIRCLE circleFruit, circleP;

	circleFruit.x = static_cast<float>(DRAW_POINT_X + MapPointX(13) + 15);
	circleFruit.y = static_cast<float>(DRAW_POINT_Y + MapPointY(16) + 15);
	circleFruit.r = 6.5f;

	circleP.x = static_cast<float>(g_player.PX);
	circleP.y = static_cast<float>(g_player.PY);
	circleP.r = 6.5f;

	//表示されているときに当たった
	if (CheckHit(circleFruit, circleP) == true && DrawFlg_F == true)
	{
		//スコア加算
		Score += FruitScore[FruitNumToClear(ClearCnt)];

		DrawFlg_F = false;    //フルーツ描画OFF
		DrawFlg_S = true;     //スコア表示ON
		DrawCnt++;            //1回目の描画なら次の描画
		DrawTime_F = 0;       //描画時間リセット
	}

	//  1回目 70個以上                   2回目 170個以上
	if (FoodCnt >= FirstTime && DrawCnt == 0 || FoodCnt >= SecondTime && DrawCnt == 1) DrawFlg_F = true;

	if (DrawFlg_S == true)DrawFruitScore(ClearCnt);
}

////フルーツの出現、描画  　引数(食べたエサ数、クリア回数)
//void Stage::DrawFruit(int FoodCnt, int ClearCnt)
//{
//	//エサを1回目は70個、2回目は170個取るとフルーツが10秒間だけ表示される
//
//	CIRCLE circleFruit, circleP;
//
//	circleFruit.x = DRAW_POINT_X + MapPointX(13)+15;
//	circleFruit.y = DRAW_POINT_Y + MapPointY(16)+15;
//	circleFruit.r = 6.5f;
//
//	circleP.x = g_player.PX;
//	circleP.y = g_player.PY;
//	circleP.r = 6.5f;
//
//	//DrawCircle(circleFruit.x, circleFruit.y, circleFruit.r, 0xffffff, TRUE);
//
//
//	//  1回目 70個以上                   2回目 170個以上
//	if (FoodCnt >= FirstTime && DrawCnt == 0 || FoodCnt >= SecondTime && DrawCnt == 1)
//	{
//		//if(g_player.Life != oldLife)DrawTime = 0;
//		//10秒間
//		if (++DrawTime < 600 && CheckHit(circleFruit, circleP) == false) DrawGraph(DRAW_POINT_X + MapPointX(13), DRAW_POINT_Y + MapPointY(16), *FruitToClear(ClearCnt), TRUE);
//		else
//		{
//			FruitScore(ClearCnt);
//			/*Fruit[FruitCount] = *FruitToClear(ClearCnt);
//			if (FruitCount < 10) {
//				FruitCount++;
//			}*/
//			DrawCnt++;
//			DrawTime = 0;
//		}
//	}
//}

//フルーツの出現、描画  　引数(食べたエサ数、クリア回数)
void Stage::DrawFruit(int ClearCnt)
{
	//エサを1回目は70個、2回目は170個取るとフルーツが10秒間だけ表示される

	if (DrawFlg_F == true)
	{
		//10秒間
		if (++DrawTime_F < 600)
		{
			DrawGraph(DRAW_POINT_X + MapPointX(13), DRAW_POINT_Y + MapPointY(16), *FruitToClear(ClearCnt), TRUE);
		}
		else
		{
			DrawCnt++;
			DrawTime_F = 0;       //描画時間リセット
			DrawFlg_F = false;    //描画OFF
		}
	}

	if (g_player.PlayerDestroyFlg == true) {
		DrawTime_F = 600;
	}

}


//クリア回数による出現フルーツの変化    画像を返す
int* Stage::FruitToClear(int ClearCnt)
{
	if (ClearCnt == 0) return &FruitImgs[0];                         //クリア回数0     cherry
	else if (ClearCnt == 1) return &FruitImgs[1];                    //クリア回数1     strawberry
	else if (ClearCnt == 2 || ClearCnt == 3) return &FruitImgs[2];   //クリア回数2～3  orange
	else if (ClearCnt == 4 || ClearCnt == 5) return &FruitImgs[3];   //クリア回数4～5  apple
	else if (ClearCnt == 6 || ClearCnt == 7) return &FruitImgs[4];   //クリア回数6～7  meron
	else if (ClearCnt == 8 || ClearCnt == 9) return &FruitImgs[5];   //クリア回数8～9  Galaxian
	else if (ClearCnt == 10 || ClearCnt == 11) return &FruitImgs[6]; //クリア回数10～11  Bell
	else if (ClearCnt >= 12) return &FruitImgs[7];                   //クリア回数12～　　key
	else return  &FruitImgs[0];                                      //それ以外はcheryy
}

//クリア回数による出現フルーツの変化　　画像番号を返す
int Stage::FruitNumToClear(int ClearCnt)
{
	if (ClearCnt == 0) return 0;                         //クリア回数0     cherry
	else if (ClearCnt == 1) return 1;                    //クリア回数1     strawberry
	else if (ClearCnt == 2 || ClearCnt == 3) return 2;   //クリア回数2～3  orange
	else if (ClearCnt == 4 || ClearCnt == 5) return 3;   //クリア回数4～5  apple
	else if (ClearCnt == 6 || ClearCnt == 7) return 4;   //クリア回数6～7  meron
	else if (ClearCnt == 8 || ClearCnt == 9) return 5;   //クリア回数8～9  Galaxian
	else if (ClearCnt == 10 || ClearCnt == 11) return 6; //クリア回数10～11  Bell
	else if (ClearCnt >= 12) return 7;                   //クリア回数12～　　key
	else return  0;                                      //それ以外はcheryy
}

//食べられたときの処理　スコア表示
void Stage::DrawFruitScore(int ClearCnt)
{
	int drawX = (13 * MAP_SIZE) + (MAP_SIZE / 2);  //基本のX座標
	int drawY = (16 * MAP_SIZE) + (MAP_SIZE / 2);  //基本のY座標

	//スコアの桁数
	int digit = GetDigit(static_cast<unsigned int>(FruitScore[FruitNumToClear(ClearCnt)]));
	//スコア
	int score = FruitScore[FruitNumToClear(ClearCnt)];
	//文字幅に沿った位置調整
	drawX = drawX - (digit / 2) * 9;

	//2秒間
	if (++DrawTime_S < 120)
	{
		for (int i = 0; i < digit; i++)
		{
			DrawRotaGraph(drawX + (i * 9) + DRAW_POINT_X, drawY + DRAW_POINT_Y,
				0.9, 0, NumImgs[ShowDigit(digit - 1 - i, score)], TRUE);
		}
	}
	else
	{
		DrawTime_S = 0;    //描画時間リセット
		DrawFlg_S = false; //描画OFF
	}

	if (g_player.PlayerDestroyFlg == true) {
		DrawFlg_S = false;
	}

}

//数字と桁数から表示する数字を返す
int Stage::ShowDigit(int digit, int num)
{
	//10の  スコアの桁数乗  score500 なら3乗
	int n = (int)pow(10.0, digit);
	return (int)((num % (10 * n)) / n);
}



int Stage::getMap(int Y, int X) {
	return MapData[Y][X];
}

void Stage::DrawMapImageV3() {
	DrawGraph(DRAW_POINT_X + 90, DRAW_POINT_Y + 105, Disp.g_StageImage, TRUE);
}

void Stage::flashingMapImageV3() {
	if (Timer++ < 20) {//Map(青)
		DrawGraph(DRAW_POINT_X + 90, DRAW_POINT_Y + 105, Disp.g_StageImage, TRUE);
	}
	else if (Timer < 40) {//Map(白)
		DrawGraph(DRAW_POINT_X + 90, DRAW_POINT_Y + 105, Disp.g_StageImageW, TRUE);
	}
	else {
		Timer = 0;
	}
}

void Stage::DrawMapScore(int ClearCnt) {
	if (flashingTimer++ < 20) {//Map(青)
		DrawString(DRAW_POINT_X + 105, 5, "1UP", 0xffffff, true);
	}
	else if (flashingTimer > 40)
	{
		flashingTimer = 0;
	}
	DrawFormatString(DRAW_POINT_X+195, 5, 0xffffff, "%02d", Score);

	DrawString(DRAW_POINT_X + 305, 5, "HIGH SCORE", 0xffffff, true);
	DrawFormatString(DRAW_POINT_X+495, 5, 0xffffff, "%02d", HScore);
	for (int i = 0;i < g_player.Life;i++) {
		DrawGraph(DRAW_POINT_X + MapPointX(3 + i) + 15, DRAW_POINT_Y + MapPointY(25) + 15, Disp.PacManImage[1], TRUE);
	}
	if (ClearCnt == 0) {
		DrawGraph(DRAW_POINT_X + MapPointX(21) + 15, DRAW_POINT_Y + MapPointY(25) + 15, *FruitToClear(ClearCnt), TRUE);
	}else if (ClearCnt < 7) {
		for (int i = 0;i < ClearCnt+1;i++) {
				DrawGraph(DRAW_POINT_X + MapPointX(21 - i) + 15, DRAW_POINT_Y + MapPointY(25) + 15, *FruitToClear(i), TRUE);
		}
	}
	else {
		for (int i = 0;i < 7;i++) {
				DrawGraph(DRAW_POINT_X + MapPointX(21 - i) + 15, DRAW_POINT_Y + MapPointY(25) + 15, *FruitToClear(i+ ClearCnt-6), TRUE);
		}
	}
	
	/*for (int i = 0;i < FruitCount;i++) {
		DrawGraph(DRAW_POINT_X + MapPointX(21-i) + 15, DRAW_POINT_Y + MapPointY(25) + 15, Fruit[i], TRUE);
	}*/
}

//void Stage::FruitScore(int ClearCnt) {
//	if (ClearCnt == 0)Score += 100;                         //クリア回数0     cherry
//	else if (ClearCnt == 1)Score += 300;                    //クリア回数1     strawberry
//	else if (ClearCnt == 2 || ClearCnt == 3)Score += 500;   //クリア回数2～3  orange
//	else if (ClearCnt == 4 || ClearCnt == 5)Score += 700;   //クリア回数4～5  apple
//	else if (ClearCnt == 6 || ClearCnt == 7)Score += 1000;  //クリア回数6～7  meron
//	else if (ClearCnt == 8 || ClearCnt == 9)Score += 2000;  //クリア回数8～9  Galaxian
//	else if (ClearCnt == 10 || ClearCnt == 11)Score += 3000;//クリア回数10～11  Bell
//	else if (ClearCnt >= 12)Score += 5000;                  //クリア回数12～　　key
//	else Score += 100;                                      //それ以外はcheryy
//}

int Stage::HitCircle() {
	CIRCLE circleE1, circleE2, circleE3, circleE4, circleP;

	circleE1.x = static_cast<float>(Red.GetEnemyX() + DRAW_POINT_X);
	circleE1.y = static_cast<float>(Red.GetEnemyY() + DRAW_POINT_Y);
	circleE1.r = 6.5f;

	circleE2.x = static_cast<float>(Pink.GetEnemyX() + DRAW_POINT_X);
	circleE2.y = static_cast<float>(Pink.GetEnemyY() + DRAW_POINT_Y);
	circleE2.r = 6.5f;

	circleE3.x = static_cast<float>(Blue.GetEnemyX() + DRAW_POINT_X);
	circleE3.y = static_cast<float>(Blue.GetEnemyY() + DRAW_POINT_Y);
	circleE3.r = 6.5f;

	circleE4.x = static_cast<float>(Orange.GetEnemyX() + DRAW_POINT_X);
	circleE4.y = static_cast<float>(Orange.GetEnemyY() + DRAW_POINT_Y);
	circleE4.r = 6.5f;

	circleP.x = static_cast<float>(g_player.PX);
	circleP.y = static_cast<float>(g_player.PY);
	circleP.r = 6.5f;

	//DrawCircle(circleE1.x, circleE1.y, circleE1.r, 0xffffff, TRUE);

	//if (Red.GetEnemyMode() != IJIKE && Pink.GetEnemyMode() != IJIKE && Blue.GetEnemyMode() != IJIKE && Orange.GetEnemyMode() != IJIKE) {
	//	if (Red.GetEnemyMode() != EYE && Pink.GetEnemyMode() != EYE && Blue.GetEnemyMode() != EYE && Orange.GetEnemyMode() != EYE) {
	//		//敵の当たり判定
	//		if (CheckHit(circleE1, circleP) == true || CheckHit(circleE2, circleP) == true || CheckHit(circleE3, circleP) == true || CheckHit(circleE4, circleP) == true) {
	//			return true;
	//		}
	//		else {
	//			return false;
	//		}
	//	}

	//}
	if (Red.GetEnemyMode() != IJIKE) {//赤
		if (Red.GetEnemyMode() != EYE) {
			if (CheckHit(circleE1, circleP) == true) {
				
				return true;
			}
		}
	}
	if (Pink.GetEnemyMode() != IJIKE) {//ピンク
		if (Pink.GetEnemyMode() != EYE) {
			if (CheckHit(circleE2, circleP) == true) {
				
				return true;
			}
		}
	}
	if (Blue.GetEnemyMode() != IJIKE) {//水色
		if (Blue.GetEnemyMode() != EYE) {
			if (CheckHit(circleE3, circleP) == true) {
				
				return true;
			}
		}
	}
	if (Orange.GetEnemyMode() != IJIKE) {//オレンジ
		if (Orange.GetEnemyMode() != EYE) {
			if (CheckHit(circleE4, circleP) == true) {
				
				return true;
			}
		}
	}
}

bool Stage::CheckHit(const CIRCLE& t_circleA, const CIRCLE& t_circleB)
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
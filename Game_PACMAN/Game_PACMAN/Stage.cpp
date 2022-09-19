#include "DxLib.h"

#include "Stage.h"

Stage stage;

Stage::Stage(){
	
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
	DrawTime_F = 0;
	DrawTime_S = 0;
	DrawCnt = 0;

	DrawFlg_F = false;    //フルーツ描画フラグ
	DrawFlg_S = false;
}

//画像読み込み
int Stage::LoadImages()
{
	if ((LoadDivGraph("images/All_Fruit.png", 8, 8, 1, 30, 30, FruitImgs)) == -1) return -1;
	//Number
	if ((LoadDivGraph("images/All_Num.png", 10, 10, 1, 10, 14, NumImgs)) == -1) return -1;
}

//フルーツの出現、描画  　引数(食べたエサ数、クリア回数)
void Stage::DrawFruit(int FoodCnt, int ClearCnt)
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
}

//クリア回数による出現フルーツの変化    DrawFruit内でのみ使用
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

//クリア回数による出現フルーツの変化
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

//フルーツの処理まとめ
void Stage::FruitControl(int HitFlg, int ClearCnt, int FoodCnt, int& score)
{
	if (HitFlg == true && DrawFlg_F == true)
	{
		//スコア加算
		score += FruitScore[FruitNumToClear(ClearCnt)];

		DrawFlg_F = false;    //フルーツ描画OFF
		DrawFlg_S = true;     //スコア表示ON
		DrawCnt++;            //1回目の描画なら次の描画
		DrawTime_F = 0;       //描画時間リセット
	}

	//  1回目 70個以上                   2回目 170個以上
	if (FoodCnt >= FirstTime && DrawCnt == 0 || FoodCnt >= SecondTime && DrawCnt == 1) DrawFlg_F = true;

	if (DrawFlg_S == true)DrawFruitScore(HitFlg, ClearCnt);
}

//食べられたときの処理　スコア表示
void Stage::DrawFruitScore(int HitFlg, int ClearCnt)
{
	int drawX = (13 * MAP_SIZE) + (MAP_SIZE / 2);  //基本のX座標
	int drawY = (16 * MAP_SIZE) + (MAP_SIZE / 2);  //基本のY座標

	//スコアの桁数
	int digit = GetDigit(static_cast<unsigned int>(FruitScore[FruitNumToClear(ClearCnt)]));
	//スコア
	int score = FruitScore[FruitNumToClear(ClearCnt)];
	//文字幅に沿った位置調整
	drawX = drawX - (digit / 2) * 9;

	//if (HitFlg == true)
	//{
	//	for (int i = 0; i < digit; i++)
	//	{
	//		DrawRotaGraph(drawX + (i * 9) + DRAW_POINT_X, drawY + DRAW_POINT_Y,
	//			0.9, 0, NumImgs[ShowDigit(digit - 1 - i, score, ClearCnt)], TRUE);
	//	}
	//}

	//2秒間
	if (++DrawTime_S < 120)
	{
		for (int i = 0; i < digit; i++)
		{
			DrawRotaGraph(drawX + (i * 9) + DRAW_POINT_X, drawY + DRAW_POINT_Y,
				0.9, 0, NumImgs[ShowDigit(digit - 1 - i, score, ClearCnt)], TRUE);
		}
	}
	else
	{
		DrawTime_S = 0;    //描画時間リセット
		DrawFlg_S = false; //描画OFF
	}
}

//数字と桁数から表示する数字を返す
int Stage::ShowDigit(int digit, int num, int ClearCnt)
{
	//10の  スコアの桁数乗  score500 なら3乗
	int n = (int)pow(10.0, digit);
	return (int)((num % (10 * n)) / n);
}

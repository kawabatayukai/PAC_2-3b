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
	DrawTime = 0;
	DrawCnt = 0;
}

//画像読み込み
int Stage::LoadImages()
{
	if ((LoadDivGraph("images/All_Fruit.png", 8, 8, 1, 30, 30, FruitImgs)) == -1) return -1;
}

//フルーツの出現、描画  　引数(食べたエサ数、クリア回数)
void Stage::DrawFruit(int FoodCnt, int ClearCnt)
{
	//エサを1回目は70個、2回目は170個取るとフルーツが10秒間だけ表示される



	//  1回目 70個以上                   2回目 170個以上
	if (FoodCnt >= FirstTime && DrawCnt == 0 || FoodCnt >= SecondTime && DrawCnt == 1)
	{
		//10秒間
		if (++DrawTime < 600) DrawGraph(DRAW_POINT_X + MapPointX(13), DRAW_POINT_Y + MapPointY(16), *FruitToClear(ClearCnt), TRUE);
		else
		{
			DrawCnt++;
			DrawTime = 0;
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
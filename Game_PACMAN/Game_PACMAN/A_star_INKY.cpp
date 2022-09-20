#include"DxLib.h"
#include <stdio.h>
#include <tchar.h>
#include <map>
#include"NewPlayer.h"
#include"A_star_INKY.h"
#include"Image.h"
#include"Stage.h"
#include"Enemy.h"
//#include"A_star_INKY.h"
#include"Blue.h"
#include"Red.h"
//#include"Enemy3.h"

//#define WIDTH (21)
//#define HEIGHT (23)

#//define GX	(4)
//#define GX	(g_player.PXC)
#//define GY	(14)
//#define GY	(g_player.PYC)

//#define SX	(20)
//#define SX	(Blue.EXC)
//#define SY	(21)
//#define SY	(Blue.EYC)

A_star_INKY a_star_inky;

A_star_INKY::A_star_INKY() {
	SX = Blue.GetEnemyX() / MAP_SIZE;
	SY = Blue.GetEnemyY() / MAP_SIZE;

	GX = g_player.PXC;
	GY = g_player.PYC;

	d = 0;
	f = 0;

	SX1 = Blue.GetEnemyX() / MAP_SIZE;
	SY1 = Blue.GetEnemyY() / MAP_SIZE;

	Count = 0;

	Time = 0;
	GFlg = false;

	Rand = 0;

	DFlg = false;

	DX = 0;
	DY = 0;

	XP = 0;
	YP = 0;
	XM = 0;
	YM = 0;

	OldXP = 0;
	OldYP = 0;
	OldXM = 0;
	OldYM = 0;

	Timer = 0;
	aas = 0;

	oldGX = 0;
	oldGY = 0;
	//	enum {
	//	SEARCH_NO_CHECK = 0,
	//	SEARCH_OPEN = 1,
	//	SEARCH_CLOSE = 2,
	//	};
	//
	//	typedef struct {
	//	int x;
	//	int y;
	//	} POINT;
	//
	//	// 8方向のベクトル設定
	//	POINT CheckMatrix[] = {
	//	{  0,  1 },		// 0
	//	//{ -1,  1 },		// 1
	//	{ -1,  0 },		// 2
	//	//{ -1, -1 },	// 3
	//	{  0, -1 },		// 4
	//	//{  1, -1 },		// 5
	//	{  1,  0 },		// 6
	//	//{  1,  1 },		// 7
	//	};
	//
	//	typedef struct
	//{
	//	int no;
	//	int chip;
	//	int status;
	//	int event_no;
	//
	//	int cost;
	//	int SearchStatus;	// 0:未調査 1:オープン 2:クローズ
	//	int parent;		// 親の向き
	//} mapcell;
	//
	//mapcell data[HEIGHT][WIDTH];
	//
	//int def_data[HEIGHT][WIDTH] = {
	//	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},
	//		{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,-1,},
	//		{-1,0,-1,-1,0,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,0,-1,-1,0,-1,},
	//		{-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,},
	//		{-1,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,0,-1,},
	//		{-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,-1,},
	//		{-1,-1,-1,-1,0,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,0,-1,-1,-1,-1,},
	//		{0,0,0,-1,0,-1,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,},
	//		{0,0,0,-1,0,-1,0,-1,-1,-1,0,-1,-1,-1,0,-1,0,-1,0,0,0,},
	//		{-1,-1,-1,-1,0,-1,0,-1,0,0,0,0,0,-1,0,-1,0,-1,-1,-1,-1,},
	//		{0,0,0,0,0,0,0,-1,0,0,0,0,0,-1,0,0,0,0,0,0,0,},
	//		{-1,-1,-1,-1,0,-1,0,-1,0,0,0,0,0,-1,0,-1,0,-1,-1,-1,-1,},
	//		{0,0,0,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,0,0,0,},
	//		{0,0,0,-1,0,-1,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,},
	//		{-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,},
	//		{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,-1,},
	//		{-1,0,-1,-1,0,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,0,-1,-1,0,-1,},
	//		{-1,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,-1,},
	//		{-1,-1,0,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,0,-1,-1,},
	//		{-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,-1,},
	//		{-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,},
	//		{-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,},
	//		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},
	//};
}

//enum {
//	SEARCH_NO_CHECK = 0,
//	SEARCH_OPEN = 1,
//	SEARCH_CLOSE = 2,
//};

//typedef struct {
//	int x;
//	int y;
//} POINT;

//// 8方向のベクトル設定
//POINT CheckMatrix[] = {
//	{  0,  1 },		// 0
//	//{ -1,  1 },		// 1
//	{ -1,  0 },		// 2
//	//{ -1, -1 },	// 3
//	{  0, -1 },		// 4
//	//{  1, -1 },		// 5
//	{  1,  0 },		// 6
//	//{  1,  1 },		// 7
//};

//typedef struct
//{
//	int no;
//	int chip;
//	int status;
//	int event_no;
//
//	int cost;
//	int SearchStatus;	// 0:未調査 1:オープン 2:クローズ
//	int parent;		// 親の向き
//} mapcell;

//mapcell data[HEIGHT][WIDTH];

//int def_data[HEIGHT][WIDTH] = {
//	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},
//		{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,-1,},
//		{-1,0,-1,-1,0,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,0,-1,-1,0,-1,},
//		{-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,},
//		{-1,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,0,-1,},
//		{-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,-1,},
//		{-1,-1,-1,-1,0,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,0,-1,-1,-1,-1,},
//		{0,0,0,-1,0,-1,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,},
//		{0,0,0,-1,0,-1,0,-1,-1,-1,0,-1,-1,-1,0,-1,0,-1,0,0,0,},
//		{-1,-1,-1,-1,0,-1,0,-1,0,0,0,0,0,-1,0,-1,0,-1,-1,-1,-1,},
//		{0,0,0,0,0,0,0,-1,0,0,0,0,0,-1,0,0,0,0,0,0,0,},
//		{-1,-1,-1,-1,0,-1,0,-1,0,0,0,0,0,-1,0,-1,0,-1,-1,-1,-1,},
//		{0,0,0,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,0,0,0,},
//		{0,0,0,-1,0,-1,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,},
//		{-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,},
//		{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,-1,},
//		{-1,0,-1,-1,0,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,0,-1,-1,0,-1,},
//		{-1,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,-1,},
//		{-1,-1,0,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,0,-1,-1,},
//		{-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,-1,},
//		{-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,},
//		{-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,},
//		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},
//};

void A_star_INKY::ResetSearchStatus(void)
{
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			data[h][w].cost = 0;
			data[h][w].SearchStatus = 0;
		}
	}
	//return;
}

void A_star_INKY::SetDefault(void)
{
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			data[h][w].status = def_data[h][w];
		}
	}

	//return;
}

void A_star_INKY::out(void)
{
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			char ch = ' ';
			if (w == GX && h == GY) ch = '*';
			if (w == SX && h == SY) ch = '@';

			printf("%c", ch);

			if (data[h][w].status > 0)  ch = 'o';
			if (data[h][w].status < 0)  ch = '#';
			if (data[h][w].status == 0) ch = '.';

			printf("%c", ch);
		}
		printf("\n");
	}
	printf("OK.\n");
	//return;
}

// マンハッタン距離を斜め移動ありを考慮して求める
int A_star_INKY::GetDistance(int from_x, int from_y, int to_x, int to_y)
{
	int cx = from_x - to_x;
	int cy = from_y - to_y;

	if (cx < 0) cx *= -1;
	if (cy < 0) cy *= -1;

	// 推定移動コストを計算
	if (cx < cy) {
		return (cx + (cy - cx));
	}
	else {
		return (cy + (cx - cy));
	}
}

int A_star_INKY::BackTrace(int x, int y)
{
	if (x == SX && y == SY) return 1;

	int parent_way = data[y][x].parent;

	return BackTrace(
		x + CheckMatrix[parent_way].x,
		y + CheckMatrix[parent_way].y
	) + 1;
}

// A*で経路探査する
int A_star_INKY::Search(int count) {

	int cost_min = 9999;
	int BackCost = 0;
	int CX = 0;
	int CY = 0;

	mapcell* n = NULL;

	// コストが最小のオープンノードを探す
	// TODO: ここを全マス探査しないようにすると、
	//       もっと早くなるかも
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {

			if (data[h][w].SearchStatus != SEARCH_OPEN)continue;
			if (GetDistance(w, h, GX, GY) > cost_min)continue;

			cost_min = GetDistance(w, h, GX, GY);
			n = &data[h][w];

			CX = w;
			CY = h;
		}
	}

	// オープンノードがなければ終了(ゴールが見つからない)
	if (n == NULL) return -9;

	// ノードをクローズする
	n->SearchStatus = SEARCH_CLOSE;

	BackCost = BackTrace(CX, CY);

	for (int i = 0; i < 4; i++) {

		int check_x = CX + CheckMatrix[i].x;
		int check_y = CY + CheckMatrix[i].y;

		/*if (Blue.VectorFlg == 1 && CheckMatrix[i].x == 1) {
			continue;
		}
		else if (Blue.VectorFlg == 2 && CheckMatrix[i].x == -1) {
			continue;
		}
		else if (Blue.VectorFlg == 3 && CheckMatrix[i].y == 1) {
			continue;
		}
		else if (Blue.VectorFlg == 4 && CheckMatrix[i].y == -1) {
			continue;
		}*/

		if (check_x < 0) continue;
		if (check_y < 0) continue;

		if (check_x >= WIDTH) continue;
		if (check_y >= HEIGHT) continue;

		// 通れないところをよける
		if (data[check_y][check_x].status == -1) continue;

		int estimate_cost = BackCost + GetDistance(check_x, check_y, GX, GY) + 1;

		mapcell* cell = &data[check_y][check_x];

		if (data[check_y][check_x].SearchStatus == SEARCH_NO_CHECK) {

			cell->parent = (i + 2) % 4;
			cell->SearchStatus = SEARCH_OPEN;

		}
		else if (estimate_cost < cell->cost) {

			cell->parent = (i + 2) % 4;
			cell->cost = estimate_cost;
			cell->SearchStatus = SEARCH_OPEN;

		}
	}

	// 見つかったら探索終了
	if (CX == GX && CY == GY) {
		return -1;
	}

	return Search(count + 1);
}

void A_star_INKY::TraceRoute(int x, int y)
{
	//if (x == SX && y == SY) {
	if (x == SX && y == SY) {
		/*if (Blue.VectorFlg == 1) {
			data[SY][SX - 1].status = -1;
			data[SY][SX - 2].status = -1;
		}
		else if (Blue.VectorFlg == 2) {
			data[SY][SX + 1].status = -1;
			data[SY][SX + 2].status = -1;
		}
		else if (Blue.VectorFlg == 3) {
			data[SY - 1][SX].status = -1;
			data[SY - 2][SX].status = -1;
		}
		else if (Blue.VectorFlg == 4) {
			data[SY + 1][SX].status = -1;
			data[SY + 2][SX].status = -1;
		}*/
		//data[y][x].status = -1;
		printf("開始ノード>");
		return;
	}
	d = x;
	f = y;

	if (data[y][x].status == 2) {
		oldGX = GX;
		oldGY = GY;
		DX = d;
		DY = f;
		DFlg = true;
	}

	POINT* parent_way = &CheckMatrix[data[y][x].parent];

	data[y][x].status = 1;

	if (y == 14) {
		if (x <= 4 && &CheckMatrix[1]) {
			data[14][25].status = -1;
			//x = 24;
		}
		else if (x >= 24 && &CheckMatrix[3]) {
			data[14][3].status = -1;
			//x = 4;
		}
	}

	/*if (CheckMatrix->x == 1) {
		OldXP = XP;
		XP = 1;
	}
	if (CheckMatrix->y == 1)
	if (CheckMatrix->x == -1)
	if (CheckMatrix->y == -1)

	if(XP>=2)*/
	try {
		TraceRoute(x + parent_way->x, y + parent_way->y);
	}
	catch (int o) {
			GX = (370 - DRAW_POINT_X) / 30;
			GY = (660 - DRAW_POINT_X) / 30;
	}

	if (d == GX && f == GY) {
		//TraceRoute(x + parent_way->x, y + parent_way->y);
		printf("ゴール\n");
		return;
	}
	else {
		printf("(%d,%d)>", x, y);
	}
	return;
}

int A_star_INKY::_tmain(/*int argc, _TCHAR* argv[]*//*int plX, int plY, int enX, int enY*/)
{
	if (Count == 0) {

		SX = Blue.GetEnemyX() / MAP_SIZE;
		SY = Blue.GetEnemyY() / MAP_SIZE;

		if (DFlg == false) {

			if (GFlg == false) {

				GX = g_player.PXC;
				GY = g_player.PYC;

				Rand = GetRand(30);

			}
			else if (GFlg == true) {
				GX = g_player.PXC + Rand;
				GY = g_player.PYC + Rand;
				if (Time++ >= 180) {
					Time = 0;
					GFlg = false;
				}
			}

		}
		else if (DFlg == true) {
			GX = DX;
			GY = DY;
		}

		Count = 1;
	}
	else if (Count == 1) {
		/*SX = Blue.EXC;
		SY = Blue.EYC;*/

		SX = Blue.GetEnemyX() / MAP_SIZE;
		SY = Blue.GetEnemyY() / MAP_SIZE;

		if (DFlg == false) {

			GX = g_player.PXC;
			GY = g_player.PYC;



			if (GFlg == false) {

				if (g_player.PXC < Red.EXC) {
					GX = (Red.EXC - g_player.PXC);
				}
				else if (g_player.PXC > Red.EXC) {
					GX = g_player.PXC - Red.EXC*2;
				}
				else {
					GX = g_player.PXC;
				}

				if (g_player.PYC < Red.EYC) {
					GY = Red.EYC - g_player.PYC;
				}
				else if (g_player.PYC > Red.EYC) {
					GY = g_player.PYC + Red.EYC*2;
				}
				else {
					GY = g_player.PYC;
				}
				do {
					Rand = GetRand(20);
				} while (Rand < 10);
				aas = GetRand(4);
			}
			else if (GFlg == true) {
				if (aas == 0) {
					GX = g_player.PXC + Rand;
					GY = g_player.PYC + Rand;
				}
				else if (aas == 1) {
					GX = g_player.PXC - Rand;
					GY = g_player.PYC + Rand;
				}
				else if (aas == 2) {
					GX = g_player.PXC + Rand;
					GY = g_player.PYC - Rand;
				}
				else if (aas == 3) {
					GX = g_player.PXC - Rand;
					GY = g_player.PYC - Rand;
				}
				if (Time++ >= 180) {
					Time = 0;
					GFlg = false;
				}
			}
		}
		else if (DFlg == true) {
			GX = DX;
			GY = DY;
		}

		if (SX == GX && SY == GY) {
			GFlg = true;
			DFlg = false;
		}
		//Count = 0;
	}

	if (SX == GX && SY == GY) {
		GFlg = true;
		DFlg = false;
	}

	/*GX = g_player.PXC;
	GY = g_player.PYC;*/

	/*SX = plX;
	SY = plY;

	GX = enX;
	GY = enY;*/

	if (GX <= 0)GX = 1;
	if (GX >= 27)GX = 26;
	if (GY <= 0)GY = 1;
	if (GY >= 29)GY = 28;

	a_star_inky.SetDefault();
	a_star_inky.ResetSearchStatus();

	if (Blue.GetMoveDir() == DIRECTION::LEFT) {
		data[SY][SX + 1].status = -1;
		//data[SY][SX + 2].status = -1;
	}
	else if (Blue.GetMoveDir() == DIRECTION::RIGHT) {
		data[SY][SX - 1].status = -1;
		//data[SY][SX - 2].status = -1;
	}
	else if (Blue.GetMoveDir() == DIRECTION::UP) {
		data[SY + 1][SX].status = -1;
		//data[SY + 2][SX].status = -1;
	}
	else if (Blue.GetMoveDir() == DIRECTION::DOWN) {
		data[SY - 1][SX].status = -1;
		//data[SY - 2][SX].status = -1;
	}

	if (DFlg == false) {
		if (def_data[Blue.EYC][Blue.EXC] == 2) {
			if (Timer == 0) {
				XP = SX;
				YP = SY;
			}
			if (Timer <= 180) {
				if (Blue.VectorFlg == 1) {
					data[YP][XP + 1].status = -1;
					data[YP][XP + 2].status = -1;
				}
				else if (Blue.VectorFlg == 2) {
					data[YP][XP - 1].status = -1;
					data[YP][XP - 2].status = -1;
				}
				else if (Blue.VectorFlg == 3) {
					data[YP + 1][XP].status = -1;
					data[YP + 2][XP].status = -1;
				}
				else if (Blue.VectorFlg == 4) {
					data[YP - 1][XP].status = -1;
					data[YP - 2][XP].status = -1;
				}
				Timer++;
			}
			else {
				Timer = 0;
			}
		}
	}

	if (Blue.EX <= 429 && Blue.EY == 330 && Blue.VectorFlg == 1) {
		data[13][7].status = -1;
	}
	if (Blue.EX >= 851 && Blue.EY == 330 && Blue.VectorFlg == 2) {
		data[13][19].status = -1;
	}

	/*if (Blue.EY >= 535) {
		data[20][13].status = -1;
		data[20][15].status = -1;
	}*/

	a_star_inky.data[SY][SX].SearchStatus = a_star_inky.SEARCH_OPEN;

	a_star_inky.Search(0);

	a_star_inky.TraceRoute(GX, GY);
	a_star_inky.out();

	return 0;
}

//void A_star::A_STAR()
//{
//
//	SetDefault();
//	ResetSearchStatus();
//
//	data[SY][SX].SearchStatus = SEARCH_OPEN;
//
//	Search(0);
//
//	TraceRoute(GX, GY);
//	out();
//
//}

void A_star_INKY::A_starInit() {
	SX = Blue.GetEnemyX() / MAP_SIZE;
	SY = Blue.GetEnemyY() / MAP_SIZE;

	GX = g_player.PXC;
	GY = g_player.PYC;

	SX1 = Blue.GetEnemyX() / MAP_SIZE;
	SY1 = Blue.GetEnemyY() / MAP_SIZE;
}
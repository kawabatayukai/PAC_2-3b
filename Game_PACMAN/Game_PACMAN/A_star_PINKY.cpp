#include"DxLib.h"
#include <stdio.h>
#include <tchar.h>
#include <map>
#include"Player.h"
#include"A_star_PINKY.h"
#include"Image.h"
#include"Stage.h"
#include"Enemy.h"
#include"Enemy2.h"

//#define WIDTH (21)
//#define HEIGHT (23)

#//define GX	(4)
//#define GX	(g_player.PXC)
#//define GY	(14)
//#define GY	(g_player.PYC)

//#define SX	(20)
//#define SX	(g_enemy2.EXC)
//#define SY	(21)
//#define SY	(g_enemy2.EYC)

A_star_PINK a_star_pink;

A_star_PINK::A_star_PINK() {
	SX = g_enemy2.EXC;
	SY = g_enemy2.EYC;

	GX = g_player.PXC;
	GY = g_player.PYC;

	d = 0;
	f = 0;

	SX1 = g_enemy2.EXC;
	SY1 = g_enemy2.EYC;

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
	//	// 8�����̃x�N�g���ݒ�
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
	//	int SearchStatus;	// 0:������ 1:�I�[�v�� 2:�N���[�Y
	//	int parent;		// �e�̌���
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

//// 8�����̃x�N�g���ݒ�
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
//	int SearchStatus;	// 0:������ 1:�I�[�v�� 2:�N���[�Y
//	int parent;		// �e�̌���
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

void A_star_PINK::ResetSearchStatus(void)
{
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			data[h][w].cost = 0;
			data[h][w].SearchStatus = 0;
		}
	}
	//return;
}

void A_star_PINK::SetDefault(void)
{
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			data[h][w].status = def_data[h][w];
		}
	}

	//return;
}

void A_star_PINK::out(void)
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

// �}���n�b�^���������΂߈ړ�������l�����ċ��߂�
int A_star_PINK::GetDistance(int from_x, int from_y, int to_x, int to_y)
{
	int cx = from_x - to_x;
	int cy = from_y - to_y;

	if (cx < 0) cx *= -1;
	if (cy < 0) cy *= -1;

	// ����ړ��R�X�g���v�Z
	if (cx < cy) {
		return (cx + (cy - cx));
	}
	else {
		return (cy + (cx - cy));
	}
}

int A_star_PINK::BackTrace(int x, int y)
{
	if (x == SX && y == SY) return 1;

	int parent_way = data[y][x].parent;

	return BackTrace(
		x + CheckMatrix[parent_way].x,
		y + CheckMatrix[parent_way].y
	) + 1;
}

// A*�Ōo�H�T������
int A_star_PINK::Search(int count) {

	int cost_min = 9999;
	int BackCost = 0;
	int CX = 0;
	int CY = 0;

	mapcell* n = NULL;

	// �R�X�g���ŏ��̃I�[�v���m�[�h��T��
	// TODO: ������S�}�X�T�����Ȃ��悤�ɂ���ƁA
	//       �����Ƒ����Ȃ邩��
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

	// �I�[�v���m�[�h���Ȃ���ΏI��(�S�[����������Ȃ�)
	if (n == NULL) return -9;

	// �m�[�h���N���[�Y����
	n->SearchStatus = SEARCH_CLOSE;

	BackCost = BackTrace(CX, CY);

	for (int i = 0; i < 4; i++) {

		int check_x = CX + CheckMatrix[i].x;
		int check_y = CY + CheckMatrix[i].y;

		/*if (g_enemy2.VectorFlg == 1 && CheckMatrix[i].x == 1) {
			continue;
		}
		else if (g_enemy2.VectorFlg == 2 && CheckMatrix[i].x == -1) {
			continue;
		}
		else if (g_enemy2.VectorFlg == 3 && CheckMatrix[i].y == 1) {
			continue;
		}
		else if (g_enemy2.VectorFlg == 4 && CheckMatrix[i].y == -1) {
			continue;
		}*/

		if (check_x < 0) continue;
		if (check_y < 0) continue;

		if (check_x >= WIDTH) continue;
		if (check_y >= HEIGHT) continue;

		// �ʂ�Ȃ��Ƃ�����悯��
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

	// ����������T���I��
	if (CX == GX && CY == GY) {
		return -1;
	}

	return Search(count + 1);
}

void A_star_PINK::TraceRoute(int x, int y)
{
	//if (x == SX && y == SY) {
	if (x == SX && y == SY) {
		/*if (g_enemy2.VectorFlg == 1) {
			data[SY][SX - 1].status = -1;
			data[SY][SX - 2].status = -1;
		}
		else if (g_enemy2.VectorFlg == 2) {
			data[SY][SX + 1].status = -1;
			data[SY][SX + 2].status = -1;
		}
		else if (g_enemy2.VectorFlg == 3) {
			data[SY - 1][SX].status = -1;
			data[SY - 2][SX].status = -1;
		}
		else if (g_enemy2.VectorFlg == 4) {
			data[SY + 1][SX].status = -1;
			data[SY + 2][SX].status = -1;
		}*/
		//data[y][x].status = -1;
		printf("�J�n�m�[�h>");
		return;
	}
	d = x;
	f = y;

	if (data[y][x].status == 2) {
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

	TraceRoute(x + parent_way->x, y + parent_way->y);

	if (d == GX && f == GY) {
		//TraceRoute(x + parent_way->x, y + parent_way->y);
		printf("�S�[��\n");
		return;
	}
	else {
		printf("(%d,%d)>", x, y);
	}
	return;
}

int A_star_PINK::_tmain(/*int argc, _TCHAR* argv[]*//*int plX, int plY, int enX, int enY*/)
{
	if (Count == 0) {

		SX = g_enemy2.EXC;
		SY = g_enemy2.EYC;

		if (DFlg == false) {

			if (GFlg == false) {

				GX = g_player.PXC;
				GY = g_player.PYC;

				Rand = GetRand(3);

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
		/*SX = g_enemy2.EXC;
		SY = g_enemy2.EYC;*/

		SX = g_enemy2.EXC;
		SY = g_enemy2.EYC;

		if (DFlg == false) {

			GX = g_player.PXC;
			GY = g_player.PYC;



			if (GFlg == false) {

				if (g_player.KEYFLG == 1) {//LEFT
					GX = g_player.PXC - 3;
					GY = g_player.PYC;
				}
				else if (g_player.KEYFLG == 2) {//RIGHT
					GX = g_player.PXC + 3;
					GY = g_player.PYC;
				}
				else if (g_player.KEYFLG == 3) {//UP
					GX = g_player.PXC;
					GY = g_player.PYC - 3;
				}
				else if (g_player.KEYFLG == 4) {//DOWN
					GX = g_player.PXC;
					GY = g_player.PYC + 3;
				}
				else {
					GX = g_player.PXC;
					GY = g_player.PYC;
				}
				Rand = GetRand(3);
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

	a_star_pink.SetDefault();
	a_star_pink.ResetSearchStatus();

	if (g_enemy2.VectorFlg == 1) {
		data[SY][SX + 1].status = -1;
		//data[SY][SX + 2].status = -1;
	}
	else if (g_enemy2.VectorFlg == 2) {
		data[SY][SX - 1].status = -1;
		//data[SY][SX - 2].status = -1;
	}
	else if (g_enemy2.VectorFlg == 3) {
		data[SY + 1][SX].status = -1;
		//data[SY + 2][SX].status = -1;
	}
	else if (g_enemy2.VectorFlg == 4) {
		data[SY - 1][SX].status = -1;
		//data[SY - 2][SX].status = -1;
	}

	if (DFlg == false) {
		if (def_data[g_enemy2.EYC][g_enemy2.EXC] == 2) {
			if (Timer == 0) {
				XP = SX;
				YP = SY;
			}
			if (Timer <= 180) {
				if (g_enemy2.VectorFlg == 1) {
					data[YP][XP + 1].status = -1;
					data[YP][XP + 2].status = -1;
				}
				else if (g_enemy2.VectorFlg == 2) {
					data[YP][XP - 1].status = -1;
					data[YP][XP - 2].status = -1;
				}
				else if (g_enemy2.VectorFlg == 3) {
					data[YP + 1][XP].status = -1;
					data[YP + 2][XP].status = -1;
				}
				else if (g_enemy2.VectorFlg == 4) {
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

	if (g_enemy2.EX <= 429 && g_enemy2.EY == 330 && g_enemy2.VectorFlg == 1) {
		data[13][7].status = -1;
	}
	if (g_enemy2.EX >= 851 && g_enemy2.EY == 330 && g_enemy2.VectorFlg == 2) {
		data[13][19].status = -1;
	}

	/*if (g_enemy2.EY >= 535) {
		data[20][13].status = -1;
		data[20][15].status = -1;
	}*/

	a_star_pink.data[SY][SX].SearchStatus = a_star_pink.SEARCH_OPEN;

	a_star_pink.Search(0);

	a_star_pink.TraceRoute(GX, GY);
	a_star_pink.out();

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

void A_star_PINK::A_starInit() {
	SX = g_enemy2.EXC;
	SY = g_enemy2.EYC;

	GX = g_player.PXC;
	GY = g_player.PYC;

	SX1 = g_enemy2.EXC;
	SY1 = g_enemy2.EYC;
}
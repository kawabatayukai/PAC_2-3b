#include"DxLib.h"
#include <stdio.h>
#include <tchar.h>
#include <map>
#include"Player.h"
#include"A_star.h"
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
//#define SX	(g_enemy.EXC)
//#define SY	(21)
//#define SY	(g_enemy.EYC)

A_star a_star;

A_star::A_star() {
	SX = g_enemy.EXC;
	SY = g_enemy.EYC;

	GX = g_player.PXC;
	GY = g_player.PYC;

	d = 0;
	f = 0;

	SX1 = g_enemy2.EXC;
	SY1 = g_enemy2.EYC;

	Count = 0;

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

void A_star::ResetSearchStatus(void)
{
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			data[h][w].cost = 0;
			data[h][w].SearchStatus = 0;
		}
	}
	//return;
}

void A_star::SetDefault(void)
{
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			data[h][w].status = def_data[h][w];
		}
	}

	//return;
}

void A_star::out(void)
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
int A_star::GetDistance(int from_x, int from_y, int to_x, int to_y)
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

int A_star::BackTrace(int x, int y)
{
	if (x == SX && y == SY) return 1;

	int parent_way = data[y][x].parent;

	return BackTrace(
		x + CheckMatrix[parent_way].x,
		y + CheckMatrix[parent_way].y
	) + 1;
}

// A*�Ōo�H�T������
int A_star::Search(int count) {

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

void A_star::TraceRoute(int x, int y)
{
	//if (x == SX && y == SY) {
	if (x == SX && y == SY) {
		printf("�J�n�m�[�h>");
		return;
	}
	d = x;
	f = y;

	POINT* parent_way = &CheckMatrix[data[y][x].parent];

	data[y][x].status = 1;

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

int A_star::_tmain(/*int argc, _TCHAR* argv[]*//*int plX, int plY, int enX, int enY*/)
{
	if (Count == 0) {

		SX = g_enemy.EXC;
		SY = g_enemy.EYC;

		GX = g_player.PXC;
		GY = g_player.PYC;
		Count = 1;
	}
	else if (Count == 1) {
		/*SX = g_enemy2.EXC;
		SY = g_enemy2.EYC;*/

		SX = g_enemy2.EXC;
		SY = g_enemy2.EYC;

		GX = g_player.PXC;
		GY = g_player.PYC;

		if (g_player.KEYFLG == 1) {//LEFT
			GX = g_player.PXC-3;
			GY = g_player.PYC;
		}
		else if (g_player.KEYFLG == 2) {//RIGHT
			GX = g_player.PXC+3;
			GY = g_player.PYC;
		}
		else if (g_player.KEYFLG == 3) {//UP
			GX = g_player.PXC;
			GY = g_player.PYC-3;
		}
		else if (g_player.KEYFLG == 4) {//DOWN
			GX = g_player.PXC;
			GY = g_player.PYC+3;
		}
		else {
			GX = g_player.PXC;
			GY = g_player.PYC;
		}
		//Count = 0;
	}

		/*GX = g_player.PXC;
		GY = g_player.PYC;*/

		/*SX = plX;
		SY = plY;

		GX = enX;
		GY = enY;*/

	a_star.SetDefault();
	a_star.ResetSearchStatus();

	a_star.data[SY][SX].SearchStatus = a_star.SEARCH_OPEN;

	a_star.Search(0);

	a_star.TraceRoute(GX, GY);
	a_star.out();

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

void A_star::A_starInit() {
	SX = g_enemy.EXC;
	SY = g_enemy.EYC;

	GX = g_player.PXC;
	GY = g_player.PYC;

	SX1 = g_enemy2.EXC;
	SY1 = g_enemy2.EYC;
}
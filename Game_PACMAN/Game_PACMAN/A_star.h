#pragma once
#define WIDTH (27)
#define HEIGHT (29)
#define CM 4


class A_star {
public:
	enum {
		SEARCH_NO_CHECK = 0,
		SEARCH_OPEN = 1,
		SEARCH_CLOSE = 2,
	};

	typedef struct {
		int x;
		int y;
	} POINT;

	// 8方向のベクトル設定
	POINT CheckMatrix[CM] = {
		{  0,  1 },		// 0
		//{ -1,  1 },		// 1
		{ -1,  0 },		// 2
		//{ -1, -1 },	// 3
		{  0, -1 },		// 4
		//{  1, -1 },		// 5
		{  1,  0 },		// 6
		//{  1,  1 },		// 7
	};

	typedef struct
	{
		int no;
		int chip;
		int status;
		int event_no;

		int cost;
		int SearchStatus;	// 0:未調査 1:オープン 2:クローズ
		int parent;		// 親の向き
	} mapcell;

	mapcell data[HEIGHT][WIDTH];

	/*int def_data[HEIGHT][WIDTH] = {
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},
		{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,-1,},
		{-1,0,-1,-1,0,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,0,-1,-1,0,-1,},
		{-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,},
		{-1,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,0,-1,},
		{-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,-1,},
		{-1,-1,-1,-1,0,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,0,-1,-1,-1,-1,},
		{0,0,0,-1,0,-1,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,},
		{0,0,0,-1,0,-1,0,-1,-1,-1,0,-1,-1,-1,0,-1,0,-1,0,0,0,},
		{-1,-1,-1,-1,0,-1,0,-1,0,0,0,0,0,-1,0,-1,0,-1,-1,-1,-1,},
		{0,0,0,0,0,0,0,-1,0,0,0,0,0,-1,0,0,0,0,0,0,0,},
		{-1,-1,-1,-1,0,-1,0,-1,0,0,0,0,0,-1,0,-1,0,-1,-1,-1,-1,},
		{0,0,0,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,0,0,0,},
		{0,0,0,-1,0,-1,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,},
		{-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,},
		{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,-1,},
		{-1,0,-1,-1,0,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,0,-1,-1,0,-1,},
		{-1,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,-1,},
		{-1,-1,0,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,0,-1,-1,},
		{-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,-1,},
		{-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,},
		{-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},
	};*/
	int def_data[HEIGHT][WIDTH] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0},
		{0,0,0,-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,-1,0,0,0},
		{0,0,0,-1,0,-1,-1,0,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,0,-1,-1,0,-1,0,0,0},
		{0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0},
		{0,0,0,-1,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,0,-1,0,0,0},
		{0,0,0,-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0},
		{0,0,0,-1,-1,-1,-1,0,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,0,-1,-1,-1,-1,0,0,0},
		{0,0,0,0,0,0,-1,0,-1,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,0,0},
		{0,0,0,0,0,0,-1,0,-1,0,-1,-1,-1,0,-1,-1,-1,0,-1,0,-1,0,0,0,0,0,0},
		{0,0,0,-1,-1,-1,-1,0,-1,0,-1,0,0,0,0,0,-1,0,-1,0,-1,-1,-1,-1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,-1,-1,-1,-1,0,-1,0,-1,0,0,0,0,0,-1,0,-1,0,-1,-1,-1,-1,0,0,0},
		{0,0,0,0,0,0,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,0,0,0,0,0,0},
		{0,0,0,0,0,0,-1,0,-1,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,0,0},
		{0,0,0,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,0,0,0},
		{0,0,0,-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,-1,0,0,0},
		{0,0,0,-1,0,-1,-1,0,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,0,-1,-1,0,-1,0,0,0},
		{0,0,0,-1,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,-1,0,0,0},
		{0,0,0,-1,-1,0,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,0,-1,-1,0,0,0},
		{0,0,0,-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0},
		{0,0,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,0,0},
		{0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0},
		{0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	};

	int SX;
	int SY;

	int GX;
	int GY;

	int d;
	int f;

	int SX1;
	int SY1;

	int Count = 0;

	int Time = 0;
	int GFlg = false;
	int Rand = 0;


	A_star();

	void ResetSearchStatus(void);
	void SetDefault(void);
	void out(void);
	// マンハッタン距離を斜め移動ありを考慮して求める
	int GetDistance(int from_x, int from_y, int to_x, int to_y);
	int BackTrace(int x, int y);
	// A*で経路探査する
	int Search(int count);
	void TraceRoute(int x, int y);
	int _tmain(/*int argc, _TCHAR* argv[]*//*int plX,int plY, int enX,int enY*/);
	void A_STAR();
	void A_starInit();

};
extern A_star a_star;
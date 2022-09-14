#pragma once
#include "Info.h"
#define BAIT_MAX /*244*/ 168
class Bait {
public:
	struct BAIT {
		int flg;		// 使用フラグ
		int type;		// タイプ
		int img;		// 画像
		int x, y;		// 座標 x,y
	};
	struct BAIT bait[BAIT_MAX];
	struct BAIT bait00 = { true,0,0,DRAW_POINT_X+132,DRAW_POINT_Y+132 };

	int pscore = 0;//エサの取得数
	int I = 0;//for文用変数
	int Timer = 0;//powerエサ点滅変数

	Bait();

	struct CIRCLE
	{
		float x, y, r;//当たり判定・円
	};

	void BaitInit();//初期化(機能してない)
	void CreateBait();//エサの生成(実質初期化)
	void BaitController();//エサの操作
	bool CheckHit(const CIRCLE& t_circleA, const CIRCLE& t_circleB);


};
extern Bait bait;
#pragma once
#include "Info.h"

#define BAIT_MAX /*244*/ 168   //最大数

struct BAIT
{
	int flg;		// 使用フラグ
	int type;		// タイプ
	int img;		// 画像
	int x, y;		// 座標 x,y
};

struct CIRCLE
{
	float x, y, r;//当たり判定・円
};

class Bait
{
public:
	Bait();
	int LoadImages();
	void BaitInit();//初期化(機能してない)
	void CreateBait();//エサの生成(実質初期化)
	void BaitController(int playerX, int playerY);//エサの操作
	bool CheckHit(const CIRCLE& t_circleA, const CIRCLE& t_circleB);

	int GetBaitCount() { return pscore; }    //食べたエサ数を返す
	int GetPowerFlg() { return PowerFlg; }

private:
	BAIT bait[BAIT_MAX];
	BAIT bait00 = { true,0,0,DRAW_POINT_X + 132,DRAW_POINT_Y + 132 };

	int pscore = 0;   //エサの取得数
	int I = 0;        //for文用変数

	int BaitImage;    //エサ画像
	int PowerImage;   //パワーエサ画像
	int PowerFlg;     //パワーエサフラグ
};
extern Bait bait;
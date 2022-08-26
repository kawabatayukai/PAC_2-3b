#pragma once
#include"Info.h"
class Player
{
public:
	Player();

	int PX = 640;
	int PY = 540;
	int KEYFLG = 0;
	int LEFT_FLG = false;
	int RIGHT_FLG = false;
	int UP_FLG = false;
	int DOWN_FLG = false;

	int PXC;
	int PYC;
	int oldX;
	int oldY;

	int I;
	int J;
	int C;
	int S;

	struct BOX
	{
		float fLeft[MAP_WIDTH+ MAP_HEIGHT], fTop[MAP_WIDTH + MAP_HEIGHT], fRight[MAP_WIDTH + MAP_HEIGHT], fBottom[MAP_WIDTH + MAP_HEIGHT];
	};

	struct CIRCLE
	{
		float x, y, r;
	};

	void PlayerInit();
	void PlayerController();
	float DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2);
	bool CheckHit(const BOX & t_box, const CIRCLE& t_circle);

};
extern Player g_player;
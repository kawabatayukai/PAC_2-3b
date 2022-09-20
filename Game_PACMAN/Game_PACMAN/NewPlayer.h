#pragma once
#include"Info.h"
//#define MAP MAP_WIDTH + MAP_HEIGHT
#define MAP MAP_WIDTH + MAP_HEIGHT

class Player
{
public:
	Player();

	int PX = 640;
	int PY = 540;
	int KEYFLG = 0;
	int NEXTFLG = 0;
	int LEFT_FLG = false;
	int RIGHT_FLG = false;
	int UP_FLG = false;
	int DOWN_FLG = false;

	int PXC;
	int PYC;
	int oldX;
	int oldY;

	int I = 0;
	int J = 0;
	int C = 0;
	int S = 0;
	int CI = 0;
	int CF = 0;

	int FLG_L;
	int FLG_R;
	int FLG_U;
	int FLG_D;

	int LC;
	int RC;
	int UC;
	int DC;

	int FLG_MAX_L;
	int FLG_MAX_R;
	int FLG_MAX_U;
	int FLG_MAX_D;

	int OldKeyFlg;
	int NextKeyFlg;

	int SpeedUPFlg;
	int SpeedUPTime;

	int PacMan[12];
	//int PacMan_motion[5];
	int PacMan_index;

	int PacMan_wait;
	int PacMan_dir;

	int Life;
	int LifeUPFlg;

	struct BOX
	{
		int fLeft[MAP], fTop[MAP], fRight[MAP], fBottom[MAP];
	};

	struct BOX1
	{
		float fLeft[MAP], fTop[MAP], fRight[MAP], fBottom[MAP];
	};

	struct CIRCLE
	{
		float x, y, r;
	};

	void PlayerInit();
	void PlayerController(int keyFlg, int MapData[MAP_HEIGHT][MAP_WIDTH]);
	float DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2);
	bool CheckHit(const BOX& t_box, const CIRCLE& t_circle);
	bool CheckHit(const BOX1& t_box, const CIRCLE& t_circle);
	bool CheckHitBOX(const BOX& t_direA, const BOX1& t_direB);

	int LoadImages();
	int GetPlayerX() { return (PX)-DRAW_POINT_X; }       //Xç¿ïWÇéÊìæ
	int GetPlayerY() { return (PY)-DRAW_POINT_Y; }       //Yç¿ïWÇéÊìæ
	int GetPlayerD() { return KEYFLG - 1; }  //ï˚å¸ÇéÊìæ


private:
	int	g_PlayerImage;
	int PlayerImageL;
	int PlayerImageR;
	int PlayerImageU;
	int PlayerImageD;
};
extern Player g_player;


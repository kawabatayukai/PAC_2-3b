#include"DxLib.h"
#include"TestPlayer.h"
#include"Info.h"
#include"Enemy.h"

PLAYER_BASE Player;

PLAYER_BASE::PLAYER_BASE()
{

}

//初期処理
void PLAYER_BASE::PlayerInit()
{
	g_player.x = MAP_SIZE + MAP_SIZE / 2;
	g_player.y = (MAP_SIZE * 5) + MAP_SIZE / 2;
	g_player.w = 30;
	g_player.h = 30;
	g_player.speed = 4;//4;
	g_player.dir = DIRECTION::NONE;
}

//描画
void PLAYER_BASE::DrawPlayer()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawCircle(g_player.x + DRAW_POINT_X, g_player.y + DRAW_POINT_Y, 15, 0xffff00, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//移動
void PLAYER_BASE::MovePlayer(int NowKey, int MapData[MAP_HEIGHT][MAP_WIDTH])
{

	int Mx = g_player.x / MAP_SIZE;
	int My = g_player.y / MAP_SIZE;

	int Lx = (g_player.x - (g_player.w / 2)) / 20;
	int Rx = (g_player.x + (g_player.w / 2)) / 20;
	int Uy = (g_player.y - (g_player.h / 2)) / 20;
	int Dy = (g_player.y + (g_player.h / 2)) / 20;

	{
		//キーボード
		if (NowKey & PAD_INPUT_LEFT && MapData[My][Mx - 1] != 1) g_player.dir = DIRECTION::LEFT;
		else if (NowKey & PAD_INPUT_RIGHT && MapData[My][Mx + 1] != 1) g_player.dir = DIRECTION::RIGHT;
		else if (NowKey & PAD_INPUT_UP && MapData[My - 1][Mx] != 1) g_player.dir = DIRECTION::UP;
		else if (NowKey & PAD_INPUT_DOWN && MapData[My + 1][Mx] != 1) g_player.dir = DIRECTION::DOWN;
	}
	if (g_player.dir == DIRECTION::LEFT) g_player.x -= g_player.speed;
	if (g_player.dir == DIRECTION::RIGHT) g_player.x += g_player.speed;
	if (g_player.dir == DIRECTION::UP) g_player.y -= g_player.speed;
	if (g_player.dir == DIRECTION::DOWN) g_player.y += g_player.speed;

	//めり込ませない
	int x1, x2, y1, y2;
	x1 = (g_player.x - (g_player.w / 2));
	x2 = (g_player.x + (g_player.w / 2) - 1);
	y1 = (g_player.y - (g_player.h / 2) + 1);
	y2 = (g_player.y + (g_player.h / 2) - 1);

	if (MapData[My][Mx - 1] == 1)
	{
		if ((Mx - 1) * MAP_SIZE + MAP_SIZE > x1) g_player.x = (Mx - 1) * MAP_SIZE + MAP_SIZE + g_player.w / 2;
	}
	if (MapData[My][Mx + 1] == 1)
	{
		if ((Mx + 1) * MAP_SIZE < x2) g_player.x = (Mx + 1) * MAP_SIZE - g_player.w / 2;
	}
	if (MapData[My - 1][Mx] == 1)
	{
		if ((My - 1) * MAP_SIZE + MAP_SIZE > y1) g_player.y = (My - 1) * MAP_SIZE + MAP_SIZE + g_player.w / 2;
	}
	if (MapData[My + 1][Mx] == 1)
	{
		if ((My + 1) * MAP_SIZE < y2) g_player.y = (My + 1) * MAP_SIZE - g_player.w / 2;
	}
}
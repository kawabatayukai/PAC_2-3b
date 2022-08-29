#pragma once
#include"Enemy.h"

struct PLAYER
{
    int x;      //X座標
    int y;      //Y座標
    int w;      //幅
    int h;      //高さ
    int speed;  //スピード
    int dir;    //向き
};

//test
class PLAYER_BASE
{
public:
    PLAYER_BASE();
    void PlayerInit();
    void DrawPlayer();
    void MovePlayer(int NowKey, int MapData[MAP_HEIGHT][MAP_WIDTH]);

    int GetPlayerX() { return g_player.x; }
    int GetPlayerY() { return g_player.y; }
    int GetPlayerD() { return g_player.dir; }

private:
    PLAYER g_player; //本体
};

extern PLAYER_BASE Player;

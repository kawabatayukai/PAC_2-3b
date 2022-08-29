#pragma once
#include"Enemy.h"

struct PLAYER
{
    int x;      //X���W
    int y;      //Y���W
    int w;      //��
    int h;      //����
    int speed;  //�X�s�[�h
    int dir;    //����
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
    PLAYER g_player; //�{��
};

extern PLAYER_BASE Player;

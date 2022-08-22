#pragma once
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

class Player {
private:
   /* int PlayerImageL;
    int PlayerImageR;
    int PlayerImageU;
    int PlayerImageD;*/

    int width;          // バーの幅
    int height;         // バーの高さ


public:
    Player();                  // コンストラクタ
    //void InitXY();          // プレイヤーの座標初期化

    // ゲッター
    int getBarX();
    int getBarY();
    int getWidth();
    int getHeight();

    void PlayerControl();
    int HitBoxPlayer();

    int PX;
    int PY;

    int KEYFLG;
    int NEXTFLG;
    int FLG;
    int g_Vector;
    int PX_2;
    int PY_2;
};

// エクスターン
extern Player g_player;

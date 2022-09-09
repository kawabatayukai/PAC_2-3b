#pragma once
#include"Info.h"

//敵キャラの幅・高さ
#define E_WIDTH  30
#define E_HEIGHT 30

//移動方向
enum DIRECTION
{
	LEFT = 0, //左方向
	RIGHT,    //右方向
	UP,       //上方向
	DOWN,     //下方向
	NONE      //移動なし
};

//状態(モード)
enum MODE
{
	STANDBY = 0,//出撃前
	PATROL,     //巡回モード
	TRACK,      //追跡モード
	RANDOM      //ランダム
};

//移動目標
struct M_POINT
{
	int x;
	int y;
};

//敵の構造体
struct ENEMY
{
	bool flg;   //描画フラグ
	int x;     //X座標
	int y;     //Y座標
	int w;     //幅
	int h;     //高さ
	int speed; //スピード
	int score; //スコア
	int img;   //画像(番号) 画像配列操作用
};


//敵キャラの基底クラス
class ENEMY_BASE
{
public:
	/*** 純粋仮想関数（基底クラスで関数の内容を定義しない）***/

	virtual int Loadimages() = 0;   //画像読み込み
	virtual int LoadSounds() = 0;   //音源読み込み
	virtual void InitEnemy() = 0;   //初期処理
	virtual void MoveEnemy(int MapData[MAP_HEIGHT][MAP_WIDTH]) = 0;   //移動
	virtual void DrawEnemy() = 0;   //描画

	/*********************************************************/

	void ChangeMoveImages();       //移動による画像チェンジ

	void search(int tx, int ty, int n);                                               //ターゲットまでの最短経路を探す
	void moveDataSet(int MapData[MAP_HEIGHT][MAP_WIDTH], int playerX, int playerY);   //最短経路を探す準備　経路探索用mapの初期化・目標座標に10(目印)を設定
	void MoveShortest(int MapData[MAP_HEIGHT][MAP_WIDTH], int targetX, int targetY);  //ターゲットの位置に最短経路で移動する

	int CheckTarget2();       //巡回モード用 

	int GetEnemyMode() { return EnemyMode; }                          //現在のモードを取得
	void SetEnemyMode(int mode) { if (mode < 3) EnemyMode = mode; }   //モードを変更

protected:
	int enemyimage[8] = { 0 };//画像（配列）　
	int enemysounds;    //音源用変数

	ENEMY g_enemy;            //敵のデータ
	int MoveCount;            //画像変化用にフレームをカウント

	int MoveDir;                              //移動方向
	M_POINT MoveTarget;                       //移動目標
	int EnemyMode = MODE::STANDBY;            //敵のモード
	int my_mapdata[MAP_HEIGHT][MAP_WIDTH];    //経路探索用map

	bool ijike_flg = false;                   //"イジケ状態"フラグ true：イジケ　false：イジケなし 
};


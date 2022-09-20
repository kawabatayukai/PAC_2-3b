#pragma once
#include"Info.h"
#define WIDTH (27)
#define HEIGHT (29)
#define MAP MAP_WIDTH + MAP_HEIGHT
#define CM 4
//敵キャラ最大数　ｱｶ　ﾋﾟﾝｸ　ﾐｽﾞｲﾛ　ｵﾚﾝｼﾞ
#define ENEMY_MAX 4

//敵キャラの幅・高さ
#define E_WIDTH  30
#define E_HEIGHT 30

//テスト出力用
char ColorStr[][7];
char DirectStr[][6];
char ModeStr[][8];

//敵の固有色
enum ENEMY_COLOR
{
	RED = 0, //赤
	PINK,    //ピンク
	BLUE,    //青
	ORANGE,  //オレンジ
	CLEAR = 99
};

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
	IJIKE,      //イジケ
	EYE,        //目
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
	int img;   //画像
};

//巣の中の位置　 初期位置ではない（初期位置はアカだけ巣の上）
int NestPoint[][2];

//敵キャラの基底クラス
class ENEMY_BASE
{
public:
	ENEMY_BASE(int color);    //コンストラクタ
	~ENEMY_BASE();                  //デストラクタ

	/*** 純粋仮想関数（基底クラスで関数の内容を定義しない）***/

	virtual int Loadimages() = 0;   //画像読み込み
	virtual void InitEnemy() = 0;   //初期処理
	virtual void MoveEnemy(int MapData[MAP_HEIGHT][MAP_WIDTH]) = 0;   //移動
	virtual void DrawEnemy() = 0;   //描画

	/*********************************************************/
	static void AllEnemyInit();    //すべてのEnemyを初期化
	void DrawAllEnemy();           //すべてのEnemyを描画

	static void SoltieControl(int NowKey, int FoodCount, int ClearCount);   //出撃を管理
	static void IjikeControl(int PowerFlg);                               //イジケ状態ON・OFF

	void SetSortie() { if (sortie_flg == false)sortie_flg = true; } //出撃フラグを変更（テスト用）

	void ChangeMoveImages();       //移動による画像チェンジ

	void search(int tx, int ty, int n);  //ターゲットまでの最短経路を探す
	void moveDataSet(int MapData[MAP_HEIGHT][MAP_WIDTH], int playerX, int playerY);   //最短経路を探す準備　コピーマップの初期化と目的地(player)の場所に10(目印)を設定
	void MoveShortest(int MapData[MAP_HEIGHT][MAP_WIDTH], int targetX, int targetY);  //ターゲットの位置に最短経路で移動する

	int CheckTarget3();

	int GetEnemyX() { return g_enemy.x; }     //x座標を取得
	int GetEnemyY() { return g_enemy.y; }     //y座標を取得

	int GetMoveDir() { return MoveDir; }     //移動方向を取得
	void SetMoveDir(int D);     //移動方向を取得

	int GetEnemyMode() { return EnemyMode; }                          //現在のモードを取得
	void SetEnemyMode(int mode) { if (mode < 5) EnemyMode = mode; }   //モードを変更

	static void DrawAllInfo();  //テスト用　敵全色の情報を表示

	int EX;
	int EY;
	int EXC;
	int EYC;
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

	int oldX;
	int oldY;

	int VectorFlg;

	int OldKeyFlg;
	int NextKeyFlg;

	int NEXTFLG;

	int DFLG;

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

	int MapData[29][27];

	void EnemyInit();
	void EnemyController();
	float DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2);
	bool CheckHit(const BOX& t_box, const CIRCLE& t_circle);
	bool CheckHit(const BOX1& t_box, const CIRCLE& t_circle);
	bool CheckHitBOX(const BOX& t_direA, const BOX1& t_direB);
	void MapCopy();

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
		{0,0,0,-1,0,0,0,2,0,0,0,0,0,-1,0,0,0,0,0,2,0,0,0,-1,0,0,0},
		{0,0,0,-1,0,-1,-1,0,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,0,-1,-1,0,-1,0,0,0},
		{0,0,0,-1,2,0,0,2,0,2,0,0,2,0,2,0,0,2,0,2,0,0,2,-1,0,0,0},
		{0,0,0,-1,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,0,-1,0,0,0},
		{0,0,0,-1,0,0,0,2,-1,0,0,0,0,-1,0,0,0,0,-1,2,0,0,0,-1,0,0,0},
		{0,0,0,-1,-1,-1,-1,0,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,0,-1,-1,-1,-1,0,0,0},
		{0,0,0,0,0,0,-1,0,-1,0,0,0,2,0,2,0,0,0,-1,0,-1,0,0,0,0,0,0},
		{0,0,0,0,0,0,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,0,0,0,0,0,0},
		{0,0,0,-1,-1,-1,-1,0,-1,0,-1,0,0,0,0,0,-1,0,-1,0,-1,-1,-1,-1,0,0,0},
		{0,0,0,0,0,0,0,2,0,2,-1,0,0,0,0,0,-1,2,0,2,0,0,0,0,0,0,0},
		{0,0,0,-1,-1,-1,-1,0,-1,0,-1,0,0,0,0,0,-1,0,-1,0,-1,-1,-1,-1,0,0,0},
		{0,0,0,0,0,0,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,0,0,0,0,0,0},
		{0,0,0,0,0,0,-1,0,-1,2,0,0,0,0,0,0,0,2,-1,0,-1,0,0,0,0,0,0},
		{0,0,0,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,0,0,0},
		{0,0,0,-1,0,0,0,2,0,2,0,0,0,-1,0,0,0,2,0,2,0,0,0,-1,0,0,0},
		{0,0,0,-1,0,-1,-1,0,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,0,-1,-1,0,-1,0,0,0},
		{0,0,0,-1,0,0,-1,2,0,2,0,0,2,0,2,0,0,2,0,2,-1,0,0,-1,0,0,0},
		{0,0,0,-1,-1,0,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,0,-1,-1,0,0,0},
		{0,0,0,-1,0,2,0,0,-1,0,0,0,0,-1,0,0,0,0,-1,0,0,2,0,-1,0,0,0},
		{0,0,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,0,0},
		{0,0,0,-1,0,0,0,0,0,0,0,0,2,0,2,0,0,0,0,0,0,0,0,-1,0,0,0},
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

	int DFlg = false;

	int DX = 0;
	int DY = 0;

	int XP = 0;
	int YP = 0;
	int XM = 0;
	int YM = 0;

	int OldXP = 0;
	int OldYP = 0;
	int OldXM = 0;
	int OldYM = 0;

	int Timer = 0;

	int X2 = 0;
	int XX = 0;
	int Y2 = 0;
	int YY = 0;

	int aas = 0;

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

protected:
	int enemyimage[16] = { 0 };//画像（配列）

	const int My_Color = ENEMY_COLOR::CLEAR; //固有色
	ENEMY g_enemy;             //敵のデータ
	int MoveCount = 0;         //画像変化用にフレームをカウント

	int MoveDir;                              //移動方向
	M_POINT MoveTarget;                       //移動目標
	int EnemyMode = MODE::STANDBY;            //敵のモード
	int my_mapdata[MAP_HEIGHT][MAP_WIDTH];    //経路探索用map

	bool sortie_flg = false;            //出撃フラグ　false 待機　　true 出撃
	int mode_count = 0;                 //モードチェンジ(巡回・追跡)用にフレームをカウント

	bool ijike_flg = false;   //"イジケ状態"フラグ true：イジケ　false：イジケなし 
	int IjikeCount = 0;       //イジケ状態時間カウント用

	bool hitp_flg = false;    //プレイヤー当たりフラグ true：当たり　false：当たりなし


	/*****************************************************************************/
											  //アカ 0　ピンク 1　アオ 2　オレンジ 3
	static ENEMY_BASE* All_Enemy[ENEMY_MAX];  //全ての敵キャラのアドレスを保持 静的メンバ変数

	static const int PtrlPoint[4][4][2];      //巡回モード用座標
};

////巡回モード用座標
//int PtrlPoint[4][4][2] =
//{
//	//アカ
//	{
//		{19 * MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//		{16 * MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//	    {16 * MAP_SIZE + (MAP_SIZE / 2),5 * MAP_SIZE + (MAP_SIZE / 2)},
//	    {19 * MAP_SIZE + (MAP_SIZE / 2),5 * MAP_SIZE + (MAP_SIZE / 2)},
//	},
//	//ピンク
//	{
//		{MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//	    {4 * MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//	    {4 * MAP_SIZE + (MAP_SIZE / 2),5 * MAP_SIZE + (MAP_SIZE / 2)},
//	    {MAP_SIZE + (MAP_SIZE / 2),5 * MAP_SIZE + (MAP_SIZE / 2)},
//	},
//	//アオ
//	{
//		{MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//		{MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//		{MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//		{MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//	},
//	//オレンジ
//	{
//		{MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//		{MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//		{MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//		{MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//	},
//};

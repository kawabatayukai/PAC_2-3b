#pragma once
#include"Info.h"
#define WIDTH (27)
#define HEIGHT (29)
#define MAP MAP_WIDTH + MAP_HEIGHT
#define CM 4
//�G�L�����ő吔�@���@��ݸ�@н޲ہ@��ݼ�
#define ENEMY_MAX 4

//�G�L�����̕��E����
#define E_WIDTH  30
#define E_HEIGHT 30

//�e�X�g�o�͗p
char ColorStr[][7];
char DirectStr[][6];
char ModeStr[][8];

//�G�̌ŗL�F
enum ENEMY_COLOR
{
	RED = 0, //��
	PINK,    //�s���N
	BLUE,    //��
	ORANGE,  //�I�����W
	CLEAR = 99
};

//�ړ�����
enum DIRECTION
{
	LEFT = 0, //������
	RIGHT,    //�E����
	UP,       //�����
	DOWN,     //������
	NONE      //�ړ��Ȃ�
};

//���(���[�h)
enum MODE
{
	STANDBY = 0,//�o���O
	PATROL,     //���񃂁[�h
	TRACK,      //�ǐՃ��[�h
	IJIKE,      //�C�W�P
	EYE,        //��
	RANDOM      //�����_��
};

//�ړ��ڕW
struct M_POINT
{
	int x;
	int y;
};

//�G�̍\����
struct ENEMY
{
	bool flg;   //�`��t���O
	int x;     //X���W
	int y;     //Y���W
	int w;     //��
	int h;     //����
	int speed; //�X�s�[�h
	int score; //�X�R�A
	int img;   //�摜
};

//���̒��̈ʒu�@ �����ʒu�ł͂Ȃ��i�����ʒu�̓A�J�������̏�j
int NestPoint[][2];

//�G�L�����̊��N���X
class ENEMY_BASE
{
public:
	ENEMY_BASE(int color);    //�R���X�g���N�^
	~ENEMY_BASE();                  //�f�X�g���N�^

	/*** �������z�֐��i���N���X�Ŋ֐��̓��e���`���Ȃ��j***/

	virtual int Loadimages() = 0;   //�摜�ǂݍ���
	virtual void InitEnemy() = 0;   //��������
	virtual void MoveEnemy(int MapData[MAP_HEIGHT][MAP_WIDTH]) = 0;   //�ړ�
	virtual void DrawEnemy() = 0;   //�`��

	/*********************************************************/
	static void AllEnemyInit();    //���ׂĂ�Enemy��������
	void DrawAllEnemy();           //���ׂĂ�Enemy��`��

	static void SoltieControl(int NowKey, int FoodCount, int ClearCount);   //�o�����Ǘ�
	static void IjikeControl(int PowerFlg);                               //�C�W�P���ON�EOFF

	void SetSortie() { if (sortie_flg == false)sortie_flg = true; } //�o���t���O��ύX�i�e�X�g�p�j

	void ChangeMoveImages();       //�ړ��ɂ��摜�`�F���W

	void search(int tx, int ty, int n);  //�^�[�Q�b�g�܂ł̍ŒZ�o�H��T��
	void moveDataSet(int MapData[MAP_HEIGHT][MAP_WIDTH], int playerX, int playerY);   //�ŒZ�o�H��T�������@�R�s�[�}�b�v�̏������ƖړI�n(player)�̏ꏊ��10(�ڈ�)��ݒ�
	void MoveShortest(int MapData[MAP_HEIGHT][MAP_WIDTH], int targetX, int targetY);  //�^�[�Q�b�g�̈ʒu�ɍŒZ�o�H�ňړ�����

	int CheckTarget3();

	int GetEnemyX() { return g_enemy.x; }     //x���W���擾
	int GetEnemyY() { return g_enemy.y; }     //y���W���擾

	int GetMoveDir() { return MoveDir; }     //�ړ��������擾
	void SetMoveDir(int D);     //�ړ��������擾

	int GetEnemyMode() { return EnemyMode; }                          //���݂̃��[�h���擾
	void SetEnemyMode(int mode) { if (mode < 5) EnemyMode = mode; }   //���[�h��ύX

	static void DrawAllInfo();  //�e�X�g�p�@�G�S�F�̏���\��

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

	// 8�����̃x�N�g���ݒ�
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
		int SearchStatus;	// 0:������ 1:�I�[�v�� 2:�N���[�Y
		int parent;		// �e�̌���
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
	// �}���n�b�^���������΂߈ړ�������l�����ċ��߂�
	int GetDistance(int from_x, int from_y, int to_x, int to_y);
	int BackTrace(int x, int y);
	// A*�Ōo�H�T������
	int Search(int count);
	void TraceRoute(int x, int y);
	int _tmain(/*int argc, _TCHAR* argv[]*//*int plX,int plY, int enX,int enY*/);
	void A_STAR();
	void A_starInit();

protected:
	int enemyimage[16] = { 0 };//�摜�i�z��j

	const int My_Color = ENEMY_COLOR::CLEAR; //�ŗL�F
	ENEMY g_enemy;             //�G�̃f�[�^
	int MoveCount = 0;         //�摜�ω��p�Ƀt���[�����J�E���g

	int MoveDir;                              //�ړ�����
	M_POINT MoveTarget;                       //�ړ��ڕW
	int EnemyMode = MODE::STANDBY;            //�G�̃��[�h
	int my_mapdata[MAP_HEIGHT][MAP_WIDTH];    //�o�H�T���pmap

	bool sortie_flg = false;            //�o���t���O�@false �ҋ@�@�@true �o��
	int mode_count = 0;                 //���[�h�`�F���W(����E�ǐ�)�p�Ƀt���[�����J�E���g

	bool ijike_flg = false;   //"�C�W�P���"�t���O true�F�C�W�P�@false�F�C�W�P�Ȃ� 
	int IjikeCount = 0;       //�C�W�P��Ԏ��ԃJ�E���g�p

	bool hitp_flg = false;    //�v���C���[������t���O true�F������@false�F������Ȃ�


	/*****************************************************************************/
											  //�A�J 0�@�s���N 1�@�A�I 2�@�I�����W 3
	static ENEMY_BASE* All_Enemy[ENEMY_MAX];  //�S�Ă̓G�L�����̃A�h���X��ێ� �ÓI�����o�ϐ�

	static const int PtrlPoint[4][4][2];      //���񃂁[�h�p���W
};

////���񃂁[�h�p���W
//int PtrlPoint[4][4][2] =
//{
//	//�A�J
//	{
//		{19 * MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//		{16 * MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//	    {16 * MAP_SIZE + (MAP_SIZE / 2),5 * MAP_SIZE + (MAP_SIZE / 2)},
//	    {19 * MAP_SIZE + (MAP_SIZE / 2),5 * MAP_SIZE + (MAP_SIZE / 2)},
//	},
//	//�s���N
//	{
//		{MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//	    {4 * MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//	    {4 * MAP_SIZE + (MAP_SIZE / 2),5 * MAP_SIZE + (MAP_SIZE / 2)},
//	    {MAP_SIZE + (MAP_SIZE / 2),5 * MAP_SIZE + (MAP_SIZE / 2)},
//	},
//	//�A�I
//	{
//		{MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//		{MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//		{MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//		{MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//	},
//	//�I�����W
//	{
//		{MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//		{MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//		{MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//		{MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
//	},
//};

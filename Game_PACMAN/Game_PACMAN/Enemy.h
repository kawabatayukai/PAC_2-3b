#pragma once
#include"Info.h"

//�G�L�����̕��E����
#define E_WIDTH  30
#define E_HEIGHT 30

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
	int img;   //�摜(�ԍ�) �摜�z�񑀍�p
};


//�G�L�����̊��N���X
class ENEMY_BASE
{
public:
	/*** �������z�֐��i���N���X�Ŋ֐��̓��e���`���Ȃ��j***/

	virtual int Loadimages() = 0;   //�摜�ǂݍ���
	virtual int LoadSounds() = 0;   //�����ǂݍ���
	virtual void InitEnemy() = 0;   //��������
	virtual void MoveEnemy(int MapData[MAP_HEIGHT][MAP_WIDTH]) = 0;   //�ړ�
	virtual void DrawEnemy() = 0;   //�`��

	/*********************************************************/

	void ChangeMoveImages();       //�ړ��ɂ��摜�`�F���W

	void search(int tx, int ty, int n);                                               //�^�[�Q�b�g�܂ł̍ŒZ�o�H��T��
	void moveDataSet(int MapData[MAP_HEIGHT][MAP_WIDTH], int playerX, int playerY);   //�ŒZ�o�H��T�������@�o�H�T���pmap�̏������E�ڕW���W��10(�ڈ�)��ݒ�
	void MoveShortest(int MapData[MAP_HEIGHT][MAP_WIDTH], int targetX, int targetY);  //�^�[�Q�b�g�̈ʒu�ɍŒZ�o�H�ňړ�����

	int CheckTarget2();       //���񃂁[�h�p 

	int GetEnemyMode() { return EnemyMode; }                          //���݂̃��[�h���擾
	void SetEnemyMode(int mode) { if (mode < 3) EnemyMode = mode; }   //���[�h��ύX

protected:
	int enemyimage[8] = { 0 };//�摜�i�z��j�@
	int enemysounds;    //�����p�ϐ�

	ENEMY g_enemy;            //�G�̃f�[�^
	int MoveCount;            //�摜�ω��p�Ƀt���[�����J�E���g

	int MoveDir;                              //�ړ�����
	M_POINT MoveTarget;                       //�ړ��ڕW
	int EnemyMode = MODE::STANDBY;            //�G�̃��[�h
	int my_mapdata[MAP_HEIGHT][MAP_WIDTH];    //�o�H�T���pmap

	bool ijike_flg = false;                   //"�C�W�P���"�t���O true�F�C�W�P�@false�F�C�W�P�Ȃ� 
};


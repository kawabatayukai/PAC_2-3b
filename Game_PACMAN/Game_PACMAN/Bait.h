#pragma once
#include "Info.h"

#define BAIT_MAX /*244*/ 168   //�ő吔

struct BAIT
{
	int flg;		// �g�p�t���O
	int type;		// �^�C�v
	int img;		// �摜
	int x, y;		// ���W x,y
};

struct CIRCLE
{
	float x, y, r;//�����蔻��E�~
};

class Bait
{
public:
	Bait();
	int LoadImages();
	void BaitInit();//������(�@�\���ĂȂ�)
	void CreateBait();//�G�T�̐���(����������)
	void BaitController(int playerX, int playerY);//�G�T�̑���
	bool CheckHit(const CIRCLE& t_circleA, const CIRCLE& t_circleB);

	int GetBaitCount() { return pscore; }    //�H�ׂ��G�T����Ԃ�
	int GetPowerFlg() { return PowerFlg; }

private:
	BAIT bait[BAIT_MAX];
	BAIT bait00 = { true,0,0,DRAW_POINT_X + 132,DRAW_POINT_Y + 132 };

	int pscore = 0;   //�G�T�̎擾��
	int I = 0;        //for���p�ϐ�

	int BaitImage;    //�G�T�摜
	int PowerImage;   //�p���[�G�T�摜
	int PowerFlg;     //�p���[�G�T�t���O
};
extern Bait bait;
#pragma once
#include "Info.h"
#define BAIT_MAX /*244*/ 168
class Bait {
public:
	struct BAIT {
		int flg;		// �g�p�t���O
		int type;		// �^�C�v
		int img;		// �摜
		int x, y;		// ���W x,y
	};
	struct BAIT bait[BAIT_MAX];
	struct BAIT bait00 = { true,0,0,DRAW_POINT_X+132,DRAW_POINT_Y+132 };

	int pscore = 0;//�G�T�̎擾��
	int I = 0;//for���p�ϐ�
	int Timer = 0;//power�G�T�_�ŕϐ�

	Bait();

	struct CIRCLE
	{
		float x, y, r;//�����蔻��E�~
	};

	void BaitInit();//������(�@�\���ĂȂ�)
	void CreateBait();//�G�T�̐���(����������)
	void BaitController();//�G�T�̑���
	bool CheckHit(const CIRCLE& t_circleA, const CIRCLE& t_circleB);


};
extern Bait bait;
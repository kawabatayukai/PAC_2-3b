//#include"DxLib.h"
//#include"enemy.h"
//#include"red.h"
//#include "Info.h"
//
//ENEMY_RED Red;
//
//
////�R���X�g���N�^  ENEMY_BASE�̃R���X�g���N�^�� "My_Color" ��ݒ�
//ENEMY_RED::ENEMY_RED() : ENEMY_BASE(ENEMY_COLOR::RED)
//{
//	////�A�h���X�ێ��p�z���0�ԖڂɃA�J�̃A�h���X�i�Œ�j
//	//if (All_Enemy[My_Color] == nullptr) All_Enemy[My_Color] = this;
//}
//
////�摜�ǂݍ���
//int ENEMY_RED::Loadimages()
//{
//	//�����ǂݍ���
//
//	if ((LoadDivGraph("images/All_Red30.png", 16, 4, 4, 30, 30, enemyimage)) == -1) return -1;   //30 �@��޹�E�ڂ��܂�
//}
//
////��������
//void ENEMY_RED::InitEnemy()
//{
//	g_enemy.flg = true;
//	g_enemy.x = 8 * MAP_SIZE + (MAP_SIZE / 2); //���̒�
//	g_enemy.y = 9 * MAP_SIZE + (MAP_SIZE / 2); //���̒�
//
//	g_enemy.w = E_WIDTH;
//	g_enemy.h = E_HEIGHT;
//	g_enemy.speed = 3;//p_speed[0];
//	//g_enemy.speed = GetRand(4) + 1;
//	g_enemy.img = 0;
//
//	//�ړ��Ȃ�
//	MoveDir = (int)DIRECTION::NONE;
//
//	//�ړ��ڕW������
//	MoveTarget = { 0,0 };
//
//	//���[�h
//	EnemyMode = MODE::STANDBY;
//	//���[�h�`�F���W�p�J�E���^�[
//	mode_count = 0;
//	//�C�W�P�i�V
//	ijike_flg = false;
//
//	if (sortie_flg == true)sortie_flg = false;
//}
//
////�ړ�
//void ENEMY_RED::MoveEnemy(int MapData[MAP_HEIGHT][MAP_WIDTH])
//{
//	//�ړ��ɂ��摜�ω�
//	//MoveCount++;
//	ChangeMoveImages();
//
//	//�^�[�Q�b�g�Ƃ̋������k�߂�
//	//�ǂɂԂ���ƕ����]��
//
//	int Tx = MoveTarget.x;    //�ǐՑΏ�X�@�@�@�ǐՃ��[�h�̂�
//	int Ty = MoveTarget.y;    //   �V�@ Y
//
//	int Mx = g_enemy.x / MAP_SIZE;
//	int My = g_enemy.y / MAP_SIZE;
//
//	int Lx = (g_enemy.x - (g_enemy.w / 2));
//	int Rx = (g_enemy.x + (g_enemy.w / 2));
//	int Uy = (g_enemy.y - (g_enemy.h / 2));
//	int Dy = (g_enemy.y + (g_enemy.h / 2));
//
//	bool hitX = false;  //X���̈�v �؁Eż
//	bool hitY = false;  //Y���̈�v �؁Eż
//
//	//�G�̍��W�ƖڕW���W�̍��idifference�j
//	int dx = g_enemy.x - MoveTarget.x;
//	int dy = g_enemy.y - MoveTarget.y;
//
//	//x,y�����̍����r�A�傫������Ă������D��  ��Βl��
//
//	//x���������킹��
//	if (abs(dx) > abs(dy))
//	{
//		if (dx > 0) //�ڕW��������荶��
//		{
//			if (MapData[My][Mx - 1] != 1) MoveDir = DIRECTION::LEFT;
//		}
//		if (dx < 0) //�ڕW���������E��
//		{
//			if (MapData[My][Mx + 1] != 1) MoveDir = DIRECTION::RIGHT;
//		}
//		//�ǂ�����ꍇ��Y�����Ɉړ�����
//		if (MapData[My][Mx - 1] == 1 || MapData[My][Mx + 1] == 1)
//		{
//			if (dy > 0) //�ڕW���������㑤
//			{
//				if (MapData[My - 1][Mx] != 1) MoveDir = DIRECTION::UP;
//			}
//
//			if (dy < 0) //�ڕW��������艺��
//			{
//				if (MapData[My + 1][Mx] != 1) MoveDir = DIRECTION::DOWN;
//			}
//		}
//	}
//	else
//	{
//		if (dy > 0) //�ڕW���������㑤
//		{
//			if (MapData[My - 1][Mx] != 1) MoveDir = DIRECTION::UP;
//		}
//		if (dy < 0) //�ڕW��������艺��
//		{
//			if (MapData[My + 1][Mx] != 1) MoveDir = DIRECTION::DOWN;
//		}
//		//�ǂ�����ꍇ��X�����Ɉړ�����
//		if (MapData[My - 1][Mx] == 1 || MapData[My + 1][Mx] == 1)
//		{
//			if (dx > 0) //�ڕW��������荶��
//			{
//				if (MapData[My][Mx - 1] != 1) MoveDir = DIRECTION::LEFT;
//			}
//			if (dx < 0) //�ڕW���������E��
//			{
//				if (MapData[My][Mx + 1] != 1) MoveDir = DIRECTION::RIGHT;
//			}
//		}
//	}
//
//
//
//	{
//		if (MoveDir == DIRECTION::LEFT && Tx != g_enemy.x)
//		{
//			if (MapData[My][Lx / MAP_SIZE] != 1) g_enemy.x -= g_enemy.speed;
//
//		}
//		if (MoveDir == DIRECTION::RIGHT && Tx != g_enemy.x)
//		{
//			if (MapData[My][Rx / MAP_SIZE] != 1) g_enemy.x += g_enemy.speed;
//
//		}
//		if (MoveDir == DIRECTION::UP && Ty != g_enemy.y)
//		{
//			if (MapData[Uy / MAP_SIZE][Mx] != 1) g_enemy.y -= g_enemy.speed;
//
//		}
//		if (MoveDir == DIRECTION::DOWN && Ty != g_enemy.y)
//		{
//			if (MapData[Dy / MAP_SIZE][Mx] != 1) g_enemy.y += g_enemy.speed;
//
//		}
//	}
//
//	//�߂荞�܂��Ȃ�
//	int x1, x2, y1, y2;
//	x1 = (g_enemy.x - (g_enemy.w / 2));
//	x2 = (g_enemy.x + (g_enemy.w / 2) - 1);
//	y1 = (g_enemy.y - (g_enemy.h / 2) + 1);
//	y2 = (g_enemy.y + (g_enemy.h / 2) - 1);
//
//	if (MapData[My][Mx - 1] == 1)
//	{
//		if ((Mx - 1) * MAP_SIZE + MAP_SIZE > x1) g_enemy.x = (Mx - 1) * MAP_SIZE + MAP_SIZE + g_enemy.w / 2;
//	}
//	if (MapData[My][Mx + 1] == 1)
//	{
//		if ((Mx + 1) * MAP_SIZE < x2) g_enemy.x = (Mx + 1) * MAP_SIZE - g_enemy.w / 2;
//	}
//	if (MapData[My - 1][Mx] == 1)
//	{
//		if ((My - 1) * MAP_SIZE + MAP_SIZE > y1) g_enemy.y = (My - 1) * MAP_SIZE + MAP_SIZE + g_enemy.w / 2;
//	}
//	if (MapData[My + 1][Mx] == 1)
//	{
//		if ((My + 1) * MAP_SIZE < y2) g_enemy.y = (My + 1) * MAP_SIZE - g_enemy.w / 2;
//	}
//
//}
//
////�e�X�g
//void ENEMY_RED::MoveEnemy2(int MapData[MAP_HEIGHT][MAP_WIDTH])
//{
//	//�ړ��ɂ��摜�ω�
//	//MoveCount++;
//	ChangeMoveImages();
//
//	if (EnemyMode == MODE::STANDBY)
//	{
//		MoveEnemy(MapData);
//	}
//	else if (EnemyMode == MODE::TRACK || EnemyMode == MODE::PATROL)
//	{
//		MoveShortest(MapData, MoveTarget.x, MoveTarget.y);
//	}
//
//}
//
////�`��
//void ENEMY_RED::DrawEnemy()
//{
//	//�e�X�g�@�ڕW�ʒu
//	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 128);
//	DrawCircle(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + DRAW_POINT_Y, 8, 0xff00ff, TRUE);
//
//	//�e�X�g�@�ڕW�`�G��
//	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 200);
//	DrawLine(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + DRAW_POINT_Y, g_enemy.x + DRAW_POINT_X, g_enemy.y + DRAW_POINT_Y, 0x00ffff);
//	DrawLine(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + DRAW_POINT_Y, MoveTarget.x + DRAW_POINT_X, MoveTarget.y + (g_enemy.y - MoveTarget.y) + DRAW_POINT_Y, 0x00ffff);
//	DrawLine(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + (g_enemy.y - MoveTarget.y) + DRAW_POINT_Y, g_enemy.x + DRAW_POINT_X, g_enemy.y + DRAW_POINT_Y, 0x00ffff);
//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
//
//	if (g_enemy.flg == true)
//	{
//		//�V���v���`��
//		DrawRotaGraph(g_enemy.x + DRAW_POINT_X, g_enemy.y + DRAW_POINT_Y, 1.0, 0, enemyimage[g_enemy.img], TRUE);
//
//		//�V���v���`��i�`��_�͍���j
//		//DrawGraph(g_enemy.x, g_enemy.y, enemyimage[g_enemy.img], TRUE);
//
//		//
//		//DrawRotaGraph((g_enemy.x*20)+(g_enemy.w/2), (g_enemy.y * 20) + (g_enemy.h / 2), 1.0, 0, enemyimage[g_enemy.img], TRUE);
//	}
//
//	//�e�X�g�@
//	//DrawFormatString(0, 0, 0xffffff, "Move : %d", MoveDir);
//	//DrawFormatString(1000, 30, 0xffffff, "x : %d", g_enemy.x);
//	//DrawFormatString(1000, 70, 0xffffff, "y : %d", g_enemy.y);
//	//DrawFormatString(1000, 100, 0xffffff, "mapX : %d", g_enemy.x / MAP_SIZE);
//	//DrawFormatString(1000, 130, 0xffffff, "mapY : %d", g_enemy.y / MAP_SIZE);
//	//DrawFormatString(1000, 160, 0xffffff, "Direct : %s", DirectStr[MoveDir]);
//	//DrawFormatString(1000, 190, 0xffffff, "ModeCount : %d", mode_count / 60);
//	//DrawFormatString(1000, 220, 0xffffff, "Mode : %s", ModeStr[EnemyMode]);
//	//DrawFormatString(1000, 250, 0xffffff, "TargetX : %d", MoveTarget.x);
//	//DrawFormatString(1000, 280, 0xffffff, "TargetY : %d", MoveTarget.y);
//
//}
//
//
////�ړ��ڕW�Ƃ̈�v�@�߂�l�@0�Fx,y���W���Ɉ�vż�@ 1�Fx���W�݈̂�v  2�Fy���W�݈̂�v�@�@3:x,y���W���Ɉ�v 
//int ENEMY_RED::CheckTarget()
//{
//	if (MoveTarget.x == g_enemy.x && MoveTarget.y != g_enemy.y) return 1;       //x���W�݈̂�v
//	else if (MoveTarget.x != g_enemy.x && MoveTarget.y == g_enemy.y) return 2;  //y���W�݈̂�v
//	else if (MoveTarget.x == g_enemy.x && MoveTarget.y == g_enemy.y) return 3;  //x,y���W���Ɉ�v
//	else if (MoveTarget.x != g_enemy.x && MoveTarget.y != g_enemy.y) return 0;  //x,y���W���Ɉ�vż
//}
//
//
////�^�[�Q�b�g�ݒ�  ����:�v���C���[�̍��W
//void ENEMY_RED::TargetCtrl(int tpX, int tpY, int tpD)
//{
//	M_POINT Point = { 0,0 };
//
//	static int order = 0;
//
//	switch (EnemyMode)
//	{
//	case MODE::STANDBY:           //�o���O�@
//
//		if (sortie_flg == false)     //�o���s��
//		{
//			//�㉺�ɉ���
//			if (CheckTarget() == 3 && g_enemy.y == 285) MoveTarget.y = 345;      //����
//			else if (CheckTarget() == 3 && g_enemy.y == 345) MoveTarget.y = 285; //�㕔
//			else if (CheckTarget() == 0) MoveTarget = { 315,285 };               //�����ʒu
//			else if (CheckTarget() == 0) MoveTarget = { NestPoint[My_Color][0],NestPoint[My_Color][1] };               //�����ʒu
//		}
//		else if (sortie_flg == true) //�o����
//		{
//			MoveTarget = { 315,225 };  //���̓����� (������o��)
//			if (g_enemy.x == 315 && g_enemy.y == 225) EnemyMode = MODE::PATROL;  //�ړ�������A���񃂁[�h�ɐ؂�ւ�
//		}
//		break;
//
//	case MODE::PATROL:            //���񃂁[�h
//
//		////������W
//		//Point = { 19*MAP_SIZE * 1 + (MAP_SIZE / 2) ,MAP_SIZE * 1 + (MAP_SIZE / 2) };
//		//MoveTarget = Point;
//
//		//������W
//		Point = { PtrlPoint[0][order][0] ,PtrlPoint[0][order][1] };
//		MoveTarget = Point;
//
//
//		if (CheckTarget3() == 3)
//		{
//			order++;
//			if (order == 4) order = 0;
//		}
//		Point = { PtrlPoint[My_Color][order][0] ,PtrlPoint[My_Color][order][1] };
//
//
//		MoveTarget = Point;
//
//		//8�b�ŒǐՃ��[�h�ɐ؂�ւ�
//		if (++mode_count % 480 == 0)
//		{
//			mode_count = 0;
//			EnemyMode = MODE::TRACK;
//		}
//		break;
//
//	case MODE::TRACK:             //�ǐՃ��[�h
//
//		//���݂̐i�s���� 
//		Point = { tpX ,tpY };
//
//		Point = { tpX ,tpY };
//		if (tpD == DIRECTION::LEFT)  Point.x = tpX;// +(-4 * MAP_SIZE);
//		if (tpD == DIRECTION::RIGHT) Point.x = tpX;// +(4 * MAP_SIZE);
//		if (tpD == DIRECTION::UP)    Point.y = tpY;// +(-4 * MAP_SIZE);
//		if (tpD == DIRECTION::DOWN)  Point.y = tpY;// +(4 * MAP_SIZE);
//		MoveTarget.x = Point.x;
//		MoveTarget.y = Point.y;
//
//		//20�b�ŏ��񃂁[�h�ɐ؂�ւ�
//		if (++mode_count % 1200 == 0)
//		{
//			mode_count = 0;
//			EnemyMode = MODE::PATROL;
//		}
//		break;
//
//	case MODE::RANDOM:
//		Point.x = 1;
//		Point.y = 1;
//		if (g_enemy.x == MoveTarget.x && g_enemy.y == MoveTarget.y)
//		{
//			Point.x = GetRand(18) + 1;
//			Point.y = GetRand(20) + 1;
//		}
//
//		MoveTarget.x = (Point.x * MAP_SIZE) + DRAW_POINT_X;
//		MoveTarget.y = (Point.y * MAP_SIZE) + DRAW_POINT_Y;
//
//	default:
//		break;
//	}
//
//}
//
//
////�G�̋���(���[�h�ɂ���ĕω�  �o���O/����/�ǐ�)
//void ENEMY_RED::EnemyControl()
//{
//	switch (EnemyMode)
//	{
//		//�o���O
//	case MODE::STANDBY:
//		break;
//
//		//����
//	case MODE::PATROL:
//		break;
//
//		//�ǐ�
//	case MODE::TRACK:
//		break;
//
//	default:
//		break;
//	}
//}
//
////�o���O�̋���
//void ENEMY_RED::Move_StandBy()
//{
//
//}
//
////���񃂁[�h�̋���
//void ENEMY_RED::Move_Patrol()
//{
//
//}
//
////�ǐՃ��[�h�̋���
//void ENEMY_RED::Move_Track()
//{
//
//}

#include"DxLib.h"
#include"Enemy.h"
#include"Red.h"
#include "Info.h"
#include "Enemy_Red.h"
#include "A_star.h"

ENEMY_RED Red;

//�R���X�g���N�^  ENEMY_BASE�̃R���X�g���N�^�� "My_Color" ��ݒ�
ENEMY_RED::ENEMY_RED() : ENEMY_BASE(ENEMY_COLOR::RED)
{
}

//�摜�ǂݍ���
int ENEMY_RED::Loadimages()
{
	//�����ǂݍ���

	if ((LoadDivGraph("images/All_Red30.png", 16, 4, 4, 30, 30, enemyimage)) == -1) return -1;   //30 �@��޹�E�ڂ��܂�
}

//��������
void ENEMY_RED::InitEnemy()
{
	g_enemy.flg = true;
	//g_enemy.x = 10 * MAP_SIZE + (MAP_SIZE / 2); //���̏�
	//g_enemy.y = 7 * MAP_SIZE + (MAP_SIZE / 2); //���̏�

	g_enemy.x = 13 * MAP_SIZE + (MAP_SIZE / 2); //���̏�
	g_enemy.y = 10 * MAP_SIZE + (MAP_SIZE / 2); //���̏�

	g_enemy.w = E_WIDTH;
	g_enemy.h = E_HEIGHT;
	g_enemy.speed = 3;//p_speed[0];
	//g_enemy.speed = GetRand(4) + 1;
	g_enemy.img = 0;

	//�ړ��Ȃ�
	MoveDir = (int)DIRECTION::LEFT;

	//�ړ��ڕW������
	MoveTarget = { 0,0 };

	//���[�h�@�Ԃ͏��񂩂�
	EnemyMode = MODE::PATROL;
	//���[�h�`�F���W�p�J�E���^�[
	mode_count = 0;
	//�C�W�P�i�V
	ijike_flg = false;

	if (sortie_flg == true)sortie_flg = false;
}

//�ړ�
void ENEMY_RED::MoveEnemy(int MapData[MAP_HEIGHT][MAP_WIDTH])
{
	//�ړ��ɂ��摜�ω�
	ChangeMoveImages();

	//�^�[�Q�b�g�Ƃ̋������k�߂�
	//�ǂɂԂ���ƕ����]��

	int Tx = MoveTarget.x;    //�ǐՑΏ�X�@�@�@�ǐՃ��[�h�̂�
	int Ty = MoveTarget.y;    //   �V�@ Y

	int Mx = g_enemy.x / MAP_SIZE;
	int My = g_enemy.y / MAP_SIZE;

	int Lx = (g_enemy.x - (g_enemy.w / 2));
	int Rx = (g_enemy.x + (g_enemy.w / 2));
	int Uy = (g_enemy.y - (g_enemy.h / 2));
	int Dy = (g_enemy.y + (g_enemy.h / 2));


	//�G�̍��W�ƖڕW���W�̍��idifference�j
	int dx = g_enemy.x - MoveTarget.x;
	int dy = g_enemy.y - MoveTarget.y;

	//a_star.main();
	//g_enemy_Red.EnemyController();

	//if (a_star.data[g_enemy_Red.EYC][g_enemy_Red.EXC - 1].status == 1) {
	//	//MoveDir = DIRECTION::LEFT;
	//	g_enemy_Red.VectorFlg = LEFT;
	//}

	//if (a_star.data[g_enemy_Red.EYC][g_enemy_Red.EXC + 1].status == 1) {
	//	//MoveDir = DIRECTION::RIGHT;
	//	g_enemy_Red.VectorFlg = RIGHT;
	//}
	//	if (a_star.data[g_enemy_Red.EYC - 1][g_enemy_Red.EXC].status == 1) {
	//		//MoveDir = DIRECTION::UP;
	//		g_enemy_Red.VectorFlg = UP;
	//	}
	//	if (a_star.data[g_enemy_Red.EYC + 1][g_enemy_Red.EXC].status == 1) {
	//		//MoveDir = DIRECTION::DOWN;
	//		g_enemy_Red.VectorFlg = DOWN;
	//	}

		/*if (g_enemy.x <= 435 && g_enemy.y == 405 && g_enemy_Red.VectorFlg == LEFT) {
			g_enemy.x = 700;
		}
		if (g_enemy.x >= 700 && g_enemy.y == 405 && g_enemy_Red.VectorFlg == RIGHT) {
			g_enemy.x = 435;
		}*/

	//x,y�����̍����r�A�傫������Ă������D��  ��Βl��

	//x���������킹��
	if (abs(dx) > abs(dy))
	{
		if (dx > 0) //�ڕW��������荶��
		{
			if (MapData[My][Mx - 1] != 1) MoveDir = DIRECTION::LEFT;
		}
		if (dx < 0) //�ڕW���������E��
		{
			if (MapData[My][Mx + 1] != 1) MoveDir = DIRECTION::RIGHT;
		}
		//�ǂ�����ꍇ��Y�����Ɉړ�����
		if (MapData[My][Mx - 1] == 1 || MapData[My][Mx + 1] == 1)
		{
			if (dy > 0) //�ڕW���������㑤
			{
				if (MapData[My - 1][Mx] != 1) MoveDir = DIRECTION::UP;
			}

			if (dy < 0) //�ڕW��������艺��
			{
				if (MapData[My + 1][Mx] != 1) MoveDir = DIRECTION::DOWN;
			}
		}
	}
	else
	{
		if (dy > 0) //�ڕW���������㑤
		{
			if (MapData[My - 1][Mx] != 1) MoveDir = DIRECTION::UP;
		}
		if (dy < 0) //�ڕW��������艺��
		{
			if (MapData[My + 1][Mx] != 1) MoveDir = DIRECTION::DOWN;
		}
		//�ǂ�����ꍇ��X�����Ɉړ�����
		if (MapData[My - 1][Mx] == 1 || MapData[My + 1][Mx] == 1)
		{
			if (dx > 0) //�ڕW��������荶��
			{
				if (MapData[My][Mx - 1] != 1) MoveDir = DIRECTION::LEFT;
			}
			if (dx < 0) //�ڕW���������E��
			{
				if (MapData[My][Mx + 1] != 1) MoveDir = DIRECTION::RIGHT;
			}
		}
	}



	{
		if (MoveDir == DIRECTION::LEFT && Tx != g_enemy.x)
		{
			if (MapData[My][Lx / MAP_SIZE] != 1) g_enemy.x -= g_enemy.speed;

		}
		if (MoveDir == DIRECTION::RIGHT && Tx != g_enemy.x)
		{
			if (MapData[My][Rx / MAP_SIZE] != 1) g_enemy.x += g_enemy.speed;

		}
		if (MoveDir == DIRECTION::UP && Ty != g_enemy.y)
		{
			if (MapData[Uy / MAP_SIZE][Mx] != 1) g_enemy.y -= g_enemy.speed;

		}
		if (MoveDir == DIRECTION::DOWN && Ty != g_enemy.y)
		{
			if (MapData[Dy / MAP_SIZE][Mx] != 1) g_enemy.y += g_enemy.speed;

		}
	}

	//�߂荞�܂��Ȃ�
	int x1, x2, y1, y2;
	x1 = (g_enemy.x - (g_enemy.w / 2));
	x2 = (g_enemy.x + (g_enemy.w / 2) - 1);
	y1 = (g_enemy.y - (g_enemy.h / 2) + 1);
	y2 = (g_enemy.y + (g_enemy.h / 2) - 1);

	if (MapData[My][Mx - 1] == 1)
	{
		if ((Mx - 1) * MAP_SIZE + MAP_SIZE > x1) g_enemy.x = (Mx - 1) * MAP_SIZE + MAP_SIZE + g_enemy.w / 2;
	}
	if (MapData[My][Mx + 1] == 1)
	{
		if ((Mx + 1) * MAP_SIZE < x2) g_enemy.x = (Mx + 1) * MAP_SIZE - g_enemy.w / 2;
	}
	if (MapData[My - 1][Mx] == 1)
	{
		if ((My - 1) * MAP_SIZE + MAP_SIZE > y1) g_enemy.y = (My - 1) * MAP_SIZE + MAP_SIZE + g_enemy.w / 2;
	}
	if (MapData[My + 1][Mx] == 1)
	{
		if ((My + 1) * MAP_SIZE < y2) g_enemy.y = (My + 1) * MAP_SIZE - g_enemy.w / 2;
	}


}

//�e�X�g
void ENEMY_RED::MoveEnemy2(int MapData[MAP_HEIGHT][MAP_WIDTH])
{
	//�ړ��ɂ��摜�ω�
	ChangeMoveImages();

	if (EnemyMode == MODE::STANDBY || EnemyMode == MODE::R_EYE)
	{
		MoveEnemy(MapData);
	}
	else if (EnemyMode == MODE::TRACK || EnemyMode == MODE::PATROL || EnemyMode == MODE::EYE || EnemyMode == MODE::IJIKE)
	{
		if (EnemyMode == MODE::TRACK) {
			EnemyController();
			//oldmode = EnemyMode;
		}
		else if (EnemyMode == MODE::EYE) {
			MoveShortest2(MapData, MoveTarget.x, MoveTarget.y);
		}
		else {
			MoveShortest(MapData, MoveTarget.x, MoveTarget.y);
		}
	}

}

//�`��
void ENEMY_RED::DrawEnemy()
{
	//�e�X�g�@�ڕW�ʒu
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 128);
	DrawCircle(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + DRAW_POINT_Y, 8, 0xff00ff, TRUE);

	//�e�X�g�@�ڕW�`�G��
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 200);
	DrawLine(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + DRAW_POINT_Y, g_enemy.x + DRAW_POINT_X, g_enemy.y + DRAW_POINT_Y, 0x00ffff);
	DrawLine(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + DRAW_POINT_Y, MoveTarget.x + DRAW_POINT_X, MoveTarget.y + (g_enemy.y - MoveTarget.y) + DRAW_POINT_Y, 0x00ffff);
	DrawLine(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + (g_enemy.y - MoveTarget.y) + DRAW_POINT_Y, g_enemy.x + DRAW_POINT_X, g_enemy.y + DRAW_POINT_Y, 0x00ffff);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (g_enemy.flg == true)
	{
		//�V���v���`��
		DrawRotaGraph(g_enemy.x + DRAW_POINT_X, g_enemy.y + DRAW_POINT_Y, 1.0, 0, enemyimage[g_enemy.img], TRUE);
	}
}


//�ړ��ڕW�Ƃ̈�v�@�߂�l�@0�Fx,y���W���Ɉ�vż�@ 1�Fx���W�݈̂�v  2�Fy���W�݈̂�v�@�@3:x,y���W���Ɉ�v 
int ENEMY_RED::CheckTarget()
{
	if (MoveTarget.x == g_enemy.x && MoveTarget.y != g_enemy.y) return 1;       //x���W�݈̂�v
	else if (MoveTarget.x != g_enemy.x && MoveTarget.y == g_enemy.y) return 2;  //y���W�݈̂�v
	else if (MoveTarget.x == g_enemy.x && MoveTarget.y == g_enemy.y) return 3;  //x,y���W���Ɉ�v
	else if (MoveTarget.x != g_enemy.x && MoveTarget.y != g_enemy.y) return 0;  //x,y���W���Ɉ�vż
}

//�^�[�Q�b�g�ݒ�  ����:�v���C���[�̍��W
void ENEMY_RED::TargetCtrl(int tpX, int tpY, int tpD)
{
	M_POINT Point = { 0,0 };

	//�C�W�P�E�ڏ�Ԃ�ݒ�
	ModeChanger();

	static int order = 0;
	

	switch (EnemyMode)
	{
	case MODE::STANDBY:           //�o���O�@

		if (sortie_flg == false)     //�o���s��
		{
			//�㉺�ɉ���
			if (CheckTarget() == 3 && g_enemy.y == 285) MoveTarget.y = 345;      //����
			else if (CheckTarget() == 3 && g_enemy.y == 345) MoveTarget.y = 285; //�㕔
			else if (CheckTarget() == 0) MoveTarget = { 315,285 };               //�����ʒu
			else if (CheckTarget() == 0) MoveTarget = { NestPoint[My_Color][0],NestPoint[My_Color][1] };               //�����ʒu
		}
		else if (sortie_flg == true) //�o����
		{
			MoveTarget = { 315,225 };  //���̓����� (������o��)
			if (g_enemy.x == 315 && g_enemy.y == 225) EnemyMode = MODE::PATROL;  //�ړ�������A���񃂁[�h�ɐ؂�ւ�
		}
		break;

	case MODE::PATROL:            //���񃂁[�h

		////������W
		//Point = { 19*MAP_SIZE * 1 + (MAP_SIZE / 2) ,MAP_SIZE * 1 + (MAP_SIZE / 2) };
		//MoveTarget = Point;

		//������W
		Point = { PtrlPoint[0][order][0] ,PtrlPoint[0][order][1] };
		MoveTarget = Point;

		if (CheckTarget3() == 3)
		{
			order++;
			if (order == 4) order = 0;
		}
		Point = { PtrlPoint[My_Color][order][0] ,PtrlPoint[My_Color][order][1] };

		MoveTarget = Point;

		//���݂̃��[�h��ێ�
		old_mode = EnemyMode;

		//8�b�ŒǐՃ��[�h�ɐ؂�ւ�
		if (++mode_count % 480 == 0)
		{
			mode_count = 0;
			EnemyMode = MODE::TRACK;
		}
		break;

	case MODE::TRACK:             //�ǐՃ��[�h

		//���݂̐i�s���� +3�}�X
		Point = { tpX ,tpY };
		if (tpD == DIRECTION::LEFT)  Point.x = tpX;// +(-4 * MAP_SIZE);
		if (tpD == DIRECTION::RIGHT) Point.x = tpX;// +(4 * MAP_SIZE);
		if (tpD == DIRECTION::UP)    Point.y = tpY;// +(-4 * MAP_SIZE);
		if (tpD == DIRECTION::DOWN)  Point.y = tpY;// +(4 * MAP_SIZE);
		MoveTarget.x = Point.x;
		MoveTarget.y = Point.y;

		//���݂̃��[�h��ێ�
		old_mode = EnemyMode;

		//20�b�ŏ��񃂁[�h�ɐ؂�ւ�
		if (++mode_count % 1200 == 0)
		{
			mode_count = 0;
			EnemyMode = MODE::PATROL;
		}
		break;

	case MODE::IJIKE:       //�C�W�P��

		Move_Ijike();
		break;

	case MODE::EYE:               //�ځi���ɖ߂�j

		Move_Eye();
		break;

	case MODE::R_EYE:        //�C�W�P�ȑO�̃��[�h�ɖ߂�

		Move_R_Eye();
		break;

	default:
		break;
	}

}

//�G�̋���(���[�h�ɂ���ĕω�  �o���O/����/�ǐ�)
void ENEMY_RED::EnemyControl()
{
	switch (EnemyMode)
	{
		//�o���O
	case MODE::STANDBY:
		break;

		//����
	case MODE::PATROL:
		break;

		//�ǐ�
	case MODE::TRACK:
		break;

	default:
		break;
	}
}

//�o���O�̋���
void ENEMY_RED::Move_StandBy()
{

}

//���񃂁[�h�̋���
void ENEMY_RED::Move_Patrol()
{

}

//�ǐՃ��[�h�̋���
void ENEMY_RED::Move_Track()
{

}
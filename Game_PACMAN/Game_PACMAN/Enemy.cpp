#include"DxLib.h"
#include"Enemy.h"
#include"Sound.h"

//�ǂ������@���E�_  ���`���ł�DRAW_POINT_X(Y)�����Z���ꂽ���W �@"�s���N"�̖ڕW���W�̓X�e�[�W�O�ɂȂ邱�Ƃ�����
const int L_END = MAP_SIZE;
const int R_END = MAP_SIZE * (MAP_WIDTH - 1);
const int U_END = MAP_SIZE;
const int D_END = MAP_SIZE * (MAP_HEIGHT - 1);

//�ړ��ɂ��摜�`�F���W �`2���̉摜�����݂Ɂ`
void ENEMY_BASE::ChangeMoveImages()
{
	//�摜�z��enemyimage
	//������ 0,1�@�E���� 2,3�@����� 4,5�@������ 6,7

	int std = 0;  //��ƂȂ�摜No �@std �� std+1 �����݂ɐ؂�ւ���

	switch (MoveDir)
	{
	case DIRECTION::LEFT:

		if (g_enemy.img != 0 && g_enemy.img != 1) g_enemy.img = 0; //�������摜�łȂ���΁A�������摜�Ƀ`�F���W
		std = 0; //����Z�b�g
		break;

	case DIRECTION::RIGHT:

		if (g_enemy.img != 2 && g_enemy.img != 3) g_enemy.img = 2; //�E�����摜�łȂ���΁A�E�����摜�Ƀ`�F���W
		std = 2; //����Z�b�g
		break;

	case DIRECTION::UP:

		if (g_enemy.img != 4 && g_enemy.img != 5) g_enemy.img = 4; //������摜�łȂ���΁A������摜�Ƀ`�F���W
		std = 4; //����Z�b�g
		break;

	case DIRECTION::DOWN:

		if (g_enemy.img != 6 && g_enemy.img != 7) g_enemy.img = 6; //�������摜�łȂ���΁A�������摜�Ƀ`�F���W
		std = 6; //����Z�b�g
		break;

	case DIRECTION::NONE:

		std = 0;
	default:
		break;
	}

	//5�t���[�����ɉ摜�؂�ւ�
	if (MoveCount % 5 == 0)
	{
		if (g_enemy.img == std)
		{
			g_enemy.img = std + 1;  //�摜n0�̎�,�摜n1��
			MoveCount = 0;
		}
		else if (g_enemy.img = std + 1)
		{
			g_enemy.img = std;      //�摜n1�̎�,�摜n0��
			MoveCount = 0;
		}
	}
}


//�^�[�Q�b�g�܂ł̍ŒZ�o�H��T��
//             �^�[�Q�b�g�̈ʒu��"��"�Ƃ��A�����ɂꂎ�����Z
//             ����tx,ty�̓}�b�v����W  �Ăяo����"/MAP_SIZE"
void ENEMY_BASE::search(int tx, int ty, int b)
{
	int n = b;
	n += 1;

	//��
	if (my_mapdata[ty][tx - 1] == 0 || my_mapdata[ty][tx - 1] >= n)
	{
		my_mapdata[ty][tx - 1] = n;
		search(tx - 1, ty, n);
	}
	//�E
	if (my_mapdata[ty][tx + 1] == 0 || my_mapdata[ty][tx + 1] >= n)
	{
		my_mapdata[ty][tx + 1] = n;
		search(tx + 1, ty, n);
	}
	//��
	if (my_mapdata[ty - 1][tx] == 0 || my_mapdata[ty - 1][tx] >= n)
	{
		my_mapdata[ty - 1][tx] = n;
		search(tx, ty - 1, n);
	}
	//��
	if (my_mapdata[ty + 1][tx] == 0 || my_mapdata[ty + 1][tx] >= n)
	{
		my_mapdata[ty + 1][tx] = n;
		search(tx, ty + 1, n);
	}

	return;
}

//�ŒZ�o�H��T������
void ENEMY_BASE::moveDataSet(int MapData[MAP_HEIGHT][MAP_WIDTH], int targetX, int targetY)
{
	//�o�H�T���pmap�̏�����
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if (MapData[i][j] != 1) my_mapdata[i][j] = 0;
			else my_mapdata[i][j] = 1;
		}
	}

	//�^�[�Q�b�g���W���X�e�[�W�O�̏ꍇ�A�X�e�[�W���ɖ߂�
	if (targetX < L_END) targetX = L_END + 1;
	if (targetX > R_END) targetX = R_END - 1;
	if (targetY < U_END) targetY = U_END + 1;
	if (targetY > D_END) targetY = D_END - 1;

	//�}�b�v��̃^�[�Q�b�g�̈ʒu�ɖڈ�(10)���Z�b�g
	my_mapdata[targetY / MAP_SIZE][targetX / MAP_SIZE] = 10;

	//"10"����ɁA�ŒZ�o�H��T��
	search((targetX / MAP_SIZE), (targetY / MAP_SIZE), 10);
}

//�^�[�Q�b�g�̈ʒu�ɍŒZ�o�H�ňړ�����
void ENEMY_BASE::MoveShortest(int MapData[MAP_HEIGHT][MAP_WIDTH], int targetX, int targetY)
{
	//�o�H�T���pmap�̏������E�^�[�Q�b�g�̈ʒu��ݒ�
	moveDataSet(MapData, targetX, targetY);

	//�G��(map���)���W
	int Mx = g_enemy.x / MAP_SIZE;
	int My = g_enemy.y / MAP_SIZE;

	//��
	if (MapData[My][Mx - 1] != 1 && my_mapdata[My][Mx - 1] < my_mapdata[My][Mx])
	{
		MoveDir = DIRECTION::LEFT;
		g_enemy.x -= g_enemy.speed;
		sound.PlayMoveSounds();
	}
	//�E
	else if (MapData[My][Mx + 1] != 1 && my_mapdata[My][Mx + 1] < my_mapdata[My][Mx])
	{
		MoveDir = DIRECTION::RIGHT;
		g_enemy.x += g_enemy.speed;
		sound.PlayMoveSounds();
	}
	//��
	else if (MapData[My - 1][Mx] != 1 && my_mapdata[My - 1][Mx] < my_mapdata[My][Mx])
	{
		MoveDir = DIRECTION::UP;
		g_enemy.y -= g_enemy.speed;
		sound.PlayMoveSounds();
	}
	//��
	else if (MapData[My + 1][Mx] != 1 && my_mapdata[My + 1][Mx] < my_mapdata[My][Mx])
	{
		MoveDir = DIRECTION::DOWN;
		g_enemy.y += g_enemy.speed;
		sound.PlayMoveSounds();
	}

	//�߂荞�܂��Ȃ�
	int x1, x2, y1, y2;
	x1 = (g_enemy.x - (g_enemy.w / 2) + 1);
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

//���񃂁[�h�p
int ENEMY_BASE::CheckTarget2()
{
	int ex1 = g_enemy.x - (g_enemy.w / 2); //��
	int ex2 = g_enemy.x + (g_enemy.w / 2); //�E
	int ey1 = g_enemy.y - (g_enemy.h / 2); //��
	int ey2 = g_enemy.y + (g_enemy.h / 2); //��

	int tx1 = MoveTarget.x - (MAP_SIZE / 2);
	int tx2 = MoveTarget.x + (MAP_SIZE / 2);
	int ty1 = MoveTarget.y - (MAP_SIZE / 2);
	int ty2 = MoveTarget.y + (MAP_SIZE / 2);

	//if(MoveTarget.x-15<g_enemy.x&&)
	if (ex1 < tx2 && tx1 < ex2 && ey1 < ty2 && ty1 < ey2)
	{
		return 3;
	}
	else return 0;
}
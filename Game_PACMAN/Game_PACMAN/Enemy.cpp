#include"DxLib.h"
#include"Enemy.h"

//�e�X�g�o�͗p
char ColorStr[][7] = { "RED","PINK","BLUE","ORANGE","CLEAR" };
char DirectStr[][6] = { "LEFT","RIGHT","UP","DOWN" ,"NONE" };
char ModeStr[][8] = { "STANDBY","PATROL","TRACK" };

//���̒��̈ʒu�@ �����ʒu�ł͂Ȃ��i�����ʒu�̓A�J�������̏�j
int NestPoint[][2] = {
	{10 * MAP_SIZE + (MAP_SIZE / 2),10 * MAP_SIZE + (MAP_SIZE / 2)},  //�A�J
	{10 * MAP_SIZE + (MAP_SIZE / 2),10 * MAP_SIZE + (MAP_SIZE / 2)},  //�s���N
	{8 * MAP_SIZE + (MAP_SIZE / 2),10 * MAP_SIZE + (MAP_SIZE / 2)},   //�~�Y
	{12 * MAP_SIZE + (MAP_SIZE / 2),10 * MAP_SIZE + (MAP_SIZE / 2)}   //�I�����W
};

//�ǂ������@���E�_  ���`���ł�DRAW_POINT_X(Y)�����Z���ꂽ���W �@"�s���N"�̖ڕW���W�̓X�e�[�W�O�ɂȂ邱�Ƃ�����
const int L_END = MAP_SIZE;
const int R_END = MAP_SIZE * (MAP_WIDTH - 1);
const int U_END = MAP_SIZE;
const int D_END = MAP_SIZE * (MAP_HEIGHT - 1);


//�S�ẴI�u�W�F�N�g�̃A�h���X��ێ��@�ÓI�����o�ϐ��@����
ENEMY_BASE* ENEMY_BASE::All_Enemy[ENEMY_MAX];

//�R���X�g���N�^
ENEMY_BASE::ENEMY_BASE(int color) : My_Color(color)
{
	//�z��̒�ʒu�Ɏ���̃A�h���X����
	//�A�J0  �s���N1  �A�I2  �I�����W3
	All_Enemy[My_Color] = this;
}

//�f�X�g���N�^
ENEMY_BASE::~ENEMY_BASE()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		//�������g������΍폜
		if (All_Enemy[i] == this) All_Enemy[i] = nullptr;
		break;
	}
}

//�o�����Ǘ�
void ENEMY_BASE::SoltieControl(int num)
{

}

//���ׂĂ�Enemy��������
void ENEMY_BASE::AllEnemyInit()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (All_Enemy[i] != nullptr)
		{
			All_Enemy[i]->InitEnemy();
		}
	}
	return;
}

//�ړ��ɂ��摜�`�F���W �`2���̉摜�����݂Ɂ`
void ENEMY_BASE::ChangeMoveImages()
{
	//�摜�z��enemyimage
	//������ 0,1�@�E���� 2,3�@����� 4,5�@������ 6,7�@�C�W�P�� 8,9�@�C�W�P�� 10,11�@�� 12�`15

	int std = 0;  //��ƂȂ�摜No �@std �� std+1 �����݂ɐ؂�ւ���
	MoveCount++;  //�؂�ւ��p�Ƀt���[�����J�E���g

	//"��"�̏�Ԏ��ɂ̓A�j���[�V�������Ȃ�
	if (EnemyMode != MODE::EYE)
	{
		//��޹��ԂłȂ�
		if (ijike_flg != true)
		{
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
		}
		else
		{
			//�C�W�P��Ԃ̎�
			if (g_enemy.img != 8 && g_enemy.img != 9) g_enemy.img = 8; //�C�W�P�摜�łȂ���΁A�C�W�P�摜�Ƀ`�F���W
			std = 8;       //����Z�b�g

			IjikeCount++;  //�C�W�P���Ԃ��J�E���g

			//6�b�ŃC�W�P�I��
			if (IjikeCount % 360 == 0)
			{
				ijike_flg = false;
				IjikeCount = 0;
			}
		}

		//5�t���[�����ɉ摜�؂�ւ�
		if (MoveCount % 5 == 0)
		{
			if (g_enemy.img == std)
			{
				g_enemy.img = std + 1;  //�摜0�̎�,�摜1��
				MoveCount = 0;
			}
			else if (g_enemy.img = std + 1)
			{
				g_enemy.img = std;      //�摜1�̎�,�摜2��
				MoveCount = 0;
			}
		}
	}
	else   //�ڂ̏��
	{
		switch (MoveDir)
		{
		case DIRECTION::LEFT:
			if (g_enemy.img != 12) g_enemy.img = 12; //�������摜(��)�łȂ���΁A�������摜(��)�Ƀ`�F���W
			break;

		case DIRECTION::RIGHT:
			if (g_enemy.img != 13) g_enemy.img = 13; //�E�����摜(��)�łȂ���΁A�E�����摜(��)�Ƀ`�F���W
			break;

		case DIRECTION::UP:
			if (g_enemy.img != 14) g_enemy.img = 14; //������摜(��)�łȂ���΁A������摜(��)�Ƀ`�F���W
			break;

		case DIRECTION::DOWN:
			if (g_enemy.img != 15) g_enemy.img = 15; //�������摜(��)�łȂ���΁A�������摜(��)�Ƀ`�F���W
			break;

		case DIRECTION::NONE:
			break;

		default:
			break;
		}
	}
}


//�^�[�Q�b�g�܂ł̍ŒZ�o�H��T��
//             �^�[�Q�b�g�̈ʒu��"��"�Ƃ��A�����ɂꂎ�����Z
//             ����tx,ty�̓}�b�v����W  �Ăяo����"/MAP_SIZE"���K�v 
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

	////�^�[�Q�b�g���W���X�e�[�W�O�̏ꍇ�A�X�e�[�W���ɖ߂�
	//if (targetX < L_END) targetX = L_END + 1;
	//if (targetX > R_END) targetX = R_END - 1;
	//if (targetY < U_END) targetY = U_END + 1;
	//if (targetY > D_END) targetY = D_END - 1;

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
	}
	//�E
	else if (MapData[My][Mx + 1] != 1 && my_mapdata[My][Mx + 1] < my_mapdata[My][Mx])
	{
		MoveDir = DIRECTION::RIGHT;
		g_enemy.x += g_enemy.speed;
	}
	//��
	else if (MapData[My - 1][Mx] != 1 && my_mapdata[My - 1][Mx] < my_mapdata[My][Mx])
	{
		MoveDir = DIRECTION::UP;
		g_enemy.y -= g_enemy.speed;
	}
	//��
	else if (MapData[My + 1][Mx] != 1 && my_mapdata[My + 1][Mx] < my_mapdata[My][Mx])
	{
		MoveDir = DIRECTION::DOWN;
		g_enemy.y += g_enemy.speed;
	}

	//�߂荞�܂��Ȃ��@�@�v����
	int x1, x2, y1, y2;
	x1 = ((g_enemy.x - (g_enemy.w / 2)) + 2);
	x2 = ((g_enemy.x + (g_enemy.w / 2)) - 2);
	y1 = ((g_enemy.y - (g_enemy.h / 2)) + 2);
	y2 = ((g_enemy.y + (g_enemy.h / 2)) - 2);

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

//�ڕW�}�X�Ƃ̓����蔻��
int ENEMY_BASE::CheckTarget3()
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


int cols[] = { 0xff0000, 0xe9a1d0,0x67a8dd,0xfd7e00 };
//�e�X�g�p�@�G�S�F�̏���\��
void ENEMY_BASE::DrawAllInfo()
{
	int x = 100;
	int y = 0;
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (All_Enemy[i] != nullptr)
		{
			SetFontSize(18);

			if (i >= 2)x = 1000;
			if (i == 1 || i == 3) y = 360;
			else y = 0;

			DrawFormatString(x, y + 20, cols[i], "Color : %s", ColorStr[All_Enemy[i]->My_Color]);
			DrawFormatString(x, y + 40, 0xffffff, "Move : %d", All_Enemy[i]->MoveDir);
			DrawFormatString(x, y + 60, 0xffffff, "x : %d", All_Enemy[i]->g_enemy.x);
			DrawFormatString(x, y + 80, 0xffffff, "y : %d", All_Enemy[i]->g_enemy.y);
			DrawFormatString(x, y + 100, 0xffffff, "mapX : %d", All_Enemy[i]->g_enemy.x / MAP_SIZE);
			DrawFormatString(x, y + 120, 0xffffff, "mapY : %d", All_Enemy[i]->g_enemy.y / MAP_SIZE);
			DrawFormatString(x, y + 140, 0xffffff, "Direct : %s", DirectStr[All_Enemy[i]->MoveDir]);
			DrawFormatString(x, y + 160, 0xffffff, "ModeCount : %d", All_Enemy[i]->mode_count / 60);
			DrawFormatString(x, y + 180, 0xffffff, "Mode : %s", ModeStr[All_Enemy[i]->EnemyMode]);
			DrawFormatString(x, y + 200, 0xffffff, "TargetX : %d", All_Enemy[i]->MoveTarget.x);
			DrawFormatString(x, y + 220, 0xffffff, "TargetY : %d", All_Enemy[i]->MoveTarget.y);
			DrawFormatString(x, y + 240, 0xffffff, "TarMapX : %d", All_Enemy[i]->MoveTarget.x / MAP_SIZE);
			DrawFormatString(x, y + 260, 0xffffff, "TarMapY : %d", All_Enemy[i]->MoveTarget.y / MAP_SIZE);
			DrawFormatString(x, y + 280, 0xffffff, "Speed : %d", All_Enemy[i]->g_enemy.speed);
		}
	}

}

//���񃂁[�h�p���W
const int ENEMY_BASE::PtrlPoint[4][4][2] =
{
	//�A�J
	{
		{19 * MAP_SIZE + (MAP_SIZE / 2)+90,MAP_SIZE + (MAP_SIZE / 2) + 90},
		{16 * MAP_SIZE + (MAP_SIZE / 2) + 90,MAP_SIZE + (MAP_SIZE / 2) + 90},
		{16 * MAP_SIZE + (MAP_SIZE / 2) + 90,5 * MAP_SIZE + (MAP_SIZE / 2) + 90},
		{19 * MAP_SIZE + (MAP_SIZE / 2) + 90,5 * MAP_SIZE + (MAP_SIZE / 2) + 90},
	},
	//�s���N
	{
		{MAP_SIZE + (MAP_SIZE / 2) + 90,MAP_SIZE + (MAP_SIZE / 2) + 90},
		{4 * MAP_SIZE + (MAP_SIZE / 2) + 90,MAP_SIZE + (MAP_SIZE / 2) + 90},
		{4 * MAP_SIZE + (MAP_SIZE / 2) + 90,5 * MAP_SIZE + (MAP_SIZE / 2) + 90},
		{MAP_SIZE + (MAP_SIZE / 2) + 90,5 * MAP_SIZE + (MAP_SIZE / 2) + 90},
	},
	//�A�I
	{
		{19 * MAP_SIZE + (MAP_SIZE / 2),21 * MAP_SIZE + (MAP_SIZE / 2)},
		{11 * MAP_SIZE + (MAP_SIZE / 2),21 * MAP_SIZE + (MAP_SIZE / 2)},
		{15 * MAP_SIZE + (MAP_SIZE / 2),17 * MAP_SIZE + (MAP_SIZE / 2)},
		{19 * MAP_SIZE + (MAP_SIZE / 2),19 * MAP_SIZE + (MAP_SIZE / 2)},
	},
	//�I�����W
	{
		{MAP_SIZE + (MAP_SIZE / 2),21 * MAP_SIZE + (MAP_SIZE / 2)},
		{9 * MAP_SIZE + (MAP_SIZE / 2),21 * MAP_SIZE + (MAP_SIZE / 2)},
		{5 * MAP_SIZE + (MAP_SIZE / 2),17 * MAP_SIZE + (MAP_SIZE / 2)},
		{MAP_SIZE + (MAP_SIZE / 2),19 * MAP_SIZE + (MAP_SIZE / 2)},
	},
};
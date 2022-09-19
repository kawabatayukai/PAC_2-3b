#include"DxLib.h"
#include"Info.h"

#include"Stage.h"
#include "display.h"

DISPLAY Disp;

//�摜�ǂݍ���
int DISPLAY::LoadImages()
{
	if ((CircleImage = LoadGraph("images/02_2.png")) == -1) return -1;
	if ((PlayImage = LoadGraph("images/PLAYER.png")) == -1) return -1;
	if ((StartImage = LoadGraph("images/READY.png")) == -1) return -1;
	if ((OverImage = LoadGraph("images/GAMEOVER.png")) == -1) return -1;
}

//�����ǂݍ���
int DISPLAY::LoadSounds()
{
	if ((StartBGM = LoadSoundMem("sounds/Start.wav")) == -1) return -1;
}

//��������
void DISPLAY::DispInit(int ClearCnt)
{
	counter = 0;

	SetDrawFruit(ClearCnt);
}

//�Q�[���X�^�[�g��
void DISPLAY::DrawStartDisp(GAME_STATE* state, ENEMY_BASE* enemy)
{
	counter++;    //�t���[�����J�E���g

	//���񎞂̂�  ����5�b�Ȃ�2.5�b��  �@�@����4�b�Ȃ�2�b��
	if (clearcount == 0)
	{
		//BGM�Đ�
		PlaySoundMem(StartBGM, DX_PLAYTYPE_BACK, FALSE);

		if (counter < 120) //  150        ����5�b�Ȃ�2.5�b��  �@�@����4�b�Ȃ�2�b��
		{
			////"PLAYER"�\��
			//DrawGraph(DRAW_POINT_X + 180, DRAW_POINT_Y + 210, PlayImage, TRUE);

			//"PLAYER"�\��
			DrawGraph(DRAW_POINT_X + 270, DRAW_POINT_Y + 300, PlayImage, TRUE);
		}
	}

	////"READY!"�\��
	//DrawGraph(DRAW_POINT_X + 180, DRAW_POINT_Y + 390, StartImage, TRUE);

	//"READY!"�\��
	DrawGraph(DRAW_POINT_X + 270, DRAW_POINT_Y + 480, StartImage, TRUE);

	//2.5�b�o�ߌ�A�G�ƃv���C���[��`��@�@����5�b�Ȃ�2.5�b��  �@�@����4�b�Ȃ�2�b��
	if (counter >= 120)  //150
	{
		//�S�G��`��
		enemy->DrawAllEnemy();

		////�v���C���[��`��@�ړ��ƕ`���ʂɂ�����
		//player->DrawPlayer();

		//�v���C���[�X�^�[�g�ʒu��"��"��`��
		DrawGraph(DRAW_POINT_X + 390, DRAW_POINT_Y + 600, CircleImage, TRUE);
	}

	//5�b�o�ߌ�A���C���ց@�@����5�b�Ȃ�5�b��  �@�@����4�b�Ȃ�4�b��
	if (counter >= 240)  //300
	{
		*state = GAME_STATE::GAME_MAIN;

		counter = 0;
		if (clearcount == 0) clearcount++;   //���񎞂̂�
	}
}

//�Q�[���I�[�o�[��
void DISPLAY::DrawOverDisp(GAME_STATE* state)
{
	counter++;    //�t���[�����J�E���g

	//"PLAYER"�\��
	DrawGraph(DRAW_POINT_X + 180, DRAW_POINT_Y + 210, PlayImage, TRUE);

	//"READY!"�\��
	DrawGraph(DRAW_POINT_X + 180, DRAW_POINT_Y + 390, OverImage, TRUE);

	//3�b�o�ߌ�A�^�C�g����
	if (counter >= 300)
	{
		*state = GAME_STATE::DRAW_TITLE;

		counter = 0;
	}
}

//�`��ʒu
const int DrawX = DRAW_POINT_X + (MAP_SIZE * MAP_WIDTH);
const int DrawY = SCREEN_HEIGHT - 80;

//�c�@�`��
void DISPLAY::DrawPlayerLife(int LifeCnt)
{
	for (int i = 0; i < LifeCnt; i++)
	{
		DrawGraph(DrawX + (i * 40), DrawY, PacImage, TRUE);
	}
}

//�N���A�ʂɂ��t���[�c�`��
void DISPLAY::DrawStageFruit(int ClearCnt)
{
	int dx = DRAW_POINT_X + (MAP_SIZE * MAP_WIDTH) - 40;
	int dy = SCREEN_HEIGHT - 200;
	for (int i = 0; i < MAX_DRAW_F; i++)
	{
		//if (Img_Fruits[i] != nullptr)

		//dx += (i * 40);
		DrawGraph(dx + (i * 40), dy, Img_Fruits[i], TRUE);
		//if (i == 3)
		//{
		//	dx = DRAW_POINT_X + (MAP_SIZE * MAP_WIDTH) - 40;
		//	dy += 40;
		//}


	}
}

//�N���A�ʂɂ��`��t���[�c�̃Z�b�g
void DISPLAY::SetDrawFruit(int ClearCnt)
{
	index = MAX_DRAW_F - 1;  //�z��̖���

	//�������󂾂����ꍇ
	if (Img_Fruits[index] == NULL)
	{
		//�ЂƂO
		while (Img_Fruits[index - 1] == NULL)
		{
			index--;
			if (index == 0) break;
		}
	}
	else
	{
		//0�Ԗڂ��폜�A����i���݂̓Y��-1�Ɂj���炷
		int sort = 1;
		for (int i = 0; i < MAX_DRAW_F - 1; i++)
		{
			Img_Fruits[i] = Img_Fruits[i + 1];
		}
	}

	Img_Fruits[index] = *stage.FruitToClear(ClearCnt);
}

//�\���p�t���[�c�z������Z�b�g�inew ���g���΂���Ȃ��j
void DISPLAY::ResetDrawFruit()
{
	for (int i = 0; i < MAX_DRAW_F; i++) Img_Fruits[i] = NULL;
}
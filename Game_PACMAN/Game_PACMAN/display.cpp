#include"DxLib.h"
#include"Info.h"

#include "display.h"

DISPLAY Disp;

//�摜�ǂݍ���
int DISPLAY::LoadImages()
{
	if ((CircleImage = LoadGraph("images/02_2.png")) == -1) return -1;
	if ((PlayImage = LoadGraph("images/PLAYER.png")) == -1) return -1;
	if ((StartImage = LoadGraph("images/READY.png")) == -1) return -1;
	if ((OverImage = LoadGraph("images/GAMEOVER.png")) == -1) return -1;
	if ((LoadDivGraph("images/PacMan.png", 12, 3, 4, 30, 30, PacManImage)) == -1)return -1;
	if ((LoadDivGraph("images/PacMan_Damage.png", 12, 12, 1, 30, 30, PacManDamageImage)) == -1)return -1;
	if ((g_StageImage = LoadGraph("images/maze_blueV3.1.png")) == -1) return -1;
	if ((g_StageImageW = LoadGraph("images/maze_blueV3.1_w.png")) == -1) return -1;

}

//�����ǂݍ���
int DISPLAY::LoadSounds()
{
	if ((StartBGM = LoadSoundMem("sounds/Start.wav")) == -1) return -1;
}

//��������
void DISPLAY::DispInit()
{
	counter = 0;

	//clearcount = 0;
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
	//DrawGraph(DRAW_POINT_X + 180, DRAW_POINT_Y + 210, PlayImage, TRUE);
	DrawGraph(DRAW_POINT_X + 270, DRAW_POINT_Y + 300, PlayImage, TRUE);

	//"READY!"�\��
	//DrawGraph(DRAW_POINT_X + 180, DRAW_POINT_Y + 390, OverImage, TRUE);
	DrawGraph(DRAW_POINT_X + 270, DRAW_POINT_Y + 480, OverImage, TRUE);

	//3�b�o�ߌ�A�^�C�g����
	if (counter >= 300)
	{
		*state = GAME_STATE::DRAW_TITLE;

		counter = 0;
	}
}
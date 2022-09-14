#include "DxLib.h"
#include <stdio.h>
#include <tchar.h>
#include <map>
#include "Stage.h"
#include "Image.h"
#include"Common.h"
#include "Player.h"
#include "A_star.h"
#include "A_star_PINKY.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "bait.h"

int	oldKey;				// �O��̓��̓L�[
int	nowKey;				// ����̓��̓L�[
int	keyFlg;				// ���̓L�[���

int InitFlg = false;
int Timer = 0;


//���C��
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("�p�b�N�}��");       //�^�C�g����ݒ�
	ChangeWindowMode(TRUE);                //�E�B���h�E���[�h�ŋN��
	SetGraphMode(1280, 720, 32);
	if (DxLib_Init() == -1) return -1;     //DX���C�u�����̏���������
	SetDrawScreen(DX_SCREEN_BACK);         //�`����ʂ𗠂ɂ���

	if (image.LoadImages() == -1)return -1;


	//�Q�[�����[�v              
	while (ProcessMessage() == 0)
	{
		oldKey = nowKey;
		nowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		keyFlg = nowKey & ~oldKey;

		//��ʂ̏�����
		ClearDrawScreen();

		if (InitFlg == false) {
			g_player.PlayerInit();
			g_enemy.EnemyInit();
			g_enemy2.EnemyInit();
			a_star.A_starInit();
			bait.CreateBait();
			//a_star.SetDefault();
			//a_star.ResetSearchStatus();
			/*a_star.main();
			a_star.main();*/
			InitFlg = true;
		}

		if (bait.pscore < 168) {
			//�X�e�[�W�̕`��
			//DrawGraph(0, 30, image.g_StageImage, TRUE);
			//DrawGraph(DRAW_POINT_X + 90, DRAW_POINT_Y + 90, image.g_StageImage, TRUE);
			//a_star.A_starInit();
			//stage.DrawMap();
			stage.DrawMapImageV3();
			g_player.PlayerController();
			//a_star.main(int plX, int plY, int enX, int enY);
			a_star.main(/*g_player.PXC, g_player.PYC, g_enemy.EXC, g_enemy.EYC*/);
			g_enemy.MapCopy();
			g_enemy.EnemyController();
			a_star_pink.main(/*g_player.PXC, g_player.PYC, g_enemy2.EXC, g_enemy2.EYC*/);
			g_enemy2.MapCopy();
			g_enemy2.EnemyController();
			bait.BaitController();
			//DrawPixel(g_player.PX, g_player.PY, 0xff00ff);
			//DrawBox(g_player.PX, g_player.PY, 1000, 200, 0xff00ff, false);
			DrawFormatString(1100, 500, 0xffffff, "%d", g_player.PX);
			DrawFormatString(1100, 550, 0xffffff, "%d", g_player.PY);

			DrawFormatString(1100, 400, 0xffffff, "%d", DRAW_POINT_X);
			DrawFormatString(1100, 450, 0xffffff, "%d", DRAW_POINT_Y);
			//stage.DrawMapImage();
			if (keyFlg & PAD_INPUT_A)bait.pscore+=10;

		}else if (bait.pscore >= 168) {
			stage.DrawMapImageV3();
			DrawGraph(g_player.PX - 15, g_player.PY - 15, image.PacManImage[g_player.PacMan_index + g_player.PacMan_dir * 3], TRUE);
			if (Timer++ <= 280) {
				if(Timer >= 80)stage.flashingMapImageV3();
				DrawGraph(g_player.PX - 15, g_player.PY - 15, image.PacManImage[g_player.PacMan_index + g_player.PacMan_dir * 3], TRUE);
			}
			else{
				Timer = 0;
				bait.pscore = 0;
				InitFlg = false;
			}
		}
	

		//����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();

		if (keyFlg == 1024) DxLib_End();
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
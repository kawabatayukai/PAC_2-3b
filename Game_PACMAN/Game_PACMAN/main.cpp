#include "DxLib.h"
#include "Stage.h"
#include "Image.h"
#include"Common.h"
#include "Player.h"

int	oldKey;				// �O��̓��̓L�[
int	nowKey;				// ����̓��̓L�[
int	keyFlg;				// ���̓L�[���

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

		//�X�e�[�W�̕`��
		//DrawGraph(0, 30, image.g_StageImage, TRUE);
		stage.DrawMap();
		g_player.PlayerController();
		DrawPixel(g_player.PX, g_player.PY, 0xff00ff);
		DrawBox(g_player.PX, g_player.PY, 1000, 200, 0xff00ff, false);
		
		
	

		//����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();

		if (keyFlg == 1024) DxLib_End();
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
#include "DxLib.h"

//���C��
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("�p�b�N�}��");       //�^�C�g����ݒ�
	ChangeWindowMode(TRUE);                //�E�B���h�E���[�h�ŋN��
	if (DxLib_Init() == -1) return -1;     //DX���C�u�����̏���������
	SetDrawScreen(DX_SCREEN_BACK);         //�`����ʂ𗠂ɂ���


	//�Q�[�����[�v              
	while (ProcessMessage() == 0)
	{
		//��ʂ̏�����
		ClearDrawScreen();

		DrawString(0, 0, "TEST", 0xffffff);


		//����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
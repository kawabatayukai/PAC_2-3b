#include "DxLib.h"
#include"coffebrake.h"


//���C��
int oldKey;				// �O��̓��̓L�[
int nowKey;				// ����̓��̓L�[
int keyFlg;				// ���̓L�[���

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	oldKey = nowKey;
	nowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	keyFlg = nowKey & ~oldKey;
	SetMainWindowText("�p�b�N�}��");       //�^�C�g����ݒ�
	ChangeWindowMode(TRUE);                //�E�B���h�E���[�h�ŋN��
	SetGraphMode(1280, 720, 32);
	if (DxLib_Init() == -1) return -1;     //DX���C�u�����̏���������
	SetDrawScreen(DX_SCREEN_BACK);         //�`����ʂ𗠂ɂ���
          
	//�Q�[�����[�v              
	while (ProcessMessage() == 0)
	{
		//coffebrake
		animasion_Initialize();
		animasion1();
		animasion2();
		animasion3();

		////����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();

		if (keyFlg == 1024) DxLib_End();
	}


	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}


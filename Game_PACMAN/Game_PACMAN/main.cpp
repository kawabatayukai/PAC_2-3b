#include "DxLib.h"
#include "Stage.h"
#include "Image.h"

//�Q�[���X�e�[�g�񋓑�
enum class GAME_STATE
{
	DRAW_TITLE = 0,     //�^�C�g��
	GAME_INIT,          //��������
	GAME_MAIN,          //���C��
	GAME_CLEAR,         //�Q�[���N���A
	GAME_OVER,          //�Q�[���I�[�o�[
	GAME_END = 99       //�Q�[���I��
};


//�ϐ�
GAME_STATE g_GameState;  //�Q�[���X�e�[�g
int g_OldKey;            // �O��̓��̓L�[ 
int g_NowKey;            // ����̓��̓L�[ 
int g_KeyFlg;            // ���̓L�[���  

//�֐�
void DrawGameTitle();    //�^�C�g���`��
void GameInit();         //��������
void GameMain();         //���C��
void DrawGameClear();    //�Q�[���N���A�`��
void DrawGameOver();     //�Q�[���I�[�o�[�`��

//���C��
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("�p�b�N�}��");       //�^�C�g����ݒ�
	ChangeWindowMode(TRUE);                //�E�B���h�E���[�h�ŋN��
	SetGraphMode(1280, 720, 32);
	if (DxLib_Init() == -1) return -1;     //DX���C�u�����̏���������
	SetDrawScreen(DX_SCREEN_BACK);         //�`����ʂ𗠂ɂ���

	if (image.LoadImages() == -1)return -1;//�摜�ǂݍ���



	//�Q�[�����[�v              
	while (ProcessMessage() == 0)
	{
		//��ʂ̏�����
		ClearDrawScreen();
		//�L�[���͎擾 
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1); 
		g_KeyFlg = g_NowKey & ~g_OldKey;


		switch (g_GameState)
		{
		case GAME_STATE::DRAW_TITLE:

			DrawGameTitle();  //�^�C�g��
			break;

		case GAME_STATE::GAME_INIT:

			GameInit();       //��������
			break;

		case GAME_STATE::GAME_MAIN:

			GameMain();       //�Q�[�����C��
			break;

		case GAME_STATE::GAME_CLEAR:

			DrawGameClear();  //�Q�[���N���A�`��
			break;

		case GAME_STATE::GAME_OVER:

			DrawGameOver();   //�Q�[���I�[�o�[�`��
			break;

		default:
			break;
		}


		//����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}


//�^�C�g���`��
void DrawGameTitle()
{

	//����������
	g_GameState = GAME_STATE::GAME_INIT;
}

//��������
void GameInit()
{

	//�Q�[�����C����
	g_GameState = GAME_STATE::GAME_MAIN;
}

//�Q�[�����C��
void GameMain()
{

	//�X�e�[�W�̕`��
	stage.DrawMap();
}

//�Q�[���N���A
void DrawGameClear()
{

}

//�Q�[���I�[�o�[
void DrawGameOver()
{

}
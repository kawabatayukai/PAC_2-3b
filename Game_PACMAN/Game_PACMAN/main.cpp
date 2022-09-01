#include "DxLib.h"
#include "Stage.h"
#include "Image.h"

#include"Pink.h"
#include"Red.h"
#include"TestPlayer.h"

int	g_OldKey;				// �O��̓��̓L�[
int	g_NowKey;				// ����̓��̓L�[
int	g_KeyFlg;				// ���̓L�[���

//������
void GameInit();

//2�����z���߂�l�ɂ���������
int MapData2[MAP_HEIGHT][MAP_WIDTH] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
	{1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1,0,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,},
	{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,},
	{1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,},
	{0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,},
	{0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,0,0,},
	{1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,},
	{0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,},
	{1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,},
	{0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,0,0,},
	{0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,},
	{1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,},
	{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
	{1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,},
	{1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,},
	{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,},
	{1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
};

//���C��
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("�p�b�N�}��");       //�^�C�g����ݒ�
	ChangeWindowMode(TRUE);                //�E�B���h�E���[�h�ŋN��
	SetGraphMode(1280, 720, 32);
	if (DxLib_Init() == -1) return -1;     //DX���C�u�����̏���������
	SetDrawScreen(DX_SCREEN_BACK);         //�`����ʂ𗠂ɂ���

	if (image.LoadImages() == -1)return -1;
	GameInit();  //��������

	//�Q�[�����[�v              
	while (ProcessMessage() == 0)
	{
		// ���̓L�[�擾
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		//��ʂ̏�����
		ClearDrawScreen();

		//�X�e�[�W�̕`��
		//DrawGraph(0, 30, image.g_StageImage, TRUE);
		stage.DrawMap();

		Red.TargetCtrl(Player.GetPlayerX(), Player.GetPlayerY(), Player.GetPlayerD()); //�^�[�Q�b�g��ݒ�
		Red.MoveEnemy2(MapData2);                                 //�^�[�Q�b�g�Ɋ�Â��ړ�
		Red.DrawEnemy();                                          //�G�`��

		Pink.TargetCtrl(Player.GetPlayerX(), Player.GetPlayerY(), Player.GetPlayerD()); //�^�[�Q�b�g��ݒ�
		Pink.MoveEnemy2(MapData2);                                 //�^�[�Q�b�g�Ɋ�Â��ړ�
		Pink.DrawEnemy();                                          //�G�`��

		if (g_NowKey & PAD_INPUT_M) Red.SetSortie();
		if (g_NowKey & PAD_INPUT_A) Red.InitEnemy();

		if (g_NowKey & PAD_INPUT_M) Pink.SetSortie();
		if (g_NowKey & PAD_INPUT_A) Pink.InitEnemy();

		Player.MovePlayer(g_NowKey, MapData2); //�v���C���[�ړ��e�X�g
		Player.DrawPlayer();                  //�v���C���[�`��

		//����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();
	}

	DxLib::DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

//������
void GameInit()
{
	Red.InitEnemy();    //�ԏ�����
	Pink.InitEnemy();   //�s���N������
	Player.PlayerInit(); //�e�X�g�v���C���[������
}
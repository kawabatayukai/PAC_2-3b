#include "DxLib.h"
#include"pink.h"
#include"red.h"
#include"blue.h"
#include"orange.h"

#include"NewPlayer.h"
#include"Info.h"
#include"Display.h"
#include"Bait.h"
#include"Stage.h"

//�ϐ�
int	g_OldKey;				// �O��̓��̓L�[
int	g_NowKey;				// ����̓��̓L�[
int	g_KeyFlg;				// ���̓L�[���

int ClearCount = 0;         //�N���A�񐔁@�t�@�C�������Ώ�

int g_GameTitleImage = 0;
GAME_STATE g_GameState = GAME_STATE::DRAW_TITLE;

//�֐�
void DrawGameTitle();    //�^�C�g���`��
void GameInit();         //��������
void GameStarter();      //�X�^�[�g�iREADY!�j
void GameMain();         //���C��
void DrawGameClear();    //�Q�[���N���A�`��
void DrawGameOver();     //�Q�[���I�[�o�[�`��
int LoadImages();        //�摜�ǂݍ���
int LoadSounds();        //�����ǂݍ���

void NewGameMain();

/********* �` �e�X�g�p�}�b�v �` *********/


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

int MapData3[MAP_HEIGHT][MAP_WIDTH] =
{
	//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	//{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,},
	//{0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,},
	//{0,0,0,1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,0,0,},
	//{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,},
	//{0,0,0,1,0,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,0,0,0,},
	//{0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,},
	//{0,0,0,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,0,0,0,},
	//{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,},
	//{0,0,0,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,0,0,0,0,0,},
	//{0,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,0,0,0,},
	//{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
	//{0,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,0,0,0,},
	//{0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,0,0,},
	//{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,},
	//{0,0,0,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,0,0,0,},
	//{0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,},
	//{0,0,0,1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,0,0,},
	//{0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,},
	//{0,0,0,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,0,0,0,},
	//{0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,},
	//{0,0,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,0,0,},
	//{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,},
	//{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,},
	//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,},
	{1,1,1,1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,1,1,1,},
	{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,},
	{1,1,1,1,0,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,1,1,},
	{1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,},
	{1,1,1,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,},
	{1,1,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,1,1,},
	{1,1,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,0,0,1,1,1,},
	{1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,},
	{1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,},
	{1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,},
	{1,1,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,0,0,1,1,1,},
	{1,1,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,1,1,},
	{1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,},
	{1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,},
	{1,1,1,1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,1,1,1,},
	{1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,},
	{1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,},
	{1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,},
	{1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,},
	{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
};

//map���"�Z�}�X��"���E�B���h�E��̍��W�ɕϊ�
int MapPointX(int mapX) { return mapX * MAP_SIZE; }
int MapPointY(int mapY) { return mapY * MAP_SIZE; }


//�`��
void DrawMap()
{
	//DrawFormatString(0, 40, 0xffffff, "%d", DRAW_POINT_X);
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			int x = MapPointX(j) + DRAW_POINT_X;
			int y = MapPointY(i) + DRAW_POINT_Y;
			if (MapData3[i][j] == 1 && i > 2 && j > 2)
			{
				DrawBox(x, y, (x + MAP_SIZE), (y + MAP_SIZE), 0x00ff00, TRUE);
			}
			SetFontSize(12);
			if (i == 0) DrawFormatString(x + 5, y + 5, 0xffffff, "%d", j);
			if (j == 0) DrawFormatString(x + 5, y + 5, 0xffffff, "%d", i);

			if (j == 23) break;
		}
		if (i == 25) break;
	}
}

/****************************************/

//�}�X
void DrawSquare()
{
	int x1 = 0;
	int x2 = 0;
	int y1 = DRAW_POINT_Y;
	int y2 = DRAW_POINT_Y + (MAP_SIZE * MAP_HEIGHT);

	for (int i = 0; i < MAP_WIDTH + 1; i++)
	{
		x1 = i * MAP_SIZE + DRAW_POINT_X;
		x2 = x1;
		DrawLine(x1, y1, x2, y2, 0xffffff);
	}

	x1 = DRAW_POINT_X;
	x2 = DRAW_POINT_X + (MAP_SIZE * MAP_WIDTH);
	y1 = 0;
	y2 = 0;

	for (int j = 0; j < MAP_HEIGHT + 1; j++)
	{
		y1 = j * MAP_SIZE + DRAW_POINT_Y;
		y2 = y1;
		DrawLine(x1, y1, x2, y2, 0xffffff);
	}
}

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("�p�b�N�}��");       //�^�C�g����ݒ�
	ChangeWindowMode(TRUE);                //�E�B���h�E���[�h�ŋN��
	SetGraphMode(1280, 720, 32);
	if (DxLib_Init() == -1) return -1;     //DX���C�u�����̏���������
	SetDrawScreen(DX_SCREEN_BACK);         //�`����ʂ𗠂ɂ���

	//�摜�ǂݍ���
	if (LoadImages() == -1) return -1;
	//�����ǂݍ���
	if (LoadSounds() == -1) return -1;

	while (ProcessMessage() == 0 && !(g_KeyFlg & PAD_INPUT_START))
	{
		// ���̓L�[�擾
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		//��ʏ�������
		ClearDrawScreen();

		switch (g_GameState)
		{
		case GAME_STATE::DRAW_TITLE:
			DrawGameTitle();

			break;

		case GAME_STATE::GAME_INIT:

			GameInit();       //��������
			break;

		case GAME_STATE::GAME_START:

			GameStarter();    //�X�^�[�g��
			break;

		case GAME_STATE::GAME_MAIN:

			NewGameMain();       //�Q�[�����C��
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

	DxLib::DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

//�^�C�g���`��
void DrawGameTitle()
{
	DrawGraph(150, 30, g_GameTitleImage, FALSE);

	SetFontSize(40);
	SetFontThickness(9);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	DrawString(500, 360, "GAME START", 0xffffff);
	if (g_NowKey & PAD_INPUT_A) {
		g_GameState = GAME_STATE::GAME_INIT;
	}
}

//��������
void GameInit()
{
	//���ׂĂ�Enemy�������� �e�N���XENEMY_BASE�̐ÓI�����o�֐�
	ENEMY_BASE::AllEnemyInit();

	g_player.PlayerInit();
	Disp.DispInit();
	bait.CreateBait();
	stage.StageInit();

	g_GameState = GAME_STATE::GAME_START;
}

//�X�^�[�g��
void GameStarter()
{
	DrawMap();
	Disp.DrawStartDisp(&g_GameState, &Pink);

	//g_GameState = GAME_STATE::GAME_MAIN;
}

//�Q�[�����C��
void GameMain()
{
	////�A�J
	//Red.TargetCtrl(BasePlayer.GetPlayerX(), BasePlayer.GetPlayerY(), BasePlayer.GetPlayerD()); //�^�[�Q�b�g��ݒ�
	//Red.MoveEnemy2(MapData2);                                 //�^�[�Q�b�g�Ɋ�Â��ړ�
	//Red.DrawEnemy();                                          //�G�`��                                         //�G�`��


	////�s���N
	//Pink.TargetCtrl(BasePlayer.GetPlayerX(), BasePlayer.GetPlayerY(), BasePlayer.GetPlayerD()); //�^�[�Q�b�g��ݒ�
	//Pink.MoveEnemy2(MapData2);                                 //�^�[�Q�b�g�Ɋ�Â��ړ�
	//Pink.DrawEnemy();                                          //�G�`��                                         //�G�`��

	////�A�I
	//Blue.TargetCtrl(BasePlayer.GetPlayerX(), BasePlayer.GetPlayerY(), BasePlayer.GetPlayerD()); //�^�[�Q�b�g��ݒ�
	//Blue.MoveEnemy2(MapData2);                                 //�^�[�Q�b�g�Ɋ�Â��ړ�
	//Blue.DrawEnemy();

	////�I�����W
	//Orange.TargetCtrl(BasePlayer.GetPlayerX(), BasePlayer.GetPlayerY(), BasePlayer.GetPlayerD()); //�^�[�Q�b�g��ݒ�
	//Orange.MoveEnemy2(MapData2);                                 //�^�[�Q�b�g�Ɋ�Â��ړ�
	//Orange.DrawEnemy();

	//ENEMY_BASE::SoltieControl(g_KeyFlg, bait.GetBaitCount(), ClearCount);

	//if (g_NowKey & PAD_INPUT_2) Pink.SetEnemyMode(MODE::EYE);
	//if (g_NowKey & PAD_INPUT_A) Pink.InitEnemy();

	//if (g_NowKey & PAD_INPUT_2) Red.SetIjike();
	//if (g_NowKey & PAD_INPUT_A) Red.InitEnemy();

	//if (g_NowKey & PAD_INPUT_2) Orange.SetIjike();
	//if (g_NowKey & PAD_INPUT_A) Orange.InitEnemy();

	//if (g_NowKey & PAD_INPUT_2) Blue.SetIjike();
	//if (g_NowKey & PAD_INPUT_A) Blue.InitEnemy();


	//ENEMY_BASE::DrawAllInfo();
	//DrawString(30, 300, "�X�y�[�X�L�[���������Ƃɏo��", 0x00faff);
	////DrawString(30, 320, "8�b�Ԃ͏��񃂁[�h", 0x00faff);
	////DrawString(30, 340, "�����20�b�Ԓǐ�", 0x00faff);

	//BasePlayer.MovePlayer(g_NowKey, MapData2); //�v���C���[�ړ��e�X�g
	//BasePlayer.DrawPlayer();                  //�v���C���[�`��
	////g_player.PlayerController(g_KeyFlg, MapData2);

	//bait.BaitController(BasePlayer.GetPlayerX(), BasePlayer.GetPlayerY());
	////bait.BaitController(g_player.GetPlayerX(), g_player.GetPlayerY());

	//DrawMap();                         //�}�b�v�`��e�X�g
	//DrawSquare();

}

void NewGameMain()
{
	//�G�T�̈ړ��E�`����Ǘ�
	bait.BaitController(g_player.GetPlayerX() + DRAW_POINT_X, g_player.GetPlayerY() + DRAW_POINT_Y);

	//�t���[�c�̏o��
	stage.DrawFruit(bait.GetBaitCount(), ClearCount);

	//�v���C���[�̈ړ��E�`����Ǘ�
	g_player.PlayerController(g_KeyFlg, MapData3);

	//�A�J
	Red.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //�^�[�Q�b�g��ݒ�
	Red.MoveEnemy2(MapData3);                                 //�^�[�Q�b�g�Ɋ�Â��ړ�
	Red.DrawEnemy();                                          //�G�`��                                         

	//�s���N
	Pink.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //�^�[�Q�b�g��ݒ�
	Pink.MoveEnemy2(MapData3);                                 //�^�[�Q�b�g�Ɋ�Â��ړ�
	Pink.DrawEnemy();                                          //�G�`��                                         //�G�`��

	//�A�I
	Blue.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //�^�[�Q�b�g��ݒ�
	Blue.MoveEnemy2(MapData3);                                 //�^�[�Q�b�g�Ɋ�Â��ړ�
	Blue.DrawEnemy();

	//�I�����W
	Orange.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //�^�[�Q�b�g��ݒ�
	Orange.MoveEnemy2(MapData3);                                 //�^�[�Q�b�g�Ɋ�Â��ړ�
	Orange.DrawEnemy();

	//if (g_NowKey & PAD_INPUT_2) Pink.SetEnemyMode(MODE::EYE);

	//if (g_NowKey & PAD_INPUT_2) Red.SetIjike();

	//if (g_NowKey & PAD_INPUT_2) Orange.SetIjike();

	//if (g_NowKey & PAD_INPUT_2) Blue.SetIjike();

	ENEMY_BASE::IjikeControl(bait.GetPowerFlg());  //�C�W�P��Ԃ��Ǘ�

	ENEMY_BASE::SoltieControl(g_KeyFlg, bait.GetBaitCount(), ClearCount);  //�G�̏o�����Ǘ�
	ENEMY_BASE::DrawAllInfo();            //�G�̏���\��

	DrawFormatString(30, 320, 0xffffff, "playerX : %d", g_player.GetPlayerX());
	DrawFormatString(30, 340, 0xffffff, "playerY : %d", g_player.GetPlayerY());




	DrawMap();                         //�}�b�v�`��e�X�g
	DrawSquare();                      //�e�X�g�p�@�g�\��

	//�e�X�g�@�N���A����
	if (bait.GetBaitCount() == BAIT_MAX)
	{
		ClearCount++;
		g_GameState = GAME_STATE::GAME_CLEAR;
	}
}

//�Q�[���N���A
void DrawGameClear()
{

	static int timer;
	DrawMap();                         //�}�b�v�`��e�X�g

	//�e�X�g�@3�b�Ŏ���
	if (++timer > 180)
	{
		g_GameState = GAME_STATE::GAME_INIT;
		timer = 0;
	}
}

//�Q�[���I�[�o�[
void DrawGameOver()
{
	DrawMap();
	Disp.DrawOverDisp(&g_GameState);
}

//�摜�ǂݍ���
int LoadImages()
{
	if ((Red.Loadimages()) == -1) return -1;
	if ((Pink.Loadimages()) == -1) return -1;
	if ((Blue.Loadimages()) == -1) return -1;
	if ((Orange.Loadimages()) == -1) return -1;

	if ((g_player.LoadImages()) == -1) return -1;
	if ((Disp.LoadImages()) == -1) return -1;
	if ((bait.LoadImages()) == -1) return -1;
	if ((stage.LoadImages()) == -1) return -1;

	if ((g_GameTitleImage = LoadGraph("images/PAC-MAN_Classic_Logo.png")) == -1)return -1;

	return 0;
}

//�����ǂݍ���
int LoadSounds()
{
	if ((Disp.LoadSounds()) == -1) return -1;
}

#include "DxLib.h"
#include "Stage.h"
#include "Image.h"

#include"Red.h"
#include"Pink.h"
#include"Blue.h"
#include"Orange.h"
#include"NewPlayer.h"

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

int MapData2[MAP_HEIGHT][MAP_WIDTH] =
{
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,},
{0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,},
{0,0,0,1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,0,0,},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,},
{0,0,0,1,0,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,0,0,0,},
{0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,},
{0,0,0,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,0,0,0,},
{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,},
{0,0,0,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,0,0,0,0,0,},
{0,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,0,0,0,},
{0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,0,0,},
{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,},
{0,0,0,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,0,0,0,},
{0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,},
{0,0,0,1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,0,0,},
{0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,},
{0,0,0,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,0,0,0,},
{0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,},
{0,0,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,0,0,},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,},
{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
};


//���C��
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("�p�b�N�}��");       //�^�C�g����ݒ�
	ChangeWindowMode(TRUE);                //�E�B���h�E���[�h�ŋN��
	SetGraphMode(1280, 720, 32);
	if (DxLib_Init() == -1) return -1;     //DX���C�u�����̏���������
	SetDrawScreen(DX_SCREEN_BACK);         //�`����ʂ𗠂ɂ���

	if (image.LoadImages() == -1)return -1;//�摜�ǂݍ���
	if ((Red.Loadimages()) == -1) return -1;
	if ((Pink.Loadimages()) == -1) return -1;
	if ((Blue.Loadimages()) == -1) return -1;
	if ((Orange.Loadimages()) == -1) return -1;

	if ((g_player.LoadImages()) == -1) return -1;


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
	//���ׂĂ�Enemy�������� �e�N���XENEMY_BASE�̐ÓI�����o�֐�
	ENEMY_BASE::AllEnemyInit();

	g_player.PlayerInit();

	//�Q�[�����C����
	g_GameState = GAME_STATE::GAME_MAIN;
}

//�Q�[�����C��
void GameMain()
{
	//�A�J
	//Red.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //�^�[�Q�b�g��ݒ�
	//Red.MoveEnemy2(MapData2);                                 //�^�[�Q�b�g�Ɋ�Â��ړ�
	//Red.DrawEnemy();                                          //�G�`��                                         //�G�`��


	//�s���N
	Pink.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //�^�[�Q�b�g��ݒ�
	Pink.MoveEnemy2(MapData2);                                 //�^�[�Q�b�g�Ɋ�Â��ړ�
	Pink.DrawEnemy();                                          //�G�`��                                         //�G�`��

	////�A�I
	//Blue.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //�^�[�Q�b�g��ݒ�
	//Blue.MoveEnemy2(MapData2);                                 //�^�[�Q�b�g�Ɋ�Â��ړ�
	//Blue.DrawEnemy();

	////�I�����W
	//Orange.TargetCtrl(g_player.GetPlayerX(), g_player.GetPlayerY(), g_player.GetPlayerD()); //�^�[�Q�b�g��ݒ�
	//Orange.MoveEnemy2(MapData2);                                 //�^�[�Q�b�g�Ɋ�Â��ړ�
	//Orange.DrawEnemy();

	//ENEMY_BASE::SoltieControl(g_KeyFlg);
	if (g_NowKey & PAD_INPUT_M) Pink.SetSortie();
	if (g_NowKey & PAD_INPUT_2) Pink.SetEnemyMode(MODE::EYE);
	if (g_NowKey & PAD_INPUT_A) Pink.InitEnemy();

	if (g_NowKey & PAD_INPUT_M) Red.SetSortie();
	if (g_NowKey & PAD_INPUT_2) Red.SetIjike();
	if (g_NowKey & PAD_INPUT_A) Red.InitEnemy();

	if (g_NowKey & PAD_INPUT_M) Orange.SetSortie();
	if (g_NowKey & PAD_INPUT_2) Orange.SetIjike();
	if (g_NowKey & PAD_INPUT_A) Orange.InitEnemy();

	if (g_NowKey & PAD_INPUT_M) Blue.SetSortie();
	if (g_NowKey & PAD_INPUT_2) Blue.SetIjike();
	if (g_NowKey & PAD_INPUT_A) Blue.InitEnemy();

	//if (g_NowKey & PAD_INPUT_M) DrawString(0, 0, "SSSSSSSS", 0xffffff);

	ENEMY_BASE::DrawAllInfo();
	DrawString(30, 300, "�X�y�[�X�L�[���������Ƃɏo��", 0x00faff);
	DrawString(30, 320, "8�b�Ԃ͏��񃂁[�h", 0x00faff);
	DrawString(30, 340, "�����20�b�Ԓǐ�", 0x00faff);


	g_player.PlayerController(g_KeyFlg, MapData2);
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
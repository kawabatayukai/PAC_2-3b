#pragma once

#define SCREEN_WIDTH  1280 //�X�N���[����
#define SCREEN_HEIGHT  720 //�X�N���[������

//#define MAP_WIDTH  21    //Map X�����̃`�b�v��
//#define MAP_HEIGHT  23   //Map Y�����̃`�b�v��
#define MAP_WIDTH   27    //Map X�����̃`�b�v��
#define MAP_HEIGHT  29   //Map Y�����̃`�b�v��

#define MAP_SIZE  30     //Map ��̃`�b�v�̃T�C�Y (20 * 20)

//#define PLUS_MAP 3

//�`��J�n�ʒu(�X�N���[���T�C�Y - �X�e�[�W�S�̂̕�/���� / �Q)
//#define DRAW_POINT_X  330//(SCREEN_WIDTH - (MAP_WIDTH * MAP_SIZE)) / 2   = 330
#define DRAW_POINT_X  (SCREEN_WIDTH - (MAP_WIDTH * MAP_SIZE)) / 2    //= 
#define DRAW_POINT_Y  (SCREEN_HEIGHT - (MAP_HEIGHT * MAP_SIZE)) / 2  //= 

//�Q�[���X�e�[�g
enum class GAME_STATE
{
	DRAW_TITLE = 0,     //�^�C�g��
	GAME_INIT,          //��������
	GAME_START,         //�X�^�[�g��(READY!)
	GAME_MAIN,          //���C��
	GAME_CLEAR,         //�Q�[���N���A
	GAME_OVER,          //�Q�[���I�[�o�[(GAME OVER)
	COFFEE,
	GAME_END = 99       //�Q�[���I��
};

#pragma once
#include"enemy.h"
//#include"player.h"

class DISPLAY
{
public:
	//�摜�ǂݍ���
	int LoadImages();
	//�����ǂݍ���
	int LoadSounds();

	void DispInit();        //������
	void DrawStartDisp(GAME_STATE* state, ENEMY_BASE* enemy);   //�Q�[���X�^�[�g��
	void DrawOverDisp(GAME_STATE* state);    //�Q�[���I�[�o�[��

	int PacManImage[12];			// �摜�p�ϐ�
	int PacManDamageImage[12];			// �摜�p�ϐ�
	int	g_StageImage;			// �摜�p�ϐ�
	int	g_StageImageW;			// �摜�p�ϐ�
private:
	int CircleImage;  //�v���C���[��"��"�摜


	int StartImage;   //"Ready!"�摜
	int OverImage;    //"Game Over" �摜
	int PlayImage;    //"Player"�摜
	int StartBGM;     //�X�^�[�gBGM

	int counter = 0;  //�t���[���J�E���g
	int clearcount = 0;

};

extern DISPLAY Disp;

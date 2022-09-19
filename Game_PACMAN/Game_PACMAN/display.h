#pragma once
#include"enemy.h"
//#include"player.h"

//�t���[�c�ő�`�搔
#define MAX_DRAW_F 8 

class DISPLAY
{
public:
	//�摜�ǂݍ���
	int LoadImages();
	//�����ǂݍ���
	int LoadSounds();

	void DispInit(int ClearCnt);        //������
	void DrawStartDisp(GAME_STATE* state, ENEMY_BASE* enemy);   //�Q�[���X�^�[�g��
	void DrawOverDisp(GAME_STATE* state);    //�Q�[���I�[�o�[��

	void DrawPlayerLife(int LifeCnt);        //�c�@�`��
	void DrawStageFruit(int ClearCnt);       //�N���A�ʂɂ��t���[�c�`��
	void SetDrawFruit(int ClearCnt);         //�N���A�ʂɂ��`��t���[�c�̃Z�b�g
	void ResetDrawFruit();                   //�\���p�t���[�c�z������Z�b�g�inew ���g���΂���Ȃ��j

private:
	int CircleImage;  //�v���C���[��"��"�摜
	int PacImage;     //�c�@�p�v���C���[�摜

	int StartImage;   //"Ready!"�摜
	int OverImage;    //"Game Over" �摜
	int PlayImage;    //"Player"�摜
	int StartBGM;     //�X�^�[�gBGM

	int Img_Fruits[MAX_DRAW_F];//�t���[�c�ő�\����
	int index = 0;

	int counter = 0;  //�t���[���J�E���g
	int clearcount = 0;
};

extern DISPLAY Disp;

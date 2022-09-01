#pragma once
#include"Enemy.h"

//�G�L�����i�s���N�j���N���X��ENEMY_BASE
class ENEMY_RED : public ENEMY_BASE
{
public:
	int Loadimages();   //�摜�ǂݍ���
	void InitEnemy();   //��������
	void MoveEnemy(int MapData[MAP_HEIGHT][MAP_WIDTH]);   //�ړ�
	void MoveEnemy2(int MapData[MAP_HEIGHT][MAP_WIDTH]);

	void DrawEnemy();   //�`��

	//�ړ��ڕW�Ƃ̈�v�@�߂�l�@0�Fx,y���W���Ɉ�vż�@ 1�Fx���W�݈̂�v  2�Fy���W�݈̂�v�@�@3:x,y���W���Ɉ�v 
	int CheckTarget();

	void TestMove6(int MapData[MAP_HEIGHT][MAP_WIDTH], int NowKey); //�e�X�g

	void TargetCtrl(int tpX, int tpY, int tpD);              //�^�[�Q�b�g��ݒ�

	void SetSortie() { if (sortie_flg == false)sortie_flg = true; } //�o���t���O��ύX�i�e�X�g�p�j

	void EnemyControl();  //�G�̋���(���[�h�ɂ���ĕω�  �o���O/����/�ǐ�)

	void Move_StandBy();  //�o���O�̋���
	void Move_Patrol();   //���񃂁[�h�̋���
	void Move_Track();    //�ǐՃ��[�h�̋���

private:
	const int p_speed[4] = { 5,6,7,8 }; //�X�s�[�h�i�ω��p�j
	const int p_score = 3373;           //�X�R�A  

	int mode_count = 0;                 //���[�h�`�F���W(����E�ǐ�)�p�Ƀt���[�����J�E���g

	bool sortie_flg = false;            //�o���t���O�@false �ҋ@�@�@true �o��
};

extern ENEMY_RED Red;


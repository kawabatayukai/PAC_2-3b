#pragma once

class Sounds
{
public:
	int LoadSounds(); //�����ǂݍ���

	void PlayPlayerMove();
	void PlayPlayerEat();
	void StopPlayerEat();

	void PlayIjikeEat();
	void PlayEnemyEye();

private:
	int PlayerMove;  //�v���C���[�ړ�
	int PlayerEat;   //�G�T��H�ׂ�

	int IjikeEat;    //�C�W�P��ߐH
	int EnemyEye;    //�ڏ�Ԃő��ɖ߂�
};

extern Sounds sound;

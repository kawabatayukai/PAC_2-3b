#pragma once

#define SCREEN_WIDTH  1280 //�X�N���[����
#define SCREEN_HEIGHT  720 //�X�N���[������

//#define MAP_WIDTH   21     //Map X�����̃`�b�v��               MAP_SIZE�@20�@���@31
//#define MAP_HEIGHT  23     //Map Y�����̃`�b�v��                             ��  33

#define MAP_WIDTH   27
#define MAP_HEIGHT  29
#define MAP_SIZE    30     //Map ��̃`�b�v�̃T�C�Y

//�`��J�n�ʒu(�X�N���[���T�C�Y - �X�e�[�W�S�̂̕�or���� / �Q)
#define DRAW_POINT_X  (SCREEN_WIDTH - (MAP_WIDTH * MAP_SIZE)) / 2  
#define DRAW_POINT_Y  (SCREEN_HEIGHT - (MAP_HEIGHT * MAP_SIZE)) / 2 


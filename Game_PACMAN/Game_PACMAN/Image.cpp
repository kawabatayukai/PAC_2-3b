#include"DxLib.h"
#include"Image.h"
#include"Pink.h"
#include"Red.h"

Image image;

Image::Image() {
	g_StageImage = 0;			// �摜�p�ϐ�
}
/***********************************************
 * �摜�ǂݍ���
 ***********************************************/
int Image::LoadImages()
{
	//�X�e�[�W�w�i
	if ((g_StageImage = LoadGraph("images/maze_blue.png")) == -1) return -1;

	//�G�i�s���N�j
	if ((Pink.Loadimages()) == -1) return -1;
	//�G�i�A�J�j
	if ((Red.Loadimages()) == -1) return -1;

	return 0;
}
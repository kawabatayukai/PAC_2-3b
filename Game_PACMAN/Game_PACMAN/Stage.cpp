#include "DxLib.h"

#include "Stage.h"

Stage stage;

Stage::Stage(){
	
}

//map���"�Z�}�X��"���E�B���h�E��̍��W�ɕϊ�
int Stage::MapPointX(int mapX) { return mapX * MAP_SIZE; }
int Stage::MapPointY(int mapY) { return mapY * MAP_SIZE; }

//�`��
void Stage::DrawMap()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if (MapData[i][j] == 1)
			{
				int x = MapPointX(j) + DRAW_POINT_X;
				int y = MapPointY(i) + DRAW_POINT_Y;
				DrawBox(x, y, (x + MAP_SIZE), (y + MAP_SIZE), 0x00ff00, TRUE);
			}
		}
	}
}

//��������
void Stage::StageInit()
{
	DrawTime = 0;
	DrawCnt = 0;
}

//�摜�ǂݍ���
int Stage::LoadImages()
{
	if ((LoadDivGraph("images/All_Fruit.png", 8, 8, 1, 30, 30, FruitImgs)) == -1) return -1;
}

//�t���[�c�̏o���A�`��  �@����(�H�ׂ��G�T���A�N���A��)
void Stage::DrawFruit(int FoodCnt, int ClearCnt)
{
	//�G�T��1��ڂ�70�A2��ڂ�170���ƃt���[�c��10�b�Ԃ����\�������



	//  1��� 70�ȏ�                   2��� 170�ȏ�
	if (FoodCnt >= FirstTime && DrawCnt == 0 || FoodCnt >= SecondTime && DrawCnt == 1)
	{
		//10�b��
		if (++DrawTime < 600) DrawGraph(DRAW_POINT_X + MapPointX(13), DRAW_POINT_Y + MapPointY(16), *FruitToClear(ClearCnt), TRUE);
		else
		{
			DrawCnt++;
			DrawTime = 0;
		}
	}
}

//�N���A�񐔂ɂ��o���t���[�c�̕ω�    DrawFruit���ł̂ݎg�p
int* Stage::FruitToClear(int ClearCnt)
{
	if (ClearCnt == 0) return &FruitImgs[0];                         //�N���A��0     cherry
	else if (ClearCnt == 1) return &FruitImgs[1];                    //�N���A��1     strawberry
	else if (ClearCnt == 2 || ClearCnt == 3) return &FruitImgs[2];   //�N���A��2�`3  orange
	else if (ClearCnt == 4 || ClearCnt == 5) return &FruitImgs[3];   //�N���A��4�`5  apple
	else if (ClearCnt == 6 || ClearCnt == 7) return &FruitImgs[4];   //�N���A��6�`7  meron
	else if (ClearCnt == 8 || ClearCnt == 9) return &FruitImgs[5];   //�N���A��8�`9  Galaxian
	else if (ClearCnt == 10 || ClearCnt == 11) return &FruitImgs[6]; //�N���A��10�`11  Bell
	else if (ClearCnt >= 12) return &FruitImgs[7];                   //�N���A��12�`�@�@key
	else return  &FruitImgs[0];                                      //����ȊO��cheryy
}
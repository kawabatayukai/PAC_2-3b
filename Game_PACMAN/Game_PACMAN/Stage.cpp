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
	DrawTime_F = 0;
	DrawTime_S = 0;
	DrawCnt = 0;

	DrawFlg_F = false;    //�t���[�c�`��t���O
	DrawFlg_S = false;
}

//�摜�ǂݍ���
int Stage::LoadImages()
{
	if ((LoadDivGraph("images/All_Fruit.png", 8, 8, 1, 30, 30, FruitImgs)) == -1) return -1;
	//Number
	if ((LoadDivGraph("images/All_Num.png", 10, 10, 1, 10, 14, NumImgs)) == -1) return -1;
}

//�t���[�c�̏o���A�`��  �@����(�H�ׂ��G�T���A�N���A��)
void Stage::DrawFruit(int FoodCnt, int ClearCnt)
{
	//�G�T��1��ڂ�70�A2��ڂ�170���ƃt���[�c��10�b�Ԃ����\�������

	if (DrawFlg_F == true)
	{
		//10�b��
		if (++DrawTime_F < 600)
		{
			DrawGraph(DRAW_POINT_X + MapPointX(13), DRAW_POINT_Y + MapPointY(16), *FruitToClear(ClearCnt), TRUE);
		}
		else
		{
			DrawCnt++;
			DrawTime_F = 0;       //�`�掞�ԃ��Z�b�g
			DrawFlg_F = false;    //�`��OFF
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

//�N���A�񐔂ɂ��o���t���[�c�̕ω�
int Stage::FruitNumToClear(int ClearCnt)
{
	if (ClearCnt == 0) return 0;                         //�N���A��0     cherry
	else if (ClearCnt == 1) return 1;                    //�N���A��1     strawberry
	else if (ClearCnt == 2 || ClearCnt == 3) return 2;   //�N���A��2�`3  orange
	else if (ClearCnt == 4 || ClearCnt == 5) return 3;   //�N���A��4�`5  apple
	else if (ClearCnt == 6 || ClearCnt == 7) return 4;   //�N���A��6�`7  meron
	else if (ClearCnt == 8 || ClearCnt == 9) return 5;   //�N���A��8�`9  Galaxian
	else if (ClearCnt == 10 || ClearCnt == 11) return 6; //�N���A��10�`11  Bell
	else if (ClearCnt >= 12) return 7;                   //�N���A��12�`�@�@key
	else return  0;                                      //����ȊO��cheryy
}

//�t���[�c�̏����܂Ƃ�
void Stage::FruitControl(int HitFlg, int ClearCnt, int FoodCnt, int& score)
{
	if (HitFlg == true && DrawFlg_F == true)
	{
		//�X�R�A���Z
		score += FruitScore[FruitNumToClear(ClearCnt)];

		DrawFlg_F = false;    //�t���[�c�`��OFF
		DrawFlg_S = true;     //�X�R�A�\��ON
		DrawCnt++;            //1��ڂ̕`��Ȃ玟�̕`��
		DrawTime_F = 0;       //�`�掞�ԃ��Z�b�g
	}

	//  1��� 70�ȏ�                   2��� 170�ȏ�
	if (FoodCnt >= FirstTime && DrawCnt == 0 || FoodCnt >= SecondTime && DrawCnt == 1) DrawFlg_F = true;

	if (DrawFlg_S == true)DrawFruitScore(HitFlg, ClearCnt);
}

//�H�ׂ�ꂽ�Ƃ��̏����@�X�R�A�\��
void Stage::DrawFruitScore(int HitFlg, int ClearCnt)
{
	int drawX = (13 * MAP_SIZE) + (MAP_SIZE / 2);  //��{��X���W
	int drawY = (16 * MAP_SIZE) + (MAP_SIZE / 2);  //��{��Y���W

	//�X�R�A�̌���
	int digit = GetDigit(static_cast<unsigned int>(FruitScore[FruitNumToClear(ClearCnt)]));
	//�X�R�A
	int score = FruitScore[FruitNumToClear(ClearCnt)];
	//�������ɉ������ʒu����
	drawX = drawX - (digit / 2) * 9;

	//if (HitFlg == true)
	//{
	//	for (int i = 0; i < digit; i++)
	//	{
	//		DrawRotaGraph(drawX + (i * 9) + DRAW_POINT_X, drawY + DRAW_POINT_Y,
	//			0.9, 0, NumImgs[ShowDigit(digit - 1 - i, score, ClearCnt)], TRUE);
	//	}
	//}

	//2�b��
	if (++DrawTime_S < 120)
	{
		for (int i = 0; i < digit; i++)
		{
			DrawRotaGraph(drawX + (i * 9) + DRAW_POINT_X, drawY + DRAW_POINT_Y,
				0.9, 0, NumImgs[ShowDigit(digit - 1 - i, score, ClearCnt)], TRUE);
		}
	}
	else
	{
		DrawTime_S = 0;    //�`�掞�ԃ��Z�b�g
		DrawFlg_S = false; //�`��OFF
	}
}

//�����ƌ�������\�����鐔����Ԃ�
int Stage::ShowDigit(int digit, int num, int ClearCnt)
{
	//10��  �X�R�A�̌�����  score500 �Ȃ�3��
	int n = (int)pow(10.0, digit);
	return (int)((num % (10 * n)) / n);
}

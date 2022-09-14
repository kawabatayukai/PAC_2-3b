#include "DxLib.h"
#include "Stage.h"
#include "Image.h"

Stage stage;

Stage::Stage(){
	Timer = 0;
	MAP_W_Flg = false;
}

//map上の"〇マス目"をウィンドウ上の座標に変換
int Stage::MapPointX(int mapX) { return mapX * MAP_SIZE; }
int Stage::MapPointY(int mapY) { return mapY * MAP_SIZE; }

//描画
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

int Stage::getMap(int Y,int X) {
	return MapData[Y][X];
}

void Stage::DrawMapImage() {
	DrawGraph(DRAW_POINT_X + 90, DRAW_POINT_Y + 90, image.g_StageImagePx[0], TRUE);
	for (int i = 0; i < 8; i++) {
		DrawGraph(DRAW_POINT_X + 120 + (MAP_SIZE * i), DRAW_POINT_Y + 90, image.g_StageImagePx[1], TRUE);
	}
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9), DRAW_POINT_Y + 90, image.g_StageImagePx[1], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 108, image.g_StageImagePx[33], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 11), DRAW_POINT_Y + 90, image.g_StageImagePx[26], TRUE);
	for (int i = 0; i < 9; i++) {
		DrawGraph(DRAW_POINT_X +90 + (MAP_SIZE * i) + (MAP_SIZE * 11), DRAW_POINT_Y + 90, image.g_StageImagePx[1], TRUE);
	}
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9) + (MAP_SIZE * 11), DRAW_POINT_Y + 90, image.g_StageImagePx[2], TRUE);
	for (int i = 0; i < 5; i++) {
		DrawGraph(DRAW_POINT_X + 90, DRAW_POINT_Y + 120 + (MAP_SIZE * i), image.g_StageImagePx[7], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * i), image.g_StageImagePx[3], TRUE);
	}
	DrawGraph(DRAW_POINT_X + 90, DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[6], TRUE);
	DrawGraph(DRAW_POINT_X + 120, DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[5], TRUE);
	DrawGraph(DRAW_POINT_X + 150, DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[5], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[5], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 19), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[5], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[4], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[38], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 6), image.g_StageImagePx[7], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[7], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[1], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 19), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[1], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[1], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[40], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[39], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[1], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 1), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[1], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[1], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[37], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 6), image.g_StageImagePx[3], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[3], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[8], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[21], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[8], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[21], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[8], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 6), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[21], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[8], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 14), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[21], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[8], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[21], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[8], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[21], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 0), image.g_StageImagePx[24], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[22], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[20], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 4), image.g_StageImagePx[24], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[19], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 6), image.g_StageImagePx[24], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[24], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[22], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 6), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[21], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[20], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 4), image.g_StageImagePx[24], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[17], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 6), image.g_StageImagePx[24], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[24], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[22], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 14), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[8], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[8], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[9], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 11), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[21], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 4), image.g_StageImagePx[24], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[22], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[14], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[15], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[15], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[10], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 11), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[15], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[15], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[11], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[47], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 9), image.g_StageImagePx[47], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[47], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[13], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[45], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 9), image.g_StageImagePx[45], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[45], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[12], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[46], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[46], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[46], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 11), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[46], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[46], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[38], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[5], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 1), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[5], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[5], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[7], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 12), image.g_StageImagePx[7], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[39], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[1], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 1), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[1], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[0], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[20], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[24], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 12), image.g_StageImagePx[24], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[22], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[20], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[24], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 12), image.g_StageImagePx[24], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[22], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[5], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 19), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[5], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[5], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[37], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[3], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 12), image.g_StageImagePx[3], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[40], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[1], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 19), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[1], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[2], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 14), image.g_StageImagePx[7], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[7], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 16), image.g_StageImagePx[7], TRUE);
	
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 18), image.g_StageImagePx[7], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[7], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 20), image.g_StageImagePx[7], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 21), image.g_StageImagePx[6], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 1), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[21], TRUE);
	DrawGraph(DRAW_POINT_X + 108 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[36], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[8], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[9], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 11), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[21], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 14), image.g_StageImagePx[24], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[22], TRUE);


	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[8], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[41], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 16), image.g_StageImagePx[24], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[22], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[21], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[44], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 16), image.g_StageImagePx[24], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[22], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[8], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 6), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[21], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[8], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 14), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[21], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[8], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[9], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 11), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[21], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 18), image.g_StageImagePx[24], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[22], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[8], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 4), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[18], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 6), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[21], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 18), image.g_StageImagePx[24], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[20], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[8], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 14), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[18], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 16), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[16], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[21], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 18), image.g_StageImagePx[24], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[20], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 14), image.g_StageImagePx[3], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[3], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 16), image.g_StageImagePx[3], TRUE);
	
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 18), image.g_StageImagePx[3], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[3], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 20), image.g_StageImagePx[3], TRUE);
	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 21), image.g_StageImagePx[4], TRUE);

	DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 19), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[8], TRUE);
	DrawGraph(DRAW_POINT_X + 72 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[34], TRUE);

	for (int i = 0;i < 19;i++) {
		DrawGraph(DRAW_POINT_X + 120 + (MAP_SIZE * i), DRAW_POINT_Y + 120 + (MAP_SIZE * 21), image.g_StageImagePx[5], TRUE);
	}


}

void Stage::flashingMapImage() {
	if (Timer++ < 20) {//Map(青)
		DrawGraph(DRAW_POINT_X + 90, DRAW_POINT_Y + 90, image.g_StageImagePx[0], TRUE);
		for (int i = 0; i < 8; i++) {
			DrawGraph(DRAW_POINT_X + 120 + (MAP_SIZE * i), DRAW_POINT_Y + 90, image.g_StageImagePx[1], TRUE);
		}
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9), DRAW_POINT_Y + 90, image.g_StageImagePx[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 108, image.g_StageImagePx[33], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 11), DRAW_POINT_Y + 90, image.g_StageImagePx[26], TRUE);
		for (int i = 0; i < 9; i++) {
			DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * i) + (MAP_SIZE * 11), DRAW_POINT_Y + 90, image.g_StageImagePx[1], TRUE);
		}
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9) + (MAP_SIZE * 11), DRAW_POINT_Y + 90, image.g_StageImagePx[2], TRUE);
		for (int i = 0; i < 5; i++) {
			DrawGraph(DRAW_POINT_X + 90, DRAW_POINT_Y + 120 + (MAP_SIZE * i), image.g_StageImagePx[7], TRUE);
			DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * i), image.g_StageImagePx[3], TRUE);
		}
		DrawGraph(DRAW_POINT_X + 90, DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[6], TRUE);
		DrawGraph(DRAW_POINT_X + 120, DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[5], TRUE);
		DrawGraph(DRAW_POINT_X + 150, DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[5], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[5], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 19), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[5], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[4], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[38], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 6), image.g_StageImagePx[7], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[7], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 19), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[40], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[39], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 1), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[1], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[37], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 6), image.g_StageImagePx[3], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[3], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 6), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 14), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 0), image.g_StageImagePx[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePx[22], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[20], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 4), image.g_StageImagePx[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[19], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 6), image.g_StageImagePx[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[22], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 6), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[20], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 4), image.g_StageImagePx[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[17], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 6), image.g_StageImagePx[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[22], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 14), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[8], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[9], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 11), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePx[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 4), image.g_StageImagePx[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePx[22], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[14], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[15], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[15], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[10], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 11), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[15], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[15], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePx[11], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[47], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 9), image.g_StageImagePx[47], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[47], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[13], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePx[45], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 9), image.g_StageImagePx[45], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[45], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[12], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[46], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[46], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[46], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 11), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[46], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[46], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[38], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[5], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 1), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[5], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[5], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[7], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 12), image.g_StageImagePx[7], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[39], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 1), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[0], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[20], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 12), image.g_StageImagePx[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[22], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[20], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 12), image.g_StageImagePx[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[22], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[5], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 19), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[5], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[5], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePx[37], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePx[3], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 12), image.g_StageImagePx[3], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[40], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 19), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[2], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 14), image.g_StageImagePx[7], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[7], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 16), image.g_StageImagePx[7], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 18), image.g_StageImagePx[7], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[7], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 20), image.g_StageImagePx[7], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 21), image.g_StageImagePx[6], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 1), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[21], TRUE);
		DrawGraph(DRAW_POINT_X + 108 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[36], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[9], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 11), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePx[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 14), image.g_StageImagePx[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[22], TRUE);


		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[41], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 16), image.g_StageImagePx[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[22], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[21], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[44], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 16), image.g_StageImagePx[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[22], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 6), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 14), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[9], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 11), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 18), image.g_StageImagePx[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[22], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 4), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[18], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 6), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 18), image.g_StageImagePx[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[20], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 14), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[18], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 16), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 18), image.g_StageImagePx[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[20], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 14), image.g_StageImagePx[3], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePx[3], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 16), image.g_StageImagePx[3], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 18), image.g_StageImagePx[3], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePx[3], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 20), image.g_StageImagePx[3], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 21), image.g_StageImagePx[4], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 19), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[8], TRUE);
		DrawGraph(DRAW_POINT_X + 72 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePx[34], TRUE);

		for (int i = 0;i < 19;i++) {
			DrawGraph(DRAW_POINT_X + 120 + (MAP_SIZE * i), DRAW_POINT_Y + 120 + (MAP_SIZE * 21), image.g_StageImagePx[5], TRUE);
		}
	}else if(Timer < 40){//Map(白)
		DrawGraph(DRAW_POINT_X + 90, DRAW_POINT_Y + 90, image.g_StageImagePxW[0], TRUE);
		for (int i = 0; i < 8; i++) {
			DrawGraph(DRAW_POINT_X + 120 + (MAP_SIZE * i), DRAW_POINT_Y + 90, image.g_StageImagePxW[1], TRUE);
		}
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9), DRAW_POINT_Y + 90, image.g_StageImagePxW[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 108, image.g_StageImagePxW[33], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 11), DRAW_POINT_Y + 90, image.g_StageImagePxW[26], TRUE);
		for (int i = 0; i < 9; i++) {
			DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * i) + (MAP_SIZE * 11), DRAW_POINT_Y + 90, image.g_StageImagePxW[1], TRUE);
		}
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9) + (MAP_SIZE * 11), DRAW_POINT_Y + 90, image.g_StageImagePxW[2], TRUE);
		for (int i = 0; i < 5; i++) {
			DrawGraph(DRAW_POINT_X + 90, DRAW_POINT_Y + 120 + (MAP_SIZE * i), image.g_StageImagePxW[7], TRUE);
			DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * i), image.g_StageImagePxW[3], TRUE);
		}
		DrawGraph(DRAW_POINT_X + 90, DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePxW[6], TRUE);
		DrawGraph(DRAW_POINT_X + 120, DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePxW[5], TRUE);
		DrawGraph(DRAW_POINT_X + 150, DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePxW[5], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePxW[5], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 19), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePxW[5], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePxW[4], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePxW[38], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 6), image.g_StageImagePxW[7], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePxW[7], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePxW[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 19), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePxW[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePxW[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePxW[40], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePxW[39], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePxW[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 1), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePxW[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePxW[1], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePxW[37], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 6), image.g_StageImagePxW[3], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePxW[3], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePxW[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePxW[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePxW[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePxW[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePxW[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 6), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePxW[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePxW[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 14), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePxW[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePxW[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePxW[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePxW[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePxW[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 0), image.g_StageImagePxW[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 1), image.g_StageImagePxW[22], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePxW[20], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 4), image.g_StageImagePxW[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePxW[19], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 6), image.g_StageImagePxW[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePxW[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePxW[22], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 6), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePxW[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePxW[20], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 4), image.g_StageImagePxW[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePxW[17], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 6), image.g_StageImagePxW[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePxW[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePxW[22], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 14), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePxW[8], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePxW[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePxW[9], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 11), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 3), image.g_StageImagePxW[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 4), image.g_StageImagePxW[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 5), image.g_StageImagePxW[22], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePxW[14], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePxW[15], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePxW[15], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePxW[10], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 11), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePxW[15], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePxW[15], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 7), image.g_StageImagePxW[11], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePxW[47], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 9), image.g_StageImagePxW[47], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePxW[47], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePxW[13], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 8), image.g_StageImagePxW[45], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 9), image.g_StageImagePxW[45], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePxW[45], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePxW[12], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePxW[46], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePxW[46], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePxW[46], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 11), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePxW[46], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePxW[46], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePxW[38], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePxW[5], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 1), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePxW[5], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePxW[5], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePxW[7], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 12), image.g_StageImagePxW[7], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePxW[39], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePxW[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 1), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePxW[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePxW[0], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePxW[20], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePxW[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 12), image.g_StageImagePxW[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePxW[22], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePxW[20], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePxW[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 12), image.g_StageImagePxW[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePxW[22], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePxW[5], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 19), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePxW[5], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePxW[5], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 10), image.g_StageImagePxW[37], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 11), image.g_StageImagePxW[3], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 12), image.g_StageImagePxW[3], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePxW[40], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePxW[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 19), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePxW[1], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePxW[2], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 14), image.g_StageImagePxW[7], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePxW[7], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 16), image.g_StageImagePxW[7], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 18), image.g_StageImagePxW[7], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePxW[7], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 20), image.g_StageImagePxW[7], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 21), image.g_StageImagePxW[6], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 1), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePxW[21], TRUE);
		DrawGraph(DRAW_POINT_X + 108 + (MAP_SIZE * 0), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePxW[36], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePxW[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePxW[9], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 11), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 13), image.g_StageImagePxW[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 14), image.g_StageImagePxW[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePxW[22], TRUE);


		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePxW[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePxW[41], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 16), image.g_StageImagePxW[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePxW[22], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePxW[21], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePxW[44], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 16), image.g_StageImagePxW[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePxW[22], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePxW[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 6), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePxW[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePxW[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 14), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePxW[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePxW[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 9), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePxW[9], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 11), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePxW[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 18), image.g_StageImagePxW[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 10), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePxW[22], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 2), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePxW[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 3), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 4), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePxW[18], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 6), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 7), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 8), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePxW[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 18), image.g_StageImagePxW[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 5), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePxW[20], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 12), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePxW[8], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 13), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 14), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePxW[18], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 16), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 17), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePxW[16], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 18), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePxW[21], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 18), image.g_StageImagePxW[24], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 15), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePxW[20], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 14), image.g_StageImagePxW[3], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 15), image.g_StageImagePxW[3], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 16), image.g_StageImagePxW[3], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 18), image.g_StageImagePxW[3], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 19), image.g_StageImagePxW[3], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 20), image.g_StageImagePxW[3], TRUE);
		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 21), image.g_StageImagePxW[4], TRUE);

		DrawGraph(DRAW_POINT_X + 90 + (MAP_SIZE * 19), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePxW[8], TRUE);
		DrawGraph(DRAW_POINT_X + 72 + (MAP_SIZE * 20), DRAW_POINT_Y + 120 + (MAP_SIZE * 17), image.g_StageImagePxW[34], TRUE);

		for (int i = 0;i < 19;i++) {
			DrawGraph(DRAW_POINT_X + 120 + (MAP_SIZE * i), DRAW_POINT_Y + 120 + (MAP_SIZE * 21), image.g_StageImagePxW[5], TRUE);
		}
	}
	else {
		Timer = 0;
	}
}

void Stage::DrawMapImageV3() {
	DrawGraph(DRAW_POINT_X + 90, DRAW_POINT_Y + 105, image.g_StageImageV3, TRUE);
}

void Stage::flashingMapImageV3() {
	if (Timer++ < 20) {//Map(青)
		DrawGraph(DRAW_POINT_X + 90, DRAW_POINT_Y + 105, image.g_StageImageV3, TRUE);
	}
	else if (Timer < 40) {//Map(白)
		DrawGraph(DRAW_POINT_X + 90, DRAW_POINT_Y + 105, image.g_StageImageV3_W, TRUE);
	}
	else {
		Timer = 0;
	}
}
#include "DxLib.h"
#include "Stage.h"

Stage stage;

Stage::Stage()
{
	
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

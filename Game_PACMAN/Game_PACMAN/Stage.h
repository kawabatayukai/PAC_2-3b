#pragma once
#include"Info.h"

class Stage
{
public:
	Stage();

	int MapPointX(int mapX);  //map上の"〇マス目"をウィンドウ上の座標に変換
	int MapPointY(int mapY);
	void DrawMap();           //描画
    int getMap(int Y,int X);

private:

	//Mapデータ[29][27]  
	int MapData[MAP_HEIGHT][MAP_WIDTH] =
	{
		/*{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
        {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
        {1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        {1,0,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,},
        {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,},
        {1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,},
        {0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,},
        {0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,0,0,},
        {1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,},
        {0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,},
        {1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,},
        {0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,0,0,},
        {0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,},
        {1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,},
        {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
        {1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,},
        {1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,},
        {1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,},
        {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,},
        {1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},*/


        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
        {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,},
        {0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,},
        {0,0,0,1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,0,0,},
        {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,},
        {0,0,0,1,0,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,0,0,0,},
        {0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,},
        {0,0,0,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,0,0,0,},
        {0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,},
        {0,0,0,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,0,0,0,0,0,},
        {0,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,0,0,0,},
        {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
        {0,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,0,0,0,},
        {0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,0,0,},
        {0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,},
        {0,0,0,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,0,0,0,},
        {0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,},
        {0,0,0,1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,0,0,},
        {0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,},
        {0,0,0,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,0,0,0,},
        {0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,},
        {0,0,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,0,0,},
        {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,},
        {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	};
};
extern Stage stage;
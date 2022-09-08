#include"DxLib.h"
#include"Enemy.h"
#include"Sound.h"

//壁より内側　限界点  ※描画上ではDRAW_POINT_X(Y)が加算された座標 　"ピンク"の目標座標はステージ外になることがある
const int L_END = MAP_SIZE;
const int R_END = MAP_SIZE * (MAP_WIDTH - 1);
const int U_END = MAP_SIZE;
const int D_END = MAP_SIZE * (MAP_HEIGHT - 1);

//移動による画像チェンジ ～2枚の画像を交互に～
void ENEMY_BASE::ChangeMoveImages()
{
	//画像配列enemyimage
	//左向き 0,1　右向き 2,3　上向き 4,5　下向き 6,7

	int std = 0;  //基準となる画像No 　std と std+1 を交互に切り替える

	switch (MoveDir)
	{
	case DIRECTION::LEFT:

		if (g_enemy.img != 0 && g_enemy.img != 1) g_enemy.img = 0; //左向き画像でなければ、左向き画像にチェンジ
		std = 0; //基準をセット
		break;

	case DIRECTION::RIGHT:

		if (g_enemy.img != 2 && g_enemy.img != 3) g_enemy.img = 2; //右向き画像でなければ、右向き画像にチェンジ
		std = 2; //基準をセット
		break;

	case DIRECTION::UP:

		if (g_enemy.img != 4 && g_enemy.img != 5) g_enemy.img = 4; //上向き画像でなければ、上向き画像にチェンジ
		std = 4; //基準をセット
		break;

	case DIRECTION::DOWN:

		if (g_enemy.img != 6 && g_enemy.img != 7) g_enemy.img = 6; //下向き画像でなければ、下向き画像にチェンジ
		std = 6; //基準をセット
		break;

	case DIRECTION::NONE:

		std = 0;
	default:
		break;
	}

	//5フレーム毎に画像切り替え
	if (MoveCount % 5 == 0)
	{
		if (g_enemy.img == std)
		{
			g_enemy.img = std + 1;  //画像n0の時,画像n1に
			MoveCount = 0;
		}
		else if (g_enemy.img = std + 1)
		{
			g_enemy.img = std;      //画像n1の時,画像n0に
			MoveCount = 0;
		}
	}
}


//ターゲットまでの最短経路を探す
//             ターゲットの位置を"ｎ"とし、離れるにつれｎを加算
//             引数tx,tyはマップ上座標  呼び出しで"/MAP_SIZE"
void ENEMY_BASE::search(int tx, int ty, int b)
{
	int n = b;
	n += 1;

	//左
	if (my_mapdata[ty][tx - 1] == 0 || my_mapdata[ty][tx - 1] >= n)
	{
		my_mapdata[ty][tx - 1] = n;
		search(tx - 1, ty, n);
	}
	//右
	if (my_mapdata[ty][tx + 1] == 0 || my_mapdata[ty][tx + 1] >= n)
	{
		my_mapdata[ty][tx + 1] = n;
		search(tx + 1, ty, n);
	}
	//上
	if (my_mapdata[ty - 1][tx] == 0 || my_mapdata[ty - 1][tx] >= n)
	{
		my_mapdata[ty - 1][tx] = n;
		search(tx, ty - 1, n);
	}
	//下
	if (my_mapdata[ty + 1][tx] == 0 || my_mapdata[ty + 1][tx] >= n)
	{
		my_mapdata[ty + 1][tx] = n;
		search(tx, ty + 1, n);
	}

	return;
}

//最短経路を探す準備
void ENEMY_BASE::moveDataSet(int MapData[MAP_HEIGHT][MAP_WIDTH], int targetX, int targetY)
{
	//経路探索用mapの初期化
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if (MapData[i][j] != 1) my_mapdata[i][j] = 0;
			else my_mapdata[i][j] = 1;
		}
	}

	//ターゲット座標がステージ外の場合、ステージ内に戻す
	if (targetX < L_END) targetX = L_END + 1;
	if (targetX > R_END) targetX = R_END - 1;
	if (targetY < U_END) targetY = U_END + 1;
	if (targetY > D_END) targetY = D_END - 1;

	//マップ上のターゲットの位置に目印(10)をセット
	my_mapdata[targetY / MAP_SIZE][targetX / MAP_SIZE] = 10;

	//"10"を基準に、最短経路を探す
	search((targetX / MAP_SIZE), (targetY / MAP_SIZE), 10);
}

//ターゲットの位置に最短経路で移動する
void ENEMY_BASE::MoveShortest(int MapData[MAP_HEIGHT][MAP_WIDTH], int targetX, int targetY)
{
	//経路探索用mapの初期化・ターゲットの位置を設定
	moveDataSet(MapData, targetX, targetY);

	//敵の(map上の)座標
	int Mx = g_enemy.x / MAP_SIZE;
	int My = g_enemy.y / MAP_SIZE;

	//左
	if (MapData[My][Mx - 1] != 1 && my_mapdata[My][Mx - 1] < my_mapdata[My][Mx])
	{
		MoveDir = DIRECTION::LEFT;
		g_enemy.x -= g_enemy.speed;
		sound.PlayMoveSounds();
	}
	//右
	else if (MapData[My][Mx + 1] != 1 && my_mapdata[My][Mx + 1] < my_mapdata[My][Mx])
	{
		MoveDir = DIRECTION::RIGHT;
		g_enemy.x += g_enemy.speed;
		sound.PlayMoveSounds();
	}
	//上
	else if (MapData[My - 1][Mx] != 1 && my_mapdata[My - 1][Mx] < my_mapdata[My][Mx])
	{
		MoveDir = DIRECTION::UP;
		g_enemy.y -= g_enemy.speed;
		sound.PlayMoveSounds();
	}
	//下
	else if (MapData[My + 1][Mx] != 1 && my_mapdata[My + 1][Mx] < my_mapdata[My][Mx])
	{
		MoveDir = DIRECTION::DOWN;
		g_enemy.y += g_enemy.speed;
		sound.PlayMoveSounds();
	}

	//めり込ませない
	int x1, x2, y1, y2;
	x1 = (g_enemy.x - (g_enemy.w / 2) + 1);
	x2 = (g_enemy.x + (g_enemy.w / 2) - 1);
	y1 = (g_enemy.y - (g_enemy.h / 2) + 1);
	y2 = (g_enemy.y + (g_enemy.h / 2) - 1);

	if (MapData[My][Mx - 1] == 1)
	{
		if ((Mx - 1) * MAP_SIZE + MAP_SIZE > x1) g_enemy.x = (Mx - 1) * MAP_SIZE + MAP_SIZE + g_enemy.w / 2;
	}
	if (MapData[My][Mx + 1] == 1)
	{
		if ((Mx + 1) * MAP_SIZE < x2) g_enemy.x = (Mx + 1) * MAP_SIZE - g_enemy.w / 2;
	}
	if (MapData[My - 1][Mx] == 1)
	{
		if ((My - 1) * MAP_SIZE + MAP_SIZE > y1) g_enemy.y = (My - 1) * MAP_SIZE + MAP_SIZE + g_enemy.w / 2;
	}
	if (MapData[My + 1][Mx] == 1)
	{
		if ((My + 1) * MAP_SIZE < y2) g_enemy.y = (My + 1) * MAP_SIZE - g_enemy.w / 2;
	}
}

//巡回モード用
int ENEMY_BASE::CheckTarget2()
{
	int ex1 = g_enemy.x - (g_enemy.w / 2); //左
	int ex2 = g_enemy.x + (g_enemy.w / 2); //右
	int ey1 = g_enemy.y - (g_enemy.h / 2); //上
	int ey2 = g_enemy.y + (g_enemy.h / 2); //下

	int tx1 = MoveTarget.x - (MAP_SIZE / 2);
	int tx2 = MoveTarget.x + (MAP_SIZE / 2);
	int ty1 = MoveTarget.y - (MAP_SIZE / 2);
	int ty2 = MoveTarget.y + (MAP_SIZE / 2);

	//if(MoveTarget.x-15<g_enemy.x&&)
	if (ex1 < tx2 && tx1 < ex2 && ey1 < ty2 && ty1 < ey2)
	{
		return 3;
	}
	else return 0;
}
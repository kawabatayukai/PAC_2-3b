#include"DxLib.h"
#include"Enemy.h"
#include"Orange.h"
#include "Info.h"

ENEMY_ORANGE Orange;

//コンストラクタ  ENEMY_BASEのコンストラクタで "My_Color" を設定
ENEMY_ORANGE::ENEMY_ORANGE() : ENEMY_BASE(ENEMY_COLOR::ORANGE)
{
}

//画像読み込み
int ENEMY_ORANGE::Loadimages()
{
	//分割読み込み
	if ((LoadDivGraph("images/All_Orange30.png", 16, 4, 4, 30, 30, enemyimage)) == -1) return -1;   //30 　ｲｼﾞｹ・目を含む
}

//初期処理
void ENEMY_ORANGE::InitEnemy()
{
	g_enemy.flg = true;
	//g_enemy.x = 12 * MAP_SIZE + (MAP_SIZE / 2); //巣の中
	//g_enemy.y = 10 * MAP_SIZE + (MAP_SIZE / 2); //巣の中

	g_enemy.x = 15 * MAP_SIZE + (MAP_SIZE / 2); //巣の中
	g_enemy.y = 13 * MAP_SIZE + (MAP_SIZE / 2); //巣の中

	g_enemy.w = E_WIDTH;
	g_enemy.h = E_HEIGHT;
	g_enemy.speed = 3;//p_speed[0];
	//g_enemy.speed = GetRand(4) + 1;
	g_enemy.img = 0;

	//移動なし
	MoveDir = (int)DIRECTION::DOWN;

	//移動目標初期化
	MoveTarget = { 0,0 };

	//モード
	EnemyMode = MODE::STANDBY;
	//モードチェンジ用カウンター
	mode_count = 0;
	//イジケナシ
	ijike_flg = false;

	if (sortie_flg == true)sortie_flg = false;
}

//移動
void ENEMY_ORANGE::MoveEnemy(int MapData[MAP_HEIGHT][MAP_WIDTH])
{
	//移動による画像変化
	ChangeMoveImages();

	//ターゲットとの距離を縮める
	//壁にぶつかると方向転換

	int Tx = MoveTarget.x;    //追跡対象X　　　追跡モードのみ
	int Ty = MoveTarget.y;    //   〃　 Y

	int Mx = g_enemy.x / MAP_SIZE;
	int My = g_enemy.y / MAP_SIZE;

	int Lx = (g_enemy.x - (g_enemy.w / 2));
	int Rx = (g_enemy.x + (g_enemy.w / 2));
	int Uy = (g_enemy.y - (g_enemy.h / 2));
	int Dy = (g_enemy.y + (g_enemy.h / 2));

	bool hitX = false;  //X軸の一致 ｱﾘ・ﾅｼ
	bool hitY = false;  //Y軸の一致 ｱﾘ・ﾅｼ

	//敵の座標と目標座標の差（difference）
	int dx = g_enemy.x - MoveTarget.x;
	int dy = g_enemy.y - MoveTarget.y;

	//x,y方向の差を比較、大きく離れている方を優先  絶対値で

	//x方向を合わせる
	if (abs(dx) > abs(dy))
	{
		if (dx > 0) //目標が自分より左側
		{
			if (MapData[My][Mx - 1] != 1) MoveDir = DIRECTION::LEFT;
		}
		if (dx < 0) //目標が自分より右側
		{
			if (MapData[My][Mx + 1] != 1) MoveDir = DIRECTION::RIGHT;
		}
		//壁がある場合はY方向に移動する
		if (MapData[My][Mx - 1] == 1 || MapData[My][Mx + 1] == 1)
		{
			if (dy > 0) //目標が自分より上側
			{
				if (MapData[My - 1][Mx] != 1) MoveDir = DIRECTION::UP;
			}

			if (dy < 0) //目標が自分より下側
			{
				if (MapData[My + 1][Mx] != 1) MoveDir = DIRECTION::DOWN;
			}
		}
	}
	else
	{
		if (dy > 0) //目標が自分より上側
		{
			if (MapData[My - 1][Mx] != 1) MoveDir = DIRECTION::UP;
		}
		if (dy < 0) //目標が自分より下側
		{
			if (MapData[My + 1][Mx] != 1) MoveDir = DIRECTION::DOWN;
		}
		//壁がある場合はX方向に移動する
		if (MapData[My - 1][Mx] == 1 || MapData[My + 1][Mx] == 1)
		{
			if (dx > 0) //目標が自分より左側
			{
				if (MapData[My][Mx - 1] != 1) MoveDir = DIRECTION::LEFT;
			}
			if (dx < 0) //目標が自分より右側
			{
				if (MapData[My][Mx + 1] != 1) MoveDir = DIRECTION::RIGHT;
			}
		}
	}



	{
		if (MoveDir == DIRECTION::LEFT && Tx != g_enemy.x)
		{
			if (MapData[My][Lx / MAP_SIZE] != 1) g_enemy.x -= g_enemy.speed;

		}
		if (MoveDir == DIRECTION::RIGHT && Tx != g_enemy.x)
		{
			if (MapData[My][Rx / MAP_SIZE] != 1) g_enemy.x += g_enemy.speed;

		}
		if (MoveDir == DIRECTION::UP && Ty != g_enemy.y)
		{
			if (MapData[Uy / MAP_SIZE][Mx] != 1) g_enemy.y -= g_enemy.speed;

		}
		if (MoveDir == DIRECTION::DOWN && Ty != g_enemy.y)
		{
			if (MapData[Dy / MAP_SIZE][Mx] != 1) g_enemy.y += g_enemy.speed;

		}
	}

	//めり込ませない
	int x1, x2, y1, y2;
	x1 = (g_enemy.x - (g_enemy.w / 2));
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

//テスト
void ENEMY_ORANGE::MoveEnemy2(int MapData[MAP_HEIGHT][MAP_WIDTH])
{
	//移動による画像変化
	//MoveCount++;
	ChangeMoveImages();

	if (EnemyMode == MODE::STANDBY)
	{
		MoveEnemy(MapData);
	}
	else if (EnemyMode == MODE::TRACK || EnemyMode == MODE::PATROL || EnemyMode == MODE::EYE || EnemyMode == MODE::IJIKE)
	{
		if (EnemyMode == MODE::TRACK) {
			EnemyController();
		}
		else {
			MoveShortest(MapData, MoveTarget.x, MoveTarget.y);
		}
	}

}

//描画
void ENEMY_ORANGE::DrawEnemy()
{
	//テスト　目標位置
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 128);
	DrawCircle(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + DRAW_POINT_Y, 8, 0xff00ff, TRUE);

	//テスト　目標〜敵間
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 200);
	DrawLine(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + DRAW_POINT_Y, g_enemy.x + DRAW_POINT_X, g_enemy.y + DRAW_POINT_Y, 0x00ffff);
	DrawLine(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + DRAW_POINT_Y, MoveTarget.x + DRAW_POINT_X, MoveTarget.y + (g_enemy.y - MoveTarget.y) + DRAW_POINT_Y, 0x00ffff);
	DrawLine(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + (g_enemy.y - MoveTarget.y) + DRAW_POINT_Y, g_enemy.x + DRAW_POINT_X, g_enemy.y + DRAW_POINT_Y, 0x00ffff);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (g_enemy.flg == true)
	{
		//シンプル描画
		DrawRotaGraph(g_enemy.x + DRAW_POINT_X, g_enemy.y + DRAW_POINT_Y, 1.0, 0, enemyimage[g_enemy.img], TRUE);
	}

	//テスト　


}


//移動目標との一致　戻り値　0：x,y座標共に一致ﾅｼ　 1：x座標のみ一致  2：y座標のみ一致　　3:x,y座標共に一致 
int ENEMY_ORANGE::CheckTarget()
{
	if (MoveTarget.x == g_enemy.x && MoveTarget.y != g_enemy.y) return 1;       //x座標のみ一致
	else if (MoveTarget.x != g_enemy.x && MoveTarget.y == g_enemy.y) return 2;  //y座標のみ一致
	else if (MoveTarget.x == g_enemy.x && MoveTarget.y == g_enemy.y) return 3;  //x,y座標共に一致
	else if (MoveTarget.x != g_enemy.x && MoveTarget.y != g_enemy.y) return 0;  //x,y座標共に一致ﾅｼ
}

//ターゲット設定  引数:プレイヤーの座標
void ENEMY_ORANGE::TargetCtrl(int tpX, int tpY, int tpD)
{
	M_POINT Point = { 0,0 };

	//イジケ
	//if (ijike_flg == true) EnemyMode = MODE::IJIKE;

	static int order = 0;
	static int oldmode;

	switch (EnemyMode)
	{
	case MODE::STANDBY:           //出撃前　

		if (sortie_flg == false)     //出撃不可
		{
			////上下に往復
			//if (CheckTarget() == 3 && g_enemy.y == 285) MoveTarget.y = 345;      //下部
			//else if (CheckTarget() == 3 && g_enemy.y == 345) MoveTarget.y = 285; //上部
			//else if (CheckTarget() == 0) MoveTarget = { 375,285 };               //初期位置

			//上下に往復
			if (CheckTarget() == 3 && g_enemy.y == 375) MoveTarget.y = 435;      //下部
			else if (CheckTarget() == 3 && g_enemy.y == 435) MoveTarget.y = 375; //上部
			else if (CheckTarget() == 0) MoveTarget = { 465,375 };               //初期位置
		}
		else if (sortie_flg == true) //出撃可
		{
			MoveTarget = { 405,315 };  //巣の入口上 (巣から出撃)
			if (g_enemy.x == 405 && g_enemy.y == 315) EnemyMode = MODE::PATROL;  //移動完了後、巡回モードに切り替え
		}
		//else if (sortie_flg == true) //出撃可
		//{
		//	MoveTarget = { 315,225 };  //巣の入口上 (巣から出撃)
		//	if (g_enemy.x == 315 && g_enemy.y == 225) EnemyMode = MODE::PATROL;  //移動完了後、巡回モードに切り替え
		//}
		break;

	case MODE::PATROL:            //巡回モード

		////左上座標
		//Point = { 19*MAP_SIZE * 1 + (MAP_SIZE / 2) ,MAP_SIZE * 1 + (MAP_SIZE / 2) };
		//MoveTarget = Point;

		//左上座標
		Point = { PtrlPoint[3][order][0] ,PtrlPoint[3][order][1] };
		MoveTarget = Point;


		if (CheckTarget3() == 3)
		{
			order++;
			if (order == 4) order = 0;
		}
		Point = { PtrlPoint[3][order][0] ,PtrlPoint[3][order][1] };

		//現在のモードを保持
		oldmode = EnemyMode;

		MoveTarget = Point;

		//8秒で追跡モードに切り替え
		if (++mode_count % 480 == 0)
		{
			mode_count = 0;
			EnemyMode = MODE::TRACK;
		}
		break;

	case MODE::TRACK:             //追跡モード

		//現在の進行方向 +3マス
		Point = { tpX ,tpY };

		//static int mode;



		//if (mode == 0)
		//{
		//	//3秒間
		//	if (++tracktime < 180)
		//	{
		//		Point = { 45,645 };
		//	}
		//	if (tracktime == 180)
		//	{
		//		tracktime = 0;
		//		mode = 1;
		//	}
		//	if ((abs(g_enemy.x - tpX) / MAP_SIZE) > 4) Point.x = tpX;
		//	else if ((abs(g_enemy.y - tpY) / MAP_SIZE) > 4) Point.y = tpY;
		//	else if ((abs(g_enemy.x - tpX) / MAP_SIZE) <= 5 && (abs(g_enemy.y - tpY) / MAP_SIZE) <= 5) mode = 1;
		//}
		//else if (mode == 1)
		//{
		//	//3秒間
		//	if (++tracktime < 180)
		//	{
		//		Point = { 45,645 };
		//	}
		//	if (tracktime == 180)
		//	{
		//		tracktime = 0;
		//		mode = 0;
		//	}
		//}

		/*if ((abs(g_enemy.x - tpX) / MAP_SIZE) > 4) Point.x = tpX;
		else if ((abs(g_enemy.y - tpY) / MAP_SIZE) > 4) Point.y = tpY;
		else if ((abs(g_enemy.x - tpX) / MAP_SIZE) <= 5 && (abs(g_enemy.y - tpY) / MAP_SIZE) <= 5) Point = { 45,645 };*/

		MoveTarget.x = Point.x;
		MoveTarget.y = Point.y;

		//現在のモードを保持
		oldmode = EnemyMode;

		//20秒で巡回モードに切り替え
		if (++mode_count % 1200 == 0)
		{
			mode_count = 0;
			EnemyMode = MODE::PATROL;
		}
		break;

	case MODE::IJIKE:       //イジケ時
//Point.x = tpX + (MAP_SIZE * ((GetRand(4) + 1) * 3));
//Point.y = tpY + (MAP_SIZE * ((GetRand(4) + 1) * 3));

//if (ijike_flg == false) EnemyMode = oldmode;

		//とりあえず巡回モード一番目
		Point = { PtrlPoint[3][order][0] ,PtrlPoint[3][order][1] };
		MoveTarget = Point;
		if (ijike_flg == false) EnemyMode = oldmode;

		break;
	case MODE::RANDOM:
		Point.x = 1;
		Point.y = 1;
		if (g_enemy.x == MoveTarget.x && g_enemy.y == MoveTarget.y)
		{
			Point.x = GetRand(18) + 1;
			Point.y = GetRand(20) + 1;
		}

		MoveTarget.x = (Point.x * MAP_SIZE) + DRAW_POINT_X;
		MoveTarget.y = (Point.y * MAP_SIZE) + DRAW_POINT_Y;

	default:
		break;
	}

}

//敵の挙動(モードによって変化  出撃前/巡回/追跡)
void ENEMY_ORANGE::EnemyControl()
{
	switch (EnemyMode)
	{
		//出撃前
	case MODE::STANDBY:
		break;

		//巡回
	case MODE::PATROL:
		break;

		//追跡
	case MODE::TRACK:
		break;

	default:
		break;
	}
}

//出撃前の挙動
void ENEMY_ORANGE::Move_StandBy()
{

}

//巡回モードの挙動
void ENEMY_ORANGE::Move_Patrol()
{

}

//追跡モードの挙動
void ENEMY_ORANGE::Move_Track()
{

}
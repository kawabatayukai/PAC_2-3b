#include"DxLib.h"
#include"Enemy.h"
#include"Pink.h"
#include "Info.h"

ENEMY_PINK Pink;

//テスト出力用
//char DirectStr[][6] = { "LEFT","RIGHT","UP","DOWN" ,"NONE" };
//char ModeStr[][8] = { "STANDBY","PATROL","TRACK" };

//左・右・上・下方向の座標差分
//const int Delta[][2] = { {-1,0},{1,0},{0,-1},{0,1} };

//画像読み込み
int ENEMY_PINK::Loadimages()
{
	//分割読み込み
	//if ((LoadDivGraph("images/All_Pink.png", 8, 4, 2, 14, 14, enemyimage)) == -1) return -1;   //14
	//if ((LoadDivGraph("images/All_Pink20.png", 8, 4, 2, 20, 20, enemyimage)) == -1) return -1; //20
	if ((LoadDivGraph("images/All_Pink30.png", 8, 4, 2, 30, 30, enemyimage)) == -1) return -1;   //30
	//if ((LoadDivGraph("images/All_PinkS30.png", 8, 4, 2, 30, 30, enemyimage)) == -1) return -1;   //30 　ｲｼﾞｹ・目を含む
}

//音源読み込み
int ENEMY_PINK::LoadSounds()
{
	if ((enemysounds = LoadSoundMem("sounds/Enemymove.mp3")) == -1) return -1;
}

//初期処理
void ENEMY_PINK::InitEnemy()
{
	g_enemy.flg = true;
	g_enemy.x = 8 * MAP_SIZE + (MAP_SIZE / 2); //巣の中
	g_enemy.y = 9 * MAP_SIZE + (MAP_SIZE / 2); //巣の中

	g_enemy.w = E_WIDTH;
	g_enemy.h = E_HEIGHT;
	g_enemy.speed = 3;//p_speed[0];
	g_enemy.img = 0;

	//移動なし
	MoveDir = (int)DIRECTION::NONE;

	//移動目標初期化
	MoveTarget = { 0,0 };

	//モード
	EnemyMode = MODE::STANDBY;
	//モードチェンジ用カウンター
	mode_count = 0;

	if (sortie_flg == true)sortie_flg = false;
}

//移動
void ENEMY_PINK::MoveEnemy(int MapData[MAP_HEIGHT][MAP_WIDTH])
{
	//移動による画像変化
	MoveCount++;
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
void ENEMY_PINK::MoveEnemy2(int MapData[MAP_HEIGHT][MAP_WIDTH])
{
	//移動による画像変化
	MoveCount++;
	ChangeMoveImages();

	if (EnemyMode == MODE::STANDBY)
	{
		MoveEnemy(MapData);
	}
	else if (EnemyMode == MODE::TRACK || EnemyMode == MODE::PATROL)
	{
		MoveShortest(MapData, MoveTarget.x, MoveTarget.y);
	}

}

//描画
void ENEMY_PINK::DrawEnemy()
{
	//テスト　目標位置
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 128);
	DrawCircle(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + DRAW_POINT_Y, 8, 0xff00ff, TRUE);

	//テスト　目標～敵間
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 200);
	DrawLine(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + DRAW_POINT_Y, g_enemy.x + DRAW_POINT_X, g_enemy.y + DRAW_POINT_Y, 0x00ffff);
	DrawLine(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + DRAW_POINT_Y, MoveTarget.x + DRAW_POINT_X, MoveTarget.y + (g_enemy.y - MoveTarget.y) + DRAW_POINT_Y, 0x00ffff);
	DrawLine(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + (g_enemy.y - MoveTarget.y) + DRAW_POINT_Y, g_enemy.x + DRAW_POINT_X, g_enemy.y + DRAW_POINT_Y, 0x00ffff);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (g_enemy.flg == true)
	{
		//シンプル描画
		DrawRotaGraph(g_enemy.x + DRAW_POINT_X, g_enemy.y + DRAW_POINT_Y, 1.0, 0, enemyimage[g_enemy.img], TRUE);

		//シンプル描画（描画点は左上）
		//DrawGraph(g_enemy.x, g_enemy.y, enemyimage[g_enemy.img], TRUE);

		//
		//DrawRotaGraph((g_enemy.x*20)+(g_enemy.w/2), (g_enemy.y * 20) + (g_enemy.h / 2), 1.0, 0, enemyimage[g_enemy.img], TRUE);
	}

	//テスト　
	DrawFormatString(0, 0, 0xffffff, "Move : %d", MoveDir);
	DrawFormatString(1000, 30, 0xffffff, "x : %d", g_enemy.x);
	DrawFormatString(1000, 70, 0xffffff, "y : %d", g_enemy.y);
	DrawFormatString(1000, 100, 0xffffff, "mapX : %d", g_enemy.x / MAP_SIZE);
	DrawFormatString(1000, 130, 0xffffff, "mapY : %d", g_enemy.y / MAP_SIZE);
	//DrawFormatString(1000, 160, 0xffffff, "Direct : %s", DirectStr[MoveDir]);
	DrawFormatString(1000, 190, 0xffffff, "ModeCount : %d", mode_count / 60);
	//DrawFormatString(1000, 220, 0xffffff, "Mode : %s", ModeStr[EnemyMode]);
	DrawFormatString(1000, 250, 0xffffff, "TargetX : %d", MoveTarget.x);
	DrawFormatString(1000, 280, 0xffffff, "TargetY : %d", MoveTarget.y);

}


//移動目標との一致　戻り値　0：x,y座標共に一致ﾅｼ　 1：x座標のみ一致  2：y座標のみ一致　　3:x,y座標共に一致 
int ENEMY_PINK::CheckTarget()
{
	if (MoveTarget.x == g_enemy.x && MoveTarget.y != g_enemy.y) return 1;       //x座標のみ一致
	else if (MoveTarget.x != g_enemy.x && MoveTarget.y == g_enemy.y) return 2;  //y座標のみ一致
	else if (MoveTarget.x == g_enemy.x && MoveTarget.y == g_enemy.y) return 3;  //x,y座標共に一致
	else if (MoveTarget.x != g_enemy.x && MoveTarget.y != g_enemy.y) return 0;  //x,y座標共に一致ﾅｼ
}

void ENEMY_PINK::TestMove6(int MapData[MAP_HEIGHT][MAP_WIDTH], int NowKey)
{
	//移動による画像変化
	MoveCount++;
	ChangeMoveImages();

	//マップ上の位置(〇マス目)
	int Mx = g_enemy.x / MAP_SIZE;
	int My = g_enemy.y / MAP_SIZE;

	int x1, x2, y1, y2;
	x1 = (g_enemy.x - (g_enemy.w / 2) + 1);
	x2 = (g_enemy.x + (g_enemy.w / 2) - 1);
	y1 = (g_enemy.y - (g_enemy.h / 2) + 1);
	y2 = (g_enemy.y + (g_enemy.h / 2) - 1);

	//キーボード
	if (NowKey & PAD_INPUT_LEFT && MapData[My][Mx - 1] != 1) MoveDir = DIRECTION::LEFT;
	if (NowKey & PAD_INPUT_RIGHT && MapData[My][Mx + 1] != 1) MoveDir = DIRECTION::RIGHT;
	else if (NowKey & PAD_INPUT_UP && MapData[My - 1][Mx] != 1) MoveDir = DIRECTION::UP;
	else if (NowKey & PAD_INPUT_DOWN && MapData[My + 1][Mx] != 1) MoveDir = DIRECTION::DOWN;

	if (MoveDir == DIRECTION::LEFT)
	{
		if (MapData[My][(x1 - 2) / MAP_SIZE] == 1)
		{
			g_enemy.x = (Mx - 1) * MAP_SIZE + MAP_SIZE + g_enemy.w / 2;
		}
		else g_enemy.x -= g_enemy.speed;

	}
	if (MoveDir == DIRECTION::RIGHT)
	{
		if (MapData[My][(x2 + 1) / MAP_SIZE] == 1)
		{
			//if ((Mx + 1) * MAP_SIZE < x2) g_enemy.x = (Mx + 1) * MAP_SIZE - g_enemy.w / 2;
			g_enemy.x = (Mx + 1) * MAP_SIZE - g_enemy.w / 2;
		}
		else g_enemy.x += g_enemy.speed;
	}
	if (MoveDir == DIRECTION::UP)
	{
		if (MapData[(y1 - 2) / MAP_SIZE][Mx] == 1)
		{
			g_enemy.y = (My - 1) * MAP_SIZE + MAP_SIZE + g_enemy.w / 2;
		}
		else g_enemy.y -= g_enemy.speed;

	}
	if (MoveDir == DIRECTION::DOWN)
	{
		if (MapData[(y2 + 1) / MAP_SIZE][Mx] == 1)
		{
			g_enemy.y = (My + 1) * MAP_SIZE - g_enemy.w / 2;
		}
		else g_enemy.y += g_enemy.speed;

	}


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

//巡回用座標
int PtrlPoint[4][2] =
{
	{MAP_SIZE * 1 + (MAP_SIZE / 2),MAP_SIZE * 1 + (MAP_SIZE / 2)},
	{4 * MAP_SIZE * 1 + (MAP_SIZE / 2),MAP_SIZE * 1 + (MAP_SIZE / 2)},
	{4 * MAP_SIZE * 1 + (MAP_SIZE / 2),5 * MAP_SIZE * 1 + (MAP_SIZE / 2)},
	{MAP_SIZE * 1 + (MAP_SIZE / 2),5 * MAP_SIZE * 1 + (MAP_SIZE / 2)},
};

//ターゲット設定  引数:プレイヤーの座標
void ENEMY_PINK::TargetCtrl(int tpX, int tpY, int tpD)
{
	M_POINT Point = { 0,0 };
	static int order = 0; //巡回

	switch (EnemyMode)
	{
	case MODE::STANDBY:           //出撃前　

		/*赤との出撃タイミング「同じ」*/
		//if (sortie_flg == false)     //出撃不可
		//{
		//	//上下に往復
		//	if (CheckTarget() == 3 && g_enemy.y == 285) MoveTarget.y = 345;      //下部
		//	else if (CheckTarget() == 3 && g_enemy.y == 345) MoveTarget.y = 285; //上部
		//	else if (CheckTarget() == 0) MoveTarget = { 255,285 };               //初期位置
		//}
		//else if (sortie_flg == true) //出撃可
		//{
		//	MoveTarget = { 315,225 };  //巣の入口上 (巣から出撃)
		//	if (g_enemy.x == 315 && g_enemy.y == 225) EnemyMode = MODE::PATROL;  //移動完了後、巡回モードに切り替え
		//}

			/*赤との出撃タイミング「違う*/
			if (sortie_flg == false)     //出撃不可
			{
				//上下に往復
				if (CheckTarget() == 3 && g_enemy.y == 285) MoveTarget.y = 345;      //下部
				else if (CheckTarget() == 3 && g_enemy.y == 345) MoveTarget.y = 285; //上部
				else if (CheckTarget() == 0) MoveTarget = { 255,285 };               //初期位置
			}
			else if (sortie_flg == true) //出撃可
			{
				//上下に往復
				if (CheckTarget() == 3 && g_enemy.y == 285) MoveTarget.y = 345;      //下部
				else if (CheckTarget() == 3 && g_enemy.y == 345) MoveTarget.y = 285; //上部
				else if (CheckTarget() == 0) MoveTarget = { 255,285 };               //初期位置

				//6秒で出撃
				if (++mode_count % 380 == 0)
				{
					 EnemyMode = MODE::PATROL;  //巡回モードに切り替え
				}
			}
		break;

	case MODE::PATROL:            //巡回モード

		//左上座標
		//Point = { MAP_SIZE + (MAP_SIZE / 2) ,MAP_SIZE + (MAP_SIZE / 2) };
		Point = { PtrlPoint[order][0] ,PtrlPoint[order][1] };
		MoveTarget = Point;


		if (CheckTarget2() == 3)
		{
			order++;
			if (order == 4) order = 0;
		}
		Point = { PtrlPoint[order][0] ,PtrlPoint[order][1] };

		MoveTarget = Point;

		//16秒で追跡モードに切り替え
		if (++mode_count % 880 == 0)
		{
			mode_count = 0;
			EnemyMode = MODE::TRACK;
		}
		break;

	case MODE::TRACK:             //追跡モード

		//現在の進行方向 +3マス
		Point = { tpX ,tpY };
		if (tpD == DIRECTION::LEFT)  Point.x = tpX + (-4 * MAP_SIZE);
		if (tpD == DIRECTION::RIGHT) Point.x = tpX + (4 * MAP_SIZE);
		if (tpD == DIRECTION::UP)    Point.y = tpY + (-4 * MAP_SIZE);
		if (tpD == DIRECTION::DOWN)  Point.y = tpY + (4 * MAP_SIZE);
		MoveTarget.x = Point.x;
		MoveTarget.y = Point.y;

		//20秒で巡回モードに切り替え
		if (++mode_count % 1200 == 0)
		{
			mode_count = 0;
			EnemyMode = MODE::PATROL;
		}
		break;

	case MODE::RANDOM:             //ランダム移動(プロト用)

		break;

	default:
		break;
	}

}



//敵の挙動(モードによって変化  出撃前/巡回/追跡)
void ENEMY_PINK::EnemyControl()
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
void ENEMY_PINK::Move_StandBy()
{

}

//巡回モードの挙動
void ENEMY_PINK::Move_Patrol()
{

}

//追跡モードの挙動
void ENEMY_PINK::Move_Track()
{

}
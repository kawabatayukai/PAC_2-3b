#include"DxLib.h"
#include"Enemy.h"
#include"Blue.h"
#include "Info.h"

ENEMY_BLUE Blue;

//コンストラクタ  ENEMY_BASEのコンストラクタで "My_Color" を設定
ENEMY_BLUE::ENEMY_BLUE() : ENEMY_BASE(ENEMY_COLOR::BLUE)
{
}

//画像読み込み
int ENEMY_BLUE::Loadimages()
{
	//分割読み込み
	if ((LoadDivGraph("images/All_Blue30.png", 16, 4, 4, 30, 30, enemyimage)) == -1) return -1;   //30 　ｲｼﾞｹ・目を含む
}

//初期処理
void ENEMY_BLUE::InitEnemy()
{
	g_enemy.flg = true;

	g_enemy.x = 11 * MAP_SIZE + (MAP_SIZE / 2); //巣の上
	g_enemy.y = 13 * MAP_SIZE + (MAP_SIZE / 2); //巣の上

	g_enemy.w = E_WIDTH;
	g_enemy.h = E_HEIGHT;
	g_enemy.speed = 2.5f;//p_speed[0];
	//g_enemy.speed = GetRand(4) + 1;
	g_enemy.img = 0;

	//移動なし
	MoveDir = (int)DIRECTION::UP;

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
void ENEMY_BLUE::MoveEnemy(int MapData[MAP_HEIGHT][MAP_WIDTH])
{
	//移動による画像変化
	ChangeMoveImages();

	//ターゲットとの距離を縮める
	//壁にぶつかると方向転換

	int Tx = MoveTarget.x;    //追跡対象X　　　追跡モードのみ
	int Ty = MoveTarget.y;    //   〃　 Y

	int Mx = static_cast<int>(g_enemy.x / MAP_SIZE);
	int My = static_cast<int>(g_enemy.y / MAP_SIZE);

	int Lx = static_cast<int>(g_enemy.x - (g_enemy.w / 2));
	int Rx = static_cast<int>(g_enemy.x + (g_enemy.w / 2));
	int Uy = static_cast<int>(g_enemy.y - (g_enemy.h / 2));
	int Dy = static_cast<int>(g_enemy.y + (g_enemy.h / 2));

	bool hitX = false;  //X軸の一致 ｱﾘ・ﾅｼ
	bool hitY = false;  //Y軸の一致 ｱﾘ・ﾅｼ

	//敵の座標と目標座標の差（difference）
	int dx = static_cast<int>(g_enemy.x - MoveTarget.x);
	int dy = static_cast<int>(g_enemy.y - MoveTarget.y);

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
	x1 = static_cast<int>(g_enemy.x - (g_enemy.w / 2));
	x2 = static_cast<int>(g_enemy.x + (g_enemy.w / 2) - 1);
	y1 = static_cast<int>(g_enemy.y - (g_enemy.h / 2) + 1);
	y2 = static_cast<int>(g_enemy.y + (g_enemy.h / 2) - 1);

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
void ENEMY_BLUE::MoveEnemy2(int MapData[MAP_HEIGHT][MAP_WIDTH])
{
	//移動による画像変化
	//MoveCount++;
	ChangeMoveImages();

	if (EnemyMode == MODE::STANDBY || EnemyMode == MODE::R_EYE)
	{
		MoveEnemy(MapData);
	}
	else if (EnemyMode == MODE::TRACK || EnemyMode == MODE::PATROL || EnemyMode == MODE::EYE || EnemyMode == MODE::IJIKE)
	{
		if (EnemyMode == MODE::TRACK) {
			EnemyController();
		}
		else if (EnemyMode == MODE::EYE) {
			MoveShortest2(MapData, MoveTarget.x, MoveTarget.y);
		}
		else {
			MoveShortest(MapData, MoveTarget.x, MoveTarget.y);
		}
	}

}

//描画
void ENEMY_BLUE::DrawEnemy()
{
	////テスト　目標位置
	//SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 128);
	//DrawCircle(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + DRAW_POINT_Y, 8, 0xff00ff, TRUE);

	////テスト　目標～敵間
	//SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 200);
	//DrawLine(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + DRAW_POINT_Y, g_enemy.x + DRAW_POINT_X, g_enemy.y + DRAW_POINT_Y, 0x00ffff);
	//DrawLine(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + DRAW_POINT_Y, MoveTarget.x + DRAW_POINT_X, MoveTarget.y + (g_enemy.y - MoveTarget.y) + DRAW_POINT_Y, 0x00ffff);
	//DrawLine(MoveTarget.x + DRAW_POINT_X, MoveTarget.y + (g_enemy.y - MoveTarget.y) + DRAW_POINT_Y, g_enemy.x + DRAW_POINT_X, g_enemy.y + DRAW_POINT_Y, 0x00ffff);
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (g_enemy.flg == true)
	{
		//シンプル描画
		DrawRotaGraph(static_cast<int>(g_enemy.x) + DRAW_POINT_X, static_cast<int>(g_enemy.y) + DRAW_POINT_Y, 1.0, 0, enemyimage[g_enemy.img], TRUE);
	}
}


//移動目標との一致　戻り値　0：x,y座標共に一致ﾅｼ　 1：x座標のみ一致  2：y座標のみ一致　　3:x,y座標共に一致 
int ENEMY_BLUE::CheckTarget()
{
	if (MoveTarget.x == g_enemy.x && MoveTarget.y != g_enemy.y) return 1;       //x座標のみ一致
	else if (MoveTarget.x != g_enemy.x && MoveTarget.y == g_enemy.y) return 2;  //y座標のみ一致
	else if (MoveTarget.x == g_enemy.x && MoveTarget.y == g_enemy.y) return 3;  //x,y座標共に一致
	else if (MoveTarget.x != g_enemy.x && MoveTarget.y != g_enemy.y) return 0;  //x,y座標共に一致ﾅｼ
}

//ターゲット設定  引数:プレイヤーの座標
void ENEMY_BLUE::TargetCtrl(int tpX, int tpY, int tpD)
{
	M_POINT Point = { 0,0 };

	//イジケ・目状態を設定
	ModeChanger();

	static int order = 0;

	int Red_X;
	int Red_Y;

	switch (EnemyMode)
	{
	case MODE::STANDBY:           //出撃前　

		if (sortie_flg == false)     //出撃不可
		{
			//上下に往復
			if (CheckTarget() == 3 && g_enemy.y == 375) MoveTarget.y = 435;      //下部
			else if (CheckTarget() == 3 && g_enemy.y == 435) MoveTarget.y = 375; //上部
			else if (CheckTarget() == 0) MoveTarget = { 345,375 };               //初期位置
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

		//巡回座標
		Point = { PtrlPoint[2][order][0] ,PtrlPoint[2][order][1] };
		MoveTarget = Point;

		if (CheckTarget3() == 3)
		{
			order++;
			if (order == 4) order = 0;
		}
		Point = { PtrlPoint[2][order][0] ,PtrlPoint[2][order][1] };

		MoveTarget = Point;

		//現在のモードを保持
		old_mode = EnemyMode;

		//8秒で追跡モードに切り替え
		if (++mode_count % 480 == 0)
		{
			mode_count = 0;
			EnemyMode = MODE::TRACK;
		}
		break;

	case MODE::TRACK:             //追跡モード

		//追跡方法を設定
		Point = { tpX ,tpY };

		//アカの座標を取得
		Red_X = All_Enemy[0]->GetEnemyX();
		Red_Y = All_Enemy[0]->GetEnemyY();

		//Point.x = tpX + (-1 * (Red_X - tpX));
		//Point.y = tpY + (-1 * (Red_Y - tpY));

		Point.x = ((tpX + (-1 * (Red_X - tpX))) / MAP_SIZE) * MAP_SIZE + (MAP_SIZE / 2);
		Point.y = ((tpY + (-1 * (Red_Y - tpY))) / MAP_SIZE) * MAP_SIZE + (MAP_SIZE / 2);

		MoveTarget.x = Point.x;
		MoveTarget.y = Point.y;

		//現在のモードを保持
		old_mode = EnemyMode;

		//20秒で巡回モードに切り替え
		if (++mode_count % 1200 == 0)
		{
			mode_count = 0;
			EnemyMode = MODE::PATROL;
		}
		break;

	case MODE::IJIKE:       //イジケ時

		Move_Ijike();
		break;

	case MODE::EYE:               //目（巣に戻る）

		Move_Eye();
		break;

	case MODE::R_EYE:        //イジケ以前のモードに戻る

		Move_R_Eye();
		break;

	default:
		break;
	}

}

//敵の挙動(モードによって変化  出撃前/巡回/追跡)
void ENEMY_BLUE::EnemyControl()
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
void ENEMY_BLUE::Move_StandBy()
{

}

//巡回モードの挙動
void ENEMY_BLUE::Move_Patrol()
{

}

//追跡モードの挙動
void ENEMY_BLUE::Move_Track()
{

}
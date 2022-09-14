#include"DxLib.h"
#include"Enemy.h"

//テスト出力用
char ColorStr[][7] = { "RED","PINK","BLUE","ORANGE","CLEAR" };
char DirectStr[][6] = { "LEFT","RIGHT","UP","DOWN" ,"NONE" };
char ModeStr[][8] = { "STANDBY","PATROL","TRACK","IJIKE","EYE","RANDOM" };

//巣の中の位置　 初期位置ではない（初期位置はアカだけ巣の上）
int NestPoint[][2] = {
	{10 * MAP_SIZE + (MAP_SIZE / 2),10 * MAP_SIZE + (MAP_SIZE / 2)},  //アカ
	{10 * MAP_SIZE + (MAP_SIZE / 2),10 * MAP_SIZE + (MAP_SIZE / 2)},  //ピンク
	{8 * MAP_SIZE + (MAP_SIZE / 2),10 * MAP_SIZE + (MAP_SIZE / 2)},   //ミズ
	{12 * MAP_SIZE + (MAP_SIZE / 2),10 * MAP_SIZE + (MAP_SIZE / 2)}   //オレンジ
};

//壁より内側　限界点  ※描画上ではDRAW_POINT_X(Y)が加算された座標 　"ピンク"の目標座標はステージ外になることがある
const int L_END = 4 * MAP_SIZE;
const int R_END = 23 * MAP_SIZE;
const int U_END = 3 * MAP_SIZE;
const int D_END = 25 * MAP_SIZE;

//目標地点が"コ"の字より外
const int L_WALL_X = 4 * MAP_SIZE;   //画面左側"コ"の字 ｘ座標
const int R_WALL_X = 17 * MAP_SIZE;  //画面右側"コ"の字 ｘ座標

const int U_WALL_Y1 = 6 * MAP_SIZE;  //上"コ"の字 ｙ座標
const int D_WALL_Y1 = 10 * MAP_SIZE;  //上"コ"の字 ｙ座標
const int U_WALL_Y2 = 11 * MAP_SIZE; //下"コ"の字 ｙ座標
const int D_WALL_Y2 = 15 * MAP_SIZE; //下"コ"の字 ｙ座標

//全てのオブジェクトのアドレスを保持　静的メンバ変数　実数
ENEMY_BASE* ENEMY_BASE::All_Enemy[ENEMY_MAX];

//コンストラクタ
ENEMY_BASE::ENEMY_BASE(int color) : My_Color(color)
{
	//配列の特定の位置に自らのアドレスを代入
	//アカ0  ピンク1  アオ2  オレンジ3
	All_Enemy[My_Color] = this;

}

//デストラクタ
ENEMY_BASE::~ENEMY_BASE()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		//自分自身がいれば削除
		if (All_Enemy[i] == this) All_Enemy[i] = nullptr;
		break;
	}
}

//出撃を管理
void ENEMY_BASE::SoltieControl(int NowKey, int FoodCount, int ClearCount)
{
	//static int count_enemy;
	//if (NowKey & PAD_INPUT_M) count_enemy++;

	//switch (count_enemy)
	//{
	//case 1:
	//	All_Enemy[0]->SetSortie(); //アカ
	//	break;

	//case 2:
	//	All_Enemy[1]->SetSortie(); //ピンク
	//	break;

	//case 3:
	//	All_Enemy[2]->SetSortie(); //アオ
	//	break;

	//case 4:
	//	All_Enemy[3]->SetSortie(); //オレンジ
	//	break;

	//default:
	//	break;
	//}

	if (ClearCount == 0)                               //クリア0回
	{
		//すぐにピンク出撃
		All_Enemy[1]->SetSortie();

		//エサを30個以上とるとアオ出撃    　　　　20個
		if (FoodCount == 20) All_Enemy[2]->SetSortie();

		//エサを90個以上とるとオレンジ出撃　　　　60個
		if (FoodCount == 60) All_Enemy[3]->SetSortie();
	}
	else if (ClearCount == 1)                          //クリア1回
	{
		//すぐにピンク・アオ出撃
		All_Enemy[1]->SetSortie();
		All_Enemy[2]->SetSortie();

		//エサを50個以上とるとオレンジ出撃　　　　35個
		if (FoodCount == 35) All_Enemy[3]->SetSortie();
	}
	else if (ClearCount >= 2)                          //クリア2回～
	{
		//すぐにピンク、水色、オレンジの順に出撃

		//ピンク出撃
		All_Enemy[1]->SetSortie();

		//ピンクのモードが切り替わり次第アオ出撃
		if (All_Enemy[1]->GetEnemyMode() != MODE::STANDBY) All_Enemy[2]->SetSortie();
		//ピンクのモードが切り替わり次第アオ出撃
		if (All_Enemy[2]->GetEnemyMode() != MODE::STANDBY) All_Enemy[3]->SetSortie();
	}

}

//イジケ状態ON・OFF
void ENEMY_BASE::IjikeControl(int PowerFlg)
{
	if (PowerFlg == true)
	{
		for (int i = 0; i < ENEMY_MAX; i++)
		{
			All_Enemy[i]->ijike_flg = true;
		}
	}
}

//すべてのEnemyを初期化
void ENEMY_BASE::AllEnemyInit()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (All_Enemy[i] != nullptr)
		{
			All_Enemy[i]->InitEnemy();
		}
		//else break;
	}
	return;
}

//すべてのEnemyを描画
void ENEMY_BASE::DrawAllEnemy()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (All_Enemy[i] != nullptr)
		{
			All_Enemy[i]->DrawEnemy();
		}
	}
}

//移動による画像チェンジ ～2枚の画像を交互に～
void ENEMY_BASE::ChangeMoveImages()
{
	//画像配列enemyimage
	//左向き 0,1　右向き 2,3　上向き 4,5　下向き 6,7　イジケ青 8,9　イジケ白 10,11　目 12～15

	int std = 0;  //基準となる画像No 　std と std+1 を交互に切り替える
	MoveCount++;  //切り替え用にフレームをカウント

	//"目"の状態時にはアニメーションがない
	if (EnemyMode != MODE::EYE)
	{
		//ｲｼﾞｹ状態でない
		if (ijike_flg != true)
		{
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
		}
		else
		{
			//イジケ状態の時
			if (g_enemy.img != 8 && g_enemy.img != 9) g_enemy.img = 8; //イジケ青画像でなければ、イジケ青画像にチェンジ
			std = 8;       //基準をセット

			IjikeCount++;  //イジケ時間をカウント

			//6秒でイジケ終了
			if (IjikeCount % 360 == 0)
			{
				ijike_flg = false;
				IjikeCount = 0;
			}
		}

		//5フレーム毎に画像切り替え
		if (MoveCount % 5 == 0)
		{
			if (g_enemy.img == std)
			{
				g_enemy.img = std + 1;  //画像0の時,画像1に
				MoveCount = 0;
			}
			else if (g_enemy.img = std + 1)
			{
				g_enemy.img = std;      //画像1の時,画像2に
				MoveCount = 0;
			}
		}
	}
	else   //目の状態
	{
		switch (MoveDir)
		{
		case DIRECTION::LEFT:
			if (g_enemy.img != 12) g_enemy.img = 12; //左向き画像(目)でなければ、左向き画像(目)にチェンジ
			break;

		case DIRECTION::RIGHT:
			if (g_enemy.img != 13) g_enemy.img = 13; //右向き画像(目)でなければ、右向き画像(目)にチェンジ
			break;

		case DIRECTION::UP:
			if (g_enemy.img != 14) g_enemy.img = 14; //上向き画像(目)でなければ、上向き画像(目)にチェンジ
			break;

		case DIRECTION::DOWN:
			if (g_enemy.img != 15) g_enemy.img = 15; //下向き画像(目)でなければ、下向き画像(目)にチェンジ
			break;
		case DIRECTION::NONE:
			break;
		default:
			break;
		}
	}
}


//ターゲットまでの最短経路を探す
//             ターゲットの位置を"ｎ"とし、離れるにつれｎを加算
//             引数tx,tyはマップ上座標  呼び出しで"/MAP_SIZE"が必要 
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
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if (MapData[i][j] != 1)
			{
				//if (i <= 2 || j <= 2) my_mapdata[i][j] = 9;
				//else my_mapdata[i][j] = 0;
				my_mapdata[i][j] = 0;
			}
			else my_mapdata[i][j] = 1;
		}
	}

	//ターゲット座標がステージ外の場合、ステージ内に戻す
	if (targetX < L_END) targetX = L_END + (MAP_SIZE / 2);
	if (targetX > R_END) targetX = R_END - (MAP_SIZE / 2);
	if (targetY < U_END) targetY = U_END + (MAP_SIZE / 2);
	if (targetY > D_END) targetY = D_END - (MAP_SIZE / 2);

	////ターゲット座標が"コ"の字外の場合、ステージ内に戻す
	////左側上
	//if (targetX< L_WALL_X && targetY>U_WALL_Y1 && targetX < L_WALL_X && targetY < D_WALL_Y1) targetX = L_WALL_X + (MAP_SIZE / 2);
	////左側下
	//if (targetX< L_WALL_X && targetY>U_WALL_Y2 && targetX < L_WALL_X && targetY < D_WALL_Y2) targetX = L_WALL_X + (MAP_SIZE / 2);
	////右側上
	//if (targetX > R_WALL_X && targetY > U_WALL_Y1 && targetX > R_WALL_X && targetY < D_WALL_Y1) targetX = R_WALL_X - (MAP_SIZE / 2);
	////右側下
	//if (targetX > R_WALL_X && targetY > U_WALL_Y2 && targetX > R_WALL_X && targetY < D_WALL_Y2) targetX = R_WALL_X - (MAP_SIZE / 2);

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
		//if (ijike_flg == false) g_enemy.x -= g_enemy.speed;
		//else                    g_enemy.x += g_enemy.speed;
	}
	//右
	else if (MapData[My][Mx + 1] != 1 && my_mapdata[My][Mx + 1] < my_mapdata[My][Mx])
	{
		MoveDir = DIRECTION::RIGHT;
		g_enemy.x += g_enemy.speed;
		//if (ijike_flg == false) g_enemy.x += g_enemy.speed;
		//else                    g_enemy.x -= g_enemy.speed;
	}
	//上
	else if (MapData[My - 1][Mx] != 1 && my_mapdata[My - 1][Mx] < my_mapdata[My][Mx])
	{
		MoveDir = DIRECTION::UP;
		g_enemy.y -= g_enemy.speed;
		//if (ijike_flg == false) g_enemy.y -= g_enemy.speed;
		//else                    g_enemy.y += g_enemy.speed;
	}
	//下
	else if (MapData[My + 1][Mx] != 1 && my_mapdata[My + 1][Mx] < my_mapdata[My][Mx])
	{
		MoveDir = DIRECTION::DOWN;
		g_enemy.y += g_enemy.speed;
		//if (ijike_flg == false) g_enemy.y += g_enemy.speed;
		//else                    g_enemy.y -= g_enemy.speed;
	}

	//めり込ませない
	int x1, x2, y1, y2;
	x1 = ((g_enemy.x - (g_enemy.w / 2)) + 2);
	x2 = ((g_enemy.x + (g_enemy.w / 2)) - 2);
	y1 = ((g_enemy.y - (g_enemy.h / 2)) + 2);
	y2 = ((g_enemy.y + (g_enemy.h / 2)) - 2);

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

//当たり判定
int ENEMY_BASE::CheckTarget3()
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

int cols[] = { 0xff0000, 0xe9a1d0,0x67a8dd,0xfd7e00 };
//テスト用　敵全色の情報を表示
void ENEMY_BASE::DrawAllInfo()
{
	int x = 100;
	int y = 0;
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (All_Enemy[i] != nullptr)
		{
			SetFontSize(18);

			if (i >= 2)x = 1000;
			if (i == 1 || i == 3) y = 360;
			else y = 0;

			DrawFormatString(x, y + 20, cols[i], "Color : %s", ColorStr[All_Enemy[i]->My_Color]);
			DrawFormatString(x, y + 40, 0xffffff, "Move : %d", All_Enemy[i]->MoveDir);
			DrawFormatString(x, y + 60, 0xffffff, "x : %d", All_Enemy[i]->g_enemy.x);
			DrawFormatString(x, y + 80, 0xffffff, "y : %d", All_Enemy[i]->g_enemy.y);
			DrawFormatString(x, y + 100, 0xffffff, "mapX : %d", All_Enemy[i]->g_enemy.x / MAP_SIZE);
			DrawFormatString(x, y + 120, 0xffffff, "mapY : %d", All_Enemy[i]->g_enemy.y / MAP_SIZE);
			DrawFormatString(x, y + 140, 0xffffff, "Direct : %s", DirectStr[All_Enemy[i]->MoveDir]);
			DrawFormatString(x, y + 160, 0xffffff, "ModeCount : %d", All_Enemy[i]->mode_count / 60);
			DrawFormatString(x, y + 180, 0xffffff, "Mode : %s", ModeStr[All_Enemy[i]->EnemyMode]);
			DrawFormatString(x, y + 200, 0xffffff, "TargetX : %d", All_Enemy[i]->MoveTarget.x);
			DrawFormatString(x, y + 220, 0xffffff, "TargetY : %d", All_Enemy[i]->MoveTarget.y);
			DrawFormatString(x, y + 240, 0xffffff, "TarMapX : %d", All_Enemy[i]->MoveTarget.x / MAP_SIZE);
			DrawFormatString(x, y + 260, 0xffffff, "TarMapY : %d", All_Enemy[i]->MoveTarget.y / MAP_SIZE);
			DrawFormatString(x, y + 280, 0xffffff, "Speed : %d", All_Enemy[i]->g_enemy.speed);
		}
	}

}

//巡回モード用座標
const int ENEMY_BASE::PtrlPoint[4][4][2] =
{
	////アカ
	//{
	//	{19 * MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
	//	{16 * MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
	//	{16 * MAP_SIZE + (MAP_SIZE / 2),5 * MAP_SIZE + (MAP_SIZE / 2)},
	//	{19 * MAP_SIZE + (MAP_SIZE / 2),5 * MAP_SIZE + (MAP_SIZE / 2)},
	//},
	////ピンク
	//{
	//	{MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
	//	{4 * MAP_SIZE + (MAP_SIZE / 2),MAP_SIZE + (MAP_SIZE / 2)},
	//	{4 * MAP_SIZE + (MAP_SIZE / 2),5 * MAP_SIZE + (MAP_SIZE / 2)},
	//	{MAP_SIZE + (MAP_SIZE / 2),5 * MAP_SIZE + (MAP_SIZE / 2)},
	//},
	////アオ
	//{
	//	{19 * MAP_SIZE + (MAP_SIZE / 2),21 * MAP_SIZE + (MAP_SIZE / 2)},
	//	{11 * MAP_SIZE + (MAP_SIZE / 2),21 * MAP_SIZE + (MAP_SIZE / 2)},
	//	{15 * MAP_SIZE + (MAP_SIZE / 2),17 * MAP_SIZE + (MAP_SIZE / 2)},
	//	{19 * MAP_SIZE + (MAP_SIZE / 2),19 * MAP_SIZE + (MAP_SIZE / 2)},
	//},
	////オレンジ
	//{
	//	{MAP_SIZE + (MAP_SIZE / 2),21 * MAP_SIZE + (MAP_SIZE / 2)},
	//	{9 * MAP_SIZE + (MAP_SIZE / 2),21 * MAP_SIZE + (MAP_SIZE / 2)},
	//	{5 * MAP_SIZE + (MAP_SIZE / 2),17 * MAP_SIZE + (MAP_SIZE / 2)},
	//	{MAP_SIZE + (MAP_SIZE / 2),19 * MAP_SIZE + (MAP_SIZE / 2)},
	//},


							  /*29×27map用*/
	//アカ
	{
		{22 * MAP_SIZE + (MAP_SIZE / 2),4 * MAP_SIZE + (MAP_SIZE / 2)},
		{19 * MAP_SIZE + (MAP_SIZE / 2),4 * MAP_SIZE + (MAP_SIZE / 2)},
		{19 * MAP_SIZE + (MAP_SIZE / 2),8 * MAP_SIZE + (MAP_SIZE / 2)},
		{22 * MAP_SIZE + (MAP_SIZE / 2),8 * MAP_SIZE + (MAP_SIZE / 2)},
	},
	//ピンク
	{
		{4 * MAP_SIZE + (MAP_SIZE / 2),4 * MAP_SIZE + (MAP_SIZE / 2)},
		{7 * MAP_SIZE + (MAP_SIZE / 2), 4 * MAP_SIZE + (MAP_SIZE / 2)},
		{7 * MAP_SIZE + (MAP_SIZE / 2),8 * MAP_SIZE + (MAP_SIZE / 2)},
		{4 * MAP_SIZE + (MAP_SIZE / 2),8 * MAP_SIZE + (MAP_SIZE / 2)},
	},
	//アオ
	{
		{22 * MAP_SIZE + (MAP_SIZE / 2),24 * MAP_SIZE + (MAP_SIZE / 2)},
		{14 * MAP_SIZE + (MAP_SIZE / 2),24 * MAP_SIZE + (MAP_SIZE / 2)},
		{18 * MAP_SIZE + (MAP_SIZE / 2),20 * MAP_SIZE + (MAP_SIZE / 2)},
		{22 * MAP_SIZE + (MAP_SIZE / 2),22 * MAP_SIZE + (MAP_SIZE / 2)},
	},
	//オレンジ
	{
		{4 * MAP_SIZE + (MAP_SIZE / 2),24 * MAP_SIZE + (MAP_SIZE / 2)},
		{12 * MAP_SIZE + (MAP_SIZE / 2),24 * MAP_SIZE + (MAP_SIZE / 2)},
		{8 * MAP_SIZE + (MAP_SIZE / 2),20 * MAP_SIZE + (MAP_SIZE / 2)},
		{4 * MAP_SIZE + (MAP_SIZE / 2),22 * MAP_SIZE + (MAP_SIZE / 2)},
	},
};
#include"DxLib.h"
#include<math.h>
#include"Enemy.h"
//#include"A_star.h"
//#include"A_star_PINKY.h"
//#include"A_star_INKY.h"
//#include"A_star_CLYDE.h"
#include"Enemy_Red.h"
#include"Stage.h"
#include"NewPlayer.h"
#include"Red.h"

//テスト出力用
char ColorStr[][7] = { "RED","PINK","BLUE","ORANGE","CLEAR" };
char DirectStr[][6] = { "LEFT","RIGHT","UP","DOWN" ,"NONE" };
char ModeStr[][8] = { "STANDBY","PATROL","TRACK","IJIKE","EYE","R_EYE","RANDOM" };

//巣の中の位置　 初期位置ではない（初期位置はアカだけ巣の上）
int NestPoint[][2] = {
	{10 * MAP_SIZE + (MAP_SIZE / 2),10 * MAP_SIZE + (MAP_SIZE / 2)},  //アカ
	{10 * MAP_SIZE + (MAP_SIZE / 2),10 * MAP_SIZE + (MAP_SIZE / 2)},  //ピンク
	{8 * MAP_SIZE + (MAP_SIZE / 2),10 * MAP_SIZE + (MAP_SIZE / 2)},   //ミズ
	{12 * MAP_SIZE + (MAP_SIZE / 2),10 * MAP_SIZE + (MAP_SIZE / 2)}   //オレンジ
};

//巣の上
const int ON_NEST[] = { 13 * MAP_SIZE + (MAP_SIZE / 2),10 * MAP_SIZE + (MAP_SIZE / 2) };

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

ENEMY_BASE* EnemyManager;              //全色の敵を管理

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
	if (ClearCount == 0)                               //クリア0回
	{
		//すぐにピンク出撃
		All_Enemy[1]->SetSortie();

		//エサを30個以上とるとアオ出撃    　　　　20個
		if (FoodCount >= 20 && All_Enemy[1]->GetEnemyMode() != MODE::STANDBY) All_Enemy[2]->SetSortie();

		//エサを90個以上とるとオレンジ出撃　　　　60個
		if (FoodCount >= 60 && All_Enemy[2]->GetEnemyMode() != MODE::STANDBY) All_Enemy[3]->SetSortie();
	}
	else if (ClearCount == 1)                          //クリア1回
	{
		//すぐにピンク・アオ出撃
		All_Enemy[1]->SetSortie();
		All_Enemy[2]->SetSortie();

		//エサを50個以上とるとオレンジ出撃　　　　35個
		if (FoodCount >= 35 && All_Enemy[2]->GetEnemyMode() != MODE::STANDBY) All_Enemy[3]->SetSortie();
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
	static int flg_count;
	if (PowerFlg == true) flg_count++;
	else flg_count = 0;

	if (flg_count == 1)
	{
		for (int i = 0; i < ENEMY_MAX; i++)
		{
			All_Enemy[i]->ijike_flg = true;
		}
	}
}

//すべてのEnemyを初期化
void ENEMY_BASE::AllEnemyInit(int ClearCnt)
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (All_Enemy[i] != nullptr)
		{
			All_Enemy[i]->InitEnemy();
			All_Enemy[i]->IjikeTime = GetIjikeTime(ClearCnt);  //現在のイジケ時間をセット
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
			//イジケ時間残り2秒以下で青白交互に
			if (IjikeCount >= (IjikeTime - 120))
			{
				if (IjikeCount % 20 == 0)
				{
					if (IjikeWhite == 0) IjikeWhite = 1;
					else IjikeWhite = 0;
				}

				if (IjikeWhite == 0)
				{
					//イジケ状態の時
					if (g_enemy.img != 8 && g_enemy.img != 9) g_enemy.img = 8; //イジケ青画像でなければ、イジケ青画像にチェンジ
					std = 8;       //基準をセット
				}
				else
				{
					//イジケ状態(白)の時
					if (g_enemy.img != 10 && g_enemy.img != 11) g_enemy.img = 10; //イジケ白画像でなければ、イジケ白画像にチェンジ
					std = 10;       //基準をセット
				}
			}
			else
			{
				//イジケ状態の時
				if (g_enemy.img != 8 && g_enemy.img != 9) g_enemy.img = 8; //イジケ青画像でなければ、イジケ青画像にチェンジ
				std = 8;       //基準をセット
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

	/*if (a_star.data[g_enemy_Red.EYC][g_enemy_Red.EXC - 1].status == 1) {
		MoveDir = DIRECTION::LEFT;
		g_enemy.x -= g_enemy.speed;
	}

	if (a_star.data[g_enemy_Red.EYC][g_enemy_Red.EXC + 1].status == 1) {
		MoveDir = DIRECTION::RIGHT;
		g_enemy.x += g_enemy.speed;

	}
	if (a_star.data[g_enemy_Red.EYC - 1][g_enemy_Red.EXC].status == 1) {
		MoveDir = DIRECTION::UP;
		g_enemy.y -= g_enemy.speed;
	}
	if (a_star.data[g_enemy_Red.EYC + 1][g_enemy_Red.EXC].status == 1) {
		MoveDir = DIRECTION::DOWN;
		g_enemy.y += g_enemy.speed;
	}*/

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

//ランダム座標との当たり判定　ポイントが壁の中でも
int ENEMY_BASE::CheckRandomPoint()
{
	int ex1 = g_enemy.x - (g_enemy.w / 2); //左
	int ex2 = g_enemy.x + (g_enemy.w / 2); //右
	int ey1 = g_enemy.y - (g_enemy.h / 2); //上
	int ey2 = g_enemy.y + (g_enemy.h / 2); //下

	int tx1 = MoveTarget.x - (MAP_SIZE)-10;
	int tx2 = MoveTarget.x + (MAP_SIZE)+10;
	int ty1 = MoveTarget.y - (MAP_SIZE)-10;
	int ty2 = MoveTarget.y + (MAP_SIZE)+10;

	//if(MoveTarget.x-15<g_enemy.x&&)
	if (ex1 < tx2 && tx1 < ex2 && ey1 < ty2 && ty1 < ey2)
	{
		return 3;
	}
	else return 0;
}

/****************** イ　ジ　ケ ******************/

//クリア回数からイジケ時間を取得
int ENEMY_BASE::GetIjikeTime(int ClearCnt)
{
	//クリア回数と時間との関連性が薄いので強引に・・

	int sec = 0;
	if (ClearCnt == 0) {
		sec = 6;
	}
	else if (ClearCnt == 1 || ClearCnt == 5 || ClearCnt == 9) {
		sec = 5;
	}
	else if (ClearCnt == 2) {
		sec = 4;
	}
	else if (ClearCnt == 3 || ClearCnt == 13) {
		sec = 3;
	}
	else if (ClearCnt == 4 || ClearCnt == 6 || ClearCnt == 7 || ClearCnt == 10) {
		sec = 2;
	}
	else if (ClearCnt == 8 || ClearCnt == 11 || ClearCnt == 12 || ClearCnt == 14 || ClearCnt == 15) {
		sec = 1;
	}
	else if (ClearCnt >= 16) {
		sec = 0;
	}
	else sec = 6;

	return sec * 60;     //sec秒
}

//モード切替え
void ENEMY_BASE::ModeChanger()
{
	if (ijike_flg == true)
	{
		//一定時間でイジケ終了
		if (++IjikeCount % IjikeTime == 0)
		{
			ijike_flg = false;
			IjikeCount = 0;
			TrackPattern = 0;
		}
	}


	if (EnemyMode != MODE::STANDBY && ijike_flg == true && eye_flg != true) EnemyMode = MODE::IJIKE;
	else if (eye_flg == true) EnemyMode = MODE::EYE;
}

//イジケ状態の挙動
void ENEMY_BASE::Move_Ijike()
{
	if (TrackPattern == 0)
	{
		//ランダムに動く X 4～22    y 4～24
		MoveTarget.x = (GetRand(18) + 4) * MAP_SIZE + (MAP_SIZE / 2);
		MoveTarget.y = (GetRand(20) + 4) * MAP_SIZE + (MAP_SIZE / 2);

		//ターゲット座標がステージ外の場合、ステージ内に戻す
		if (MoveTarget.x < L_END) MoveTarget.x = L_END + (MAP_SIZE / 2);
		if (MoveTarget.x > R_END) MoveTarget.x = R_END - (MAP_SIZE / 2);
		if (MoveTarget.y < U_END) MoveTarget.y = U_END + (MAP_SIZE / 2);
		if (MoveTarget.y > D_END) MoveTarget.y = D_END - (MAP_SIZE / 2);
		//ターゲット座標が"コ"の字外の場合、ステージ内に戻す
		//左側上
		if (MoveTarget.x< L_WALL_X && MoveTarget.y>U_WALL_Y1 && MoveTarget.x < L_WALL_X && MoveTarget.y < D_WALL_Y1) MoveTarget.x = L_WALL_X + (MAP_SIZE / 2);
		//左側下
		if (MoveTarget.x< L_WALL_X && MoveTarget.y>U_WALL_Y2 && MoveTarget.x < L_WALL_X && MoveTarget.y < D_WALL_Y2)MoveTarget.x = L_WALL_X + (MAP_SIZE / 2);
		//右側上
		if (MoveTarget.x > R_WALL_X && MoveTarget.y > U_WALL_Y1 && MoveTarget.x > R_WALL_X && MoveTarget.y < D_WALL_Y1) MoveTarget.x = R_WALL_X - (MAP_SIZE / 2);
		//右側下
		if (MoveTarget.x > R_WALL_X && MoveTarget.y > U_WALL_Y2 && MoveTarget.x > R_WALL_X && MoveTarget.y < D_WALL_Y2) MoveTarget.x = R_WALL_X - (MAP_SIZE / 2);

		TrackPattern++;
	}
	else if (TrackPattern >= 1)
	{
		if (TrackPattern >= 1 && CheckRandomPoint() == 3) TrackPattern = 0;
		else TrackPattern++;
	}

	//イジケ終了時に以前のモードに戻る
	if (IjikeCount % IjikeTime == 0 && EnemyMode != MODE::R_EYE && EnemyMode != MODE::EYE) EnemyMode = old_mode;
}

//"目"状態の挙動
void ENEMY_BASE::Move_Eye()
{
	//巣の中の初期位置               初  x                    初  y
	MoveTarget = { SbyPoint[0][0][0],SbyPoint[0][0][0] };

	//巣に到着後
	if (CheckTarget3() == 3)
	{
		eye_flg = false;
		ijike_flg = false;
		EnemyMode = MODE::R_EYE;
	}
}

//目→イジケ以前のモードに
void ENEMY_BASE::Move_R_Eye()
{
	//巣の上
	MoveTarget.x = ON_NEST[0];
	MoveTarget.y = ON_NEST[1];

	//到達後、イジケ以前のモードに戻す
	if (CheckTarget3() == 3)
	{
		EnemyMode = old_mode;
	}
}

//イジケ時に食べられる
void ENEMY_BASE::Eaten_OnIjike(float px, float py, float pr, int& score)
{
	if (CheckHitCircle(px, py, pr) == true && ijike_flg == true) eye_flg = true;

	//スコア加算
	//score+= //スコア

	//その場にスコア表示
}

//'引数'と敵との当たり判定
bool ENEMY_BASE::CheckHitCircle(float x, float y, float r)
{
	float dx = g_enemy.x - x;             //x座標の差分
	float dy = g_enemy.y - y;             //y座標の差分
	float dis = sqrtf((dx * dx) + (dy * dy));  //2つの円の距離

	if (dis < 6.5f + r) return true;    //2点の距離<=A半径+B半径
	else false;
}

/************************************************/

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
			DrawFormatString(x, y + DRAW_POINT_X, 0xffffff, "TarMapX : %d", All_Enemy[i]->MoveTarget.x / MAP_SIZE);
			DrawFormatString(x, y + 260, 0xffffff, "TarMapY : %d", All_Enemy[i]->MoveTarget.y / MAP_SIZE);
			DrawFormatString(x, y + 280, 0xffffff, "Speed : %d", All_Enemy[i]->g_enemy.speed);
		}
	}

}

//巡回モード用座標
const int ENEMY_BASE::PtrlPoint[4][4][2] =
{
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

//出撃前座標
const int ENEMY_BASE::SbyPoint[4][3][2]
{
	//アカ  ※アカは巡回モードなし
	{
		{13 * MAP_SIZE + (MAP_SIZE / 2),13 * MAP_SIZE + (MAP_SIZE / 2)},  //初期位置
		{13 * MAP_SIZE + (MAP_SIZE / 2),12 * MAP_SIZE + (MAP_SIZE / 2)},  //上部
		{13 * MAP_SIZE + (MAP_SIZE / 2),14 * MAP_SIZE + (MAP_SIZE / 2)}   //下部
	},
	//ピンク
	{
		{13 * MAP_SIZE + (MAP_SIZE / 2),13 * MAP_SIZE + (MAP_SIZE / 2)},  //初期位置
		{13 * MAP_SIZE + (MAP_SIZE / 2),12 * MAP_SIZE + (MAP_SIZE / 2)},  //上部
		{13 * MAP_SIZE + (MAP_SIZE / 2),14 * MAP_SIZE + (MAP_SIZE / 2)},  //下部
	},
	//アオ
	{
		{11 * MAP_SIZE + (MAP_SIZE / 2),13 * MAP_SIZE + (MAP_SIZE / 2)},  //初期位置
		{11 * MAP_SIZE + (MAP_SIZE / 2),12 * MAP_SIZE + (MAP_SIZE / 2)},  //上部
		{11 * MAP_SIZE + (MAP_SIZE / 2),14 * MAP_SIZE + (MAP_SIZE / 2)},  //下部
	},
	//オレンジ
	{
		{15 * MAP_SIZE + (MAP_SIZE / 2),13 * MAP_SIZE + (MAP_SIZE / 2)},  //初期位置
		{15 * MAP_SIZE + (MAP_SIZE / 2),12 * MAP_SIZE + (MAP_SIZE / 2)},  //上部
		{15 * MAP_SIZE + (MAP_SIZE / 2),14 * MAP_SIZE + (MAP_SIZE / 2)},  //下部
	},
};

void ENEMY_BASE::SetMoveDir(int D) {
	MoveDir = D;
}

void ENEMY_BASE::EnemyController() {
	EX = g_enemy.x;
	EY = g_enemy.y;
	EXC = g_enemy.x / MAP_SIZE;
	EYC = g_enemy.y / MAP_SIZE;

	BOX				box[783] = { 0 };
	BOX1			boxP[4] = { 0 };

	oldX = g_enemy.x;
	oldY = g_enemy.y;

	OldKeyFlg = MoveDir;

	if (data[EYC][EXC - 1].status == 1) {
		if (LC >= 783) {
			MoveDir = DIRECTION::LEFT;
			MoveDir = LEFT;
			NEXTFLG = 0;
		}
		else if (LC <= 782) {
			NEXTFLG = LEFT;
		}
	}
	if (data[EYC][EXC + 1].status == 1) {
		if (RC >= 783) {
			MoveDir = DIRECTION::RIGHT;
			MoveDir = RIGHT;
			NEXTFLG = 0;
		}
		else if (RC <= 782) {
			NEXTFLG = RIGHT;
		}
	}
	if (data[EYC - 1][EXC].status == 1) {
		if (UC >= 783) {
			MoveDir = DIRECTION::UP;
			MoveDir = UP;
			NEXTFLG = 0;
		}
		else if (UC <= 782) {
			NEXTFLG = UP;
		}
	}
	if (data[EYC + 1][EXC].status == 1) {
		if (DC >= 783) {
			MoveDir = DIRECTION::DOWN;
			MoveDir = DOWN;
			NEXTFLG = 0;
		}
		else if (DC <= 782) {
			NEXTFLG = DOWN;
		}
	}

	/*if (MapData[EYC][EXC - 1] == 1) {
		if (LC >= 783) {
			MoveDir = DIRECTION::LEFT;
			MoveDir = LEFT;
			NEXTFLG = 0;
		}
		else if (LC <= 782) {
			NEXTFLG = LEFT;
		}
	}
	if (MapData[EYC][EXC + 1] == 1) {
		if (RC >= 783) {
			MoveDir = DIRECTION::RIGHT;
			MoveDir = RIGHT;
			NEXTFLG = 0;
		}
		else if (RC <= 782) {
			NEXTFLG = RIGHT;
		}
	}
	if (MapData[EYC - 1][EXC] == 1) {
		if (UC >= 783) {
			MoveDir = DIRECTION::UP;
			MoveDir = UP;
			NEXTFLG = 0;
		}
		else if (UC <= 782) {
			NEXTFLG = UP;
		}
	}
	if (MapData[EYC + 1][EXC] == 1) {
		if (DC >= 783) {
			MoveDir = DIRECTION::DOWN;
			MoveDir = DOWN;
			NEXTFLG = 0;
		}
		else if (DC <= 782) {
			NEXTFLG = DOWN;
		}
	}*/

	//if (MapData[EYC][EXC - 1] == 1) {
	//	if (LC >= 783) {
	//		MoveDir = LEFT;
	//		NEXTFLG = 0;
	//	}
	//	else if (LC <= 782) {
	//		NEXTFLG = LEFT;
	//	}
	//}
	//if (MapData[EYC][EXC + 1] == 1) {
	//	if (RC >= 783) {
	//		MoveDir = RIGHT;
	//		NEXTFLG = 0;
	//	}
	//	else if (RC <= 782) {
	//		NEXTFLG = RIGHT;
	//	}
	//}
	//if (MapData[EYC - 1][EXC] == 1) {
	//	if (UC >= 783) {
	//		MoveDir = UP;
	//		NEXTFLG = 0;
	//	}
	//	else if (UC <= 782) {
	//		NEXTFLG = UP;
	//	}
	//}
	//if (MapData[EYC + 1][EXC] == 1) {
	//	if (DC >= 783) {
	//		MoveDir = DOWN;
	//		NEXTFLG = 0;
	//	}
	//	else if (DC <= 782) {
	//		NEXTFLG = DOWN;
	//	}
	//}

	//if (a_star.data[EYC][EXC - 1].status == 1/* && FLG_MAX_L == true*/) {
	//	MoveDir = LEFT;
	//}
	//if (a_star.data[EYC][EXC + 1].status == 1/* && FLG_MAX_R == true*/) {
	//	MoveDir = RIGHT;
	//}
	//if (a_star.data[EYC - 1][EXC].status == 1/* && FLG_MAX_U == true*/) {
	//	MoveDir = UP;
	//}
	//if (a_star.data[EYC + 1][EXC].status == 1/* && FLG_MAX_D == true*/) {
	//	MoveDir = DOWN;
	//}

	switch (MoveDir)
	{
	case LEFT:
		//PX -= 3;
		if (FLG_MAX_L == true && NEXTFLG == LEFT) {
			//EX -= 4;
			g_enemy.x -= 3;
		}
		else {
			//EX -= 3;
			g_enemy.x -= 3;
		}
		//DrawGraph(PX, PY, image.PlayerImageL, TRUE);
		//DrawGraph(PX - 15, PY - 15, image.PlayerImageL, TRUE);
		//DrawGraph(EX - 15, EY - 15, image.g_T01Image, TRUE);
		break;
	case RIGHT:
		//PX += 3;
		if (FLG_MAX_R == true && NEXTFLG == RIGHT) {
			//EX += 4;
			g_enemy.x += 4;
		}
		else {
			//EX += 3;
			g_enemy.x += 3;
		}
		//DrawGraph(PX - 15, PY - 15, image.PlayerImageR, TRUE);
		//DrawGraph(EX - 15, EY - 15, image.g_T01Image, TRUE);
		break;
	case UP:
		//PY -= 3;
		if (FLG_MAX_U == true && NEXTFLG == UP) {
			//EY -= 4;
			g_enemy.y -= 4;
		}
		else {
			//EY -= 3;
			g_enemy.y -= 3;
		}
		//DrawGraph(PX - 15, PY - 15, image.PlayerImageU, TRUE);
		//DrawGraph(EX - 15, EY - 15, image.g_T01Image, TRUE);
		break;
	case DOWN:
		//PY += 3;
		if (FLG_MAX_D == true && NEXTFLG == DOWN) {
			//EY += 4;
			g_enemy.y += 4;
		}
		else {
			//EY += 3;
			g_enemy.y += 3;
		}
		//DrawGraph(PX, PY, image.PlayerImageD, TRUE);
		//DrawGraph(PX - 15, PY - 15, image.PlayerImageD, TRUE);
		break;
	default:
		//DrawGraph(PX, PY, image.g_PlayerImage, TRUE);
		//DrawGraph(PX - 15, PY - 15, image.g_PlayerImage, TRUE);
		//DrawGraph(EX - 15, EY - 15, image.g_T01Image, TRUE);
		break;

	}

	CIRCLE			circle;

	circle.x = g_enemy.x + DRAW_POINT_X;
	circle.y = g_enemy.y + DRAW_POINT_Y;
	circle.r = 14.5f;

	DrawFormatString(50, 650, 0x0000ff, "%d", circle.x);
	DrawFormatString(50, 680, 0x0000ff, "%d", circle.y);
	DrawFormatString(100, 650, 0x0000ff, "%d", g_enemy.x);
	DrawFormatString(100, 680, 0x0000ff, "%d", g_enemy.y);

	C = 0;
	CF = 0;
	for (I = 0; I < MAP_HEIGHT; I++) {
		for (J = 0; J < MAP_WIDTH; J++) {

			try {


				if (stage.getMap(I, J) != 0) {
					box[C].fLeft[CF] = DRAW_POINT_X + (J * 30);
					box[C].fTop[CF] = DRAW_POINT_Y + (I * 30);
					box[C].fRight[CF] = DRAW_POINT_X + (J * 30) + 30;
					box[C].fBottom[CF] = DRAW_POINT_Y + (I * 30) + 30;


					if (CheckHit(box[C], circle))
					{
						//DrawCircle(circle.x, circle.y, circle.r, GetColor(125, 125, 125));
						//DrawBox(box[C].fLeft[CF], box[C].fTop[CF], box[C].fRight[CF], box[C].fBottom[CF], GetColor(125, 125, 125), true);
						NextKeyFlg = MoveDir;
						//EX = oldX;
						//EY = oldY;
						if (oldX % 5 != 0) {
							oldX -= oldX % 10;
							oldX += 5;
						}
						if (oldY % 5 != 0) {
							oldY -= oldY % 10;
							oldY += 5;
						}
						g_enemy.x = oldX;
						g_enemy.y = oldY;
						MoveDir = OldKeyFlg;
					}
					else
					{
						//DrawCircle(circle.x, circle.y, circle.r, GetColor(255, 255, 255));
						//DrawBox(box[C].fLeft[CF], box[C].fTop[CF], box[C].fRight[CF], box[C].fBottom[CF], GetColor(125, 125, 125), true);
					}
					//DrawFormatString(box[C].fLeft[C], box[C].fTop[C], 0xFF00FF, "%d", C);

				}
			}
			catch (int p) {
				break;
			}

			C++;
		}
	}
	I = 0;
	J = 0;
	C = 0;

	LC = 0;
	RC = 0;
	UC = 0;
	DC = 0;
	for (CI = 0; CI < 783; CI++) {
		for (I = 0; I < 4; I++) {

			switch (I)
			{
			case 0://Left
				boxP[I].fLeft[I] = g_enemy.x - 20 + DRAW_POINT_X;
				boxP[I].fTop[I] = g_enemy.y - 15 + DRAW_POINT_Y;
				boxP[I].fRight[I] = g_enemy.x - 15 + 30.0f + DRAW_POINT_X;
				boxP[I].fBottom[I] = g_enemy.y - 15 + 30.0f + DRAW_POINT_Y;
				break;
			case 1://Up
				boxP[I].fLeft[I] = g_enemy.x - 15 + DRAW_POINT_X;
				boxP[I].fTop[I] = g_enemy.y - 20 + DRAW_POINT_Y;
				boxP[I].fRight[I] = g_enemy.x - 15 + 30.0f + DRAW_POINT_X;
				boxP[I].fBottom[I] = g_enemy.y - 10 + 25.0f + DRAW_POINT_Y;
				break;
			case 2://Right
				boxP[I].fLeft[I] = g_enemy.x - 15 + DRAW_POINT_X;
				boxP[I].fTop[I] = g_enemy.y - 15 + DRAW_POINT_Y;
				boxP[I].fRight[I] = g_enemy.x - 15 + 35.0f + DRAW_POINT_X;
				boxP[I].fBottom[I] = g_enemy.y - 15 + 30.0f + DRAW_POINT_Y;
				break;
			case 3://Down
				boxP[I].fLeft[I] = g_enemy.x - 15 + DRAW_POINT_X;
				boxP[I].fTop[I] = g_enemy.y - 15 + DRAW_POINT_Y;
				boxP[I].fRight[I] = g_enemy.x - 15 + 30.0f + DRAW_POINT_X;
				boxP[I].fBottom[I] = g_enemy.y - 15 + 35.0f + DRAW_POINT_Y;
				break;

			default:
				break;
			}

			if (CheckHitBOX(box[CI], boxP[I]))
			{
				//DrawCircle(circle.x, circle.y, circle.r, GetColor(125, 125, 125));
				/*if (I == 0)DrawBox(boxP[I].fLeft[I], boxP[I].fTop[I], boxP[I].fRight[I], boxP[I].fBottom[I], GetColor(75, 75, 125), true);
				if (I == 1)DrawBox(boxP[I].fLeft[I], boxP[I].fTop[I], boxP[I].fRight[I], boxP[I].fBottom[I], GetColor(75, 95, 55), true);
				if (I == 2)DrawBox(boxP[I].fLeft[I], boxP[I].fTop[I], boxP[I].fRight[I], boxP[I].fBottom[I], GetColor(95, 0, 125), true);
				if (I == 3)DrawBox(boxP[I].fLeft[I], boxP[I].fTop[I], boxP[I].fRight[I], boxP[I].fBottom[I], GetColor(25, 30, 185), true);*/

				/*EX = oldX;
				EY = oldY;*/

				if (I == 0)FLG_L = CI;
				if (I == 1)FLG_U = CI;
				if (I == 2)FLG_R = CI;
				if (I == 3)FLG_D = CI;

				NextKeyFlg = MoveDir;


			}
			else
			{
				//DrawCircle(circle.x, circle.y, circle.r, GetColor(255, 255, 255));
				/*if (I == 0)DrawBox(boxP[I].fLeft[I], boxP[I].fTop[I], boxP[I].fRight[I], boxP[I].fBottom[I], GetColor(75, 75, 125), false);
				if (I == 1)DrawBox(boxP[I].fLeft[I], boxP[I].fTop[I], boxP[I].fRight[I], boxP[I].fBottom[I], GetColor(75, 95, 55), false);
				if (I == 2)DrawBox(boxP[I].fLeft[I], boxP[I].fTop[I], boxP[I].fRight[I], boxP[I].fBottom[I], GetColor(95, 0, 125), false);
				if (I == 3)DrawBox(boxP[I].fLeft[I], boxP[I].fTop[I], boxP[I].fRight[I], boxP[I].fBottom[I], GetColor(25, 30, 185), false);*/

				if (I == 0)LC++;
				if (I == 1)UC++;
				if (I == 2)RC++;
				if (I == 3)DC++;

			}
			//DrawFormatString(boxP[I].fLeft[I], boxP[I].fTop[I], 0xFF00FF, "%d", I);
		}

		I = 0;
	}
	CI = 0;

	if (LC >= 783) {
		FLG_MAX_L = true;
	}
	else if (LC <= 782) {
		FLG_MAX_L = false;
	}
	if (RC >= 783) {
		FLG_MAX_R = true;
	}
	else if (RC <= 782) {
		FLG_MAX_R = false;
	}
	if (UC >= 783) {
		FLG_MAX_U = true;
	}
	else if (UC <= 782) {
		FLG_MAX_U = false;
	}
	if (DC >= 783) {
		FLG_MAX_D = true;
	}
	else if (DC <= 782) {
		FLG_MAX_D = false;
	}

	if (NEXTFLG != 0) {
		if (FLG_MAX_L == true && NEXTFLG == LEFT) {
			//MoveDir = NEXTFLG;
			MoveDir = NEXTFLG;
			NEXTFLG = 0;
		}
		if (FLG_MAX_R == true && NEXTFLG == RIGHT) {
			//MoveDir = NEXTFLG;
			MoveDir = NEXTFLG;
			NEXTFLG = 0;
		}
		if (FLG_MAX_U == true && NEXTFLG == UP) {
			//MoveDir = NEXTFLG;
			MoveDir = NEXTFLG;
			NEXTFLG = 0;
		}
		if (FLG_MAX_D == true && NEXTFLG == DOWN) {
			//MoveDir = NEXTFLG;
			MoveDir = NEXTFLG;
			NEXTFLG = 0;
		}
	}

	//if (keyFlg & PAD_INPUT_B)DFLG = true;
	//if (keyFlg & PAD_INPUT_A)DFLG = false;

	//if (DFLG == true) {

		//for (int i = 0; i < 27; i++) {
		//	for (int j = 0; j < 29; j++) {
		//		if (MapData[j][i] == 1) {
		//			DrawFormatString(10 + (i * 20), 20 + (j * 20), 0xff0000, "%d", MapData[j][i]);
		//		}
		//		else if (MapData[j][i] == 0) {
		//			DrawFormatString(10 + (i * 20), 20 + (j * 20), 0xffffff, "%d", MapData[j][i]);
		//		}
		//		else if (MapData[j][i] == 2) {
		//			DrawFormatString(10 + (i * 20), 20 + (j * 20), 0xff00ff, "%d", MapData[j][i]);
		//		}
		//		else {
		//			DrawFormatString(10 + (i * 20), 20 + (j * 20), 0x0000ff, "%d", MapData[j][i]);
		//		}
		//		//DrawFormatString(10 + (i * 30), 20 + (j * 30), 0xffffff, "%d" ,stage.getMap[j][i]);
		//	}
		//}
	DrawFormatString(1100, 20, 0x0000ff, "%d", EYC);
	DrawFormatString(1100, 30, 0x0000ff, "%d", EY);
	DrawFormatString(1100, 60, 0x0000ff, "%d", MoveDir);
	DrawFormatString(1100, 80, 0x0000ff, "%d", NextKeyFlg);

	//DrawCircle(circle.x, circle.y, circle.r, GetColor(255, 255, 255));

	//DrawCircle(circle.x, circle.y, circle.r, GetColor(255, 255, 255));

	//a_star.main(g_player.PXC, g_player.PYC, EXC, EYC);

//}

//DrawGraph(EX - 15, EY - 15, image.g_T01Image, TRUE);

	if (g_enemy.x <= 105 && g_enemy.y == 405 && MoveDir == LEFT) {
		g_enemy.x = 705;
	}
	if (g_enemy.x >= 705 && g_enemy.y == 405 && MoveDir == RIGHT) {
		g_enemy.x = 105;
	}
	/*if (EX + DRAW_POINT_X <= 340 && EY+ DRAW_POINT_Y == 330 && MoveDir == LEFT) {
		EX = 940;
	}
	if (EX + DRAW_POINT_X >= 940 && EY + DRAW_POINT_Y == 330 && MoveDir == RIGHT) {
		EX = 340;
	}*/

	if (EX <= 429 && EY == 405 && MoveDir == LEFT) {
		EX += 1;
	}
	if (EX <= 429 && EY == 405 && MoveDir == RIGHT) {
		EX -= 1;
	}
	if (EX >= 851 && EY == 405 && MoveDir == LEFT) {
		EX += 1;
	}
	if (EX >= 851 && EY == 405 && MoveDir == RIGHT) {
		EX -= 1;
	}

	/*if (EY == 330) {
		if (EX == 762)EX = 760;
		if (EX == 518)EX = 520;
	}*/

	SetMoveDir(MoveDir);

}

float ENEMY_BASE::DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2) {
	float dx = t_x2 - t_x1;
	float dy = t_y2 - t_y1;

	return (dx * dx) + (dy * dy);
}

bool ENEMY_BASE::CheckHit(const BOX& t_box, const CIRCLE& t_circle) {
	bool nResult = false;

	// 四角形の四辺に対して円の半径分だけ足したとき円が重なっていたら
	if ((t_circle.x > t_box.fLeft[CF] - t_circle.r) &&
		(t_circle.x < t_box.fRight[CF] + t_circle.r) &&
		(t_circle.y > t_box.fTop[CF] - t_circle.r) &&
		(t_circle.y < t_box.fBottom[CF] + t_circle.r))
	{
		nResult = true;
		float fl = t_circle.r * t_circle.r;


		// 左
		if (t_circle.x < t_box.fLeft[CF])
		{
			// 左上
			if ((t_circle.y < t_box.fTop[CF]))
			{
				if ((DistanceSqrf(t_box.fLeft[CF], t_box.fTop[CF], t_circle.x, t_circle.y) >= fl))
				{
					nResult = false;
				}
			}
			else
			{
				// 左下
				if ((t_circle.y > t_box.fBottom[CF]))
				{
					if ((DistanceSqrf(t_box.fLeft[CF], t_box.fBottom[CF], t_circle.x, t_circle.y) >= fl))
					{
						nResult = false;
					}
				}
			}
		}
		else
		{
			// 右
			if (t_circle.x > t_box.fRight[CF])
			{
				// 右上
				if ((t_circle.y < t_box.fTop[CF]))
				{
					if ((DistanceSqrf(t_box.fRight[CF], t_box.fTop[CF], t_circle.x, t_circle.y) >= fl))
					{
						nResult = false;
					}
				}
				else
				{
					// 右下
					if ((t_circle.y > t_box.fBottom[CF]))
					{
						if ((DistanceSqrf(t_box.fRight[CF], t_box.fBottom[CF], t_circle.x, t_circle.y) >= fl))
						{
							nResult = false;
						}
					}
				}
			}
		}
	}

	return nResult;
}

bool ENEMY_BASE::CheckHit(const BOX1& t_box, const CIRCLE& t_circle) {
	bool nResult = false;

	// 四角形の四辺に対して円の半径分だけ足したとき円が重なっていたら
	if ((t_circle.x > t_box.fLeft[I] - t_circle.r) &&
		(t_circle.x < t_box.fRight[I] + t_circle.r) &&
		(t_circle.y > t_box.fTop[I] - t_circle.r) &&
		(t_circle.y < t_box.fBottom[I] + t_circle.r))
	{
		nResult = true;
		float fl = t_circle.r * t_circle.r;


		// 左
		if (t_circle.x < t_box.fLeft[I])
		{
			// 左上
			if ((t_circle.y < t_box.fTop[I]))
			{
				if ((DistanceSqrf(t_box.fLeft[I], t_box.fTop[I], t_circle.x, t_circle.y) >= fl))
				{
					nResult = false;
				}
			}
			else
			{
				// 左下
				if ((t_circle.y > t_box.fBottom[I]))
				{
					if ((DistanceSqrf(t_box.fLeft[I], t_box.fBottom[I], t_circle.x, t_circle.y) >= fl))
					{
						nResult = false;
					}
				}
			}
		}
		else
		{
			// 右
			if (t_circle.x > t_box.fRight[I])
			{
				// 右上
				if ((t_circle.y < t_box.fTop[I]))
				{
					if ((DistanceSqrf(t_box.fRight[I], t_box.fTop[I], t_circle.x, t_circle.y) >= fl))
					{
						nResult = false;
					}
				}
				else
				{
					// 右下
					if ((t_circle.y > t_box.fBottom[I]))
					{
						if ((DistanceSqrf(t_box.fRight[I], t_box.fBottom[I], t_circle.x, t_circle.y) >= fl))
						{
							nResult = false;
						}
					}
				}
			}
		}
	}

	return nResult;
}

bool ENEMY_BASE::CheckHitBOX(const BOX& t_direA, const BOX1& t_direB)
{
	if ((t_direA.fRight[CF] > t_direB.fLeft[I]) &&
		(t_direA.fLeft[CF] < t_direB.fRight[I]))
	{
		if ((t_direA.fBottom[CF] > t_direB.fTop[I]) &&
			(t_direA.fTop[CF] < t_direB.fBottom[I]))
		{
			return true;
		}
	}

	return false;
}

void ENEMY_BASE::MapCopy() {
	//static int P = 0;
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			//if (P == 0) {
				//MapData[h][w] = a_star.data[h][w].status;
			MapData[h][w] = data[h][w].status;
			//}else if (P == 1) {
			//	//MapData[h][w] = a_star_pink.data[h][w].status;
			//	MapData[h][w] = data[h][w].status;
			//}
			//else if (P == 2) {
			//	//MapData[h][w] = a_star_inky.data[h][w].status;
			//	MapData[h][w] = data[h][w].status;
			//}
			//else if (P == 3) {
			//	//MapData[h][w] = a_star_clyde.data[h][w].status;
			//	MapData[h][w] = data[h][w].status;
			//}

		}
	}
	//if (P++ > 4)P = 0;
}

void ENEMY_BASE::ResetSearchStatus(void)
{
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			data[h][w].cost = 0;
			data[h][w].SearchStatus = 0;
		}
	}
	//return;
}

void ENEMY_BASE::SetDefault(void)
{
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			data[h][w].status = def_data[h][w];
		}
	}

	//return;
}

void ENEMY_BASE::out(void)
{
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			char ch = ' ';
			if (w == GX && h == GY) ch = '*';
			if (w == SX && h == SY) ch = '@';

			printf("%c", ch);

			if (data[h][w].status > 0)  ch = 'o';
			if (data[h][w].status < 0)  ch = '#';
			if (data[h][w].status == 0) ch = '.';

			printf("%c", ch);
		}
		printf("\n");
	}
	printf("OK.\n");
	//return;
}

// マンハッタン距離を斜め移動ありを考慮して求める
int ENEMY_BASE::GetDistance(int from_x, int from_y, int to_x, int to_y)
{
	int cx = from_x - to_x;
	int cy = from_y - to_y;

	if (cx < 0) cx *= -1;
	if (cy < 0) cy *= -1;

	// 推定移動コストを計算
	if (cx < cy) {
		return (cx + (cy - cx));
	}
	else {
		return (cy + (cx - cy));
	}
}

int ENEMY_BASE::BackTrace(int x, int y)
{
	if (x == SX && y == SY) return 1;

	int parent_way = data[y][x].parent;

	return BackTrace(
		x + CheckMatrix[parent_way].x,
		y + CheckMatrix[parent_way].y
	) + 1;
}

// A*で経路探査する
int ENEMY_BASE::Search(int count) {

	int cost_min = 9999;
	int BackCost = 0;
	int CX = 0;
	int CY = 0;

	mapcell* n = NULL;

	// コストが最小のオープンノードを探す
	// TODO: ここを全マス探査しないようにすると、
	//       もっと早くなるかも
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {

			if (data[h][w].SearchStatus != SEARCH_OPEN)continue;
			if (GetDistance(w, h, GX, GY) > cost_min)continue;

			cost_min = GetDistance(w, h, GX, GY);
			n = &data[h][w];

			CX = w;
			CY = h;
		}
	}

	// オープンノードがなければ終了(ゴールが見つからない)
	if (n == NULL) return -9;

	// ノードをクローズする
	n->SearchStatus = SEARCH_CLOSE;

	BackCost = BackTrace(CX, CY);

	for (int i = 0; i < 4; i++) {

		int check_x = CX + CheckMatrix[i].x;
		int check_y = CY + CheckMatrix[i].y;

		/*if (CheckMatrix[i].x == 1) {
			X2++;
		}
		if (X2 == 1) {
			if (CheckMatrix[i].x == -1) {

			}
		}*/

		/*if (g_enemy_Red.VectorFlg == 1 && CheckMatrix[i].x == 1) {
			continue;
		}
		else if (g_enemy_Red.VectorFlg == 2 && CheckMatrix[i].x == -1) {
			continue;
		}
		else if (g_enemy_Red.VectorFlg == 3 && CheckMatrix[i].y == 1) {
			continue;
		}
		else if (g_enemy_Red.VectorFlg == 4 && CheckMatrix[i].y == -1) {
			continue;
		}*/

		if (check_x < 0) continue;
		if (check_y < 0) continue;

		if (check_x >= WIDTH) continue;
		if (check_y >= HEIGHT) continue;

		// 通れないところをよける
		if (data[check_y][check_x].status == -1) continue;

		int estimate_cost = BackCost + GetDistance(check_x, check_y, GX, GY) + 1;

		mapcell* cell = &data[check_y][check_x];

		if (data[check_y][check_x].SearchStatus == SEARCH_NO_CHECK) {

			cell->parent = (i + 2) % 4;
			cell->SearchStatus = SEARCH_OPEN;

		}
		else if (estimate_cost < cell->cost) {

			cell->parent = (i + 2) % 4;
			cell->cost = estimate_cost;
			cell->SearchStatus = SEARCH_OPEN;

		}
	}

	// 見つかったら探索終了
	if (CX == GX && CY == GY) {
		return -1;
	}

	return Search(count + 1);
}

void ENEMY_BASE::TraceRoute(int x, int y)
{
	//if (x == SX && y == SY) {
	if (x == SX && y == SY) {
		/*if (g_enemy_Red.VectorFlg == 1) {
			data[SY][SX - 1].status = -1;
			data[SY][SX - 2].status = -1;
		}
		else if (g_enemy_Red.VectorFlg == 2) {
			data[SY][SX + 1].status = -1;
			data[SY][SX + 2].status = -1;
		}
		else if (g_enemy_Red.VectorFlg == 3) {
			data[SY - 1][SX].status = -1;
			data[SY - 2][SX].status = -1;
		}
		else if (g_enemy_Red.VectorFlg == 4) {
			data[SY + 1][SX].status = -1;
			data[SY + 2][SX].status = -1;
		}*/
		//data[y][x].status = -1;
		printf("開始ノード>");
		return;
	}
	d = x;
	f = y;

	/*if (data[y][x].status == 2) {
		DX = d;
		DY = f;
		DFlg = true;
	}*/

	POINT* parent_way = &CheckMatrix[data[y][x].parent];

	data[y][x].status = 1;

	if (y == 14) {
		if (x <= 4 && &CheckMatrix[1]) {
			data[14][25].status = -1;
			//x = 24;
		}
		else if (x >= 24 && &CheckMatrix[3]) {
			data[14][3].status = -1;
			//x = 4;
		}
	}

	/*if (CheckMatrix->x == 1) {
		OldXP = XP;
		XP = 1;
	}
	if (CheckMatrix->y == 1)
	if (CheckMatrix->x == -1)
	if (CheckMatrix->y == -1)

	if(XP>=2)*/

	try {
		TraceRoute(x + parent_way->x, y + parent_way->y);
		//throw 1;
	}
	catch (int o) {
		GX = (910 - DRAW_POINT_X) / 30;
		GY = (60 - DRAW_POINT_X) / 30;
	}

	if (d == GX && f == GY) {
		//TraceRoute(x + parent_way->x, y + parent_way->y);
		printf("ゴール\n");
		return;
	}
	else {
		printf("(%d,%d)>", x, y);
	}
	return;
}

int ENEMY_BASE::_tmain(/*int argc, _TCHAR* argv[]*//*int plX, int plY, int enX, int enY*/)
{
	static int E = 0;

	SX = g_enemy.x / MAP_SIZE;
	SY = g_enemy.y / MAP_SIZE;
	/*SX = (Red.GetEnemyX() - DRAW_POINT_X) / 30;
	SY = (Red.GetEnemyY() - DRAW_POINT_Y) / 30;*/


	if (E == 0) {//赤

		if (DFlg == false) {

			if (GFlg == false) {

				GX = g_player.PXC;
				GY = g_player.PYC;

				Rand = GetRand(5);

			}
			else if (GFlg == true) {
				GX = g_player.PXC + Rand;
				GY = g_player.PYC + Rand;
				if (Time++ >= 180) {
					Time = 0;
					GFlg = false;
				}
			}

		}
		else if (DFlg == true) {
			GX = DX;
			GY = DY;
		}

		if (SX == GX && SY == GY) {
			GFlg = true;
			DFlg = false;
		}

		//Count = 1;

	}
	else if (E == 1) {//ピンク
		SX = g_enemy.x / MAP_SIZE;
		SY = g_enemy.y / MAP_SIZE;

		//SX = (Red.GetEnemyX() - DRAW_POINT_X) / 30;
		//SY = (Red.GetEnemyY() - DRAW_POINT_Y) / 30;

		if (DFlg == false) {

			GX = g_player.PXC;
			GY = g_player.PYC;



			if (GFlg == false) {

				if (g_player.KEYFLG == 1) {//LEFT
					GX = g_player.PXC - 3;
					GY = g_player.PYC;
				}
				else if (g_player.KEYFLG == 2) {//RIGHT
					GX = g_player.PXC + 3;
					GY = g_player.PYC;
				}
				else if (g_player.KEYFLG == 3) {//UP
					GX = g_player.PXC;
					GY = g_player.PYC - 3;
				}
				else if (g_player.KEYFLG == 4) {//DOWN
					GX = g_player.PXC;
					GY = g_player.PYC + 3;
				}
				else {
					GX = g_player.PXC;
					GY = g_player.PYC;
				}
				do {
					Rand = GetRand(20);
				} while (Rand < 10);
				aas = GetRand(4);
			}
			else if (GFlg == true) {
				if (aas == 0) {
					GX = g_player.PXC + Rand;
					GY = g_player.PYC + Rand;
				}
				else if (aas == 1) {
					GX = g_player.PXC - Rand;
					GY = g_player.PYC + Rand;
				}
				else if (aas == 2) {
					GX = g_player.PXC + Rand;
					GY = g_player.PYC - Rand;
				}
				else if (aas == 3) {
					GX = g_player.PXC - Rand;
					GY = g_player.PYC - Rand;
				}
				if (Time++ >= 180) {
					Time = 0;
					GFlg = false;
				}
			}
		}
		else if (DFlg == true) {
			GX = DX;
			GY = DY;
		}

		if (SX == GX && SY == GY) {
			GFlg = true;
			DFlg = false;
		}
		//Count = 0;
	}
	else if (E == 2) {//水色
		if (DFlg == false) {

			GX = g_player.PXC;
			GY = g_player.PYC;



			if (GFlg == false) {

				if (g_player.PXC < Red.EXC) {
					GX = (Red.EXC - g_player.PXC);
				}
				else if (g_player.PXC > Red.EXC) {
					GX = g_player.PXC - Red.EXC * 2;
				}
				else {
					GX = g_player.PXC;
				}

				if (g_player.PYC < Red.EYC) {
					GY = Red.EYC - g_player.PYC;
				}
				else if (g_player.PYC > Red.EYC) {
					GY = g_player.PYC + Red.EYC * 2;
				}
				else {
					GY = g_player.PYC;
				}
				do {
					Rand = GetRand(20);
				} while (Rand < 10);
				aas = GetRand(4);
			}
			else if (GFlg == true) {
				if (aas == 0) {
					GX = g_player.PXC + Rand;
					GY = g_player.PYC + Rand;
				}
				else if (aas == 1) {
					GX = g_player.PXC - Rand;
					GY = g_player.PYC + Rand;
				}
				else if (aas == 2) {
					GX = g_player.PXC + Rand;
					GY = g_player.PYC - Rand;
				}
				else if (aas == 3) {
					GX = g_player.PXC - Rand;
					GY = g_player.PYC - Rand;
				}
				if (Time++ >= 180) {
					Time = 0;
					GFlg = false;
				}
			}
		}
		else if (DFlg == true) {
			GX = DX;
			GY = DY;
		}

		if (SX == GX && SY == GY) {
			GFlg = true;
			DFlg = false;
		}
	}
	else if (E == 3) {//オレンジ
		if (DFlg == false) {

			GX = g_player.PXC;
			GY = g_player.PYC;



			if (GFlg == false) {

				if (g_player.PXC < Red.EXC) {
					GX = (Red.EXC - g_player.PXC);
				}
				else if (g_player.PXC > Red.EXC) {
					GX = g_player.PXC - Red.EXC * 2;
				}
				else {
					GX = g_player.PXC;
				}

				if (g_player.PYC < Red.EYC) {
					GY = Red.EYC - g_player.PYC;
				}
				else if (g_player.PYC > Red.EYC) {
					GY = g_player.PYC + Red.EYC * 2;
				}
				else {
					GY = g_player.PYC;
				}
				do {
					Rand = GetRand(20);
				} while (Rand < 10);
				aas = GetRand(4);
			}
			else if (GFlg == true) {
				if (aas == 0) {
					GX = g_player.PXC + Rand;
					GY = g_player.PYC + Rand;
				}
				else if (aas == 1) {
					GX = g_player.PXC - Rand;
					GY = g_player.PYC + Rand;
				}
				else if (aas == 2) {
					GX = g_player.PXC + Rand;
					GY = g_player.PYC - Rand;
				}
				else if (aas == 3) {
					GX = g_player.PXC - Rand;
					GY = g_player.PYC - Rand;
				}
				if (Time++ >= 180) {
					Time = 0;
					GFlg = false;
				}
			}
		}
		else if (DFlg == true) {
			GX = DX;
			GY = DY;
		}

		if (SX == GX && SY == GY) {
			GFlg = true;
			DFlg = false;
		}
		//Count = 0;
	}



	/*GX = g_player.PXC;
	GY = g_player.PYC;*/

	/*SX = plX;
	SY = plY;

	GX = enX;
	GY = enY;*/

	if (GX <= 0)GX = 1;
	if (GX >= 27)GX = 26;
	if (GY <= 0)GY = 1;
	if (GY >= 29)GY = 28;

	/*a_star.SetDefault();
	a_star.ResetSearchStatus();*/
	SetDefault();
	ResetSearchStatus();

	if (GetMoveDir() == DIRECTION::LEFT) {
		data[SY][SX + 1].status = -1;
		//data[SY][SX + 2].status = -1;
	}
	else if (GetMoveDir() == DIRECTION::RIGHT) {
		data[SY][SX - 1].status = -1;
		//data[SY][SX - 2].status = -1;
	}
	else if (GetMoveDir() == DIRECTION::UP) {
		data[SY + 1][SX].status = -1;
		//data[SY + 2][SX].status = -1;
	}
	else if (GetMoveDir() == DIRECTION::DOWN) {
		data[SY - 1][SX].status = -1;
		//data[SY - 2][SX].status = -1;
	}

	if (DFlg == false) {
		if (def_data[EYC][EXC] == 2) {
			if (Timer == 0) {
				XP = SX;
				YP = SY;
			}
			if (Timer <= 180) {
				if (VectorFlg == 1) {
					data[YP][XP + 1].status = -1;
					data[YP][XP + 2].status = -1;
				}
				else if (VectorFlg == 2) {
					data[YP][XP - 1].status = -1;
					data[YP][XP - 2].status = -1;
				}
				else if (VectorFlg == 3) {
					data[YP + 1][XP].status = -1;
					data[YP + 2][XP].status = -1;
				}
				else if (VectorFlg == 4) {
					data[YP - 1][XP].status = -1;
					data[YP - 2][XP].status = -1;
				}
				Timer++;
			}
			else {
				Timer = 0;
			}
		}
	}

	/*if (g_enemy_Red.EX <= 429 && g_enemy_Red.EY == 330 && g_enemy_Red.VectorFlg == 1) {
		data[13][7].status = -1;
	}
	if (g_enemy_Red.EX >= 851 && g_enemy_Red.EY == 330 && g_enemy_Red.VectorFlg == 2) {
		data[13][19].status = -1;
	}*/

	/*if (g_enemy_Red.EY >= 230) {
		data[8][12].status = -1;
		data[8][14].status = -1;
	}
	if (g_enemy_Red.EY >= 530) {
		data[18][12].status = -1;
		data[18][14].status = -1;
	}*/

	/*if (g_enemy_Red.EY >= 535) {
		data[20][13].status = -1;
		data[20][15].status = -1;
	}*/

	//a_star.data[SY][SX].SearchStatus = a_star.SEARCH_OPEN;
	data[SY][SX].SearchStatus = SEARCH_OPEN;

	//a_star.Search(0);
	Search(0);

	//a_star.TraceRoute(GX, GY);
	TraceRoute(GX, GY);
	//a_star.out();
	out();

	E++;
	if (E >= 5)E = 0;

	return 0;
}

//void A_star::A_STAR()
//{
//
//	SetDefault();
//	ResetSearchStatus();
//
//	data[SY][SX].SearchStatus = SEARCH_OPEN;
//
//	Search(0);
//
//	TraceRoute(GX, GY);
//	out();
//
//}

void ENEMY_BASE::A_starInit() {
	//SX = (Red.GetEnemyX() - DRAW_POINT_X) / 30;
	//SY = (Red.GetEnemyY() - DRAW_POINT_Y) / 30;
	SX = g_enemy.x / MAP_SIZE;
	SY = g_enemy.y / MAP_SIZE;

	GX = g_player.PXC;
	GY = g_player.PYC;

	//SX1 = g_enemy_Red.EXC;
	//SY1 = g_enemy_Red.EYC;
}
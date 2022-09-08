#pragma once
#include "Enemy.h"

class ENEMY_BLUE : public ENEMY_BASE
{
public:
	ENEMY_BLUE();       //コンストラクタ
	int Loadimages();   //画像読み込み
	void InitEnemy();   //初期処理
	void MoveEnemy(int MapData[MAP_HEIGHT][MAP_WIDTH]);   //移動
	void MoveEnemy2(int MapData[MAP_HEIGHT][MAP_WIDTH]);

	void DrawEnemy();   //描画

	//移動目標との一致　戻り値　0：x,y座標共に一致ﾅｼ　 1：x座標のみ一致  2：y座標のみ一致　　3:x,y座標共に一致 
	int CheckTarget();

	//ターゲットを設定
	void TargetCtrl(int tpX, int tpY, int tpD);

	//イジケフラグを変更（テスト用）
	void SetIjike() { if (ijike_flg == false) ijike_flg = true; }   


	void EnemyControl();  //敵の挙動(モードによって変化  出撃前/巡回/追跡)

	void Move_StandBy();  //出撃前の挙動
	void Move_Patrol();   //巡回モードの挙動
	void Move_Track();    //追跡モードの挙動

private:
	const int p_speed[4] = { 5,6,7,8 }; //スピード（変化用）
	const int p_score = 3373;           //スコア  
};

extern ENEMY_BLUE Blue;


#pragma once
#include"Enemy.h"

//敵キャラ（ピンク）基底クラスにENEMY_BASE
class ENEMY_RED : public ENEMY_BASE
{
public:
	int Loadimages();   //画像読み込み
	void InitEnemy();   //初期処理
	void MoveEnemy(int MapData[MAP_HEIGHT][MAP_WIDTH]);   //移動
	void MoveEnemy2(int MapData[MAP_HEIGHT][MAP_WIDTH]);

	void DrawEnemy();   //描画

	//移動目標との一致　戻り値　0：x,y座標共に一致ﾅｼ　 1：x座標のみ一致  2：y座標のみ一致　　3:x,y座標共に一致 
	int CheckTarget();

	void TestMove6(int MapData[MAP_HEIGHT][MAP_WIDTH], int NowKey); //テスト

	void TargetCtrl(int tpX, int tpY, int tpD);              //ターゲットを設定

	void SetSortie() { if (sortie_flg == false)sortie_flg = true; } //出撃フラグを変更（テスト用）

	void EnemyControl();  //敵の挙動(モードによって変化  出撃前/巡回/追跡)

	void Move_StandBy();  //出撃前の挙動
	void Move_Patrol();   //巡回モードの挙動
	void Move_Track();    //追跡モードの挙動

private:
	const int p_speed[4] = { 5,6,7,8 }; //スピード（変化用）
	const int p_score = 3373;           //スコア  

	int mode_count = 0;                 //モードチェンジ(巡回・追跡)用にフレームをカウント

	bool sortie_flg = false;            //出撃フラグ　false 待機　　true 出撃
};

extern ENEMY_RED Red;


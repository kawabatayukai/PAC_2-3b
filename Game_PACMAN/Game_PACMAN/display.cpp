#include"DxLib.h"
#include"Info.h"

#include "display.h"

DISPLAY Disp;

//画像読み込み
int DISPLAY::LoadImages()
{
	if ((CircleImage = LoadGraph("images/02_2.png")) == -1) return -1;
	if ((PlayImage = LoadGraph("images/PLAYER.png")) == -1) return -1;
	if ((StartImage = LoadGraph("images/READY.png")) == -1) return -1;
	if ((OverImage = LoadGraph("images/GAMEOVER.png")) == -1) return -1;
	if ((LoadDivGraph("images/PacMan.png", 12, 3, 4, 30, 30, PacManImage)) == -1)return -1;
	if ((LoadDivGraph("images/PacMan_Damage.png", 12, 12, 1, 30, 30, PacManDamageImage)) == -1)return -1;
	if ((g_StageImage = LoadGraph("images/maze_blueV3.1.png")) == -1) return -1;
	if ((g_StageImageW = LoadGraph("images/maze_blueV3.1_w.png")) == -1) return -1;

}

//音声読み込み
int DISPLAY::LoadSounds()
{
	if ((StartBGM = LoadSoundMem("sounds/Start.wav")) == -1) return -1;
}

//初期処理
void DISPLAY::DispInit()
{
	counter = 0;

	//clearcount = 0;
}

//ゲームスタート時
void DISPLAY::DrawStartDisp(GAME_STATE* state, ENEMY_BASE* enemy)
{
	counter++;    //フレームをカウント

	//初回時のみ  音が5秒なら2.5秒間  　　音が4秒なら2秒間
	if (clearcount == 0)
	{
		//BGM再生
		PlaySoundMem(StartBGM, DX_PLAYTYPE_BACK, FALSE);

		if (counter < 120) //  150        音が5秒なら2.5秒間  　　音が4秒なら2秒間
		{
			////"PLAYER"表示
			//DrawGraph(DRAW_POINT_X + 180, DRAW_POINT_Y + 210, PlayImage, TRUE);

			//"PLAYER"表示
			DrawGraph(DRAW_POINT_X + 270, DRAW_POINT_Y + 300, PlayImage, TRUE);
		}
	}

	////"READY!"表示
	//DrawGraph(DRAW_POINT_X + 180, DRAW_POINT_Y + 390, StartImage, TRUE);

	//"READY!"表示
	DrawGraph(DRAW_POINT_X + 270, DRAW_POINT_Y + 480, StartImage, TRUE);

	//2.5秒経過後、敵とプレイヤーを描画　　音が5秒なら2.5秒間  　　音が4秒なら2秒間
	if (counter >= 120)  //150
	{
		//全敵を描画
		enemy->DrawAllEnemy();

		////プレイヤーを描画　移動と描画を別にしたい
		//player->DrawPlayer();

		//プレイヤースタート位置に"●"を描画
		DrawGraph(DRAW_POINT_X + 390, DRAW_POINT_Y + 600, CircleImage, TRUE);
	}

	//5秒経過後、メインへ　　音が5秒なら5秒間  　　音が4秒なら4秒間
	if (counter >= 240)  //300
	{
		*state = GAME_STATE::GAME_MAIN;

		counter = 0;
		if (clearcount == 0) clearcount++;   //初回時のみ
	}
}

//ゲームオーバー時
void DISPLAY::DrawOverDisp(GAME_STATE* state)
{
	counter++;    //フレームをカウント

	//"PLAYER"表示
	//DrawGraph(DRAW_POINT_X + 180, DRAW_POINT_Y + 210, PlayImage, TRUE);
	DrawGraph(DRAW_POINT_X + 270, DRAW_POINT_Y + 300, PlayImage, TRUE);

	//"READY!"表示
	//DrawGraph(DRAW_POINT_X + 180, DRAW_POINT_Y + 390, OverImage, TRUE);
	DrawGraph(DRAW_POINT_X + 270, DRAW_POINT_Y + 480, OverImage, TRUE);

	//3秒経過後、タイトルへ
	if (counter >= 300)
	{
		*state = GAME_STATE::DRAW_TITLE;

		counter = 0;
	}
}
#include"DxLib.h"
#include"Info.h"

#include"Stage.h"
#include "display.h"

DISPLAY Disp;

//画像読み込み
int DISPLAY::LoadImages()
{
	if ((CircleImage = LoadGraph("images/02_2.png")) == -1) return -1;
	if ((PlayImage = LoadGraph("images/PLAYER.png")) == -1) return -1;
	if ((StartImage = LoadGraph("images/READY.png")) == -1) return -1;
	if ((OverImage = LoadGraph("images/GAMEOVER.png")) == -1) return -1;
}

//音声読み込み
int DISPLAY::LoadSounds()
{
	if ((StartBGM = LoadSoundMem("sounds/Start.wav")) == -1) return -1;
}

//初期処理
void DISPLAY::DispInit(int ClearCnt)
{
	counter = 0;

	SetDrawFruit(ClearCnt);
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
	DrawGraph(DRAW_POINT_X + 180, DRAW_POINT_Y + 210, PlayImage, TRUE);

	//"READY!"表示
	DrawGraph(DRAW_POINT_X + 180, DRAW_POINT_Y + 390, OverImage, TRUE);

	//3秒経過後、タイトルへ
	if (counter >= 300)
	{
		*state = GAME_STATE::DRAW_TITLE;

		counter = 0;
	}
}

//描画位置
const int DrawX = DRAW_POINT_X + (MAP_SIZE * MAP_WIDTH);
const int DrawY = SCREEN_HEIGHT - 80;

//残機描画
void DISPLAY::DrawPlayerLife(int LifeCnt)
{
	for (int i = 0; i < LifeCnt; i++)
	{
		DrawGraph(DrawX + (i * 40), DrawY, PacImage, TRUE);
	}
}

//クリア面によるフルーツ描画
void DISPLAY::DrawStageFruit(int ClearCnt)
{
	int dx = DRAW_POINT_X + (MAP_SIZE * MAP_WIDTH) - 40;
	int dy = SCREEN_HEIGHT - 200;
	for (int i = 0; i < MAX_DRAW_F; i++)
	{
		//if (Img_Fruits[i] != nullptr)

		//dx += (i * 40);
		DrawGraph(dx + (i * 40), dy, Img_Fruits[i], TRUE);
		//if (i == 3)
		//{
		//	dx = DRAW_POINT_X + (MAP_SIZE * MAP_WIDTH) - 40;
		//	dy += 40;
		//}


	}
}

//クリア面による描画フルーツのセット
void DISPLAY::SetDrawFruit(int ClearCnt)
{
	index = MAX_DRAW_F - 1;  //配列の末尾

	//末尾が空だった場合
	if (Img_Fruits[index] == NULL)
	{
		//ひとつ前
		while (Img_Fruits[index - 1] == NULL)
		{
			index--;
			if (index == 0) break;
		}
	}
	else
	{
		//0番目を削除、一つずつ（現在の添字-1に）ずらす
		int sort = 1;
		for (int i = 0; i < MAX_DRAW_F - 1; i++)
		{
			Img_Fruits[i] = Img_Fruits[i + 1];
		}
	}

	Img_Fruits[index] = *stage.FruitToClear(ClearCnt);
}

//表示用フルーツ配列をリセット（new を使えばいらない）
void DISPLAY::ResetDrawFruit()
{
	for (int i = 0; i < MAX_DRAW_F; i++) Img_Fruits[i] = NULL;
}
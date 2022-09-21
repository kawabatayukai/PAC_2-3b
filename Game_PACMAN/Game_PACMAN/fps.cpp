#include"Fps.h"
Fps fps;
bool Fps::Update() {
	if (mCount == 0) { //1フレーム目なら時刻を記憶
		mStartTime = GetNowCount();		//最初の時間
	}
	if (mCount == N) { //60フレーム目なら平均を計算する
		int t = GetNowCount();		//現在までの時間
		mFps = 1000.f / ((t - mStartTime) / (float)N);		//現在のFPSの計算
		mCount = 0;		//フレームのリセット
		mStartTime = t;		//0フレーム目の設定
	}
	mCount++;		//毎フレーム加算
	return true;
}
void  Fps::Draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", mFps);
}
void  Fps::Wait() {
	int tookTime = GetNowCount() - mStartTime;	//かかった時間	
	int waitTime = mCount * 1000 / FPS - tookTime;	//待つべき時間
	if (waitTime > 0) {
		Sleep(waitTime);	//waitTimeが1以上なら待機
	}
}
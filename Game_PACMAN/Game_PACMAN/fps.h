#pragma once
#include<math.h>
#include"DxLib.h"
class Fps {
	int mStartTime;         //����J�n����
	int mCount;             //�J�E���^
	float mFps;             //fps
	static const int N = 60;//���ς����T���v����
	static const int FPS = 60;	//�ݒ肵��FPS
public:
	Fps() {
		mStartTime = 0;
		mCount = 0;
		mFps = 0;
	}
	bool Update();
	void Draw();
	void Wait();
};
extern Fps fps;
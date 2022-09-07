//#define MAX_BUTTON 16
//
//class CController
//{
//private:
//	XINPUT_STATE input;
//	XINPUT_STATE OldKey;
//	XINPUT_STATE data;
//
//	int Score = 0;
//
//	bool ControlFlg = TRUE;
//	struct XINPUT_STATE
//	{
//		unsigned char	Buttons[16];	// ボタン１６個( 添字には XINPUT_BUTTON_DPAD_UP 等を使用する、
//						//			0:押されていない  1:押されている )
//		unsigned char	LeftTrigger;	// 左トリガー( 0～255 )
//		unsigned char	RightTrigger;	// 右トリガー( 0～255 )
//		short		ThumbLX;	// 左スティックの横軸値( -32768 ～ 32767 )
//		short		ThumbLY;	// 左スティックの縦軸値( -32768 ～ 32767 )
//		short		ThumbRX;	// 右スティックの横軸値( -32768 ～ 32767 )
//		short		ThumbRY;	// 右スティックの縦軸値( -32768 ～ 32767 )
//	};
//
//public:
//	void control(bool data);
//
//	XINPUT_STATE GetControl() const;
//
//	bool GetControlFlg() const;
//	void SetControlFlg(bool flg) { ControlFlg = flg; }
//
//	void SetScore(int i) { Score = i; }
//	int GetScore() { return Score; }
//};
//

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
//		unsigned char	Buttons[16];	// �{�^���P�U��( �Y���ɂ� XINPUT_BUTTON_DPAD_UP �����g�p����A
//						//			0:������Ă��Ȃ�  1:������Ă��� )
//		unsigned char	LeftTrigger;	// ���g���K�[( 0�`255 )
//		unsigned char	RightTrigger;	// �E�g���K�[( 0�`255 )
//		short		ThumbLX;	// ���X�e�B�b�N�̉����l( -32768 �` 32767 )
//		short		ThumbLY;	// ���X�e�B�b�N�̏c���l( -32768 �` 32767 )
//		short		ThumbRX;	// �E�X�e�B�b�N�̉����l( -32768 �` 32767 )
//		short		ThumbRY;	// �E�X�e�B�b�N�̏c���l( -32768 �` 32767 )
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

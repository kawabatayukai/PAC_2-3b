#pragma once
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

class Player {
private:
   /* int PlayerImageL;
    int PlayerImageR;
    int PlayerImageU;
    int PlayerImageD;*/

    int width;          // �o�[�̕�
    int height;         // �o�[�̍���


public:
    Player();                  // �R���X�g���N�^
    //void InitXY();          // �v���C���[�̍��W������

    // �Q�b�^�[
    int getBarX();
    int getBarY();
    int getWidth();
    int getHeight();

    void PlayerControl();
    int HitBoxPlayer();

    int PX;
    int PY;

    int KEYFLG;
    int NEXTFLG;
    int FLG;
    int g_Vector;
    int PX_2;
    int PY_2;
};

// �G�N�X�^�[��
extern Player g_player;

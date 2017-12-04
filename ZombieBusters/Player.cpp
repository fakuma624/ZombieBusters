#include "Player.h"



Player::Player()
{
	WindowPos.x = 300;
	WindowPos.y = 300;
	/* WorldPos;*/
	 Size.Width=90.0f;
	 Size.Hight=180.0f;
	 Speed=2.0f;
}


Player::~Player()
{
}

void Player::Draw()
{
	CUSTOMVERTEX player[4];
		static CUSTOMVERTEX PlayerVertex[4]
	{
		//{プレイヤーのX座標 ,    プレイヤーのY座標 ,  1固定,  ?,   カラー    ,tu,tv}
		{ - Size.Width / 2,- Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ + Size.Width / 2,- Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ + Size.Width / 2,+ Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ - Size.Width / 2,+ Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }

	};
	for (int i = 0; i < 4; ++i)
	{
		player[i] = PlayerVertex[i];
		player[i].x += WindowPos.x;
		player[i].y += WindowPos.y;

	}
	DirectGraphics::GetpInstance()->Draw(&TextureID, player);
}
void Player::Update()
{
	/*KEYSTATE* key = DirectInput::GetInstance()->GetKey();*/
	DirectInput::GetInstance()->KeyCheck(&Key[KEY_LEFT], DIK_LEFT);
	DirectInput::GetInstance()->KeyCheck(&Key[KEY_RIGHT], DIK_RIGHT);
	DirectInput::GetInstance()->KeyCheck(&Key[KEY_UP], DIK_UP);
	DirectInput::GetInstance()->KeyCheck(&Key[KEY_DOWN], DIK_DOWN);
	DirectInput::GetInstance()->KeyCheck(&Key[KEY_Z], DIK_Z);
	DirectInput::GetInstance()->KeyCheck(&Key[KEY_A], DIK_A);
	DirectInput::GetInstance()->KeyCheck(&Key[KEY_W], DIK_W);
	DirectInput::GetInstance()->KeyCheck(&Key[KEY_SPACE], DIK_SPACE);


	if (Key[KEY_UP] == KEY_ON) {
		WindowPos.y -= Speed;
	}
	if (Key[KEY_DOWN] == KEY_ON) {
		WindowPos.y += Speed;
	}
	if (Key[KEY_LEFT] == KEY_ON) {
		WindowPos.x -= Speed;
	}
	if (Key[KEY_RIGHT] == KEY_ON) {
		WindowPos.x += Speed;
	}
}

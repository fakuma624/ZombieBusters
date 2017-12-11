#include "Bullet.h"


Bullet::Bullet(int BulletTexture, D3DXVECTOR2 PlayerWindoPos, bool IsRight, TEXTURESIZE PlayerSize)
{
	TextureID = BulletTexture;
	Size.Width = 90;
	Size.Hight = 90;
	//弾の表示位置指定
	if (IsRight)
	{
		//右向き
		WindowPos.x = PlayerWindoPos.x + PlayerSize.Width / 2 + Size.Width / 2;
		WindowPos.y = PlayerWindoPos.y;
	}
	else
	{
		WindowPos.x = PlayerWindoPos.x - PlayerSize.Width / 2 - Size.Width / 2;
		WindowPos.y = PlayerWindoPos.y;
	}
}

Bullet::~Bullet()
{

}

void Bullet::Draw()
{
	CUSTOMVERTEX Bullet[4];
	static CUSTOMVERTEX BulletVertex[4]
	{

		{ -Size.Width / 2,-Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ +Size.Width / 2,-Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, BulletTu, 0.f },
		{ +Size.Width / 2,+Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, BulletTu, BulletTv },
		{ -Size.Width / 2,+Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, 0.f, BulletTv }

	};
	for (int i = 0; i < 4; ++i)
	{
		Bullet[i] = BulletVertex[i];
		Bullet[i].x += WindowPos.x;
		Bullet[i].y += WindowPos.y;
	}
	DirectGraphics::GetpInstance()->Draw(&TextureID, Bullet);
}
void Bullet::Update()
{

}

#include "Bullet.h"


Bullet::Bullet(int BulletTexture, D3DXVECTOR2 PlayerWindoPos, bool PlayerIsRight, TEXTURESIZE PlayerSize)
{
	TextureID = BulletTexture;
	Size.Width = 300;
	Size.Hight = 90;
	//弾の表示位置指定
	if (PlayerIsRight)
	{
		//右向き
		WindowPos.x = PlayerWindoPos.x + PlayerSize.Width / 2 + Size.Width / 2;
		WindowPos.y = PlayerWindoPos.y-55;
	}
	else
	{
		WindowPos.x = PlayerWindoPos.x - PlayerSize.Width / 2 - Size.Width / 2;
		WindowPos.y = PlayerWindoPos.y-55;
	}
	IsRight = PlayerIsRight;

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
	static int FireCount = 0;
	static int CountMax = 60;
	if (0 <= FireCount && FireCount < CountMax * 1 / 4)
	{
		for (int i = 0; i < 4; ++i)
		{
			Bullet[i].tu += BulletTu * 0;
		

		}
	}
	if (CountMax * 1 / 4 <= FireCount && FireCount < CountMax * 2 / 4)
	{
		for (int i = 0; i < 4; ++i)
		{
			Bullet[i].tu += BulletTu * 1;
			

		}
	}
	if (CountMax * 2 / 4 <= FireCount && FireCount < CountMax * 3 / 4)
	{
		for (int i = 0; i < 4; ++i)
		{
			Bullet[i].tu += BulletTu * 2;

		}
	}
	if (CountMax * 3 / 4 <= FireCount && FireCount < CountMax * 4 / 4)
	{
		for (int i = 0; i < 4; ++i)
		{
			Bullet[i].tu +=BulletTu * 1;


		}
	}

	if (!IsRight)
	{

	}
	if (IsRight)
	{
		//反転する関数を呼ぶ
		DirectGraphics::GetpInstance()->InvertedRight(Bullet);
	}
	if (FireCount == CountMax)
	{
		FireCount = 0;
	}
	++FireCount;


	DirectGraphics::GetpInstance()->Draw(&TextureID, Bullet);
}
void Bullet::Update(int BulletTexture, D3DXVECTOR2 PlayerWindoPos, bool PlayerIsRight, TEXTURESIZE PlayerSize)
{
	if (IsRight)
	{
		//右向き
		WindowPos.x = PlayerWindoPos.x + PlayerSize.Width / 2 + Size.Width / 2;
		WindowPos.y = PlayerWindoPos.y-55;
	}
	else
	{
		WindowPos.x = PlayerWindoPos.x - PlayerSize.Width / 2 - Size.Width / 2;
		WindowPos.y = PlayerWindoPos.y-55;
	}
	IsRight = PlayerIsRight;
}

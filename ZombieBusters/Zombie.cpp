#include "Zombie.h"



Zombie::Zombie()
{
	DirectGraphics::GetpInstance()->InitGraphics("image\\Zombie\\Zombie.png", GetTexture());
	WindowPos.x = 100;
	WindowPos.y = 100;
	Size.Width = 90.0f;
	Size.Hight = 180.0f;
	Speed = 2.0f;
	SpawnPos.x = WindowPos.x;
	SpawnPos.y = WindowPos.y;

	IsRight = false;
}


Zombie::~Zombie()
{
}
void Zombie::Draw()
{
	CUSTOMVERTEX Zombie[4];
	static CUSTOMVERTEX ZombieVertex[4]
	{
		//{プレイヤーのX座標 ,    プレイヤーのY座標 ,  1固定,  ?,   カラー    ,tu,tv}
		{ -Size.Width / 2,-Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ +Size.Width / 2,-Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ +Size.Width / 2,+Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -Size.Width / 2,+Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }

	};
	for (int i = 0; i < 4; ++i)
	{
		Zombie[i] = ZombieVertex[i];
		Zombie[i].x += WindowPos.x;
		Zombie[i].y += WindowPos.y;

	}
	DirectGraphics::GetpInstance()->Draw(&TextureID, Zombie);
}
void Zombie::Update()
{
	Control();
}

void Zombie::Control()
{
	if (IsRight == true)
	{
		if (WindowPos.x >= SpawnPos.x + MovingRange)
		{
			IsRight = false;
		}
	}
	if (IsRight == false)
	{
		if (WindowPos.x <= SpawnPos.x - MovingRange)
		{
			IsRight = true;
		}
	}

	if (IsRight == false)
	{
		WindowPos.x -= Speed;
	}
	if (IsRight == true)
	{
		WindowPos.x += Speed;
	}
}


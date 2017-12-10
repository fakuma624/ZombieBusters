#include "Zombie.h"



Zombie::Zombie()
{
	DirectGraphics::GetpInstance()->InitGraphics("image\\Character\\Character2.png", GetTexture());
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
		{ -Size.Width / 2,-Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ +Size.Width / 2,-Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, ZombieTu, 0.f },
		{ +Size.Width / 2,+Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, ZombieTu, ZombieTv },
		{ -Size.Width / 2,+Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, 0.f, ZombieTv }

	};
	for (int i = 0; i < 4; ++i)
	{
		Zombie[i] = ZombieVertex[i];
		Zombie[i].x += WindowPos.x;
		Zombie[i].y += WindowPos.y;

	}
	
	Animation(Zombie);
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

void Zombie::Animation(CUSTOMVERTEX vertex[])
{
	static int Fcount = 0;
	static int FcountMax = 100;
	if (0 <= Fcount&&Fcount <  FcountMax * 1 / 9)
	{
		for (int i = 0; i < 4; ++i)
		{
			vertex[i].tu += ZombieTu * 0;
			vertex[i].tv += ZombieTv * 2;
		}
	}
	if (FcountMax * 1 / 9 <= Fcount&&Fcount < FcountMax * 2 / 9)
	{
		for (int i = 0; i < 4; ++i)
		{
			vertex[i].tu += ZombieTu * 1;
			vertex[i].tv += ZombieTv * 2;
		}
	}
	if (FcountMax * 2 / 9 <= Fcount&&Fcount < FcountMax * 3 / 9)
	{
		for (int i = 0; i < 4; ++i)
		{
			vertex[i].tu += ZombieTu * 2;
			vertex[i].tv += ZombieTv * 2;
		}
	}
	if (FcountMax * 3 / 9 <= Fcount&&Fcount < FcountMax * 4 / 9)
	{
		for (int i = 0; i < 4; ++i)
		{
			vertex[i].tu += ZombieTu * 3;
			vertex[i].tv += ZombieTv * 2;
		}
	}
	if (FcountMax * 4 / 9 <= Fcount&& Fcount < FcountMax * 5 / 9)
	{
		for (int i = 0; i < 4; ++i)
		{
			vertex[i].tu += ZombieTu * 4;
			vertex[i].tv += ZombieTv * 2;
		}
	}

	if (FcountMax * 5 / 9 <= Fcount&&Fcount < FcountMax * 6/9)
	{
		for (int i = 0; i < 4; ++i)
		{
			vertex[i].tu += ZombieTu * 4;
			vertex[i].tv += ZombieTv * 2;
		}
	}
	if (FcountMax * 6 / 9 <= Fcount&&Fcount < FcountMax * 7/9)
	{
		for (int i = 0; i < 4; ++i)
		{
			vertex[i].tu += ZombieTu * 3;
			vertex[i].tv += ZombieTv * 2;
		}
	}
	if (FcountMax * 7 / 9 <= Fcount&&Fcount < FcountMax * 8 / 9)
	{
		for (int i = 0; i < 4; ++i)
		{
			vertex[i].tu += ZombieTu * 2;
			vertex[i].tv += ZombieTv * 2;
		}
	}
	if (FcountMax * 8/9 <= Fcount&&Fcount < FcountMax * 9/9)
	{
		for (int i = 0; i < 4; ++i)
		{
			vertex[i].tu += ZombieTu * 1;
			vertex[i].tv += ZombieTv * 2;
		}
	}
	if (IsRight)
	{
		DirectGraphics::GetpInstance()->InvertedRight(vertex);
	}
	else {

	}

	if (Fcount == FcountMax)
	{
		Fcount = 0;
	}
	++Fcount;
	
}


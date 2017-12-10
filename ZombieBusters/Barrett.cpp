#include "Barrett.h"


Barrett::Barrett()
{
	DirectGraphics::GetpInstance()->InitGraphics("image\\炎.png", GetTexture());
	Size.Width = 90;
	Size.Hight = 90;
	WindowPos.x = 100;
	WindowPos.y = 100;
	Speed = 2;
}

Barrett::~Barrett()
{

}

void Barrett::Draw()
{
	CUSTOMVERTEX Barrett[4];
	static CUSTOMVERTEX BarrettVertex[4]
	{
		//{プレイヤーのX座標 ,    プレイヤーのY座標 ,  1固定,  ?,   カラー    ,tu,tv}
		{ -Size.Width / 2,-Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ +Size.Width / 2,-Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, BarrettTu, 0.f },
		{ +Size.Width / 2,+Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, BarrettTu, BarrettTv },
		{ -Size.Width / 2,+Size.Hight / 2, 1.f,1.f, 0xFFFFFFFF, 0.f, BarrettTv }

	};
	for (int i = 0; i < 4; ++i)
	{
		Barrett[i] = BarrettVertex[i];
		Barrett[i].x += WindowPos.x;
		Barrett[i].y += WindowPos.y;
	}
	DirectGraphics::GetpInstance()->Draw(&TextureID, Barrett);
}
void Barrett::Update()
{

}
void Barrett::Control()
{

}
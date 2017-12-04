#include "CollisionJudgment.h"



CollisionJudgment::CollisionJudgment()
{
}


CollisionJudgment::~CollisionJudgment()
{
}

bool CollisionJudgment::RectangleCollosion(D3DXVECTOR2 PosA,TEXTURESIZE SizeA, D3DXVECTOR2 PosB,TEXTURESIZE SizeB)//矩形の当たり判定
{
	D3DXVECTOR2 TopLeftA;//A左上
	D3DXVECTOR2 TopRightA;//A右上
	D3DXVECTOR2 BottomLeftA;//A左下
	D3DXVECTOR2 BottomRightA;//A右下
	D3DXVECTOR2 TopLeftB;//B左上
	D3DXVECTOR2 TopRightB;//B右上
	D3DXVECTOR2 BottomLeftB;//B左下
	D3DXVECTOR2 BottomRightB;//B右下

							 //各場所の座標を代入
							 //矩形A
	TopLeftA.x = BottomLeftA.x = PosA.x - SizeA.Width / 2;
	TopRightA.x = BottomRightA.x = PosA.x + SizeA.Width / 2;
	TopLeftA.y = TopRightA.y = PosA.y - SizeA.Hight / 2;
	BottomLeftA.y = BottomRightA.x = PosA.y + SizeA.Hight / 2;
	//矩形B
	TopLeftB.x = BottomLeftB.x = PosB.x - SizeB.Width / 2;
	TopRightB.x = BottomRightB.x = PosB.x + SizeB.Width / 2;
	TopLeftB.y = TopRightB.y = PosB.y - SizeB.Hight / 2;
	BottomLeftB.y = BottomRightB.x = PosB.y + SizeB.Hight / 2;

	if (TopLeftA.x <= TopRightB.x && TopLeftB.x <= TopRightA.x)
	{
		if (TopLeftA.y <= BottomLeftB.y&&TopLeftB.y <= BottomLeftA.y)
		{
			return true;
		}
	}

	return false;

}

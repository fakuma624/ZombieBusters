#include "CollisionJudgment.h"



CollisionJudgment::CollisionJudgment()
{
}


CollisionJudgment::~CollisionJudgment()
{
}

bool CollisionJudgment::RectangleCollosion(D3DXVECTOR2 PosA,TEXTURESIZE SizeA, D3DXVECTOR2 PosB,TEXTURESIZE SizeB)//��`�̓����蔻��
{
	D3DXVECTOR2 TopLeftA;//A����
	D3DXVECTOR2 TopRightA;//A�E��
	D3DXVECTOR2 BottomLeftA;//A����
	D3DXVECTOR2 BottomRightA;//A�E��
	D3DXVECTOR2 TopLeftB;//B����
	D3DXVECTOR2 TopRightB;//B�E��
	D3DXVECTOR2 BottomLeftB;//B����
	D3DXVECTOR2 BottomRightB;//B�E��

							 //�e�ꏊ�̍��W����
							 //��`A
	TopLeftA.x = BottomLeftA.x = PosA.x - SizeA.Width / 2;
	TopRightA.x = BottomRightA.x = PosA.x + SizeA.Width / 2;
	TopLeftA.y = TopRightA.y = PosA.y - SizeA.Hight / 2;
	BottomLeftA.y = BottomRightA.x = PosA.y + SizeA.Hight / 2;
	//��`B
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

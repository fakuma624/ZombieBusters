#pragma once
#include "Player.h"
#include "Zombie.h"
class CollisionJudgment
{
public:
	CollisionJudgment();
	~CollisionJudgment();
	bool RectangleCollosion(D3DXVECTOR2 PosA, TEXTURESIZE SizeA, D3DXVECTOR2 PosB, TEXTURESIZE SizeB);

};


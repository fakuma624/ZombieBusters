#pragma once
#include <d3dx9.h>
#include "DirectGraphics.h"

class Zombie
{
	Zombie();
	~Zombie();
	void Update();
	void Draw();
public:
	D3DXVECTOR2 WindowPos;
	D3DXVECTOR2 WorldPos;
	float Width;//�摜�̕�
	float Hight;//����
	float Speed;
};


#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "DirectGraphics.h"


class Bullet
{
public:

	Bullet(int BulletTexture, D3DXVECTOR2 WindoPos, bool IsRight, TEXTURESIZE Size);
	~Bullet();
	void Update();
	void Draw();

	int* GetTexture() { return &TextureID; }
private:
	int TextureID;
	D3DXVECTOR2 WindowPos;
	D3DXVECTOR2 WorldPos;
	TEXTURESIZE Size;
	float Speed;
	const float BulletTu = 90 / 90;
	const float BulletTv = 90 / 90;

};


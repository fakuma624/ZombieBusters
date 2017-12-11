#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "DirectGraphics.h"


class Bullet
{
public:

	Bullet(int BulletTexture, D3DXVECTOR2 WindoPos, bool IsRight, TEXTURESIZE Size);
	~Bullet();
	void Update(int BulletTexture, D3DXVECTOR2 PlayerWindoPos, bool IsRight, TEXTURESIZE PlayerSize);
	void Draw();

	int* GetTexture() { return &TextureID; }
private:
	int TextureID;
	D3DXVECTOR2 WindowPos;
	D3DXVECTOR2 WorldPos;
	TEXTURESIZE Size;
	float Speed;
	bool IsRight;
	const float BulletTu = 300.f / 1024.f;
	const float BulletTv = 90.f / 128.f;

};

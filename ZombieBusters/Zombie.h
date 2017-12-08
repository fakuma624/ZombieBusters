#pragma once
#include <d3dx9.h>
#include "DirectGraphics.h"
#include "CharaBase.h"

class Zombie:public CharaBase
{
public:
	Zombie();
	~Zombie();
	void Update();
	void Draw();
	void Control();
	TEXTURESIZE GetSize() { return Size; }
	D3DXVECTOR2 GetPos() { return WindowPos; }
	int* GetTexture() { return &TextureID; }
private:
	int TextureID;
	D3DXVECTOR2 WindowPos;
	D3DXVECTOR2 WorldPos;
	D3DXVECTOR2 SpawnPos;//スポーンした座標
	TEXTURESIZE Size;
	bool IsRight;
	float Speed;
	float const MovingRange = 100;//移動範囲
};


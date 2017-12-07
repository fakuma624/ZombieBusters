#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "DirectGraphics.h"
class CharaBase
{
public:
	CharaBase();
	~CharaBase();
	void Update();
	void Draw();
	virtual TEXTURESIZE GetSize() { return Size; }
	virtual D3DXVECTOR2 GetPos() { return WindowPos; }
	virtual int* GetTexture() { return &TextureID; }
private:
	int TextureID;
	//int PlayerTexture;
	//static int Fcount; 
	D3DXVECTOR2 WindowPos;
	D3DXVECTOR2 WorldPos;
	TEXTURESIZE Size;
	float Speed;

};


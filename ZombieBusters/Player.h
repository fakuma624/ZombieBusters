#pragma once
#include <d3dx9.h>
#include <d3d9.h>
#include "DirectGraphics.h"
#include "DirectInput.h"
#include "CharaBase.h"

class Player:public CharaBase
{
public:
	Player();
	~Player();
	void Update();
	void Draw();
	void Move();
	void Control();

	TEXTURESIZE GetSize() { return Size; }
	D3DXVECTOR2 GetPos() { return WindowPos; }
	int* GetTexture() { return &TextureID; }
private:
	int TextureID;
	//int PlayerTexture;
	//static int Fcount; 
	D3DXVECTOR2 WindowPos;
	D3DXVECTOR2 WorldPos;
	TEXTURESIZE Size;
	Direction Direction;
	float MovementX;
	float MovementY;
	bool IsAtk;
	bool IsMoving;
	const float PlayerTu = 90.f / 1024.f;
	const float PlayerTv = 180.f / 2048.f;
	float Speed;
	float const tu = 90;
	float const tv = 180;
	KEYSTATE Key[KEYMAX] = { KEY_OFF };

};


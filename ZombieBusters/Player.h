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
	enum Direction {
		UNKNOWN,
		UP,
		DOWN,
		RIGHT,
		LEFT
	};
	TEXTURESIZE* GetSize() { return &Size; }
	D3DXVECTOR2* GetPos() { return &WindowPos; }
	int* GetTexture() { return &TextureID; }
private:
	int TextureID;
	//int PlayerTexture;
	//static int Fcount; 
	D3DXVECTOR2 WindowPos;
	D3DXVECTOR2 WorldPos;
	TEXTURESIZE Size;
	float Speed;
	KEYSTATE Key[KEYMAX] = { KEY_OFF };

};


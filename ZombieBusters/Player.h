#pragma once
#include <d3dx9.h>
#include <d3d9.h>
#include "DirectGraphics.h"
#include "DirectInput.h"

class Player
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

	int* GetTexture() { return &TextureID; }
private:
	int TextureID;
	//int PlayerTexture;
	//static int Fcount; 
	D3DXVECTOR2 WindowPos;
	D3DXVECTOR2 WorldPos;
	float Width;//âÊëúÇÃïù
	float Hight;//çÇÇ≥
	float Speed;
	KEYSTATE Key[KEYMAX] = { KEY_OFF };

};


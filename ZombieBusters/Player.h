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
<<<<<<< HEAD
	float Speed;

	Direction Direction;
	const float PlayerTu = 90.f / 1024.f;
	const float PlayerTv = 180.f / 2048.f;


=======
	Direction Direction;
	const float PlayerTu = 90.f / 1024.f;
	const float PlayerTv = 180.f / 2048.f;
	float Speed;
	float const tu = 90;
	float const tv = 180;
<<<<<<< HEAD
=======
=======

>>>>>>> [#11　enh]ゾンビの歩行アニメーション　左右反転してる
>>>>>>> master

>>>>>>> 画像のアニメーション（画像を統合フェイルに変更）
	KEYSTATE Key[KEYMAX] = { KEY_OFF };

};


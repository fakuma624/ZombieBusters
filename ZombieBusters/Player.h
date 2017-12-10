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

>>>>>>> [#11縲enh]繧ｾ繝ｳ繝薙・豁ｩ陦後い繝九Γ繝ｼ繧ｷ繝ｧ繝ｳ縲蟾ｦ蜿ｳ蜿崎ｻ｢縺励※繧・
>>>>>>> master

>>>>>>> 逕ｻ蜒上・繧｢繝九Γ繝ｼ繧ｷ繝ｧ繝ｳ・育判蜒上ｒ邨ｱ蜷医ヵ繧ｧ繧､繝ｫ縺ｫ螟画峩・・
	KEYSTATE Key[KEYMAX] = { KEY_OFF };

};


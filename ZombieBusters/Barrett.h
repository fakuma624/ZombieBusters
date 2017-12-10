#include <d3d9.h>
#include <d3dx9.h>
#include "DirectGraphics.h"


class Barrett
{
public:

	Barrett();
	~Barrett();
	void Update();
	void Draw();
	void Control();
	int* GetTexture() { return &TextureID; }
private:
	int TextureID;
	D3DXVECTOR2 WindowPos;
	D3DXVECTOR2 WorldPos;
	TEXTURESIZE Size;
	float Speed;
	const float BarrettTu = 90 / 90;
	const float BarrettTv = 90 / 90;

};


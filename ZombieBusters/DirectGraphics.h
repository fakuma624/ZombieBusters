#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <vector>

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
};
struct TEXTURESIZE {
	float Width, Hight;
};


class DirectGraphics {
public:
	//2Dグラフィックス解放
	virtual ~DirectGraphics();
	static void CreateInstance(HWND hWnd);
	//描画の初期化関数
	void RenderInitialization();
	//描画開始関数
	void StartRender();
	//シーンに画像をセットする関数
	void Draw(int* textureid, CUSTOMVERTEX vertex[]);
	//描画終了関数
	void EndRender();
	void InitGraphics(char* filepath, int *texture);
	static  DirectGraphics* GetpInstance() { return pInstance; }
private:
	//2Dグラフィックス生成
	DirectGraphics(HWND hWnd);
	static DirectGraphics* pInstance;
	LPDIRECT3D9			pDirect3D = NULL;		// DirectXオブジェクトのポインタ
	LPDIRECT3DDEVICE9	pDirect3DDevice = NULL;	// DirectXデバイスのポインタ
	std::vector<LPDIRECT3DTEXTURE9> pTexture;
	std::vector<char*> FileName;
};

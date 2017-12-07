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
	//2D�O���t�B�b�N�X���
	virtual ~DirectGraphics();
	static void CreateInstance(HWND hWnd);
	//�`��̏������֐�
	void RenderInitialization();
	//�`��J�n�֐�
	void StartRender();
	//�V�[���ɉ摜���Z�b�g����֐�
	void Draw(int* textureid, CUSTOMVERTEX vertex[]);
	//�`��I���֐�
	void EndRender();
	void InitGraphics(char* filepath, int *texture);
	static  DirectGraphics* GetpInstance() { return pInstance; }
private:
	//2D�O���t�B�b�N�X����
	DirectGraphics(HWND hWnd);
	static DirectGraphics* pInstance;
	LPDIRECT3D9			pDirect3D = NULL;		// DirectX�I�u�W�F�N�g�̃|�C���^
	LPDIRECT3DDEVICE9	pDirect3DDevice = NULL;	// DirectX�f�o�C�X�̃|�C���^
	std::vector<LPDIRECT3DTEXTURE9> pTexture;
	std::vector<char*> FileName;
};

#include "DirectGraphics.h"

DirectGraphics* DirectGraphics::pInstance = NULL;

void DirectGraphics::CreateInstance(HWND hWnd)
{
	if (pInstance == NULL) {
		pInstance = new DirectGraphics(hWnd);
	}
}
//2D�O���t�B�b�N�X����
DirectGraphics::DirectGraphics(HWND hWnd)
{
	// DirectX�I�u�W�F�N�g����
	if (FAILED(pDirect3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		MessageBox(0, "DirectX�I�u�W�F�N�g�̐����Ɏ��s���܂���", NULL, MB_OK);
	}
	D3DDISPLAYMODE		D3DdisplayMode;
	// DisplayMode�̎擾
	if (FAILED(pDirect3D->GetAdapterDisplayMode(
		D3DADAPTER_DEFAULT,
		&D3DdisplayMode)))
	{
		MessageBox(0, "DisplayMode�̎擾�Ɏ��s���܂���", NULL, MB_OK);
	}
	// DirectX�̃f�o�C�X�𐶐�����ۂɕK�v�ȏ���p��
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));

	d3dpp.BackBufferFormat = D3DdisplayMode.Format;
	d3dpp.BackBufferCount = 1;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = TRUE;

	// DirectX�̃f�o�C�X����
	if (FAILED(pDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp,
		&pDirect3DDevice)))
	{
		MessageBox(0, "DirectX�̃f�o�C�X�����Ɏ��s���܂���", NULL, MB_OK);
	}
	//�`��̏�����
	RenderInitialization();
}

DirectGraphics::~DirectGraphics()
{
	pDirect3D->Release();			// DirectX�I�u�W�F�N�g�̉��
	pDirect3DDevice->Release();	// DirectX�̃f�o�C�X�̉��
	pDirect3D = NULL;
	pDirect3DDevice = NULL;
}

//�`��̏������֐�
void DirectGraphics::RenderInitialization()
{
	// �`��̐ݒ�
	pDirect3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	pDirect3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);  //SRC�̐ݒ�
	pDirect3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	pDirect3DDevice->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);

	pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
}
//�`��J�n�֐�
void DirectGraphics::StartRender()
{
	// ���_���̎w��
	pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// ��ʂ̏���
	pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// �`����J�n%
	pDirect3DDevice->BeginScene();
}
//�V�[���ɉ摜���Z�b�g����֐�
void DirectGraphics::Draw(int* textureid, CUSTOMVERTEX vertex[])
{
	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	pDirect3DDevice->SetTexture(0, pTexture[*textureid]);
	// �`��
	pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex, sizeof(CUSTOMVERTEX));
}
//�`��I���֐�
void DirectGraphics::EndRender()
{
	// �`����I��
	pDirect3DDevice->EndScene();
	// ��ʂɕ\��
	pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
}
//�摜�ǂݍ��݊֐�
void DirectGraphics::InitGraphics(char* filepath, int *texture)
{
	//�������Ȃ��摜�t�@�C������������ǂݍ��݂����Ȃ�
	auto result = std::find(FileName.begin(), FileName.end(), filepath);
	if (result == FileName.end()) {
		LPDIRECT3DTEXTURE9 tmp = NULL;
		//�摜�̓ǂݍ���
		D3DXCreateTextureFromFile(
			pDirect3DDevice,
			filepath,
			&tmp);
		FileName.push_back(filepath);
		*texture = pTexture.size();
		pTexture.push_back(tmp);
	}
}
#include "DirectGraphics.h"

DirectGraphics* DirectGraphics::pInstance = NULL;

void DirectGraphics::CreateInstance(HWND hWnd)
{
	if (pInstance == NULL) {
		pInstance = new DirectGraphics(hWnd);
	}
}
//2Dグラフィックス生成
DirectGraphics::DirectGraphics(HWND hWnd)
{
	// DirectXオブジェクト生成
	if (FAILED(pDirect3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		MessageBox(0, "DirectXオブジェクトの生成に失敗しました", NULL, MB_OK);
	}
	D3DDISPLAYMODE		D3DdisplayMode;
	// DisplayModeの取得
	if (FAILED(pDirect3D->GetAdapterDisplayMode(
		D3DADAPTER_DEFAULT,
		&D3DdisplayMode)))
	{
		MessageBox(0, "DisplayModeの取得に失敗しました", NULL, MB_OK);
	}
	// DirectXのデバイスを生成する際に必要な情報を用意
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));

	d3dpp.BackBufferFormat = D3DdisplayMode.Format;
	d3dpp.BackBufferCount = 1;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = TRUE;

	// DirectXのデバイス生成
	if (FAILED(pDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp,
		&pDirect3DDevice)))
	{
		MessageBox(0, "DirectXのデバイス生成に失敗しました", NULL, MB_OK);
	}
	//描画の初期化
	RenderInitialization();
}

DirectGraphics::~DirectGraphics()
{
	pDirect3D->Release();			// DirectXオブジェクトの解放
	pDirect3DDevice->Release();	// DirectXのデバイスの解放
	pDirect3D = NULL;
	pDirect3DDevice = NULL;
}

//描画の初期化関数
void DirectGraphics::RenderInitialization()
{
	// 描画の設定
	pDirect3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	pDirect3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);  //SRCの設定
	pDirect3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	pDirect3DDevice->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);

	pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
}
//描画開始関数
void DirectGraphics::StartRender()
{
	// 頂点情報の指定
	pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// 画面の消去
	pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// 描画を開始%
	pDirect3DDevice->BeginScene();
}
//シーンに画像をセットする関数
void DirectGraphics::Draw(int* textureid, CUSTOMVERTEX vertex[])
{
	// テクスチャをステージに割り当てる
	pDirect3DDevice->SetTexture(0, pTexture[*textureid]);
	// 描画
	pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex, sizeof(CUSTOMVERTEX));
}
//描画終了関数
void DirectGraphics::EndRender()
{
	// 描画を終了
	pDirect3DDevice->EndScene();
	// 画面に表示
	pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
}
//画像読み込み関数
void DirectGraphics::InitGraphics(char* filepath, int *texture)
{
	//もしおなじ画像ファイルがあったら読み込みをしない
	auto result = std::find(FileName.begin(), FileName.end(), filepath);
	if (result == FileName.end()) {
		LPDIRECT3DTEXTURE9 tmp = NULL;
		//画像の読み込み
		D3DXCreateTextureFromFile(
			pDirect3DDevice,
			filepath,
			&tmp);
		FileName.push_back(filepath);
		*texture = pTexture.size();
		pTexture.push_back(tmp);
	}
}
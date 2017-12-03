#include "DirectInput.h"

DirectInput* DirectInput::pInstance = NULL;

DirectInput::DirectInput(HWND hWnd)
{
	//�uDirectInput�v�I�u�W�F�N�g�̍쐬
	if (FAILED(DirectInput8Create(GetModuleHandle(NULL),
		DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&pDInput, NULL)))
	{
		MessageBox(0, "DirectInput�̍쐬�Ɏ��s���܂���", NULL, MB_OK);
	}

	//�L�[�{�[�h�̏�����
	if (FAILED(pDInput->CreateDevice(GUID_SysKeyboard,
		&pKeyDevice, NULL)))
	{
		MessageBox(0, "DirectInput�̍쐬�Ɏ��s���܂���", NULL, MB_OK);
	}

	//�f�[�^�t�H�[�}�b�g
	if (FAILED(pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		MessageBox(0, "DirectInput�̃f�[�^�t�H�[�}�b�g�Ɏ��s���܂���", NULL, MB_OK);
	}

	//�������x��
	if (FAILED(pKeyDevice->SetCooperativeLevel(
		hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		MessageBox(0, "DirectInput�̋������x���̐ݒ�Ɏ��s���܂���", NULL, MB_OK);
	}


	pKeyDevice->Acquire();
}
DirectInput::~DirectInput()
{
	delete pInstance;
	pDInput->Release();
	pKeyDevice->Release();
	pDInput = NULL;
	pKeyDevice = NULL;
}

void DirectInput::CreateDirectInput(HWND hWnd)
{
	pInstance = new DirectInput(hWnd);
}

KEYSTATE* DirectInput::GetKey()
{
	return Key;
}

void DirectInput::KeyCheck(KEYSTATE* Key, int DIK)
{
	BYTE diks[256];
	static BYTE old_diks[256] = { KEY_OFF };

	HRESULT hr = pKeyDevice->Acquire();
	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		pKeyDevice->GetDeviceState(sizeof(diks), &diks);

		if (diks[DIK] & 0x80)
		{
			if (old_diks[DIK] == KEY_OFF)
			{
				*Key = KEY_PUSH;
				old_diks[DIK] = KEY_ON;
			}
			else
			{
				*Key = KEY_ON;
				old_diks[DIK] = KEY_ON;
			}
		}
		else
		{
			if (old_diks[DIK] == KEY_ON)
			{
				*Key = KEY_RELEASE;
				old_diks[DIK] = KEY_OFF;
			}
			else
			{
				*Key = KEY_OFF;
				old_diks[DIK] = KEY_OFF;
			}
		}
	}
}
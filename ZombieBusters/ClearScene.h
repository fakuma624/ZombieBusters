#pragma once
#include "SceneBase.h"
#include "DirectGraphics.h"
#include "DirectInput.h"
class ClearScene :
	public SceneBase
{
public:
	ClearScene();
	~ClearScene();
	int* GetTexture() { return &TextureID; }
	int* GetSceneID() { return &SceneID; }
private:
	int TextureID;
	int SceneID;
	KEYSTATE Key[KEYMAX] = { KEY_OFF };
};


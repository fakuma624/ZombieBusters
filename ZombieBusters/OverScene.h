#pragma once
#include "SceneBase.h"
#include "DirectGraphics.h"
#include "DirectInput.h"
class OverScene :
	public SceneBase
{
public:
	OverScene();
	~OverScene();
	int* GetTexture() { return &TextureID; }
	int* GetSceneID() { return &SceneID; }
private:
	int TextureID;
	int SceneID;
	KEYSTATE Key[KEYMAX] = { KEY_OFF };
};


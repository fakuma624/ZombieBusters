#pragma once
#include "SceneBase.h"


class TitleScene :
	public SceneBase
{
public:
	TitleScene();
	~TitleScene();
	void Draw();
	int* GetTexture() { return &TextureID; }
	int* GetSceneID() { return &SceneID; }
private:
	int TextureID;
	int SceneID;
	KEYSTATE Key[KEYMAX] = { KEY_OFF };
};


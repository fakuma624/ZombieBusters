#pragma once
#include "DirectGraphics.h"
#include "DirectInput.h"

#define DISPLAY_WIDTH 960
#define DISPLAY_HIGHT 540
enum SCENEID 
{
	Titel,
	Stage1,
	Clear,
	Over,

};

class SceneBase
{
public:

	SceneBase();
	virtual ~SceneBase();
	const float DisplayWidth= 960.0f;
	const float DisplayHight = 540.0f;
	virtual void Draw();
	virtual void Control();
	int* GetTexture() { return &TextureID; }
	int* GetSceneID() { return &SceneID; }
private:
	int TextureID;
	int SceneID;
	KEYSTATE Key[KEYMAX] = { KEY_OFF };
};


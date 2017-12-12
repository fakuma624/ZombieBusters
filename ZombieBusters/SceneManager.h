#pragma once
#include "SceneBase.h"
#include "TitleScene.h"
#include "OverScene.h"
#include "ClearScene.h"
#include "Stage1Scene.h"
#include "DirectInput.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	void SceneControl();
	void SceneUpdate();
	void SceneDraw();
	int GetSceneID() { return SceneID; }
	void SceneChange();
private:
	SceneBase* pScene;
	int SceneID;
	KEYSTATE Key[KEYMAX] = { KEY_OFF };

};


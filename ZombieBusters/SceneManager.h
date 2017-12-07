#pragma once
#include "SceneBase.h"
#include "TitleScene.h"
#include "OverScene.h"
#include "ClearScene.h"
#include "Stage1Scene.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	void SceneControl();
	void SceneUpdate();
	void SceneDraw();
private:
	SceneBase* pScene;

};


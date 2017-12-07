#include "SceneManager.h"



SceneManager::SceneManager()
{
	pScene = new Stage1Scene;
}


SceneManager::~SceneManager()
{

}

void SceneManager::SceneControl()
{
}

void SceneManager::SceneUpdate()
{
	SceneControl();
}
void SceneManager::SceneDraw()
{
	pScene->Draw();
}
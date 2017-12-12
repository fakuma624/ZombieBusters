#include "SceneManager.h"



SceneManager::SceneManager()
{


	pScene = new Stage1Scene;
	SceneID = Titel;
}


SceneManager::~SceneManager()
{

}

void SceneManager::SceneControl()
{
	//DirectInput::GetInstance()->KeyCheck(&Key[KEY_SPACE], DIK_SPACE);
	//switch (SceneID)
	//{
	//case Titel:

	//	if (Key[KEY_SPACE] == KEY_ON)
	//	{
	//		SceneID = Stage1;
	//		pScene = new Stage1Scene;
	//	}
	//case Stage1:
	//{
	//	if (Key[KEY_SPACE] == KEY_ON)
	//	{
	//		SceneID = Clear;
	//		pScene = new ClearScene;
	//	}
	//}

	//default:
	//	break;
	//}
}

void SceneManager::SceneUpdate()
{
	SceneControl();
	SceneChange();
	pScene->Control();
}
void SceneManager::SceneDraw()
{
	pScene->Draw();
}
void SceneManager::SceneChange()
{
	/*switch (SceneID)
	{
	case Titel:
		pScene = NULL;
		pScene = new Stage1Scene;*/
	//break;
	//default:
	//	break;
	//}
}
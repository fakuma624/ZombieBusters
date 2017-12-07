#include "Stage1Scene.h"



Stage1Scene::Stage1Scene()
{
	DirectGraphics::GetpInstance()->InitGraphics("image\\BackGround\\stage1.png", GetTexture());
}


Stage1Scene::~Stage1Scene()
{
}
void Stage1Scene::Draw()
{
 CUSTOMVERTEX BackGround
	 [4]
	{

		{	0 ,0, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ DISPLAY_WIDTH,0, 1.f,1.f, 0xFFFFFFFF, 0.25f, 0.f },
		{ DISPLAY_WIDTH,DISPLAY_HIGHT, 1.f,1.f, 0xFFFFFFFF, 0.25f, 1.f },
		{ 0,DISPLAY_HIGHT, 1.f,1.f, 0xFFFFFFFF, 0.f,1.f }

	};

	DirectGraphics::GetpInstance()->Draw(&TextureID, BackGround);
}

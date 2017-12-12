#include "TitleScene.h"



TitleScene::TitleScene()
{
	DirectGraphics::GetpInstance()->InitGraphics("image\\BackGround\\Title.png", GetTexture());
}


TitleScene::~TitleScene()
{
	
}
void TitleScene::Draw()
{
	CUSTOMVERTEX BackGround
		[4]
	{

		{ 0 ,0, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ DISPLAY_WIDTH,0, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ DISPLAY_WIDTH,DISPLAY_HIGHT, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0,DISPLAY_HIGHT, 1.f,1.f, 0xFFFFFFFF, 0.f,1.f }

	};

	DirectGraphics::GetpInstance()->Draw(&TextureID, BackGround);
}

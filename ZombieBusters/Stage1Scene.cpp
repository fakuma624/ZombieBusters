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
	CUSTOMVERTEX Stage1[4];
	 static CUSTOMVERTEX Stage1Vertex[4]
	{

		{	0 ,0, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ DISPLAY_WIDTH,0, 1.f,1.f, 0xFFFFFFFF, Stage1Tu, 0.f },
		{ DISPLAY_WIDTH,DISPLAY_HIGHT, 1.f,1.f, 0xFFFFFFFF, Stage1Tu, Stage1Tv },
		{ 0,DISPLAY_HIGHT, 1.f,1.f, 0xFFFFFFFF, 0.f,Stage1Tv }

	};
	 for (int i = 0; i < 4; ++i)
	 {
		 Stage1[i] = Stage1Vertex[i];

	 }
	 static int Fcount=0;
	 Fcount++;
	 for (int i = 0; i < 4; ++i)
	 {
		 Stage1[i].tu += Stage1Tu*(0.001*Fcount);

	 }





	DirectGraphics::GetpInstance()->Draw(&TextureID, Stage1);
}
void Stage1Scene::Control()
{
	
}
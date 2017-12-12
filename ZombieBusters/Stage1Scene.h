#pragma once
#include "SceneBase.h"


class Stage1Scene :
	public SceneBase
{
public:
	Stage1Scene();
	~Stage1Scene();
	void Draw();
	void Control();
	int* GetTexture(){ return &TextureID; }
private:
	int TextureID;
	const float Stage1Tu= 0.25f;
	const float Stage1Tv=1.f;
};


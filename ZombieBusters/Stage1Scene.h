#pragma once
#include "SceneBase.h"


class Stage1Scene :
	public SceneBase
{
public:
	Stage1Scene();
	~Stage1Scene();
	void Draw();
	int* GetTexture(){ return &TextureID; }
private:
	int TextureID;
};


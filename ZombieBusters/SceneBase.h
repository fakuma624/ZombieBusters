#pragma once
#include "DirectGraphics.h"
class SceneBase
{
public:

	SceneBase();
	virtual ~SceneBase();
	virtual void Draw();
	const float DisplayWidth= 960.0f;
	const float DisplayHight = 540.0f;
};


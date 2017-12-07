#pragma once
#include "DirectGraphics.h"
#define DISPLAY_WIDTH 960
#define DISPLAY_HIGHT 540

class SceneBase
{
public:

	SceneBase();
	virtual ~SceneBase();
	virtual void Draw();
	const float DisplayWidth= 960.0f;
	const float DisplayHight = 540.0f;
};


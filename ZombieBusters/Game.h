#pragma once
#include "DirectGraphics.h"
#include "DirectInput.h"
#include <Windows.h>
#include <d3d9.h>
#include "Player.h"

class Player;

class Game
{
public:
	Game();
	virtual ~Game();
	virtual void Draw();
	virtual void Update();
	void Run();
	Player* GetPlayer() { return pPlayer; }
private:
	KEYSTATE Key[KEYMAX] = { KEY_OFF };
	Player* pPlayer;
	
};


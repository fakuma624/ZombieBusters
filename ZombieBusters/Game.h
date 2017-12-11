#pragma once
#include "DirectGraphics.h"
#include "DirectInput.h"
#include <Windows.h>
#include <d3d9.h>
#include "Player.h"
#include "Zombie.h"
#include "CollisionJudgment.h"
#include "SceneManager.h"
#include "Bullet.h"



class Game
{
public:
	Game();
	virtual ~Game();
	virtual void Draw();
	virtual void Update();
	void Run();
	void HitCalculation();
	Player* GetPlayer() { return pPlayer; }
	Zombie* GetZombie() { return pZombie; }
private:
	KEYSTATE Key[KEYMAX] = { KEY_OFF };
	Player* pPlayer;
	Zombie* pZombie;
	CollisionJudgment* pCollision;
	SceneManager* pSceneManager;
	
};


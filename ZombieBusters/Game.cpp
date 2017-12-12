#include "Game.h"



Game::Game()
{
	pPlayer = new Player;
	pZombie = new Zombie;
	pCollision = new CollisionJudgment;
	pSceneManager = new SceneManager;
}


Game::~Game()
{

}
void Game::Update()
{
	pSceneManager->SceneUpdate();
	pPlayer->Update();
	pZombie->Update();
	HitCalculation();

}
void Game::Draw()
{
	DirectGraphics::GetpInstance()->StartRender();
	pSceneManager->SceneDraw();
	pPlayer->Draw();
	pZombie->Draw();
	if (pPlayer->GetBullet() != NULL)
	{
		pPlayer->GetBullet()->Draw();
	}
	
	DirectGraphics::GetpInstance()->EndRender();
}
void Game::Run()
{
	Update();
	Draw();
}

void Game::HitCalculation()
{
	bool PlayerVSZombie = false;
	bool BulletVSZombie = false; 
	if (pPlayer->GetAlive() && pZombie->GetAlive())
	{
		PlayerVSZombie = pCollision->RectangleCollosion(GetPlayer()->GetPos(), GetPlayer()->GetSize(), GetZombie()->GetPos(), GetZombie()->GetSize());
	}
	if (pZombie->GetAlive())
	{
		if (pPlayer->GetBullet() != NULL)
		{
			BulletVSZombie = pCollision->RectangleCollosion(GetPlayer()->GetBullet()->GetPos(), GetPlayer()->GetBullet()->GetSize(), GetZombie()->GetPos(), GetZombie()->GetSize());
		}
	}

	static int PlayerVSZombieFCount = 0;
	static int  BulletVSZombieFcount = 0;
	static int ZombieDethCount = 0;




	if (PlayerVSZombie)
	{
		++PlayerVSZombieFCount;
		if (PlayerVSZombieFCount == 1)
		{
			pPlayer->SetPlayerHp(pZombie->ZombieAtk());
		}



	}
	if (!PlayerVSZombie)
	{
		PlayerVSZombieFCount = 0;
	}
	if (BulletVSZombie)
	{
		++ZombieDethCount;
			
	}
	if (ZombieDethCount > 0)
	{
		++ZombieDethCount;
	}
	if (ZombieDethCount == 60)
	{
		pZombie->SetZombieHp(pPlayer->GetBullet()->BulletAtk());
	}
}
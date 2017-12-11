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
	
	PlayerVSZombie = pCollision->RectangleCollosion(GetPlayer()->GetPos(), GetPlayer()->GetSize(), GetZombie()->GetPos(), GetZombie()->GetSize());
	if (pPlayer->GetBullet() != NULL)
	{
		BulletVSZombie = pCollision->RectangleCollosion(GetPlayer()->GetBullet()->GetPos(), GetPlayer()->GetBullet()->GetSize(), GetZombie()->GetPos(), GetZombie()->GetSize());
	}
	if (PlayerVSZombie)
	{
		pPlayer->SetPlayerHp(pZombie->ZombieAtk());
	}
	if (BulletVSZombie)
	{
		pZombie->SetZombieHp(pPlayer->GetBullet()->BulletAtk());
	}

}
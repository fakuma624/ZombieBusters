#include "Game.h"



Game::Game()
{
	pPlayer = new Player;
	pZombie = new Zombie;
}


Game::~Game()
{

}
void Game::Update()
{
	pPlayer->Update();
	pZombie->Update();
}

void Game::Draw()
{
	DirectGraphics::GetpInstance()->StartRender();
	pPlayer->Draw();
	pZombie->Draw();
	DirectGraphics::GetpInstance()->EndRender();
}
void Game::Run()
{
	Update();
	Draw();
}
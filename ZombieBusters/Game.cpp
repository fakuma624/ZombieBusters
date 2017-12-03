#include "Game.h"



Game::Game()
{
	pPlayer = new Player;
}


Game::~Game()
{

}
void Game::Update()
{
	pPlayer->Update();
}

void Game::Draw()
{
	DirectGraphics::GetpInstance()->StartRender();
	pPlayer->Draw();
	DirectGraphics::GetpInstance()->EndRender();
}
void Game::Run()
{
	Update();
	Draw();
}
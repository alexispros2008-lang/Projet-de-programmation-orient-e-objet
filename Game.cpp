#include "Game.h"

Game::Game()
{
	_endGame = false;
}

Game::~Game()
{
}

void Game::run()
{
	while (!_endGame)
	{

	}
}

void Game::checkBoundings()
{
	if (_player.getPlayerBounds().intersects(_arena.getArenaBounds()))
	{

	}
}

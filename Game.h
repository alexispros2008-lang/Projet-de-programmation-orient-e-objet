#pragma once
#include "Player.h"
#include "Arena.h"
#include "Boss.h"

class Game
{
private:
	Player _player;
	Arena _arena;
	Boss _boss;

	bool _endGame;

public:
	Game();
	~Game();
	void run();

	void checkArenaBounds();

	void movePlayer();

	void showHealthBar(sf::RenderWindow& window);
};


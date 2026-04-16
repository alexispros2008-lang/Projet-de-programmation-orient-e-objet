#pragma once
#include "Player.h"
#include "Arena.h"
#include "Boss.h"

class Game
{
private:
	Player player;
	Arena arena;
	Boss boss;

public:
	Game();
	~Game();
	void run();
};


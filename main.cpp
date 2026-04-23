#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>

int main()
{
    srand(time(NULL));
	Game game;
    game.run();

    return 0;
}
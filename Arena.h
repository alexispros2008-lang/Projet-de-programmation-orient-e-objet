#pragma once
#include "SFML/Graphics.hpp"
#include "mesConstantes.h"

class Arena
{
private:
	sf::RectangleShape _arena;
	sf::FloatRect _arenaBounds = _arena.getGlobalBounds();
public:
	Arena();
	~Arena();
	sf::FloatRect getArenaBounds() { return _arenaBounds; }
	sf::RectangleShape getArena() { return _arena; }
};


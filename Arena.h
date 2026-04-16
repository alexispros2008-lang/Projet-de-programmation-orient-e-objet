#pragma once
#include "SFML/Graphics.hpp"
#include "mesConstantes.h"

class Arena
{
private:
	sf::RectangleShape _arena;
	sf::FloatRect _arenaBounds;
	sf::RectangleShape outlineArena;

public:
	Arena();
	~Arena();
	sf::FloatRect getArenaBounds() { return _arenaBounds; }
	sf::RectangleShape getArena() { return _arena; }

	void drawOutlineArena(sf::RenderWindow& window);
};


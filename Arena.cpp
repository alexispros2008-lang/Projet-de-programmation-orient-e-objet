#include "Arena.h"

Arena::Arena()
{
	_arena.setPosition(ARENA_POS_X, ARENA_POS_Y);
	_arena.setSize(sf::Vector2f(ARENA_WIDTH, ARENA_HEIGHT));
	_arena.setFillColor(sf::Color::Black);
	_arenaBounds = _arena.getGlobalBounds();
}

Arena::~Arena()
{
	_arena.setPosition(ARENA_POS_X, ARENA_POS_Y);
	_arena.setSize(sf::Vector2f(ARENA_WIDTH, ARENA_HEIGHT));
	_arena.setFillColor(sf::Color::Transparent);
	_arenaBounds = _arena.getGlobalBounds();
}

#include "Arena.h"

Arena::Arena()
{
	_arena.setPosition(ARENA_POS_X, ARENA_POS_Y);
	_arena.setSize(sf::Vector2f(ARENA_WIDTH, ARENA_HEIGHT));
	_arena.setFillColor(sf::Color::Black);
	_arenaBounds = _arena.getGlobalBounds();
	_arenaBounds.left += 45;
	_arenaBounds.top += 45;
	_arenaBounds.width -= 90;
	_arenaBounds.height -= 90;
}

Arena::~Arena()
{
	_arena.setPosition(ARENA_POS_X, ARENA_POS_Y);
	_arena.setSize(sf::Vector2f(ARENA_WIDTH, ARENA_HEIGHT));
	_arena.setFillColor(sf::Color::Transparent);
	_arenaBounds = _arena.getGlobalBounds();
}

void Arena::drawOutlineArena(sf::RenderWindow& window)
{
	outlineArena.setPosition(ARENA_POS_X - 5, ARENA_POS_Y - 5);
	outlineArena.setSize(sf::Vector2f(ARENA_WIDTH + 10, ARENA_HEIGHT + 10));
	outlineArena.setFillColor(sf::Color::Transparent);
	outlineArena.setOutlineThickness(5);
	outlineArena.setOutlineColor(sf::Color::White);
	window.draw(outlineArena);

}

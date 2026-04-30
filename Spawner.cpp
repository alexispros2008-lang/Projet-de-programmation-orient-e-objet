#include "Spawner.h"

Spawner::Spawner()
{
	_spawner.setSize(sf::Vector2f(0, 0));
	_spawner.setPosition(0, 0);
	_rotation = 0.0f;
	_speed = sf::Vector2f(0, 0);
}

Spawner::~Spawner()
{
	_spawner.setSize(sf::Vector2f(0, 0));
	_spawner.setPosition(0, 0);
}

void Spawner::move()
{
	_spawner.move(_speed);
}

void Spawner::turn()
{
	_spawner.rotate(_rotation);
}

void Spawner::summonBullet()
{
	Snowball s(_spawner.getPosition(), 0, NOTHING, 0);
	_snowballs.push_back(s);
}

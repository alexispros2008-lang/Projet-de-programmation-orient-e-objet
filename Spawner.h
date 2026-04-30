#pragma once
#include "SFML/Graphics.hpp"
#include "Snowball.h"
class Spawner
{
private:
	sf::RectangleShape _spawner;
	sf::FloatRect _spawnerBounds = _spawner.getGlobalBounds();
	sf::Vector2f _speed;
	float _rotation; //angle
	std::vector <Snowball> _snowballs;
public:
	Spawner();

	~Spawner();
	inline sf::RectangleShape getSpawner() const { return _spawner; }

	void move();
	void turn();
	void summonBullet();
};


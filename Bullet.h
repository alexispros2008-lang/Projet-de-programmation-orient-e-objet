#pragma once
#include <SFML/Graphics.hpp>
enum Direction {
	LEFT,
	IP,
	DOWN,
	RIGHT,
	NOTHING
};

class Bullet
{
	protected:
		sf::Vector2 <int> _positionBullet;
		sf::Vector2 <int> _bulletSize;
		int _bulletSpeed;
		int _damageAmount;
		Direction _direction;
	public:
		Bullet();
		Bullet(sf::Vector2 <int> positionBullet, sf::Vector2 <int> bulletSize, int bulletSpeed, int damageAmount, Direction direction);
		~Bullet();
};


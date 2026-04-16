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
		int _bulletSpeed;
		int _damageAmount;
		Direction _direction;
	public:
		Bullet();
		Bullet(sf::Vector2 <int> positionBullet, int bulletSpeed, int damageAmount, Direction direction);
		~Bullet();
		virtual void drawBullet() = 0;
};


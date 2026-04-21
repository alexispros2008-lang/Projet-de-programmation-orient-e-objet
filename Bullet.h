#pragma once
#include <SFML/Graphics.hpp>
enum Direction {
	LEFT,
	UP,
	DOWN,
	RIGHT,
	RIGHT_UP,
	RIGHT_DOWN,
	LEFT_UP,
	LEFT_DOWN,
	NOTHING
};

class Bullet
{
	protected:
		sf::Vector2 <float> _positionBullet;
		int _bulletSpeed;
		Direction _direction;
	public:
		Bullet();
		Bullet(sf::Vector2 <float> positionBullet, int bulletSpeed, Direction direction);
		~Bullet();
		void createBullet(sf::Vector2 <float> positionBullet, int bulletSpeed, Direction direction);
		virtual void bulletMovement() = 0;
};


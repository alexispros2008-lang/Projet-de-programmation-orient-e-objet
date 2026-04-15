#pragma once
#include <SFML/Graphics.hpp>
class Bullet
{
	protected:
		sf::Vector2 <int> _positionBullet;
		int _bulletSpeed;
	public:
		Bullet();
		Bullet(sf::Vector2 <int> positionBullet, int bulletSpeed);
		~Bullet();
};


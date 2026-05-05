#pragma once
#include <SFML/Graphics.hpp>
#include "mesConstantes.h"

class Bullet
{
	protected:
		sf::CircleShape _bulletCircle;
		int _bulletSpeed;
		float _angle;
		float _rotation; //speed of rotation
		float _bulletLifeTime;
	public:
		Bullet();
		Bullet(sf::CircleShape bulletCircle, int bulletSpeed, int radius, float angle, float rotation, float bulletLifeTime);
		~Bullet();

		Bullet& getBullet() { return *this; }
		const sf::CircleShape& getBulletCircle() const { return _bulletCircle; }

		void createBullet(sf::CircleShape bulletCircle, int bulletSpeed, int radius, float angle, float rotation, float bulletLifeTime);
		void bulletMovement();
};


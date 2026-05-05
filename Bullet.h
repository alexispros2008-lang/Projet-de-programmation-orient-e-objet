#pragma once
#include <SFML/Graphics.hpp>
#include "mesConstantes.h"

class Bullet
{
	protected:
		sf::CircleShape _bulletCircle;
		sf::Rect <float> _bulletBounds = _bulletCircle.getGlobalBounds();
			
		int _bulletSpeed;
		float _angle;
		float _rotation; //speed of rotation
	public:
		Bullet();
		Bullet(sf::CircleShape bulletCircle, int bulletSpeed, int radius, float angle, float rotation);
		~Bullet();

		Bullet& getBullet() { return *this; }
		const sf::CircleShape& getBulletCircle() const { return _bulletCircle; }
		const sf::Rect<float>& getBulletBounds() const { return _bulletBounds; }

		void createBullet(sf::CircleShape bulletCircle, int bulletSpeed, int radius, float angle, float rotation);
		void bulletMovement();
		float &getBulletLifeTime();
};


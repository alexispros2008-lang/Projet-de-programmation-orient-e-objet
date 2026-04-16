#pragma once
#include "Bullet.h"
class Snowball : public Bullet
{
	private:
		sf::CircleShape _snowballCircle;
	public:
		Snowball(sf::Vector2 <float> positionBullet, int bulletSpeed, int damageAmount, Direction direction, int radius);
		~Snowball();
		const sf::CircleShape getCircle();
		void bulletMovement() override;
};


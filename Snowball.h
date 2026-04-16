#pragma once
#include "Bullet.h"
class Snowball : public Bullet
{
	private:
		sf::CircleShape _snowballCircle;
	public:
		Snowball();
		Snowball(sf::Vector2 <int> positionBullet, int bulletSpeed, int damageAmount, Direction direction);
		~Snowball();
		void drawBullet() override;
};


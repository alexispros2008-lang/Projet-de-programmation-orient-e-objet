#pragma once
#include "Bullet.h"
class Snowball : public Bullet
{
	public:
		Snowball(sf::CircleShape bulletCircle, int bulletSpeed, float angle, int radius, float rotation);
		~Snowball();
		const sf::CircleShape& getSnowballCircle();
		void setColorWhite();
		void setColorBlue();
		void setColorOrange();
		void setColorGreen();
		bool checkWhite();
		bool checkBlue();
		bool checkOrange();
		bool checkGreen();
};


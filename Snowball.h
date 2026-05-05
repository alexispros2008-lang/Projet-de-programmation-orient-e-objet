#pragma once
#include "Bullet.h"
class Snowball : public Bullet
{
	private:
		sf::Rect <float> _snowballBounds = _bulletCircle.getGlobalBounds();
	public:
		Snowball(sf::CircleShape bulletCircle, int bulletSpeed, float angle, int radius, float rotation, float bulletLifeTime);
		~Snowball();
		sf::Rect <float> getSnowballBounds() const { return _snowballBounds; }
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


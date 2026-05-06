#pragma once
#include "Bullet.h"
class Snowball : public Bullet
{
	public:
		Snowball(sf::CircleShape bulletCircle, int bulletSpeed, float angle, int radius, float rotation);
		Snowball(); 
		~Snowball();

		const sf::CircleShape& getSnowballCircle();
		inline Bullet& getBullet() { return *this; }
		inline const sf::Rect<float>& getSnowballBounds() const { return _bulletBounds; }
		inline int getBulletSpeed() const { return _bulletSpeed; }
		inline float getAngle() const { return _angle; }
		inline float getRotation() const { return _rotation; }

		void setColorWhite();
		void setColorBlue();
		void setColorOrange();
		void setColorGreen();
		bool checkWhite();
		bool checkBlue();
		bool checkOrange();
		bool checkGreen();
};


#pragma once
#include "Bullet.h"
class Snowball : public Bullet
{
	private:
		sf::CircleShape _snowballCircle;
		sf::Rect <float> _snowballBounds = _snowballCircle.getGlobalBounds();
	public:
		Snowball(sf::Vector2 <float> positionBullet, int bulletSpeed, Direction direction, int radius);
		~Snowball();
		sf::Rect <float> getSnowballBounds() const { return _snowballBounds; }
		const sf::CircleShape getSnowballCircle();
		void bulletMovement() override;
		void setColorWhite();
		void setColorBlue();
		void setColorOrange();
		void setColorGreen();
		bool checkWhite();
		bool checkBlue();
		bool checkOrange();
		bool checkGreen();
};


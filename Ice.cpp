#include "Ice.h"

Ice::Ice()
{
	createBullet(_bulletCircle, 0, 0, 0.0f, 0.0f);
}

Ice::Ice(sf::CircleShape bulletCircle, int bulletSpeed, int radius, float angle, float rotation)
{
	createBullet(bulletCircle, bulletSpeed, radius, angle, rotation);
	_bulletCircle.setFillColor(sf::Color::Cyan);
}

Ice::~Ice()
{
	createBullet(_bulletCircle, 0, 0, 0.0f, 0.0f);
}
#include "Ice.h"

Ice::Ice()
{
	createBullet(sf::Vector2f(0.0f, 0.0f), 0, NOTHING);
	_iceCircle.setRadius(0);
	_iceCircle.setPosition({ 0.0f, 0.0f });
	_rotation = 0.0f;
	_angle = 0.0f;
}

Ice::Ice(sf::Vector2<float> positionBullet, int bulletSpeed, int radius, float angle, float rotation)
{
	createBullet(positionBullet, bulletSpeed, NOTHING);
	_iceCircle.setPosition(positionBullet);
	_iceCircle.setRadius(radius);
	_iceCircle.setFillColor(sf::Color::Cyan);
	_rotation = rotation;
	_angle = angle;
}

Ice::~Ice()
{
	createBullet(sf::Vector2f(0.0f, 0.0f), 0, NOTHING);
	_iceCircle.setRadius(0);
	_iceCircle.setPosition({ 0.0f, 0.0f });
	_rotation = 0.0f;
	_angle = 0.0f;
}

void Ice::bulletMovement()
{
	_angle += _rotation;
	sf::Vector2f bulletMovement(_bulletSpeed * (cos(_angle * PI / 180) / 2), _bulletSpeed * (sin(_angle * PI / 180) / 2)); //convertir angle en radians, mettre dans un vecteur
	_iceCircle.move(bulletMovement);
	
}

#include "Bullet.h"
#include "Windows.h"
#include "assert.h"

Bullet::Bullet()
{
	_bulletCircle.setRadius(0);
	_bulletCircle.setPosition({ 0.0f, 0.0f });
	_bulletSpeed = 0;
	_rotation = 0.0f;
	_angle = 0.0f;
	_bulletLifeTime = 0.0f;
}

Bullet::Bullet(sf::CircleShape bulletCircle, int bulletSpeed, int radius, float angle, float rotation, float bulletLifeTime)
{
	createBullet(bulletCircle, bulletSpeed, radius, angle, rotation, bulletLifeTime);
}

Bullet::~Bullet()
{
	_bulletCircle.setRadius(0);
	_bulletCircle.setPosition({ 0.0f, 0.0f });
	_bulletSpeed = 0;
	_rotation = 0.0f;
	_angle = 0.0f;
}

void Bullet::createBullet(sf::CircleShape bulletCircle, int bulletSpeed, int radius, float angle, float rotation, float bulletLifeTime)
{
	_bulletCircle.setRadius(radius);
	_bulletCircle.setPosition({ bulletCircle.getPosition().x, bulletCircle.getPosition().y});
	_bulletSpeed = bulletSpeed;
	_rotation = rotation;
	_angle = angle;
}

void Bullet::bulletMovement()
{
	_angle += _rotation;
	sf::Vector2f bulletMovement(_bulletSpeed * (cos(_angle * PI / 180) / 2), -(_bulletSpeed * (sin(_angle * PI / 180) / 2))); //convertir angle en radians, mettre dans un vecteur
	_bulletCircle.move(bulletMovement);
}

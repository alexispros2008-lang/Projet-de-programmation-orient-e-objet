#include "Bullet.h"
#include "Windows.h"
#include "assert.h"

Bullet::Bullet()
{
	createBullet({ 0.0f, 0.0f }, 0, NOTHING);
}

Bullet::Bullet(sf::Vector2 <float> positionBullet, int bulletSpeed, Direction direction)
{
	createBullet(positionBullet, bulletSpeed, direction);
}

Bullet::~Bullet()
{
	createBullet({ 0.0f, 0.0f }, 0, NOTHING);
}

void Bullet::createBullet(sf::Vector2<float> positionBullet, int bulletSpeed, Direction direction)
{
	_positionBullet = positionBullet;
	_bulletSpeed = bulletSpeed;
	_direction = direction;
}

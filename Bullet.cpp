#include "Bullet.h"

Bullet::Bullet()
{
	_positionBullet.x = 0;
	_positionBullet.y = 0;
	_bulletSpeed = 0;
}

Bullet::Bullet(sf::Vector2 <int> positionBullet, int bulletSpeed)
{
	_positionBullet.x = positionBullet.x;
	_positionBullet.y = positionBullet.y;
	_bulletSpeed = bulletSpeed;
}

Bullet::~Bullet()
{
	_positionBullet.x = 0;
	_positionBullet.y = 0;
	_bulletSpeed = 0;
}

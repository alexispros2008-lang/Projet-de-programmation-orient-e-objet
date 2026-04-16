#include "Bullet.h"

Bullet::Bullet()
{
	_positionBullet.x = 0;
	_positionBullet.y = 0;
	_bulletSize.x = 0;
	_bulletSize.y = 0;
	_bulletSpeed = 0;
	_direction = NOTHING;
	_damageAmount = 0;
}

Bullet::Bullet(sf::Vector2 <int> positionBullet, sf::Vector2 <int> bulletSize, int bulletSpeed, int damageAmount, Direction direction)
{
	_positionBullet.x = positionBullet.x;
	_positionBullet.y = positionBullet.y;
	_bulletSize.x = bulletSize.x;
	_bulletSize.y = bulletSize.y;
	_bulletSpeed = bulletSpeed;
	_direction = direction;
	_damageAmount = damageAmount;
}

Bullet::~Bullet()
{
	_positionBullet.x = 0;
	_positionBullet.y = 0;
	_bulletSize.x = 0;
	_bulletSize.y = 0;
	_bulletSpeed = 0;
	_direction = NOTHING;
	_damageAmount = 0;
}

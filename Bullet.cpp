#include "Bullet.h"
#include "Windows.h"

Bullet::Bullet()
{
	_positionBullet.x = 0.0;
	_positionBullet.y = 0.0;
	_bulletSpeed = 0;
	_direction = NOTHING;
	_damageAmount = 0;
}

Bullet::Bullet(sf::Vector2 <float> positionBullet, int bulletSpeed, int damageAmount, Direction direction)
{
	_positionBullet.x = positionBullet.x;
	_positionBullet.y = positionBullet.y;
	_bulletSpeed = bulletSpeed;
	_direction = direction;
	_damageAmount = damageAmount;
}

Bullet::~Bullet()
{
	_positionBullet.x = 0.0;
	_positionBullet.y = 0.0;
	_bulletSpeed = 0;
	_direction = NOTHING;
	_damageAmount = 0;
}

void Bullet::createBullet(sf::Vector2<float> positionBullet, int bulletSpeed, int damageAmount, Direction direction)
{
	_positionBullet.x = positionBullet.x;
	_positionBullet.y = positionBullet.y;
	_bulletSpeed = bulletSpeed;
	_direction = direction;
	_damageAmount = damageAmount;
}

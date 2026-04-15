#include "Bullet.h"

Bullet::Bullet()
{
	_positionBulletX = 0;
	_positionBulletY = 0;
	_bulletSpeed = 0;
}

Bullet::Bullet(int positionBulletX, int positionBulletY, int bulletSpeed)
{
	_positionBulletX = positionBulletX;
	_positionBulletY = positionBulletY;
	_bulletSpeed = bulletSpeed;
}

Bullet::~Bullet()
{
	_positionBulletX = 0;
	_positionBulletY = 0;
	_bulletSpeed = 0;
}

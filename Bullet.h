#pragma once
class Bullet
{
	protected:
		int _positionBulletX;
		int _positionBulletY;
		int _bulletSpeed;
	public:
		Bullet();
		Bullet(int positionBulletX, int positionBulletY, int bulletSpeed);
		~Bullet();
};


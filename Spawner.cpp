#include "Spawner.h"

Spawner::Spawner()
{
	_spawner.setSize(sf::Vector2f(0, 0));
	_spawner.setPosition(0, 0);
	_angle = 0.0f;
	_rotation = 0.0f;
	_speed = sf::Vector2f(0, 0);
	_shootSpeed = 0.0f;
	_spawnerLifeTime = 0.0f;
}

Spawner::Spawner(sf::Vector2f position, float angle, float rotation, float shootSpeed, float spawnerLifeTime)
{
	setSpawner(position, angle, rotation, shootSpeed, spawnerLifeTime);
}

Spawner::~Spawner()
{
	_spawner.setSize(sf::Vector2f(0, 0));
	_spawner.setPosition(0, 0);
	_angle = 0.0f;
	_rotation = 0.0f;
	_speed = sf::Vector2f(0, 0);
	_shootSpeed = 0.0f;
	_spawnerLifeTime = 0.0f;
}

void Spawner::setTypeBullet(Snowball bullet)
{
	sf::CircleShape tempBullet;
	tempBullet.setPosition(bullet.getSnowballCircle().getPosition());
	_typeSnowball.setSnowball(tempBullet, bullet.getBulletSpeed(), bullet.getSnowballCircle().getRadius(), bullet.getAngle(), bullet.getRotation());
}

void Spawner::setSpawner(sf::Vector2f position, float angle, float rotation, float shootSpeed, float spawnerLifeTime)
{
	_spawner.setPosition(position);
	_spawner.setSize(sf::Vector2f(50, 50));
	_angle = angle;
	_rotation = rotation;
	_shootSpeed = shootSpeed;
	_spawnerLifeTime = spawnerLifeTime;
}

void Spawner::move()
{
	if (_shootSpeedClock.getElapsedTime() >= sf::seconds(_shootSpeed / 10))
	{
		_angle += _rotation;
		sf::Vector2f movement(_speed.x * (cos(_angle * PI / 180) / 2), _speed.y * (sin(_angle * PI / 180) / 2)); //convertir angle en radians, mettre dans un vecteur
		_spawner.move(movement);
	}
}

void Spawner::turn()
{
	_spawner.rotate(_rotation);
}

void Spawner::summonBullet()
{
	if (_shootSpeedClock.getElapsedTime() >= sf::seconds(_shootSpeed / 10))
	{
		sf::CircleShape tempCircle;
		tempCircle.setPosition(_spawner.getPosition());
		Snowball snowball(tempCircle, _typeSnowball.getBulletSpeed(), _typeSnowball.getBullet().getBulletCircle().getRadius(), _typeSnowball.getAngle() + _angle, _typeSnowball.getRotation());
		_snowBullets.push_back(snowball);
		_shootSpeedClock.restart();
	}
}

void Spawner::deleteOneSnowball(int snowballVectorPlace)
{
	_snowBullets.erase(_snowBullets.begin() + snowballVectorPlace);
}
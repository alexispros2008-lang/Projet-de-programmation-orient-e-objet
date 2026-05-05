#include "Spawner.h"

Spawner::Spawner()
{
	_spawner.setSize(sf::Vector2f(0, 0));
	_spawner.setPosition(0, 0);
	_angle = 0.0f;
	_rotation = 0.0f;
	_speed = sf::Vector2f(0, 0);
	_shootSpeed = 0.0f;
}

Spawner::Spawner(sf::Vector2f position, float angle, float rotation, float shootSpeed)
{
	setSpawner(position, angle, rotation, shootSpeed);
}

Spawner::~Spawner()
{
	_spawner.setSize(sf::Vector2f(0, 0));
	_spawner.setPosition(0, 0);
}

void Spawner::setSpawner(sf::Vector2f position, float angle, float rotation, float shootSpeed)
{
	_spawner.setPosition(position);
	_spawner.setSize(sf::Vector2f(50, 50));
	_angle = angle;
	_rotation = rotation;
	_shootSpeed = shootSpeed;
}

void Spawner::move()
{
	_angle += _rotation;
	sf::Vector2f movement(_speed.x * (cos(_angle * PI / 180) / 2), _speed.y * (sin(_angle * PI / 180) / 2)); //convertir angle en radians, mettre dans un vecteur
	_spawner.move(movement);
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
		Ice iceBullet(tempCircle, _typeIce.getBulletSpeed(), _typeIce.getRadius(), _typeIce.getAngle() + _angle, _typeIce.getRotation(), 0.0f);
		_iceBullets.push_back(iceBullet);
		_shootSpeedClock.restart();
	}
}

#include "Spawner.h"

Spawner::Spawner()
{
	_spawner.setSize(sf::Vector2f(0, 0));
	_spawner.setPosition(0, 0);
	_angle = 0.0f;
	_rotation = 0.0f;
	_speed = sf::Vector2f(0, 0);
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
	_spawner.setFillColor(sf::Color::Magenta);
	_angle = angle;
	_rotation = rotation;
}

void Spawner::move()
{
	_angle += _rotation;
	sf::Vector2f movement(_speed.x * (cos(_angle * 3.14 / 180) / 2), _speed.y * (sin(_angle * 3.14 / 180) / 2)); //convertir angle en radians, mettre dans un vecteur
	_spawner.move(movement);
}

void Spawner::turn()
{
	_spawner.rotate(_rotation);
}

void Spawner::summonBullet()
{
	Ice iceBullet(_spawner.getPosition(), _typeIce.getBulletSpeed(), _typeIce.getRadius(), _typeIce.getAngle() + _angle, _typeIce.getRotation());
	_iceBullets.push_back(iceBullet);
}

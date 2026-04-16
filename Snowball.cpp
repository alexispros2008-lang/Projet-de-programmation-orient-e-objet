#include "Snowball.h"
#include "mesFonctions.h"
#include <SFML/Window.hpp>
#include "Windows.h"

Snowball::Snowball(sf::Vector2<float> positionBullet, int bulletSpeed, int damageAmount, Direction direction, int radius)
{
	createBullet(positionBullet, bulletSpeed, damageAmount, direction);
	_snowballCircle = sf::CircleShape(radius);
	_snowballCircle.setPosition(positionBullet);
}

Snowball::~Snowball()
{
}

const sf::CircleShape Snowball::getCircle()
{
	return _snowballCircle;
}

void Snowball::bulletMovement()
{
	Sleep(_bulletSpeed);
	_snowballCircle.setPosition(_snowballCircle.getPosition().x, _snowballCircle.getPosition().y + 2);
}

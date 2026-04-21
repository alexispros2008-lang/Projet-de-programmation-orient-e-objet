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
	if (_direction == UP) {
		_snowballCircle.setPosition(_snowballCircle.getPosition().x, _snowballCircle.getPosition().y - 2);
	}
	else if (_direction == RIGHT_UP) {
		_snowballCircle.setPosition(_snowballCircle.getPosition().x + 1, _snowballCircle.getPosition().y - 1);
	}
	else if (_direction == RIGHT_DOWN) {
		_snowballCircle.setPosition(_snowballCircle.getPosition().x + 1, _snowballCircle.getPosition().y + 1);
	}
	else if (_direction == LEFT_UP) {
		_snowballCircle.setPosition(_snowballCircle.getPosition().x - 1, _snowballCircle.getPosition().y - 1);
	}
	else if (_direction == LEFT_DOWN) {
		_snowballCircle.setPosition(_snowballCircle.getPosition().x - 1, _snowballCircle.getPosition().y + 1);
	}
	else if (_direction == LEFT) {
		_snowballCircle.setPosition(_snowballCircle.getPosition().x - 2, _snowballCircle.getPosition().y);
	}
	else if (_direction == RIGHT) {
		_snowballCircle.setPosition(_snowballCircle.getPosition().x + 2, _snowballCircle.getPosition().y);
	}
	else if (_direction == DOWN) {
		_snowballCircle.setPosition(_snowballCircle.getPosition().x, _snowballCircle.getPosition().y + 2);
	}
	else {

	}

	_snowballBounds = _snowballCircle.getGlobalBounds();
}

#include "Snowball.h"
#include "mesFonctions.h"
#include <SFML/Window.hpp>
#include "Windows.h"

Snowball::Snowball(sf::Vector2<float> positionBullet, int bulletSpeed, Direction direction, int radius)
{
	createBullet(positionBullet, bulletSpeed, direction);
	_snowballCircle = sf::CircleShape(radius);
	_snowballCircle.setPosition(positionBullet);
}

Snowball::~Snowball()
{
}

const sf::CircleShape Snowball::getSnowballCircle()
{
	return _snowballCircle;
}

void Snowball::bulletMovement()
{
	if (_direction == RIGHT_UP) {
		_snowballCircle.setPosition(_snowballCircle.getPosition().x + _bulletSpeed, _snowballCircle.getPosition().y - _bulletSpeed);
	}
	else if (_direction == RIGHT_DOWN) {
		_snowballCircle.setPosition(_snowballCircle.getPosition().x + _bulletSpeed, _snowballCircle.getPosition().y + _bulletSpeed);
	}
	else if (_direction == LEFT_UP) {
		_snowballCircle.setPosition(_snowballCircle.getPosition().x - _bulletSpeed, _snowballCircle.getPosition().y - _bulletSpeed);
	}
	else if (_direction == LEFT_DOWN) {
		_snowballCircle.setPosition(_snowballCircle.getPosition().x - _bulletSpeed, _snowballCircle.getPosition().y + _bulletSpeed);
	}
	else if (_direction == UP) {
		_snowballCircle.setPosition(_snowballCircle.getPosition().x, _snowballCircle.getPosition().y - (_bulletSpeed * 1.45));
	}
	else if (_direction == LEFT) {
		_snowballCircle.setPosition(_snowballCircle.getPosition().x - (_bulletSpeed * 1.45), _snowballCircle.getPosition().y);
	}
	else if (_direction == RIGHT) {
		_snowballCircle.setPosition(_snowballCircle.getPosition().x + (_bulletSpeed * 1.45), _snowballCircle.getPosition().y);
	}
	else if (_direction == DOWN) {
		_snowballCircle.setPosition(_snowballCircle.getPosition().x, _snowballCircle.getPosition().y + (_bulletSpeed * 1.45));
	}
	else {

	}

	_snowballBounds = _snowballCircle.getGlobalBounds();
}
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

void Snowball::setColorWhite()
{
	_snowballCircle.setFillColor(sf::Color::White);
}

void Snowball::setColorBlue()
{
	_snowballCircle.setFillColor(sf::Color::Cyan);
}

void Snowball::setColorOrange()
{
	sf::Color orange(248, 147, 41);
	_snowballCircle.setFillColor(orange);
}

void Snowball::setColorGreen()
{
	_snowballCircle.setFillColor(sf::Color::Green);
}

bool Snowball::checkWhite()
{
	if (_snowballCircle.getFillColor() == sf::Color::White)
	{
		return true;
	}
	return false;
}

bool Snowball::checkBlue()
{
	if (_snowballCircle.getFillColor() == sf::Color::Cyan) 
	{
		return true;
	}
	return false;
}

bool Snowball::checkOrange()
{
	sf::Color orange(248, 147, 41);
	if (_snowballCircle.getFillColor() == orange)
	{
		return true;
	}
	return false;
}

bool Snowball::checkGreen()
{
	if (_snowballCircle.getFillColor() == sf::Color::Green)
	{
		return true;
	}
	return false;
}

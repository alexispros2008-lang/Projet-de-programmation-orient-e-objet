#include "Snowball.h"
#include "mesFonctions.h"
#include <SFML/Window.hpp>
#include "Windows.h"

Snowball::Snowball(sf::CircleShape bulletCircle, int bulletSpeed, float angle, int radius, float rotation)
{
	createBullet(bulletCircle, bulletSpeed, radius, angle, rotation);
	_bulletCircle = sf::CircleShape(radius);
	_bulletCircle.setPosition(bulletCircle.getPosition().x, bulletCircle.getPosition().y);
}

Snowball::~Snowball()
{
}

const sf::CircleShape& Snowball::getSnowballCircle()
{
	return _bulletCircle;
}

void Snowball::setColorWhite()
{
	_bulletCircle.setFillColor(sf::Color::White);
}

void Snowball::setColorBlue()
{
	_bulletCircle.setFillColor(sf::Color::Cyan);
}

void Snowball::setColorOrange()
{
	sf::Color orange(248, 147, 41);
	_bulletCircle.setFillColor(orange);
}

void Snowball::setColorGreen()
{
	_bulletCircle.setFillColor(sf::Color::Green);
}

bool Snowball::checkWhite()
{
	if (_bulletCircle.getFillColor() == sf::Color::White)
	{
		return true;
	}
	return false;
}

bool Snowball::checkBlue()
{
	if (_bulletCircle.getFillColor() == sf::Color::Cyan) 
	{
		return true;
	}
	return false;
}

bool Snowball::checkOrange()
{
	sf::Color orange(248, 147, 41);
	if (_bulletCircle.getFillColor() == orange)
	{
		return true;
	}
	return false;
}

bool Snowball::checkGreen()
{
	if (_bulletCircle.getFillColor() == sf::Color::Green)
	{
		return true;
	}
	return false;
}

#include "Snowball.h"
#include "mesFonctions.h"
#include <SFML/Window.hpp>
#include "Windows.h"

Snowball::Snowball(sf::CircleShape bulletCircle, int bulletSpeed, float angle, int radius, float rotation)
{
	createBullet(bulletCircle, bulletSpeed, radius, angle, rotation);
	_snowballCircle = sf::CircleShape(radius);
	_snowballCircle.setPosition(bulletCircle.getPosition().x, bulletCircle.getPosition().y);
}

Snowball::~Snowball()
{
}

const sf::CircleShape Snowball::getSnowballCircle()
{
	return _snowballCircle;
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

#include "Snowball.h"
#include "mesFonctions.h"
#include <SFML/Window.hpp>

Snowball::Snowball() : Bullet()
{
	_snowballCircle.setPosition(_positionBullet.x, _positionBullet.y);
	sf::Texture textureSnowball;
	std::string pathTextureSnowball = "images/snowball1.jpeg";
	verificationTexture(textureSnowball, pathTextureSnowball);
	_snowballCircle.setTexture(&textureSnowball);
	sf::CircleShape shape(100.f);
}

Snowball::Snowball(sf::Vector2<int> positionBullet, sf::Vector2<int> bulletSize, int bulletSpeed, int damageAmount, Direction direction) : Bullet()
{
	_snowballCircle.setPosition(_positionBullet.x, _positionBullet.y);
	sf::Texture textureSnowball;
	std::string pathTextureSnowball = "images/snowball1.jpeg";
	verificationTexture(textureSnowball, pathTextureSnowball);
	_snowballCircle.setTexture(&textureSnowball);
	sf::CircleShape shape(100.f);
}

Snowball::~Snowball()
{
}

const sf::CircleShape Snowball::getCircle()
{
	return _snowballCircle;
}

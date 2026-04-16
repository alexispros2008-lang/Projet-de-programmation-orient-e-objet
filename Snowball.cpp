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
}

Snowball::Snowball(sf::Vector2<int> positionBullet, int bulletSpeed, int damageAmount, Direction direction) : Bullet()
{
}

Snowball::~Snowball()
{
}

void Snowball::drawBullet()
{

}


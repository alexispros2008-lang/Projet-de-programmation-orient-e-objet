#include "Player.h"
#include "mesFonctions.h"

Player::Player()
{
	_player.setPosition(0, 0);
	_player.setSize(sf::Vector2f(0, 0));
	_playerHitbox.setPosition(0, 0);
	_playerHitbox.setSize(sf::Vector2f(0, 0));
	_playerSpeed = 0.0f;
	_playerHealth = 0;
	_playerBounds = _playerHitbox.getGlobalBounds();
}

Player::Player(sf::Vector2f position, sf::Vector2f size)
{
	_player.setPosition(position);
	_player.setSize(size);
	_playerHitbox.setPosition(position);
	_playerHitbox.setSize(size);
	_playerSpeed = 0.0f;
	_playerHealth = PLAYER_HP;
}

Player::~Player()
{
	_player.setPosition(0, 0);
	_player.setSize(sf::Vector2f(0, 0));
	_playerHitbox.setPosition(0, 0);
	_playerHitbox.setSize(sf::Vector2f(0, 0));
	_playerSpeed = 0.0f;
}

void Player::initSprite()
{
	sf::Texture playerTexture;
	verificationTexture(playerTexture, "images/player.png");
	_player.setTexture(&playerTexture);
	_playerHitbox.setTexture(&playerTexture);
}

void Player::movePlayer(sf::Vector2f movement)
{
	_player.move(movement);
	_playerHitbox.move(movement);
	_playerBounds = _playerHitbox.getGlobalBounds();
	_previousMovement.push_back(movement);
}

void Player::takeDamage(int dmg)
{
	_playerHealth -= dmg;
}

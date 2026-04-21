#include "Player.h"
#include "mesFonctions.h"
#include "SFML/Audio.hpp"

Player::Player()
{
	_player.setPosition(0, 0);
	_player.setSize(sf::Vector2f(0, 0));
	_playerHitbox.setPosition(0, 0);
	_playerHitbox.setSize(sf::Vector2f(0, 0));
	_playerSpeed = 0.0f;
	_playerHealth = 0;
	_playerBounds = _playerHitbox.getGlobalBounds();
	_hasIFrames = false;
}

Player::Player(sf::Vector2f position, sf::Vector2f size)
{
	_player.setPosition(position);
	_player.setSize(size);
	_playerHitbox.setPosition(position);
	_playerHitbox.setSize(size);
	_playerSpeed = 0.0f;
	_playerHealth = PLAYER_HP;
	_hasIFrames = false;
}

Player::~Player()
{
	_player.setPosition(0, 0);
	_player.setSize(sf::Vector2f(0, 0));
	_playerHitbox.setPosition(0, 0);
	_playerHitbox.setSize(sf::Vector2f(0, 0));
	_playerSpeed = 0.0f;
	_hasIFrames = false;
}

void Player::initSprite()
{
	static sf::Texture playerTexture; // durée de vie statique : reste valide tant que le programme tourne

	// Charger la texture une seule fois
	verificationTexture(playerTexture, "images\\player.png");
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
	startIFrames();

	sf::SoundBuffer dmgBuffer;
	sf::Sound dmgSound;

	if (!dmgBuffer.loadFromFile("sound/dmg.wav")) {
		exit(1);
	} 

	dmgSound.setBuffer(dmgBuffer);
	dmgSound.setLoop(false);
	dmgSound.setVolume(100);
	dmgSound.play(); 
}

void Player::startIFrames()
{
	_iFramesClock.restart();
	_hasIFrames = true;
}

void Player::stopIFrames()
{
	_iFramesTimer = _iFramesClock.getElapsedTime();
	if (_iFramesTimer.asSeconds() >= IFRAME_DURATION) {
		_hasIFrames = false;
	}
}

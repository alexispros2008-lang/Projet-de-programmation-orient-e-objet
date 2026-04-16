#pragma once
#include <SFML/Graphics.hpp>
#include "mesConstantes.h"

class Player
{
private:
	sf::RectangleShape _player;
	sf::RectangleShape _playerHitbox;
	sf::FloatRect _playerBounds = _playerHitbox.getGlobalBounds();

	sf::Texture _playerTexture;
	sf::IntRect _playerSprite;

	float _playerSpeed;
	int _playerHealth;
public:
	Player();
	Player(sf::Vector2f position, sf::Vector2f size);
	~Player();

	sf::FloatRect getPlayerBounds() { return _playerBounds; }
	float getPlayerSpeed() { return _playerSpeed; }
	sf::RectangleShape getPlayer() { return _player; }
	sf::RectangleShape getPlayerHitbox() { return _playerHitbox; }

	void setPlayerTexture(sf::Texture texture) { _playerTexture = texture; }
	void setPlayerSprite(sf::IntRect sprite) { _playerSprite = sprite; }
	void setPlayerSpeed(float speed) { _playerSpeed = speed; }

	void movePlayer(sf::Vector2f movement);
	void takeDamage(int dmg);
};


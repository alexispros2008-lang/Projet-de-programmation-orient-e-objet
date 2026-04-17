#pragma once
#include <SFML/Graphics.hpp>
#include "mesConstantes.h"
#include <vector>

class Player
{
private:
	sf::RectangleShape _player;
	sf::RectangleShape _playerHitbox;
	sf::FloatRect _playerBounds = _playerHitbox.getGlobalBounds();

	std::vector<sf::Vector2f> _previousMovement;
	float _playerSpeed;
	int _playerHealth;
public:
	Player();
	Player(sf::Vector2f position, sf::Vector2f size);
	~Player();

	sf::FloatRect& getPlayerBounds() { return _playerBounds; }
	float getPlayerSpeed() { return _playerSpeed; }
	sf::RectangleShape& getPlayer() { return _player; }
	sf::RectangleShape& getPlayerHitbox() { return _playerHitbox; }
	std::vector<sf::Vector2f>& getPreviousMovement() { return _previousMovement; }
	int getPlayerHealth() { return _playerHealth; }

	void setPlayerSpeed(float speed) { _playerSpeed = speed; }

	void initSprite();

	void movePlayer(sf::Vector2f movement);
	void takeDamage(int dmg);
};


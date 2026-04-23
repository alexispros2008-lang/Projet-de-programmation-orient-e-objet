#pragma once
#include <SFML/Graphics.hpp>
#include "mesConstantes.h"
#include <vector>

class Player
{
private:
	sf::RectangleShape _player;
	sf::RectangleShape _playerHitbox = _player;
	sf::FloatRect _playerBounds = _playerHitbox.getGlobalBounds();

	sf::Texture _playerTexture;

	std::vector<sf::Vector2f> _previousMovement;
	float _playerSpeed;
	int _playerHealth;

	bool _hasIFrames;
	sf::Clock _iFramesClock;
	sf::Clock _iFramesAnimationClock;
public:
	Player();
	Player(sf::Vector2f position, sf::Vector2f size);
	~Player();

	inline sf::FloatRect& getPlayerBounds() { return _playerBounds; }
	inline float getPlayerSpeed() const { return _playerSpeed; }
	inline sf::RectangleShape& getPlayer() { return _player; }
	inline sf::RectangleShape& getPlayerHitbox() { return _playerHitbox; }
	inline std::vector<sf::Vector2f>& getPreviousMovement() { return _previousMovement; }
	inline int getPlayerHealth() const { return _playerHealth; }

	inline void setPlayerSpeed(float speed) { _playerSpeed = speed; }

	void initSprite();

	void movePlayer(sf::Vector2f movement);
	void takeDamage(int dmg);

	void startIFrames();
	void stopIFrames();
	inline bool hasIFrames() const { return _hasIFrames; }
};


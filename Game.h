#pragma once
#include "Player.h"
#include "Arena.h"
#include "Boss.h"
#include "Bullet.h"
#include "Pattern.h"
#include <SFML/Audio.hpp>

class Game
{
private:
	Player _player;
	Arena _arena;
	Boss snowBoss;
	Pattern pattern;

	bool _endGame;
	bool _showMenu = true;

	sf::Clock clock;

	sf::SoundBuffer bgmBuffer;
	sf::Sound bgm;

	std::vector<sf::Keyboard::Key> v_key;

public:
	Game();
	~Game();
	void run();

	void checkArenaBounds();

	void movePlayer();

	void drawHealthBar(sf::RenderWindow& window);

	void checkHealth();

	void draw(sf::RenderWindow& window);
};


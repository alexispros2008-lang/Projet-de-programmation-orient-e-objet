#pragma once
#include "Player.h"
#include "Arena.h"
#include "Boss.h"
#include "Bullet.h"
#include "Pattern.h"
#include "Windows.h"
#include <SFML/Audio.hpp>

class Game
{
private:
	Player _player;
	Arena _arena;
	Boss snowBoss;
	Pattern pattern;
	sf::Clock startOfGameClock;

	bool _endGame;
	bool _showMenu = true;
	int _numberOfPattern = 0;

	sf::Clock clock;

	sf::SoundBuffer bgmBuffer;
	sf::Sound bgm;

	std::vector<sf::Keyboard::Key> v_key;

public:
	Game();
	~Game();
	void run();

	void checkArenaBounds();

	void checkMovePlayer();

	void drawHealthBar(sf::RenderWindow& window);

	void checkHealth();

	void checkDeath(sf::RenderWindow& window);

	void checkPattern();

	void menu(sf::RenderWindow& window);

	void draw(sf::RenderWindow& window);
};


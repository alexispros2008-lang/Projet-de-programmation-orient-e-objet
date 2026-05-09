#pragma once
#include "Player.h"
#include "Arena.h"
#include "Boss.h"
#include "Bullet.h"
#include "Pattern.h"
#include "Windows.h"
#include "Spawner.h"
#include <SFML/Audio.hpp>

class Game
{
private:
	Player _player;
	Arena _arena;
	Boss _snowBoss;
	std::vector<Pattern> _patterns;
	sf::Clock _startOfGameClock;
	Spawner _spawner;

	sf::RenderWindow _window;

	bool _endGame;
	bool _showMenu = true;

	sf::Clock _patternClock;

	sf::SoundBuffer _bgmBuffer;
	sf::Sound _bgm;

	std::vector<sf::Keyboard::Key> _v_key;

	int _nbPatterns = 0;
	int _currentFps = 60;
	int _actualDifficulty = 0;

public:
	Game();
	~Game();
	void run();

	void checkArenaBounds();

	void checkMovePlayer();

	void drawHealthBar();

	void checkHealth();

	void checkDeath();

	void checkPattern();

	void menu();

	void draw();
};


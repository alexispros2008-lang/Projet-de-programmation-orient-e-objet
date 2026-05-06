#include "Game.h"
#include "mesFonctions.h"

//Optimisations a faire: IFrameClock qui compte pas pour infini (Gros nombre)

Game::Game()
{
	_player = Player(sf::Vector2f(PLAYER_INIT_POSITION_X, PLAYER_INIT_POSITION_Y), sf::Vector2f(20, 20));

    if (!_bgmBuffer.loadFromFile("sound/bgm.wav")) {
        exit(1);
    }

    _window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "UndertaleBossFight", sf::Style::Close);
    
    _bgm.setBuffer(_bgmBuffer); // On applique la musique chargée à l’objet de type "Sound"
    _bgm.setLoop(true); // La musique jouera en boucle

	_endGame = false;
}

Game::~Game()
{
}

void Game::run()
{
    
    _window.setFramerateLimit(60);

	//_spawner.setSpawner(sf::Vector2f(ARENA_POS_X + ARENA_WIDTH / 2, ARENA_POS_Y), 270, 1.0f, 1.f);
	//_spawner.setTypeIce(Ice(sf::CircleShape(), 10, 10, 0.0f, 1.0f));

    sf::Event event;
    
    while (_window.isOpen())
    {
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window.close();

            if (event.key.code == sf::Keyboard::Escape)
            {
                _showMenu = true;
            }
            if (event.key.code == sf::Keyboard::Q)
            {
                _player.takeDamage(1);
            }
        }

		menu();

        //_spawner.summonBullet();
        //_spawner.move();

        checkPattern();
        checkMovePlayer();
        checkArenaBounds();

        draw();
        checkDeath();

        _player.getPreviousMovement().clear();
    }
}

void Game::checkArenaBounds()
{
    if (!checkBoundingBox(_player.getPlayerBounds(), _arena.getArenaBounds()))
    {
        for (int i = 0; i < _player.getPreviousMovement().size(); i++)
        {
            _player.movePlayer(-_player.getPreviousMovement().at(i));
            _player.getPreviousMovement().pop_back();
        }
    }
}

void Game::checkMovePlayer()
{
    _player.setPlayerSpeed(0.0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        _player.movePlayer(sf::Vector2f(0, -PLAYER_SPEED));
        _player.setPlayerSpeed(PLAYER_SPEED);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        _player.movePlayer(sf::Vector2f(-PLAYER_SPEED, 0));
        _player.setPlayerSpeed(PLAYER_SPEED);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        _player.movePlayer(sf::Vector2f(0, PLAYER_SPEED));
        _player.setPlayerSpeed(PLAYER_SPEED);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        _player.movePlayer(sf::Vector2f(PLAYER_SPEED, 0));
        _player.setPlayerSpeed(PLAYER_SPEED);
    }
}

void Game::drawHealthBar()
{
	sf::RectangleShape healthBar;
	sf::RectangleShape healthBarBackground;
	healthBarBackground.setPosition(PLAYER_HEALTH_BAR_POS_X, PLAYER_HEALTH_BAR_POS_Y);
	healthBarBackground.setSize(sf::Vector2f(PLAYER_HEALTH_BAR_WIDTH, 20));
    healthBarBackground.setFillColor(sf::Color(sf::Color::Red));
	_window.draw(healthBarBackground);

	healthBar.setPosition(PLAYER_HEALTH_BAR_POS_X, PLAYER_HEALTH_BAR_POS_Y);
	healthBar.setSize(sf::Vector2f(200 * (_player.getPlayerHealth() / 50.0f), 20));
	healthBar.setFillColor(sf::Color::Yellow);
	_window.draw(healthBar);

    sf::Font healthBarFont;
	verificationFont(healthBarFont, "fonts\\PixelOperator8-bold.ttf");
	sf::Text healthBarText;
	healthBarText.setFont(healthBarFont);
	healthBarText.setString(std::to_string(_player.getPlayerHealth()) + " / 20");
	healthBarText.setCharacterSize(18);
	healthBarText.setFillColor(sf::Color::White);
	healthBarText.setPosition(PLAYER_HEALTH_BAR_POS_X + PLAYER_HEALTH_BAR_WIDTH + 5, PLAYER_HEALTH_BAR_POS_Y);
	_window.draw(healthBarText);

}

void Game::checkHealth()
{
   if (_player.getPlayerHealth() <= 0)
    {
        _endGame = true;
   }
}

void Game::checkDeath()
{
    if (_player.getPlayerHealth() <= 0)
    {
        _bgm.stop();

        _endGame = true;
        insertStats(_patterns.size(), _startOfGameClock);

        _window.clear(sf::Color::Black);

        sf::Texture splitSoul;
        verificationTexture(splitSoul, "images/undertale-split-soul.png");
        _player.getPlayer().setTexture(&splitSoul);

        sf::SoundBuffer deathBuffer;
        sf::Sound deathSound;
        if (!deathBuffer.loadFromFile("sound/undertale-death.wav")) {
            exit(1);
        }
        deathSound.setBuffer(deathBuffer);
        deathSound.setLoop(false);
        deathSound.play();

        _window.draw(_player.getPlayer());

        _window.display();

        Sleep(2000);
    }
}

void Game::checkPattern()
{
    if (_startOfGameClock.getElapsedTime() > sf::seconds(4.f))
    {
        if (_patterns.size() == 0)
        {
            Pattern pattern;
            _patterns.push_back(pattern); //temp pattern so it doesnt break everything under it
        }

        if (_patternClock.getElapsedTime() > sf::seconds(_patterns.at(_patterns.size() - 1).getPatternLifeTime()))
        {
            Pattern pattern;
            pattern.createPattern();
            _patterns.push_back(pattern);
            _patternClock.restart();
        }

        for (int i = 0; i < _patterns.size(); i++)
        {
            for (int j = 0; j < _patterns.at(i).getPattern().size(); j++) {

                if (checkBoundingBox(_player.getPlayerBounds(), _patterns.at(i).getPattern()[j].getBullet().getBulletBounds()) && !_player.hasIFrames())
                {
                    if (_patterns.at(i).getPattern()[j].checkBlue() && _player.getPlayerSpeed() != 0 || _patterns.at(i).getPattern()[j].checkOrange() && _player.getPlayerSpeed() == 0)
                    {
                        _player.takeDamage(1);
                    }
                    else if (_patterns.at(i).getPattern()[j].checkWhite())
                    {
                        _player.takeDamage(1);
                    }
                }
                if (checkBoundingBox(_player.getPlayerBounds(), _patterns.at(i).getPattern()[j].getBullet().getBulletBounds()) && _player.getPlayerHealth() < PLAYER_HP && _patterns.at(i).getPattern()[j].checkGreen())
                {
                    _patterns.at(i).deleteOneSnowball(j);
                    _player.setPlayerHealth(_player.getPlayerHealth() + 1);
                }
                _patterns.at(i).patternMovement(j);
            }

            _patterns.at(i).resetPattern();
        }
    }
}

void Game::menu()
{
    if (_showMenu || _endGame)
    {
        _bgm.stop();

        showMenu(_window);

        //Reinit
        _player.setPlayerPosition(sf::Vector2f(PLAYER_INIT_POSITION_X, PLAYER_INIT_POSITION_Y));
        _player.setPlayerHealth(PLAYER_HP);
        _player.initSprite();

        _bgm.play();

        _startOfGameClock.restart();

        _showMenu = false;
        _endGame = false;

        _patterns.clear();
    }
}

void Game::draw()
{
    _window.clear();

    for (int i = 0; i < _spawner.getSnowBullets().size(); i++)
    {
        _spawner.getSnowBullets().at(i).bulletMovement();
        _window.draw(_spawner.getSnowBullets().at(i).getSnowballCircle());
    }

    _arena.drawOutlineArena(_window);
    _window.draw(_snowBoss.getBoss());
    _window.draw(_player.getPlayer());
    drawHealthBar();

    for (int i = 0; i < _patterns.size(); i++) {
        for (int j = 0; j < _patterns.at(i).getPattern().size(); j++) {
            _window.draw(_patterns.at(i).getPattern().at(j).getBullet().getBulletCircle());
        }
    }
    
    _window.display();
}

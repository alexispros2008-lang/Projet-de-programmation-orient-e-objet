#include "Game.h"
#include "mesFonctions.h"

Game::Game()
{
	_player = Player(sf::Vector2f(400, 400), sf::Vector2f(20, 20));
    _player.initSprite();

    if (!bgmBuffer.loadFromFile("sound/bgm.wav")) {
        exit(1);
    }
    
    bgm.setBuffer(bgmBuffer); // On applique la musique chargée à l’objet de type "Sound"
    bgm.setLoop(true); // La musique jouera en boucle
    bgm.play(); // On fait jouer la musique
    //put all the music in function later

	_endGame = false;
}

Game::~Game()
{
}

void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "UndertaleBossFight", sf::Style::Close);
    window.setFramerateLimit(60);
    int numberOfPattern = 0;

    showMenu(window);

    while (window.isOpen())
    {
        sf::Time waitTime = sf::seconds(1.f);
        if (clock.getElapsedTime() >= waitTime) {
            clock.restart();
            pattern.resetPattern();
            numberOfPattern++;
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        movePlayer();
        checkArenaBounds();
        _player.stopIFrames();


        for (int i = 0; i < pattern.getPattern().size(); i++) {
            if (checkBoundingBox(_player.getPlayerBounds(), pattern.getPattern()[i].getSnowballBounds()) && !_player.hasIFrames())
            {
                _player.takeDamage(1);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //test pour take dmg
        {
            _player.takeDamage(1);
        }

        draw(window);

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

void Game::movePlayer()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        _player.movePlayer(sf::Vector2f(0, -PLAYER_SPEED));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        _player.movePlayer(sf::Vector2f(-PLAYER_SPEED, 0));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        _player.movePlayer(sf::Vector2f(0, PLAYER_SPEED));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        _player.movePlayer(sf::Vector2f(PLAYER_SPEED, 0));
    }
}

void Game::drawHealthBar(sf::RenderWindow& window)
{
	sf::RectangleShape healthBar;
	sf::RectangleShape healthBarBackground;
	healthBarBackground.setPosition(PLAYER_HEALTH_BAR_POS_X, PLAYER_HEALTH_BAR_POS_Y);
	healthBarBackground.setSize(sf::Vector2f(PLAYER_HEALTH_BAR_WIDTH, 20));
    healthBarBackground.setFillColor(sf::Color(sf::Color::Red));
	window.draw(healthBarBackground);

	healthBar.setPosition(PLAYER_HEALTH_BAR_POS_X, PLAYER_HEALTH_BAR_POS_Y);
	healthBar.setSize(sf::Vector2f(200 * (_player.getPlayerHealth() / 50.0f), 20));
	healthBar.setFillColor(sf::Color::Yellow);
	window.draw(healthBar);

    sf::Font healthBarFont;
	verificationFont(healthBarFont, "fonts\\PixelOperator8-bold.ttf");
	sf::Text healthBarText;
	healthBarText.setFont(healthBarFont);
	healthBarText.setString(std::to_string(_player.getPlayerHealth()) + " / 20");
	healthBarText.setCharacterSize(18);
	healthBarText.setFillColor(sf::Color::White);
	healthBarText.setPosition(PLAYER_HEALTH_BAR_POS_X + PLAYER_HEALTH_BAR_WIDTH + 5, PLAYER_HEALTH_BAR_POS_Y);
	window.draw(healthBarText);

}

void Game::checkHealth()
{
   if (_player.getPlayerHealth() <= 0)
    {
        _endGame = true;
   }
}

void Game::draw(sf::RenderWindow& window)
{
    window.clear();

    _arena.drawOutlineArena(window);
    window.draw(snowBoss.getBoss());
    window.draw(_player.getPlayer());
    drawHealthBar(window);

    for (int i = 0; i < pattern.getPattern().size(); i++) {
        pattern.patternMovement(i);
        window.draw(pattern.getPattern()[i].getSnowballCircle());
    }

    window.display();
}

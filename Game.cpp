#include "Game.h"
#include "Snowball.h"
#include "Pattern.h"
#include "mesFonctions.h"

Game::Game()
{
	_player = Player(sf::Vector2f(400, 400), sf::Vector2f(20, 20));
    _player.initSprite();
	_endGame = false;
}

Game::~Game()
{
}

void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "UndertaleBossFight", sf::Style::Close);
    sf::Vector2 <float> positionTestBullet;
    positionTestBullet.x = 120.f;
    positionTestBullet.y = 100.f;
    Snowball s(positionTestBullet, 1, 1, RIGHT_DOWN, 10);
    Boss snowBoss;
    Pattern pattern1("pattern/pattern1.txt");

    window.setFramerateLimit(60);

    std::vector<sf::Keyboard::Key> v_key;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();


        }

        movePlayer();
        checkBoundings();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //test pour take dmg
        {
            _player.takeDamage(1);
        }

        

        window.clear();



        _arena.drawOutlineArena(window);
        window.draw(snowBoss.getBoss());
        window.draw(_player.getPlayer());
        s.bulletMovement();
        /*pattern1.getAllProjectile().bulletMovement();*/
        window.draw(s.getCircle());
        window.draw(pattern1.drawPatern());
		showHealthBar(window);

        window.display();



        _player.getPreviousMovement().clear();



    }
}

void Game::checkBoundings()
{
    if (!_player.getPlayerBounds().intersects(_arena.getArenaBounds()))
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

void Game::showHealthBar(sf::RenderWindow& window)
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

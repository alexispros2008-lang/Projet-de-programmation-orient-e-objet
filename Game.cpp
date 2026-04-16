#include "Game.h"
#include "Snowball.h"

Game::Game()
{
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

	_player = Player(sf::Vector2f(400, 400), sf::Vector2f(10, 10));
    _player.initSprite();

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

        

        window.clear();



        _arena.drawOutlineArena(window);
        window.draw(snowBoss.getBoss());
        window.draw(_player.getPlayer());
        s.bulletMovement();
        window.draw(s.getCircle());
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

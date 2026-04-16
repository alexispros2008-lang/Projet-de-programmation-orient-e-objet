#include <iostream>
#include <SFML/Graphics.hpp>
#include "Snowball.h"
#include "Arena.h"
#include "mesConstantes.h"
#include "Player.h"
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!", sf::Style::Close);
    sf::Vector2 <int> positionTestBullet;
    positionTestBullet.x = 50;
    positionTestBullet.y = 50;

    Arena arena;

	Player p(sf::Vector2f(400, 400), sf::Vector2f(50, 50));

    std::vector<sf::Keyboard::Key> v_key;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            
        }

        //add clock so its not based on fps
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            p.movePlayer(sf::Vector2f(0, -0.1));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            p.movePlayer(sf::Vector2f(-0.1, 0));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            p.movePlayer(sf::Vector2f(0, 0.1));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            p.movePlayer(sf::Vector2f(0.1, 0));
        }

        if (!p.getPlayerBounds().intersects(arena.getArenaBounds()))
        {
            for (int i = 0; i < p.getPreviousMovement().size(); i++)
            {
                p.movePlayer(-p.getPreviousMovement().at(i));
                p.getPreviousMovement().pop_back();
            }
        }
       

        window.clear();

        

		arena.drawOutlineArena(window);
        window.draw(p.getPlayer());

        window.display();


        
        p.getPreviousMovement().clear();

        
    }

    return 0;
}
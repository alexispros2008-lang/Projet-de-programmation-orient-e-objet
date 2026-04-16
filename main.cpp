#include <iostream>
#include <SFML/Graphics.hpp>
#include "Snowball.h"
#include "Arena.h"
#include "mesConstantes.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!", sf::Style::Close);
    sf::Vector2 <int> positionTestBullet;
    positionTestBullet.x = 50;
    positionTestBullet.y = 50;
    Snowball s(positionTestBullet, positionTestBullet, 1, 1, NOTHING);
    Arena arena;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        

        window.draw(s.getCircle());
		arena.drawOutlineArena(window);

        window.display();
    }

    return 0;
}
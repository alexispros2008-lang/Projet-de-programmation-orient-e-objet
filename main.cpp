#include <iostream>
#include <SFML/Graphics.hpp>
#include "Snowball.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::Vector2 <int> positionTestBullet;
    positionTestBullet.x = 0;
    positionTestBullet.y = 0;
    Snowball s(positionTestBullet, positionTestBullet, 1, 1, NOTHING);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
        window.draw(s.getCircle());
    }

    return 0;
}
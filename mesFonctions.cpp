#include "mesFonctions.h"
#include "mesConstantes.h"
#include <SFML/Graphics.hpp>

void verificationTexture(sf::Texture &texture, std::string pathTexture) {
	if (!texture.loadFromFile(pathTexture)) {
		exit(1);
	}
}

void verificationFont(sf::Font& font, std::string pathFont) {
	if (!font.loadFromFile(pathFont)) {
		exit(1);
	}
}

bool checkBoundingBox(sf::FloatRect box1, sf::FloatRect box2) {
	return box1.intersects(box2);
}

void showMenu(sf::RenderWindow& window) {

	sf::Font menuFont;
	verificationFont(menuFont, "fonts\\PixelOperator8-bold.ttf");

	sf::Text menuText;
	menuText.setFont(menuFont);
	menuText.setString("Press Enter to Play");
	menuText.setCharacterSize(30);
	menuText.setFillColor(sf::Color::White);
	menuText.setPosition(WINDOW_WIDTH / 2 - menuText.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2 - menuText.getGlobalBounds().height / 2);

	sf::Text titleText;
	titleText.setFont(menuFont);
	titleText.setString("Undertale Boss Fight");
	titleText.setCharacterSize(20);
	titleText.setFillColor(sf::Color::White);
	titleText.setPosition(WINDOW_WIDTH / 2 - titleText.getGlobalBounds().width / 2, WINDOW_HEIGHT / 4 - titleText.getGlobalBounds().height / 2);

	sf::Text statsText;
	statsText.setFont(menuFont);
	statsText.setString("Press Space for Statistics");
	statsText.setCharacterSize(30);
	statsText.setFillColor(sf::Color::White);
	statsText.setPosition(WINDOW_WIDTH / 2 - statsText.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2 - statsText.getGlobalBounds().height / 2 + 50);

	sf::Text quitText;
	quitText.setFont(menuFont);
	quitText.setString("Press Escape to Quit");
	quitText.setCharacterSize(30);
	quitText.setFillColor(sf::Color::White);
	quitText.setPosition(WINDOW_WIDTH / 2 - quitText.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2 - quitText.getGlobalBounds().height / 2 + 100);

	window.draw(titleText);
	window.draw(menuText);
	window.draw(statsText);
	window.draw(quitText);

	window.display();

	sf::Event event;
	while (window.waitEvent(event))
	{
		if (event.key.code == sf::Keyboard::Enter)
		{
			break;
		}

		if (event.key.code == sf::Keyboard::Space)
		{

		}

		if(event.key.code == sf::Keyboard::Escape)
		{
			window.close();
			exit(0);
		}
	}	
}
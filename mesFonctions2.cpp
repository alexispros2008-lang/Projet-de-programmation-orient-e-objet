#include "mesFonctions.h"
#include "mesFonctions2.h"

void showHelp(sf::RenderWindow& window) {

	sf::Event event;
	while (window.waitEvent(event))
	{
		window.clear(sf::Color::Black);

		sf::Font menuFont;
		verificationFont(menuFont, "fonts\\PixelOperator8-bold.ttf");

		sf::Text helpText;
		helpText.setFont(menuFont);
		helpText.setString("Use the arrow keys to move.\nThe longer you survive, the more points you get!\n\nPress Escape to return to the menu.");
		helpText.setCharacterSize(15);
		helpText.setFillColor(sf::Color::White);
		helpText.setPosition(WINDOW_WIDTH / 2 - helpText.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2 - helpText.getGlobalBounds().height / 2);
		window.draw(helpText);
		window.display();

		if (event.type == sf::Event::KeyPressed)
		{
			break;
		}
	}
}
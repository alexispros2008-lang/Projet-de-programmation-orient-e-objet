#include "mesFonctions.h"
#include "mesFonctions2.h"
#include "mesConstantes.h"
#include <SFML/Graphics.hpp>
#include <fstream>

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

	sf::Text helpText;
	helpText.setFont(menuFont);
	helpText.setString("Press H for Help");
	helpText.setCharacterSize(30);
	helpText.setFillColor(sf::Color::White);
	helpText.setPosition(WINDOW_WIDTH / 2 - helpText.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2 - helpText.getGlobalBounds().height / 2 + 100);

	sf::Text quitText;
	quitText.setFont(menuFont);
	quitText.setString("Press Escape to Quit");
	quitText.setCharacterSize(30);
	quitText.setFillColor(sf::Color::White);
	quitText.setPosition(WINDOW_WIDTH / 2 - quitText.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2 - quitText.getGlobalBounds().height / 2 + 150);


	

	

	sf::Event event;
	sf::Clock clock;
	do
	{
		window.clear(sf::Color::Black);

		window.draw(titleText);
		window.draw(menuText);
		window.draw(statsText);
		window.draw(helpText);
		window.draw(quitText);

		if (clock.getElapsedTime() >= sf::seconds(0.5f))
		{
			if (event.key.code == sf::Keyboard::Enter)
			{
				break;
			}

			if (event.key.code == sf::Keyboard::Space)
			{

			}

			if (event.key.code == sf::Keyboard::H) {
				showHelp(window);
			}

			if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
			{
				window.close();
				exit(0);
			}
			clock.restart();
		}

		window.display();
	} while (window.waitEvent(event));
}

void iFrameAnimation(sf::RectangleShape& player, sf::Clock& animationClock)
{
	sf::Time elapsed;
	do
	{
		elapsed = animationClock.getElapsedTime();
		if (static_cast<int>(elapsed.asSeconds() * 10) % 2 == 1) {
			player.setFillColor(sf::Color::Color(player.getFillColor().r, player.getFillColor().g, player.getFillColor().b, 128));
		}
		if (static_cast<int>(elapsed.asSeconds() * 10) % 2 == 0)
		{
			player.setFillColor(sf::Color::Color(player.getFillColor().r, player.getFillColor().g, player.getFillColor().b, 255));
		}

	} while (elapsed.asSeconds() <= 1.0f);
}

void showStats() {
	std::ifstream statsFile;
	statsFile.open("stats.txt");

	if (!statsFile) {
		exit(1);
	}

	int totalGamesPlayed = 0;
	int totalDamageTaken = 0;
	int secondsPlayed = 0;

	statsFile >> totalGamesPlayed >> totalDamageTaken >> secondsPlayed;

	statsFile.close();
}


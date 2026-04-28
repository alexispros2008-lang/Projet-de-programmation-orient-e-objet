#include "mesFonctions.h"
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
	menuText.setCharacterSize(30);
	menuText.setFillColor(sf::Color::White);
	menuText.setPosition(50, 50);

	menuText.setString("Undertale Boss Fight\n\n\n"
		"Press Enter to Play\n\n"
		"Press Space for Statistics\n\n"
		"Press H for Help\n\n"
		"Press C for Option\n\n"
		"Press Escape to Quit"
	);

	sf::Event event;
	sf::Clock clock;
	do
	{
		window.clear(sf::Color::Black);

		window.draw(menuText);

		if (clock.getElapsedTime() >= sf::seconds(0.5f))
		{
			if (event.key.code == sf::Keyboard::Enter)
			{
				break;
			}

			if (event.key.code == sf::Keyboard::Space)
			{
				showStats(window);
			}

			if (event.key.code == sf::Keyboard::H) {
				showHelp(window);
			}

			if (event.key.code == sf::Keyboard::C)
			{
				showOption(window);
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

void iFrameAnimation(sf::RectangleShape& player, bool& hasIFrames)
{
	hasIFrames = true;

	sf::Clock iFramesClock;
	sf::Time elapsed;
	do
	{
		elapsed = iFramesClock.getElapsedTime();

		if (static_cast<int>(elapsed.asSeconds() * 10) % 2 == 1) 
		{
			player.setFillColor(sf::Color::Color(player.getFillColor().r, player.getFillColor().g, player.getFillColor().b, 128));
		}

		if (static_cast<int>(elapsed.asSeconds() * 10) % 2 == 0)
		{
			player.setFillColor(sf::Color::Color(player.getFillColor().r, player.getFillColor().g, player.getFillColor().b, 255));
		}

	} while (elapsed.asSeconds() <= 1.0f);

	hasIFrames = false;
}

void showStats(sf::RenderWindow& window) {
	
	std::ifstream statsFile;
	statsFile.open("save/stats.txt");

	if (!statsFile) {
		exit(1);
	}

	int bestSecondsSurvived = 0;
	int bestNumberOfPattern = 0;

	statsFile >> bestNumberOfPattern >> bestSecondsSurvived;

	statsFile.close();

	std::string numberOfPatternIntoString = std::to_string(bestNumberOfPattern);
	std::string secondsSurvivedIntoString = std::to_string(bestSecondsSurvived);

	sf::Event event;

	sf::Font menuFont;
	verificationFont(menuFont, "fonts\\PixelOperator8-bold.ttf");

	sf::Text numberOfPatternText;
	numberOfPatternText.setFont(menuFont);
	numberOfPatternText.setString("Best number of pattern : " + numberOfPatternIntoString);
	numberOfPatternText.setCharacterSize(30);
	numberOfPatternText.setFillColor(sf::Color::White);
	numberOfPatternText.setPosition(WINDOW_WIDTH / 2 - numberOfPatternText.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2 - numberOfPatternText.getGlobalBounds().height / 2 + 50);

	sf::Text secondsSurvivedText;
	secondsSurvivedText.setFont(menuFont);
	secondsSurvivedText.setString("Best time in seconds : " + secondsSurvivedIntoString);
	secondsSurvivedText.setCharacterSize(30);
	secondsSurvivedText.setFillColor(sf::Color::White);
	secondsSurvivedText.setPosition(WINDOW_WIDTH / 2 - secondsSurvivedText.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2 - secondsSurvivedText.getGlobalBounds().height / 2 + 100);

	sf::Text titleStatsText;
	titleStatsText.setFont(menuFont);
	titleStatsText.setString("Best statistics for every game played");
	titleStatsText.setCharacterSize(20);
	titleStatsText.setFillColor(sf::Color::White);
	titleStatsText.setPosition(WINDOW_WIDTH / 2 - titleStatsText.getGlobalBounds().width / 2, WINDOW_HEIGHT / 4 - titleStatsText.getGlobalBounds().height / 2);

	while (window.waitEvent(event))
	{
		window.clear(sf::Color::Black);

		window.draw(numberOfPatternText);
		window.draw(secondsSurvivedText);
		window.draw(titleStatsText);
		window.display();

		if (event.type == sf::Event::KeyPressed)
		{
			break;
		}
	}
}

bool compareStats(int numberOfPattern, sf::Clock startOfGameClock)
{
	std::ifstream statsFile;
	statsFile.open("save/stats.txt");

	if (!statsFile) {
		exit(1);
	}

	int oldBestSecondsSurvived = 0;
	int oldBestNumberOfPattern = 0;

	statsFile >> oldBestNumberOfPattern >> oldBestSecondsSurvived;

	statsFile.close();

	if (oldBestNumberOfPattern >= numberOfPattern)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void insertStats(int numberOfPattern, sf::Clock startOfGameClock)
{
	std::ofstream statsFile;
	statsFile.open("save/stats.txt");

	if (!statsFile) {
		exit(1);
	}

	if (compareStats(numberOfPattern, startOfGameClock))
	{
		statsFile << numberOfPattern << " " << startOfGameClock.getElapsedTime().asSeconds();
	}

	statsFile.close();
}



void showHelp(sf::RenderWindow& window) {

	sf::Font menuFont;
	verificationFont(menuFont, "fonts\\PixelOperator8-bold.ttf");

	sf::Text helpText;
	helpText.setFont(menuFont);
	helpText.setString("Use the arrow keys to move.\n"
		"Survive for as many patterns as you can!\n"
		"Blue bullets will hit you if you move.\n"
		"Orange bullets will hit you if you stay still.\n\n"
		"Press Escape to return to the menu."
	);
	helpText.setCharacterSize(17.5f);
	helpText.setFillColor(sf::Color::White);
	helpText.setPosition(WINDOW_WIDTH / 2 - helpText.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2 - helpText.getGlobalBounds().height / 2);

	sf::Event event;
	while (window.waitEvent(event))
	{
		window.clear(sf::Color::Black);

		window.draw(helpText);

		window.display();

		if (event.type == sf::Event::KeyPressed)
		{
			break;
		}
	}
}

void showOption(sf::RenderWindow& window) {

	sf::Event event;
	while (window.waitEvent(event))
	{
		window.clear(sf::Color::Black);

		sf::Font menuFont;
		verificationFont(menuFont, "fonts\\PixelOperator8-bold.ttf");

		sf::Text optionText;
		optionText.setFont(menuFont);
		optionText.setString("Press Y to put the game in 120fps, it will speed.\n"
			"up the game and make it harder.\n\n"
			"Press Escape to return to the menu."
);
		optionText.setCharacterSize(15);
		optionText.setFillColor(sf::Color::White);
		optionText.setPosition(50, 50);
		window.draw(optionText);
		window.display();

		if (event.key.code == sf::Keyboard::Escape)
		{
			break;
		}
		if (event.key.code == sf::Keyboard::Y)
		{
			window.setFramerateLimit(120);
			break;
		}
	}
}
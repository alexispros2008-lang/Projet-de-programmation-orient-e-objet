#include "mesFonctions.h"
#include "mesConstantes.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

	sf::SoundBuffer menuBGMBuffer;
	sf::Sound menuBGM;
	if (!menuBGMBuffer.loadFromFile("sound/mainmenu.wav")) {
		exit(1);
	}
	menuBGM.setBuffer(menuBGMBuffer);
	menuBGM.setLoop(true);
	menuBGM.play();

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
		"Press T for Tutorial\n\n"
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

			if (event.key.code == sf::Keyboard::T)
			{
				showTutorial(window);
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

	sf::Text titleStatsText;
	titleStatsText.setFont(menuFont);
	titleStatsText.setString("Best statistics for every game played");
	titleStatsText.setCharacterSize(20);
	titleStatsText.setFillColor(sf::Color::White);
	titleStatsText.setPosition(WINDOW_WIDTH / 2 - titleStatsText.getGlobalBounds().width / 2, WINDOW_HEIGHT / 4 - titleStatsText.getGlobalBounds().height / 2);

	sf::Text statisticText;
	statisticText.setFont(menuFont);
	statisticText.setString("Best number of pattern : " + numberOfPatternIntoString + "\n" +
		"Best time in seconds : " + secondsSurvivedIntoString + "\n"
	);
	statisticText.setCharacterSize(30);
	statisticText.setFillColor(sf::Color::White);
	statisticText.setPosition(WINDOW_WIDTH / 2 - statisticText.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2 - statisticText.getGlobalBounds().height / 2 + 50);

	while (window.waitEvent(event))
	{
		window.clear(sf::Color::Black);

		window.draw(titleStatsText);
		window.draw(statisticText);
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
			"Press U to put the game in 60fps, it will put.\n"
			"the game at the intended speed limit.\n\n"
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
		if (event.key.code == sf::Keyboard::U)
		{
			window.setFramerateLimit(60);
			break;
		}
	}
}

void showTutorial(sf::RenderWindow& window)
{
	int actualTutorial = 0;
	sf::Event event;
	sf::Clock clock;
	sf::RectangleShape tutorialInfo1;
	tutorialInfo1.setPosition(0.f, 0.f);
	tutorialInfo1.setSize({WINDOW_WIDTH, WINDOW_HEIGHT});
	static sf::Texture tutorialTexture1;

	verificationTexture(tutorialTexture1, "images\\tutorial\\1.png");
	tutorialInfo1.setTexture(&tutorialTexture1);

	sf::RectangleShape tutorialInfo2;
	tutorialInfo2.setPosition(0.f, 0.f);
	tutorialInfo2.setSize({ WINDOW_WIDTH, WINDOW_HEIGHT });
	static sf::Texture tutorialTexture2;

	verificationTexture(tutorialTexture2, "images\\tutorial\\2.png");
	tutorialInfo2.setTexture(&tutorialTexture2);

	sf::RectangleShape tutorialInfo3;
	tutorialInfo3.setPosition(0.f, 0.f);
	tutorialInfo3.setSize({ WINDOW_WIDTH, WINDOW_HEIGHT });
	static sf::Texture tutorialTexture3;

	verificationTexture(tutorialTexture3, "images\\tutorial\\3.png");
	tutorialInfo3.setTexture(&tutorialTexture3);

	sf::RectangleShape tutorialInfo4;
	tutorialInfo4.setPosition(0.f, 0.f);
	tutorialInfo4.setSize({ WINDOW_WIDTH, WINDOW_HEIGHT });
	static sf::Texture tutorialTexture4;

	verificationTexture(tutorialTexture4, "images\\tutorial\\4.png");
	tutorialInfo4.setTexture(&tutorialTexture4);
	
	sf::RectangleShape tutorialInfo5;
	tutorialInfo5.setPosition(0.f, 0.f);
	tutorialInfo5.setSize({ WINDOW_WIDTH, WINDOW_HEIGHT });
	static sf::Texture tutorialTexture5;

	verificationTexture(tutorialTexture5, "images\\tutorial\\5.png");
	tutorialInfo5.setTexture(&tutorialTexture5);

	while (window.waitEvent(event))
	{
		window.clear(sf::Color::Black);

		if (actualTutorial == 0) {
			window.draw(tutorialInfo1);
		}
		else if (actualTutorial == 1) {
			window.draw(tutorialInfo2);
		}
		else if (actualTutorial == 2) {
			window.draw(tutorialInfo3);
		}
		else if (actualTutorial == 3) {
			window.draw(tutorialInfo4);
		}
		else if (actualTutorial == 4) {
			window.draw(tutorialInfo5);
		}
		window.display();

		if (clock.getElapsedTime() >= sf::seconds(0.4f))
		{
			if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
			{
				if (actualTutorial == 0)
				{

				}
				else
				{
					actualTutorial = actualTutorial - 1;
				}
			}
			if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Right)
			{
				if (actualTutorial == 4)
				{

				}
				else
				{
					actualTutorial = actualTutorial + 1;

				}
			}
			if (event.key.code == sf::Keyboard::Escape)
			{
				break;
			}
			clock.restart();
		}
	}
}

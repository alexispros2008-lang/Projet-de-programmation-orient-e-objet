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
		"Press H for Credits\n\n"
		"Press C for Option\n\n"
		"Press T for Tutorial\n\n"
		"Press P for PowerPoint\n\n"
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

			if (event.key.code == sf::Keyboard::H) 
			{
				showCredits(window);
			}

			if (event.key.code == sf::Keyboard::C)
			{
				showOption(window);
			}

			if (event.key.code == sf::Keyboard::T)
			{
				showTutorial(window);
			}

			if (event.key.code == sf::Keyboard::P)
			{
				showPowerPoint(window);
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
	
	sf::Event event;

	while (window.waitEvent(event))
	{
		std::ifstream statsFile;

		int currentFps = 60;
		int actualDifficulty = 0;
		readOptionFile(currentFps, actualDifficulty);

		std::string actualDifficultyInString;
		actualDifficultyInString = transformActualDifficultyIntoString(actualDifficulty);

		if (actualDifficulty == NORMAL_MODE)
		{
			statsFile.open("save/normalModeStats.txt");
		}
		else if (actualDifficulty == HARD_MODE)
		{
			statsFile.open("save/hardModeStats.txt");
		}
		else if (actualDifficulty == EASY_MODE)
		{
			statsFile.open("save/easyModeStats.txt");
		}
		else if (actualDifficulty == DEBUG_MODE)
		{
			statsFile.open("save/debugModeStats.txt");
		}
		else if (actualDifficulty == CHAOS_MODE)
		{
			statsFile.open("save/chaosModeStats.txt");
		}
		else if (actualDifficulty == SUPER_HARD_MODE)
		{
			statsFile.open("save/superHardModeStats.txt");
		}

		if (!statsFile) {
			exit(1);
		}

		int bestSecondsSurvived = 0;
		int bestNumberOfPattern = 0;

		statsFile >> bestNumberOfPattern >> bestSecondsSurvived;

		statsFile.close();

		std::string numberOfPatternIntoString = std::to_string(bestNumberOfPattern);
		std::string secondsSurvivedIntoString = std::to_string(bestSecondsSurvived);

		sf::Font menuFont;
		verificationFont(menuFont, "fonts\\PixelOperator8-bold.ttf");

		sf::Text titleStatsText;
		titleStatsText.setFont(menuFont);
		titleStatsText.setString("Best statistics for every " + actualDifficultyInString + " game played");
		titleStatsText.setCharacterSize(20);
		titleStatsText.setFillColor(sf::Color::White);
		titleStatsText.setPosition(WINDOW_WIDTH / 2 - titleStatsText.getGlobalBounds().width / 2, WINDOW_HEIGHT / 4 - titleStatsText.getGlobalBounds().height / 2);

		sf::Text statisticText;
		statisticText.setFont(menuFont);
		statisticText.setString("Best number of pattern : " + numberOfPatternIntoString + "\n" +
			"Best time in seconds : " + secondsSurvivedIntoString + "\n"
			"\n\nPress B to put the game in easy mode.\n\n"
			"Press N to put the game in normal mode.\n\n"
			"Press M to put the game in hard mode.\n\n"
			"Press S to put the game in super hard mode.\n\n"
			"Press C to put the game in chaos mode.\n\n"
			"Press Z to put the game in debug mode.\n\n"
		);
		statisticText.setCharacterSize(20);
		statisticText.setFillColor(sf::Color::White);
		statisticText.setPosition(WINDOW_WIDTH / 2 - statisticText.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2 - statisticText.getGlobalBounds().height / 2 + 50);

		window.clear(sf::Color::Black);

		window.draw(titleStatsText);
		window.draw(statisticText);
		window.display();

		if (event.key.code == sf::Keyboard::Escape)
		{
			break;
		}
		if (event.key.code == sf::Keyboard::B)
		{
			actualDifficulty = EASY_MODE;
		}
		if (event.key.code == sf::Keyboard::N)
		{
			actualDifficulty = NORMAL_MODE;
		}
		if (event.key.code == sf::Keyboard::M)
		{
			actualDifficulty = HARD_MODE;
		}
		if (event.key.code == sf::Keyboard::C)
		{
			actualDifficulty = CHAOS_MODE;
		}
		if (event.key.code == sf::Keyboard::Z)
		{
			actualDifficulty = DEBUG_MODE;
		}
		if (event.key.code == sf::Keyboard::S)
		{
			actualDifficulty = SUPER_HARD_MODE;
		}
		writeCurrentOptionFile(currentFps, actualDifficulty);
	}
}

bool compareStats(int numberOfPattern, sf::Clock startOfGameClock, int actualDifficulty)
{
	std::ifstream statsFile;

	if (actualDifficulty == NORMAL_MODE)
	{
		statsFile.open("save/normalModeStats.txt");
	}
	else if (actualDifficulty == HARD_MODE)
	{
		statsFile.open("save/hardModeStats.txt");
	}
	else if (actualDifficulty == EASY_MODE)
	{
		statsFile.open("save/easyModeStats.txt");
	}
	else if (actualDifficulty == DEBUG_MODE)
	{
		statsFile.open("save/debugModeStats.txt");
	}
	else if (actualDifficulty == CHAOS_MODE)
	{
		statsFile.open("save/chaosModeStats.txt");
	}
	else if (actualDifficulty == SUPER_HARD_MODE)
	{
		statsFile.open("save/superHardModeStats.txt");
	}

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

void insertStats(int numberOfPattern, sf::Clock startOfGameClock, int actualDifficulty)
{
	std::ofstream statsFile;
	
	if (actualDifficulty == NORMAL_MODE)
	{
		statsFile.open("save/normalModeStats.txt");
	}
	else if (actualDifficulty == HARD_MODE)
	{
		statsFile.open("save/hardModeStats.txt");
	}
	else if (actualDifficulty == EASY_MODE)
	{
		statsFile.open("save/easyModeStats.txt");
	}
	else if (actualDifficulty == DEBUG_MODE)
	{
		statsFile.open("save/debugModeStats.txt");
	}
	else if (actualDifficulty == CHAOS_MODE)
	{
		statsFile.open("save/chaosModeStats.txt");
	}
	else if (actualDifficulty == SUPER_HARD_MODE)
	{
		statsFile.open("save/superHardModeStats.txt");
	}

	if (!statsFile) {
		exit(1);
	}

	if (compareStats(numberOfPattern, startOfGameClock, actualDifficulty))
	{
		statsFile << numberOfPattern << " " << startOfGameClock.getElapsedTime().asSeconds();
	}

	statsFile.close();
}



void showCredits(sf::RenderWindow& window) {

	sf::Font menuFont;
	verificationFont(menuFont, "fonts\\PixelOperator8-bold.ttf");

	sf::Text creditText;
	creditText.setFont(menuFont);
	creditText.setString("Made by :\n"
		"Nicolas Buldakov\n"
		"Alexis Provencher"
	);
	creditText.setCharacterSize(45.5f);
	creditText.setFillColor(sf::Color::White);
	creditText.setPosition(WINDOW_WIDTH / 2 - creditText.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2 - creditText.getGlobalBounds().height / 2);

	sf::Event event;
	while (window.waitEvent(event))
	{
		window.clear(sf::Color::Black);

		window.draw(creditText);

		window.display();

		if (event.type == sf::Event::KeyPressed)
		{
			break;
		}
	}
}

void showOption(sf::RenderWindow& window) {

	sf::Event event;
	int currentFps = 60;
	int actualDifficulty = 0;
	std::string actualDifficultyInString;
	readOptionFile(currentFps, actualDifficulty);

	while (window.waitEvent(event))
	{
		window.clear(sf::Color::Black);

		std::string currentFpsInString = std::to_string(currentFps);
		actualDifficultyInString = transformActualDifficultyIntoString(actualDifficulty);

		sf::Font menuFont;
		verificationFont(menuFont, "fonts\\PixelOperator8-bold.ttf");

		sf::Text optionText;
		optionText.setFont(menuFont);
		optionText.setString("Current Fps setting : " + currentFpsInString + "\n" 
			"Current difficulty : " + actualDifficultyInString + "\n\n\n\n"
			"Press Y to put the game in 120fps, it will speed.\n"
			"up the game and make it harder.\n\n"
			"Press U to put the game in 60fps, it will put.\n"
			"the game at the intended speed limit.\n\n"
			"Press B to put the game in easy mode.\n\n"
			"Press N to put the game in normal mode.\n\n"
			"Press M to put the game in hard mode.\n\n"
			"Press S to put the game in super hard mode.\n\n"
			"Press C to put the game in chaos mode.\n\n"
			"Press Z to put the game in debug mode.\n\n"
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
			currentFps = 120;
			window.setFramerateLimit(currentFps);
		}
		if (event.key.code == sf::Keyboard::U)
		{
			currentFps = 60;
			window.setFramerateLimit(currentFps);
		}
		if (event.key.code == sf::Keyboard::B)
		{
			actualDifficulty = EASY_MODE;
		}
		if (event.key.code == sf::Keyboard::N)
		{
			actualDifficulty = NORMAL_MODE;
		}
		if (event.key.code == sf::Keyboard::M)
		{
			actualDifficulty = HARD_MODE;
		}
		if (event.key.code == sf::Keyboard::C)
		{
			actualDifficulty = CHAOS_MODE;
		}
		if (event.key.code == sf::Keyboard::S)
		{
			actualDifficulty = SUPER_HARD_MODE;
		}
		if (event.key.code == sf::Keyboard::Z)
		{
			actualDifficulty = DEBUG_MODE;
		}
		writeCurrentOptionFile(currentFps, actualDifficulty);
	}
}

void readOptionFile(int& currentFps, int& actualDifficulty)
{
	std::ifstream optionFile;
	optionFile.open("save/option.txt");

	if (!optionFile) {
		exit(1);
	}

	optionFile >> currentFps >> actualDifficulty;

	optionFile.close();
}

void writeCurrentOptionFile(int& currentFps, int& actualDifficulty)
{
	std::ofstream optionFile;
	optionFile.open("save/option.txt");

	if (!optionFile) {
		exit(1);
	}

	optionFile << currentFps << " " << actualDifficulty;

	optionFile.close();
}

void showTutorial(sf::RenderWindow& window)
{
	int actualTutorial = 0;
	sf::Event event;
	sf::Clock clock;
	sf::RectangleShape tutorialInfo;
	tutorialInfo.setPosition(0.f, 0.f);
	tutorialInfo.setSize({WINDOW_WIDTH, WINDOW_HEIGHT});
	static sf::Texture tutorialTexture1;
	verificationTexture(tutorialTexture1, "images\\tutorial\\1.png");
	static sf::Texture tutorialTexture2;
	verificationTexture(tutorialTexture2, "images\\tutorial\\2.png");
	static sf::Texture tutorialTexture3;
	verificationTexture(tutorialTexture3, "images\\tutorial\\3.png");
	static sf::Texture tutorialTexture4;
	verificationTexture(tutorialTexture4, "images\\tutorial\\4.png");
	static sf::Texture tutorialTexture5;
	verificationTexture(tutorialTexture5, "images\\tutorial\\5.png");
	static sf::Texture tutorialTexture6;
	verificationTexture(tutorialTexture6, "images\\tutorial\\6.png");

	while (window.waitEvent(event))
	{
		window.clear(sf::Color::Black);

		if (actualTutorial == 0) {
			tutorialInfo.setTexture(&tutorialTexture1);
		}
		else if (actualTutorial == 1) {
			tutorialInfo.setTexture(&tutorialTexture2);
		}
		else if (actualTutorial == 2) {
			tutorialInfo.setTexture(&tutorialTexture3);
		}
		else if (actualTutorial == 3) {
			tutorialInfo.setTexture(&tutorialTexture4);
		}
		else if (actualTutorial == 4) {
			tutorialInfo.setTexture(&tutorialTexture5);
		}
		else if (actualTutorial == 5) {
			tutorialInfo.setTexture(&tutorialTexture6);
		}
		window.draw(tutorialInfo);
		window.display();

		if (clock.getElapsedTime() >= sf::seconds(0.4f))
		{
			if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
			{
				if (actualTutorial != 0)
				{
					actualTutorial = actualTutorial - 1;
				}
			}
			if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Right)
			{
				if (actualTutorial != 5)
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

void showPowerPoint(sf::RenderWindow& window)
{
	int actualPowerPoint = 0;
	sf::Event event;
	sf::Clock clock;
	sf::RectangleShape powerPointInfo;
	powerPointInfo.setPosition(0.f, 0.f);
	powerPointInfo.setSize({ WINDOW_WIDTH, WINDOW_HEIGHT });
	static sf::Texture powerPointTexture1;
	verificationTexture(powerPointTexture1, "images\\presentation\\Diapositive1.jpg");
	static sf::Texture powerPointTexture2;
	verificationTexture(powerPointTexture2, "images\\presentation\\Diapositive2.jpg");
	static sf::Texture powerPointTexture3;
	verificationTexture(powerPointTexture3, "images\\presentation\\Diapositive3.jpg");
	static sf::Texture powerPointTexture4;
	verificationTexture(powerPointTexture4, "images\\presentation\\Diapositive4.jpg");
	static sf::Texture powerPointTexture5;
	verificationTexture(powerPointTexture5, "images\\presentation\\Diapositive5.jpg");
	static sf::Texture powerPointTexture6;
	verificationTexture(powerPointTexture6, "images\\presentation\\Diapositive6.jpg");
	static sf::Texture powerPointTexture7;
	verificationTexture(powerPointTexture7, "images\\presentation\\Diapositive7.jpg");
	static sf::Texture powerPointTexture8;
	verificationTexture(powerPointTexture8, "images\\presentation\\Diapositive8.jpg");
	static sf::Texture powerPointTexture9;
	verificationTexture(powerPointTexture9, "images\\presentation\\Diapositive9.jpg");
	static sf::Texture powerPointTexture10;
	verificationTexture(powerPointTexture10, "images\\presentation\\Diapositive10.jpg");
	static sf::Texture powerPointTexture11;
	verificationTexture(powerPointTexture11, "images\\presentation\\Diapositive11.jpg");
	static sf::Texture powerPointTexture12;
	verificationTexture(powerPointTexture12, "images\\presentation\\Diapositive12.jpg");

	while (window.waitEvent(event))
	{
		window.clear(sf::Color::Black);

		if (actualPowerPoint == 0) 
		{
			powerPointInfo.setTexture(&powerPointTexture1);
		}
		else if (actualPowerPoint == 1) 
		{
			powerPointInfo.setTexture(&powerPointTexture2);
		}
		else if (actualPowerPoint == 2) 
		{
			powerPointInfo.setTexture(&powerPointTexture3);
		}
		else if (actualPowerPoint == 3) 
		{
			powerPointInfo.setTexture(&powerPointTexture4);
		}
		else if (actualPowerPoint == 4)
		{
			powerPointInfo.setTexture(&powerPointTexture5);
		}
		else if (actualPowerPoint == 5)
		{
			powerPointInfo.setTexture(&powerPointTexture6);
		}
		else if (actualPowerPoint == 6)
		{
			powerPointInfo.setTexture(&powerPointTexture7);
		}
		else if (actualPowerPoint == 7)
		{
			powerPointInfo.setTexture(&powerPointTexture8);
		}
		else if (actualPowerPoint == 8)
		{
			powerPointInfo.setTexture(&powerPointTexture9);
		}
		else if (actualPowerPoint == 9)
		{
			powerPointInfo.setTexture(&powerPointTexture10);
		}
		else if (actualPowerPoint == 10)
		{
			powerPointInfo.setTexture(&powerPointTexture11);
		}
		else if (actualPowerPoint == 11)
		{
			powerPointInfo.setTexture(&powerPointTexture12);
		}
		window.draw(powerPointInfo);
		window.display();

		if (clock.getElapsedTime() >= sf::seconds(0.4f))
		{
			if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
			{
				if (actualPowerPoint != 0)
				{
					actualPowerPoint = actualPowerPoint - 1;
				}
			}
			if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Right)
			{
				if (actualPowerPoint != 11)
				{
					actualPowerPoint = actualPowerPoint + 1;
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

std::string transformActualDifficultyIntoString(const int& actualDifficulty)
{
	std::string actualDifficultyInString = std::to_string(actualDifficulty);
	if (actualDifficulty == NORMAL_MODE)
	{
		actualDifficultyInString = "Normal";
	}
	else if (actualDifficulty == HARD_MODE)
	{
		actualDifficultyInString = "Hard";
	}
	else if (actualDifficulty == EASY_MODE)
	{
		actualDifficultyInString = "Easy";
	}
	else if (actualDifficulty == DEBUG_MODE)
	{
		actualDifficultyInString = "Debug";
	}
	else if (actualDifficulty == CHAOS_MODE)
	{
		actualDifficultyInString = "Chaos";
	}
	else if (actualDifficulty == SUPER_HARD_MODE)
	{
		actualDifficultyInString = "SHard";
	}
	return actualDifficultyInString;
}

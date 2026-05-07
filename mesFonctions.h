#pragma once
#include <SFML/Graphics.hpp>

void verificationTexture(sf::Texture& texture, std::string pathTexture);
void verificationFont(sf::Font& font, std::string pathFont);
bool checkBoundingBox(sf::FloatRect, sf::FloatRect);
void showMenu(sf::RenderWindow& window);
void iFrameAnimation(sf::RectangleShape& player, bool& hasIFrames);
void showHelp(sf::RenderWindow& window);
void insertStats(int numberOfPattern, sf::Clock startOfGameClock);
bool compareStats(int numberOfPattern, sf::Clock startOfGameClock);
void showStats(sf::RenderWindow& window);
void showOption(sf::RenderWindow& window);
void showTutorial(sf::RenderWindow& window);
void showPowerPoint(sf::RenderWindow& window);
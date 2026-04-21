#pragma once
#include <SFML/Graphics.hpp>

void verificationTexture(sf::Texture& texture, std::string pathTexture);
void verificationFont(sf::Font& font, std::string pathFont);
bool checkBoundingBox(sf::FloatRect, sf::FloatRect);


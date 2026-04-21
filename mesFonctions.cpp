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
	menuText.setString("Press Enter to Start");
	menuText.setCharacterSize(30);
	menuText.setFillColor(sf::Color::White);
	menuText.setPosition(WINDOW_WIDTH / 2 - menuText.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2 - menuText.getGlobalBounds().height / 2);
	window.draw(menuText);
}
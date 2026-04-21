#include "mesFonctions.h"
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
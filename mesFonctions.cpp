#include "mesFonctions.h"
#include <SFML/Graphics.hpp>

void verificationTexture(sf::Texture &texture, std::string pathTexture) {
	if (!texture.loadFromFile(pathTexture)) {
		exit(1);
	}
}
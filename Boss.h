#pragma once
#include <SFML/Graphics.hpp>
class Boss
{
	private:
		sf::RectangleShape _boss;
	public:
		Boss();
		void initSpriteBoss();
		sf::RectangleShape getBoss();
};


#pragma once
#include <SFML/Graphics.hpp>
class Boss
{
	private:
		sf::RectangleShape _boss;
		sf::Clock _timerForNextText;
		int _randomNumberIntVersion = 1;
	public:
		Boss();
		void initSpriteBoss();
		void randomSpriteBoss(std::string randomNumberForBossText);
		sf::RectangleShape getBoss();
};


#pragma once
#include <SFML/Graphics.hpp>
class Boss
{
	private:
		sf::RectangleShape _boss;
		sf::Text _bossText;
		sf::Clock _timerForNextText;
		int _randomEventText = 1;
		bool _hasChanged = false;
		sf::Texture _bossTexture;
		sf::Texture _bossTextureWithText;
		sf::Font _textboxBossFont;

	public:
		Boss();
		void initSpriteBoss();
		void initTextBoss();
		void randomTextBoss(int randomEventText);
		sf::RectangleShape getBoss();
		sf::Text& getBossText();
};

